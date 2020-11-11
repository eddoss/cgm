

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
    , plateVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{
    FT_Init_FreeType(&ftLibInstance);

    roughShader->create();
    roughShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Rough");
    roughShader->link();

    controlShader->create();
    controlShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Control");
    controlShader->link();

    text = std::make_unique<Text>(ftLibInstance, roughShader, controlShader);
//    text->setFont("C:/Windows/Fonts/FreeSerifItalic.ttf");
    text->setFont("C:/Windows/Fonts/Candara.ttf");
    text->setText("hello world");

    glGenTextures(1, &fboTexture);
    glGenFramebuffers(1, &fbo);
}

void
Text2DLauncher::beforeLoop()
{
    text->init();

    setWidth(1280);
    setHeight(720);

    setupFrameBuffer();
    setupPlate();

    const auto aspectRatio = this->aspect<float>();

    text->roughShader()->bind();
    text->roughShader()->setUniform("parmAspect", aspectRatio);
    text->roughShader()->release();

    text->controlShader()->bind();
    text->controlShader()->setUniform("parmAspect", aspectRatio);
    text->controlShader()->release();
}

void
Text2DLauncher::render()
{
    // draw to frame buffer
//    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
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


//    // draw on the screen
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
////    glDisable(GL_MULTISAMPLE);
//    glDisable(GL_BLEND);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    plateShader.bind();
//    plateVao.bind();
//    glBindTexture(GL_TEXTURE_2D, fboTexture);
//    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    plateVbo.bind();
}

void
Text2DLauncher::resizeEvent()
{
    const auto aspectRatio = this->aspect<float>();

    text->roughShader()->bind();
    text->roughShader()->setUniform("parmAspect", aspectRatio);
    text->roughShader()->release();

    text->controlShader()->bind();
    text->controlShader()->setUniform("parmAspect", aspectRatio);
    text->controlShader()->release();

    setupFrameBuffer();

    glViewport(0, 0, GLsizei(width()), GLsizei(height()));
    clearEvent();
    renderEvent();
    glfwSwapBuffers(m_window);
}

void
Text2DLauncher::mouseMoveEvent(cgm::Vector<2, int> position)
{
    Application::mouseMoveEvent(position);

    const auto offset = mouseOffset();
    const auto scaleStep = 0.01f;

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
    glBindTexture(GL_TEXTURE_2D, fboTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width(), height(), 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTexture, 0);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        CGM_EXAMPLES_FUNC_ERROR("Could not create FBO")
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void
Text2DLauncher::setupPlate()
{
    const auto platePoints = std::vector
    {
        cgm::vec2 {-1,-1}, cgm::vec2 {-1, 1},
        cgm::vec2 { 1, 1}, cgm::vec2 { 1,-1}
    };

    plateVao.create();
    plateVbo.create();
    plateShader.create();

    plateShader.addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Plate");
    plateShader.link();

    plateVao.bind();

    plateVbo.bind();
    plateVbo.allocate(platePoints.size() * sizeof(cgm::vec2), platePoints.data());

    plateShader.bind();
    plateShader.setAttributeBuffer("attrPosition", EGLType::Float, 2, 0, sizeof(cgm::vec2));
    plateShader.enableAttributeArray("attrPosition");
    plateShader.setUniform("screenTexture", fboTexture);

    plateVao.release();
}
