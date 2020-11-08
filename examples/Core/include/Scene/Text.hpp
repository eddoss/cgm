#pragma once


#include <CGM/Modules/Core.hpp>
#include <OpenGL/VertexArrayObject.hpp>
#include <OpenGL/VertexBufferObject.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <vector>


class Text
{

public:
    struct ControlAttrs
    {
        cgm::vec2 P;
        cgm::vec2 A;
        cgm::vec2 B;
        cgm::vec2 C;

        ControlAttrs() = default;
        ControlAttrs(cgm::vec2 p, cgm::vec2 a, cgm::vec2 b, cgm::vec2 c) : P(p), A(a), B(b), C(c) {}
    };

public:
    using Shared    = std::shared_ptr<Text>;
    using Unique    = std::unique_ptr<Text>;
    using Weak      = std::weak_ptr<Text>;

//public:
//    const static uint16_t
//    primitiveRestartValue = std::numeric_limits<cgm::uint16>::max();

public:
    Text(const std::string& text, std::string fontFile, ShaderProgram::Shared roughShader, ShaderProgram::Shared controlShader);

    void
    init();

    CGM_FORCEINLINE const VAO&
    roughVao() const;

    CGM_FORCEINLINE cgm::uint16
    roughPointsCount() const;

    CGM_FORCEINLINE ShaderProgram::Shared
    roughShader() const;

    CGM_FORCEINLINE const VAO&
    controlVao() const;

    CGM_FORCEINLINE cgm::uint16
    controlPointsCount() const;

    CGM_FORCEINLINE ShaderProgram::Shared
    controlShader() const;

protected:
    void
    setupText(const std::string& text);

private:
    FT_Library
    ftlib;

    FT_Face
    ftface;



    VAO
    m_roughVao;

    VBO
    m_roughVbo;

    std::vector<cgm::vec2>
    m_roughPoints;

    cgm::uint16
    m_roughPointsCount {0};

    ShaderProgram::Shared
    m_roughShader;



    VAO
    m_controlVao;

    VBO
    m_controlVbo;

    std::vector<ControlAttrs>
    m_controlPoints;

    cgm::uint16
    m_controlPointsCount {0};

    ShaderProgram::Shared
    m_controlShader;
};


CGM_FORCEINLINE const VAO&
Text::roughVao() const
{
    return m_roughVao;
}

CGM_FORCEINLINE cgm::uint16
Text::roughPointsCount() const
{
    return m_roughPointsCount;
}

CGM_FORCEINLINE ShaderProgram::Shared
Text::roughShader() const
{
    return m_roughShader;
}

CGM_FORCEINLINE const VAO&
Text::controlVao() const
{
    return m_controlVao;
}

CGM_FORCEINLINE cgm::uint16
Text::controlPointsCount() const
{
    return m_controlPointsCount;
}

CGM_FORCEINLINE ShaderProgram::Shared
Text::controlShader() const
{
    return m_controlShader;
}