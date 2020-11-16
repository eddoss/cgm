

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
    glDeleteTextures(1, &m_fboTexture);
}

Text2DLauncher::Text2DLauncher(const CLI& parameters)
    : m_params(parameters)
    , m_roughShader(std::make_shared<ShaderProgram>())
    , m_controlShader(std::make_shared<ShaderProgram>())
    , m_screenPlateVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{
    FT_Init_FreeType(&m_ftLibInstance);

    m_roughShader->create();
    m_roughShader->addShaderPack(L"Resources/Shaders/Text/Rough");
    m_roughShader->link();

    m_controlShader->create();
    m_controlShader->addShaderPack(L"Resources/Shaders/Text/Control");
    m_controlShader->link();

    m_text = std::make_unique<Text>(m_ftLibInstance, m_roughShader, m_controlShader);
    m_text->setFont(m_params.fontFile);
    m_text->setText(TEXT);

    glGenTextures(1, &m_fboTexture);
    glGenFramebuffers(1, &m_fbo);
}

void
Text2DLauncher::beforeLoop()
{
    m_text->init();

    setupFrameBuffer();
    setupScreenPlate();

    const auto aspectRatio = this->aspect<float>();

    m_roughShader->bind();
    m_roughShader->setUniform("parmAspect", aspectRatio);
    m_roughShader->setUniform("em", m_text->emSize());
    m_roughShader->release();

    m_controlShader->bind();
    m_controlShader->setUniform("parmAspect", aspectRatio);
    m_controlShader->setUniform("em", m_text->emSize());
    m_controlShader->release();
}

void
Text2DLauncher::render()
{
    // draw to frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_SUBTRACT);
    glClear(GL_COLOR_BUFFER_BIT);

    m_text->roughShader()->bind();
    m_text->roughShader()->setUniform("offset", m_textOffset);
    m_text->roughShader()->setUniform("scale", m_textScale);
    m_text->roughVao().bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, m_text->roughPointsCount());
    m_text->roughVao().release();

    if (m_text->controlPointsCount())
    {
        m_text->controlShader()->bind();
        m_text->controlShader()->setUniform("offset", m_textOffset);
        m_text->controlShader()->setUniform("scale", m_textScale);

        m_text->controlVao().bind();
        glDrawArrays(GL_TRIANGLES, 0, m_text->controlPointsCount());
        m_text->controlVao().release();
    }

    // draw on the screen
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_BLEND);
    glClear(GL_COLOR_BUFFER_BIT);

    m_postProcessShader.bind();
    m_screenPlateVao.bind();
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, m_fboTexture);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    m_screenPlateVao.release();
}

void
Text2DLauncher::resizeEvent()
{
    glViewport(0, 0, GLsizei(width()), GLsizei(height()));

    const auto aspectRatio = this->aspect<float>();

    setupFrameBuffer();

    m_postProcessShader.bind();
    m_postProcessShader.setUniform("screenWidth", width());
    m_postProcessShader.setUniform("screenHeight", height());
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
    const auto scaleStep = 0.0005f;

    if (buttonState(EButton::Left) == EState::Press)
    {
        m_textOffset.x += 2 * offset.x;
        m_textOffset.y += 2 * offset.y;
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
            m_textScale.y += scaleStep;
        }
        else if (offset.y < 0)
        {
            m_textScale.y -= scaleStep;
        }
    }
}

void
Text2DLauncher::keyEvent(BaseWindow::EKey key, BaseWindow::EState state, BaseWindow::EModifier modifier)
{
    BaseWindow::keyEvent(key, state, modifier);

    if (key == EKey::Space)
    {
        m_textOffset = {-0.5, 0};
        m_textScale = {0.045, 0.045};
    }
}

void
Text2DLauncher::setupFrameBuffer()
{
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, m_fboTexture );
    glTexParameteri (GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri (GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexImage2DMultisample( GL_TEXTURE_2D_MULTISAMPLE, 16, GL_RGB, width(), height(), false );

    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo );
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, m_fboTexture, 0 );

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

    m_postProcessShader.addShaderPack(L"Resources/Shaders/Text/PostProcess");
    m_postProcessShader.link();

    m_screenPlateVao.bind();
    m_screenPlateVbo.bind();
    m_screenPlateVbo.allocate(platePoints.size() * sizeof(cgm::vec2), platePoints.data());

    m_postProcessShader.bind();
    m_postProcessShader.enableAttributeArray("attrPosition");
    m_postProcessShader.setAttributeBuffer("attrPosition", EGLType::Float, 2, 0, sizeof(cgm::vec2));
    m_postProcessShader.setUniform("screenTexture", m_fboTexture);
    m_postProcessShader.setUniform("screenWidth", width());
    m_postProcessShader.setUniform("screenHeight", height());
    m_postProcessShader.setUniform("enableSPAA", m_params.spaa);
    m_postProcessShader.setUniform("gammaCorrection", m_params.gamma);

    m_screenPlateVao.release();
}

