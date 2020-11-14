#pragma once


#include <Application/Application.hpp>
#include <TextObject.hpp>


class Text2DLauncher : public Application
{
public:
    ~Text2DLauncher();
    Text2DLauncher();

protected:
    void
    beforeLoop() override;

    void
    render() override;

    void
    resizeEvent() override;

    void mouseMoveEvent(cgm::Vector<2, int> position) override;

    void
    setupFrameBuffer();

    void
    setupScreenPlate();

private:
    FT_Library
    ftLibInstance;



    Text::Unique
    text = nullptr;

    cgm::vec2
    textOffset {0,0};

    cgm::vec2
    textScale {1,1};



    ShaderProgram::Shared
    roughShader = nullptr;

    ShaderProgram::Shared
    controlShader = nullptr;



    uint32_t
    fbo = 0;

    uint32_t
    fboTexture = 0;

    VAO
    screenPlateVao;

    VBO
    screenPlateVbo;

    ShaderProgram
    antialiasingShader;

    ShaderProgram
    subpixelAntialiasingShader;
};