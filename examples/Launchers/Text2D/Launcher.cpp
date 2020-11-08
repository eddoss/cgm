

#include <Launcher.hpp>
#include <CGM/Modules/Coordinates.hpp>

namespace cgx = cgm::xyz;

Text2DLauncher::Text2DLauncher()
    : roughShader(std::make_shared<ShaderProgram>())
    , controlShader(std::make_shared<ShaderProgram>())
{
    roughShader->create();
    roughShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Rough");
    roughShader->link();

    controlShader->create();
    controlShader->addShaderPack(L"C:/Users/edward/Desktop/dev/projects/ComputerGraphixMath/examples/Resources/Shaders/Text/Control");
    controlShader->link();

//    const auto fontFile = std::string("C:/Windows/Fonts/JetBrainsMono-Medium.ttf");
    const auto fontFile = std::string("C:/Windows/Fonts/FreeSerifItalic.ttf");
    const auto textValue = std::string("ez");

    text = std::make_unique<Text>(textValue, fontFile, roughShader, controlShader);
}

void
Text2DLauncher::beforeLoop()
{
    glPointSize(3.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_MULTISAMPLE);

//    glPrimitiveRestartIndex(Text::primitiveRestartValue);
//    glEnable(GL_PRIMITIVE_RESTART);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glBlendEquation(GL_FUNC_SUBTRACT);

    text->init();

    setWidth(720);
    setHeight(720);
}

void
Text2DLauncher::clearEvent()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void
Text2DLauncher::renderEvent()
{
    text->roughShader()->bind();
    text->roughVao().bind();
        glDrawArrays(GL_TRIANGLE_FAN, 0, text->roughPointsCount());
    text->roughVao().release();

//    text->controlShader()->bind();
//    text->controlVao().bind();
//        glDrawArrays(GL_TRIANGLES, 0, text->controlPointsCount());
//    text->controlVao().release();
}

void
Text2DLauncher::resizeEvent()
{
    glViewport(0, 0, GLsizei(width()), GLsizei(height()));
    clearEvent();
    renderEvent();
    glfwSwapBuffers(m_window);
}