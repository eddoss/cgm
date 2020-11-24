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
    drawRoughShape();

    void
    drawSmoothPieces();

    void
    drawAntialiasing();

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

    void
    setupOffsets();

private:
    CLI
    m_params;

    FT_Library
    m_ftLibInstance;

    Text::Unique
    m_text = nullptr;

    cgm::vec2
    m_textOffset {-0.99, 0.95};

    cgm::vec2
    m_textScale {0.04, 0.04};

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

    std::vector<std::pair<cgm::vec2, cgm::vec3>>
    samplesProperties;
};