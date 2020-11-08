#pragma once


#include <Application/Application.hpp>
#include <Scene/Text.hpp>


class Text2DLauncher : public BaseWindow
{
public:
    Text2DLauncher();

protected:
    void
    beforeLoop() override;

    void
    renderEvent() override;

    void
    clearEvent() override;

    void
    resizeEvent() override;

private:
    Text::Unique
    text = nullptr;

    ShaderProgram::Shared
    roughShader = nullptr;

    ShaderProgram::Shared
    controlShader = nullptr;
};