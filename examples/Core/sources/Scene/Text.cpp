

#include <Scene/Text.hpp>
#include <CGM/Modules/Coordinates.hpp>
#include <freetype/ftoutln.h>


class Visitor
{

public:
    std::vector<cgm::vec2>&
    points;

    std::vector<cgm::vec2>&
    controls;

    FT_BBox
    bound {};

public:
    Visitor(std::vector<cgm::vec2>& pts, std::vector<cgm::vec2>& ctls) : points(pts), controls(ctls) {}

public:
    cgm::vec2
    remapped(const FT_Vector& vec) const
    {
        return
        {
            cgm::fit<cgm::vec2::value_type>(vec.x, bound.xMin, bound.xMax, -0.5f, 0.5f),
            cgm::fit<cgm::vec2::value_type>(vec.y, bound.yMin, bound.yMax, -0.5f, 0.5f)
        };
    }
};

Text::Text(const std::string& text, std::string fontFile, ShaderProgram::Shared roughShader, ShaderProgram::Shared controlShader)
    : m_roughShader(std::move(roughShader))
    , m_controlShader(std::move(controlShader))
    , m_roughVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
    , m_controlVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{
    FT_Init_FreeType(&ftlib);

    FT_New_Face(ftlib, fontFile.data(), 0, &ftface);
    FT_Load_Glyph(ftface, 0, FT_LOAD_DEFAULT);
    FT_Set_Char_Size(ftface, 8, 8, 0, 0);
    
    setupText(text);
}

/* --------------------------------------------------------------------------------------- */

void 
Text::setupText(const std::string& text)
{
    FT_Load_Char(ftface, text[0], FT_LOAD_DEFAULT);

    auto& glyph = ftface->glyph;
    auto& outline = glyph->outline;

    Visitor visitor(m_roughPoints, m_controlPoints);
    FT_Outline_Get_CBox(&outline, &visitor.bound);

    FT_Outline_Funcs funcs;
    funcs.delta = 0;
    funcs.shift = 0;

    funcs.move_to = [](const FT_Vector* to, void* user) -> int
    {
        auto& visitor = *reinterpret_cast<Visitor*>(user);
        visitor.points.emplace_back(cgm::vec2(0.0f));
        visitor.points.emplace_back(visitor.remapped(*to));
        return 0;
    };

    funcs.line_to = [](const FT_Vector* to, void* user) -> int
    {
        auto& visitor = *reinterpret_cast<Visitor*>(user);
        visitor.points.emplace_back(visitor.remapped(*to));
        return 0;
    };

    funcs.conic_to = [](const FT_Vector* control, const FT_Vector* to, void* user) -> int
    {
        auto& visitor = *reinterpret_cast<Visitor*>(user);

        const auto next = visitor.remapped(*to);
        const auto prev = visitor.points[visitor.points.size()-1];

        visitor.points.emplace_back(visitor.remapped(*to));
        visitor.controls.emplace_back(prev);
        visitor.controls.emplace_back(visitor.remapped(*control));
        visitor.controls.emplace_back(next);
        return 0;
    };

    funcs.cubic_to = [](const FT_Vector* control1, const FT_Vector* control2, const FT_Vector* to, void* user) -> int
    {
        CGM_EXAMPLES_FUNC_ERROR("Cubic interpolation in fonts does not support !!!");
    };

    FT_Outline_Decompose(&outline, &funcs, &visitor);

    m_controlPointsCount = m_controlPoints.size();
    m_roughPointsCount = m_roughPoints.size();
}

/* --------------------------------------------------------------------------------------- */

void
Text::init()
{
    if (!m_roughShader)
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. 'Rough' shader is nullptr")
    }

    if (m_roughPointsCount == 0)
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. 'Rough' points is empty");
    }

    if (!m_roughVao.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Rough' VAO");
    }

    if (!m_roughVbo.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Rough' VBO");
    }



    if (!m_controlShader)
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. 'Controls' shader is nullptr")
    }

    if (m_controlPointsCount == 0)
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. 'Control' points is empty");
    }

    if (!m_controlVao.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Controls' VAO");
    }

    if (!m_controlVbo.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Controls' VBO");
    }



    m_roughVao.bind();

    m_roughVbo.bind();
    m_roughVbo.allocate(m_roughPointsCount * sizeof(cgm::vec2), m_roughPoints.data());

    m_roughShader->enableAttributeArray("position");
    m_roughShader->setAttributeBuffer("position", EGLType::Float, 2, 0, sizeof(cgm::vec2));

    m_roughVao.release();
    m_roughPoints.clear();



    m_controlVao.bind();

    m_controlVbo.bind();
    m_controlVbo.allocate(m_controlPointsCount * sizeof(cgm::vec2), m_controlPoints.data());

    m_controlShader->enableAttributeArray("position");
    m_controlShader->setAttributeBuffer("position", EGLType::Float, 2, 0, sizeof(cgm::vec2));

    m_controlVao.release();
    m_controlPoints.clear();
}