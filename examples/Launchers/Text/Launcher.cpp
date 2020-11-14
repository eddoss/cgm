

#include <Launcher.hpp>
#include <CGM/Modules/Coordinates.hpp>

namespace cgx = cgm::xyz;

Text2DLauncher::~Text2DLauncher()
{
    if (ftLibInstance)
    {
        FT_Done_FreeType(ftLibInstance);
    }

    glDeleteFramebuffers(1, &fbo);
    glDeleteTextures(1, &fboTexture);
}

Text2DLauncher::Text2DLauncher()
    : roughShader(std::make_shared<ShaderProgram>())
    , controlShader(std::make_shared<ShaderProgram>())
    , screenPlateVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{
    FT_Init_FreeType(&ftLibInstance);

    roughShader->create();
    roughShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Rough");
    roughShader->link();

    controlShader->create();
    controlShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Control");
    controlShader->link();

    text = std::make_unique<Text>(ftLibInstance, roughShader, controlShader);
    text->setFont("C:/Windows/Fonts/FreeSerifItalic.ttf");
//    text->setFont("C:/Windows/Fonts/Candara.ttf");
//    text->setFont("C:/Windows/Fonts/times.ttf");
//    text->setFont("C:/Windows/Fonts/tahoma.ttf");
    text->setText("VA. Hello World. Scalable text. 0123456789 .,!?<>()[]{}");

    glGenTextures(1, &fboTexture);
    glGenFramebuffers(1, &fbo);
}

void
Text2DLauncher::beforeLoop()
{
    text->init();

//    setWidth(1280);
//    setHeight(720);

    setupFrameBuffer();
    setupScreenPlate();

    const auto aspectRatio = this->aspect<float>();

    roughShader->bind();
//    roughShader->setUniform("screenWidth", width());
//    roughShader->setUniform("screenHeight", height());
    roughShader->setUniform("parmAspect", aspectRatio);
    roughShader->setUniform("em", text->emSize());
    roughShader->release();

    controlShader->bind();
//    controlShader->setUniform("screenWidth", width());
//    controlShader->setUniform("screenHeight", height());
    controlShader->setUniform("parmAspect", aspectRatio);
    controlShader->setUniform("em", text->emSize());
    controlShader->release();
}

void
Text2DLauncher::render()
{
    // draw to frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_SUBTRACT);
    glClear(GL_COLOR_BUFFER_BIT);

    text->roughShader()->bind();
    text->roughShader()->setUniform("offset", textOffset);
    text->roughShader()->setUniform("scale", textScale);
    text->roughVao().bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, text->roughPointsCount());
    text->roughVao().release();

    if (text->controlPointsCount())
    {
        text->controlShader()->bind();
        text->controlShader()->setUniform("offset", textOffset);
        text->controlShader()->setUniform("scale", textScale);

        text->controlVao().bind();
            glDrawArrays(GL_TRIANGLES, 0, text->controlPointsCount());
        text->controlVao().release();
    }

    // draw on the screen
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_BLEND);
    glClear(GL_COLOR_BUFFER_BIT);

    subpixelAntialiasingShader.bind();
    screenPlateVao.bind();
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, fboTexture);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    screenPlateVbo.bind();
}

void
Text2DLauncher::resizeEvent()
{
    glViewport(0, 0, GLsizei(width()), GLsizei(height()));

    const auto aspectRatio = this->aspect<float>();

    setupFrameBuffer();

    subpixelAntialiasingShader.bind();
    subpixelAntialiasingShader.setUniform("screenWidth", width());
    subpixelAntialiasingShader.setUniform("screenHeight", height());
    subpixelAntialiasingShader.release();

    roughShader->bind();
//    roughShader->setUniform("screenWidth", width());
//    roughShader->setUniform("screenHeight", height());
    roughShader->setUniform("parmAspect", aspectRatio);
    roughShader->release();

    controlShader->bind();
//    controlShader->setUniform("screenWidth", width());
//    controlShader->setUniform("screenHeight", height());
    controlShader->setUniform("parmAspect", aspectRatio);
    controlShader->release();

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
        textOffset.x += 2 * offset.x;
        textOffset.y += 2 * offset.y;
    }
    else if (buttonState(EButton::Right) == EState::Press)
    {
        if (offset.x > 0)
        {
            textScale.x += scaleStep;
        }
        else if (offset.x < 0)
        {
            textScale.x -= scaleStep;
        }

        if (offset.y > 0)
        {
            textScale.y += scaleStep;
        }
        else if (offset.y < 0)
        {
            textScale.y -= scaleStep;
        }
    }
}

void
Text2DLauncher::setupFrameBuffer()
{
//    glBindTexture(GL_TEXTURE_2D, fboTexture);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width(), height(), 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTexture, 0);
//
//    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//    {
//        CGM_EXAMPLES_FUNC_ERROR("Could not create FBO")
//    }
//
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glBindTexture( GL_TEXTURE_2D_MULTISAMPLE, fboTexture );
    glTexParameteri (GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri (GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexImage2DMultisample( GL_TEXTURE_2D_MULTISAMPLE, 16, GL_RGB, width(), height(), false );

    glBindFramebuffer( GL_FRAMEBUFFER, fbo );
    glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, fboTexture, 0 );

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

    screenPlateVao.create();
    screenPlateVbo.create();
    subpixelAntialiasingShader.create();
    antialiasingShader.create();

//    antialiasingShader.addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/AA");
//    antialiasingShader.link();

    subpixelAntialiasingShader.addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/SAA");
    subpixelAntialiasingShader.link();

    screenPlateVao.bind();

    screenPlateVbo.bind();
    screenPlateVbo.allocate(platePoints.size() * sizeof(cgm::vec2), platePoints.data());

    subpixelAntialiasingShader.bind();
    subpixelAntialiasingShader.setAttributeBuffer("attrPosition", EGLType::Float, 2, 0, sizeof(cgm::vec2));
    subpixelAntialiasingShader.enableAttributeArray("attrPosition");
    subpixelAntialiasingShader.setUniform("screenTexture", fboTexture);
    subpixelAntialiasingShader.setUniform("screenWidth", width());
    subpixelAntialiasingShader.setUniform("screenHeight", height());

    screenPlateVao.release();
}
