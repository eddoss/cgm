#pragma once


#include <Application/Application.hpp>
#include <TextObject.hpp>


struct CLI
{
    std::string
    fontFile;

    float
    gamma = 1.0f;

    bool
    spaa = true;
};

class Text2DLauncher : public Application
{
public:
    explicit
    Text2DLauncher(const CLI& parameters);
    ~Text2DLauncher() override;

protected:
    void
    beforeLoop() override;

    void
    render() override;

    void
    resizeEvent() override;

    void
    mouseMoveEvent(cgm::Vector<2, int> position) override;

    void
    keyEvent(EKey key, EState state, EModifier modifier) override;

    void
    setupFrameBuffer();

    void
    setupScreenPlate();

private:
    CLI
    m_params;

    FT_Library
    m_ftLibInstance;

    Text::Unique
    m_text = nullptr;

    cgm::vec2
    m_textOffset {-0.5, 0};

    cgm::vec2
    m_textScale {0.03, 0.03};

    uint32_t
    m_fbo = 0;

    uint32_t
    m_fboTexture = 0;

    VAO
    m_screenPlateVao;

    VBO
    m_screenPlateVbo;

    ShaderProgram
    m_postProcessShader;

    ShaderProgram::Shared
    m_roughShader = nullptr;

    ShaderProgram::Shared
    m_controlShader = nullptr;
};