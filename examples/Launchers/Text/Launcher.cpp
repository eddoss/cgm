

#include <Launcher.hpp>
#include <CGM/Modules/Coordinates.hpp>


static std::string TEXT = "Our first goal is to fill in all of the pixels inside the glyph using the GPU.\n"
                          "The outline of a glyph is formed by a series of straight and curved segments.\n"
                          "TrueType fonts use quadratic Bezier curve segments. Each quadratic segment\n"
                          "has one control point that controls how the curve bends. The control points\n"
                          "are drawn below in gray.";

Text2DLauncher::~Text2DLauncher()
{
    if (m_ftLibInstance)
    {
        FT_Done_FreeType(m_ftLibInstance);
    }

    glDeleteFramebuffers(1, &m_fbo);
    glDeleteTextures(1, &m_fboTextureA);
}

Text2DLauncher::Text2DLauncher(const CLI& parameters)
    : m_params(parameters)
    , m_roughShader(std::make_shared<ShaderProgram>())
    , m_controlShader(std::make_shared<ShaderProgram>())
    , m_screenPlateVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{
    FT_Init_FreeType(&m_ftLibInstance);

    m_roughShader->create();
    m_roughShader->addShaderPack(resource("Shaders/Text/Rough"));
    m_roughShader->link();

    m_controlShader->create();
    m_controlShader->addShaderPack(resource("Shaders/Text/Control"));
    m_controlShader->link();

    m_text = std::make_unique<Text>(m_ftLibInstance, m_roughShader, m_controlShader);
    m_text->setFont(m_params.fontFile);
    m_text->setText(TEXT);
}

void
Text2DLauncher::beforeLoop()
{
    setupOffsets();

    m_text->init();

    glGenFramebuffers(1, &m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glGenTextures(1, &m_fboTextureA);
    glGenTextures(1, &m_fboTextureB);
    setupFrameBuffer();

    setupScreenPlate();

    const auto aspectRatio = this->aspect<float>();
    const auto color = cgm::vec4(16.0f/255.0f);

    m_roughShader->bind();
    m_roughShader->setUniform("parmAspect", aspectRatio);
    m_roughShader->setUniform("em", m_text->emSize());
    m_roughShader->setUniform("color", color);
    m_roughShader->release();

    m_controlShader->bind();
    m_controlShader->setUniform("parmAspect", aspectRatio);
    m_controlShader->setUniform("em", m_text->emSize());
    m_controlShader->setUniform("color", color);
    m_controlShader->release();

    glDisable(GL_MULTISAMPLE);

}

void
Text2DLauncher::drawRoughShape()
{
    m_roughShader->bind();
    m_roughShader->setUniform("offset", m_textOffset);
    m_roughShader->setUniform("scale", m_textScale);
    m_text->roughVao().bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, m_text->roughPointsCount());
    m_text->roughVao().release();
}

void
Text2DLauncher::drawSmoothPieces()
{
    if (m_text->controlPointsCount())
    {
        m_controlShader->bind();
        m_controlShader->setUniform("offset", m_textOffset);
        m_controlShader->setUniform("scale", m_textScale);
        m_text->controlVao().bind();
        glDrawArrays(GL_TRIANGLES, 0, m_text->controlPointsCount());
        m_text->controlVao().release();
    }
}

void
Text2DLauncher::drawAntialiasing()
{
    m_postProcessShader.bind();
    m_screenPlateVao.bind();
    glBindTexture(GL_TEXTURE_2D, m_fboTextureA);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    m_screenPlateVao.release();
}

void
Text2DLauncher::render()
{
    // draw to frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_ADD);

//    glDrawBuffer(GL_COLOR_ATTACHMENT0);
    glNamedFramebufferDrawBuffer(m_fbo, GL_COLOR_ATTACHMENT0);
    glClear(GL_COLOR_BUFFER_BIT);
    for (const auto& [offset, color] : samplesPropertiesA)
    {
        m_roughShader->bind();
        m_roughShader->setUniform("internalOffset", offset);
        m_roughShader->setUniform("color", color);
        drawRoughShape();

        m_controlShader->bind();
        m_controlShader->setUniform("internalOffset", offset);
        m_controlShader->setUniform("color", color);
        drawSmoothPieces();
    }

//    glNamedFramebufferDrawBuffer(m_fbo, GL_COLOR_ATTACHMENT1);
//    glClear(GL_COLOR_BUFFER_BIT);
//    for (const auto& [offset, color] : samplesPropertiesB)
//    {
//        m_roughShader->bind();
//        m_roughShader->setUniform("internalOffset", offset);
//        m_roughShader->setUniform("color", color);
//        drawRoughShape();
//
//        m_controlShader->bind();
//        m_controlShader->setUniform("internalOffset", offset);
//        m_controlShader->setUniform("color", color);
//        drawSmoothPieces();
//    }

    // draw framebuffer on the screen
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_BLEND);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawAntialiasing();
}

void
Text2DLauncher::resizeEvent()
{
    setupOffsets();

    glViewport(0, 0, GLsizei(width()), GLsizei(height()));

    const auto aspectRatio = this->aspect<float>();

    setupFrameBuffer();

    m_postProcessShader.bind();
    m_postProcessShader.setUniform("screenWidth", width());
    m_postProcessShader.release();

    m_roughShader->bind();
    m_roughShader->setUniform("parmAspect", aspectRatio);
    m_roughShader->release();

    m_controlShader->bind();
    m_controlShader->setUniform("parmAspect", aspectRatio);
    m_controlShader->release();

    renderEvent();
    glfwSwapBuffers(m_window);
}

void
Text2DLauncher::mouseMoveEvent(cgm::Vector<2, int> position)
{
    Application::mouseMoveEvent(position);

    const auto offset = mouseOffset();
    const auto scaleStep = 0.0025f;

    if (buttonState(EButton::Left) == EState::Press)
    {
        m_textOffset.x += offset.x;
        m_textOffset.y += offset.y;
    }
    else if (buttonState(EButton::Right) == EState::Press)
    {
        if (offset.x > 0)
        {
            m_textScale.x += scaleStep;
        }
        else if (offset.x < 0)
        {
            m_textScale.x -= scaleStep;
        }

        if (offset.y > 0)
        {
            m_textScale.y *= (1.0f + scaleStep);
        }
        else if (offset.y < 0)
        {
            m_textScale.y *= (1.0f - scaleStep);
        }
    }
}

void
Text2DLauncher::keyEvent(BaseWindow::EKey key, BaseWindow::EState state, BaseWindow::EModifier modifier)
{
    BaseWindow::keyEvent(key, state, modifier);

    switch (key)
    {
        case EKey::KP1:
        {
            m_textOffset = {-0.5, 0};
            m_textScale = {0.045, 0.045};
            break;
        }
        case EKey::KP2:
        {
            m_textOffset = {-0.5, 0};
            m_textScale = {0.03, 0.03};
            break;
        }
        case EKey::Space:
        {
            if (keyState(key) == EState::Release)
            {
                m_params.spaa = !m_params.spaa;
                m_postProcessShader.setUniform("enableSPAA", m_params.spaa);
            }
            break;
        }
    }
}

void
Text2DLauncher::setupFrameBuffer()
{
    glBindTexture(GL_TEXTURE_2D, m_fboTextureA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    glBindTexture(GL_TEXTURE_2D, m_fboTextureB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_fboTextureA, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, m_fboTextureB, 0);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        CGM_EXAMPLES_FUNC_ERROR("Could not create FBO")
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void
Text2DLauncher::setupScreenPlate()
{
    const auto platePoints = std::vector
    {
        cgm::vec2 {-1,-1}, cgm::vec2 {-1, 1},
        cgm::vec2 { 1, 1}, cgm::vec2 { 1,-1}
    };

    m_screenPlateVao.create();
    m_screenPlateVbo.create();

    m_postProcessShader.create();
    m_postProcessShader.addShaderPack(resource("Shaders/Text/PostProcess"));
    m_postProcessShader.link();

    m_screenPlateVao.bind();
    m_screenPlateVbo.bind();
    m_screenPlateVbo.allocate(platePoints.size() * sizeof(cgm::vec2), platePoints.data());

    m_postProcessShader.bind();
    m_postProcessShader.enableAttributeArray("attrPosition");
    m_postProcessShader.setAttributeBuffer("attrPosition", EGLType::Float, 2, 0, sizeof(cgm::vec2));
    m_postProcessShader.setUniform("samplesA", m_fboTextureA);
    m_postProcessShader.setUniform("samplesB", m_fboTextureB);
    m_postProcessShader.setUniform("screenWidth", width());
    m_postProcessShader.setUniform("enableSPAA", m_params.spaa);
    m_postProcessShader.setUniform("gammaCorrection", m_params.gamma);

    m_screenPlateVao.release();
}

void
Text2DLauncher::setupOffsets()
{
    const auto c = 1.0f / 255.0f;
    const auto r = cgm::vec4{c, 0.0, 0.0, 0.0};
    const auto g = cgm::vec4{0.0, c, 0.0, 0.0};
    const auto b = cgm::vec4{0.0, 0.0, c, 0.0};
    const auto a = cgm::vec4{0.0, 0.0, 0.0, c};

    const auto x = 2.0f / (cgm::float32(width()));
    const auto y = 2.0f / (cgm::float32(height()));
    const auto pixelSize = cgm::vec2{x,y};

    samplesPropertiesA =
    {
        {pixelSize * cgm::vec2{+0.06654f, +0.44832f}, r},
        {pixelSize * cgm::vec2{+0.45031f, +0.19291f}, g},
        {pixelSize * cgm::vec2{+0.31802f, -0.32054f}, b},
        {pixelSize * cgm::vec2{-0.19149f, -0.44759f}, a}
    };

    samplesPropertiesB =
    {
        {pixelSize * cgm::vec2{-0.44690f, -0.19480f}, r},
        {pixelSize * cgm::vec2{-0.32378f, +0.31996f}, g},
        {pixelSize * cgm::vec2{+0.19621f, -0.06381f}, b},
        {pixelSize * cgm::vec2{-0.06575f, +0.06324f}, a}
    };
}

