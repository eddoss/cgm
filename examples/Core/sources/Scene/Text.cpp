

#include <Scene/Text.hpp>
#include <CGM/Modules/Coordinates.hpp>
#include <freetype/ftoutln.h>


class Visitor
{

public:
    std::vector<cgm::vec2>&
    points;

    std::vector<Text::ControlAttrs>&
    controls;

    FT_BBox
    bound {};

public:
    Visitor(std::vector<cgm::vec2>& pts, std::vector<Text::ControlAttrs>& ctls) : points(pts), controls(ctls) {}

public:
    cgm::vec2
    remapped(const FT_Vector& vec) const
    {
        return
        {
            cgm::fit<cgm::vec2::value_type>(vec.x, bound.xMin, bound.xMax, -1.0f, 1.0f),
            cgm::fit<cgm::vec2::value_type>(vec.y, bound.yMin, bound.yMax, -1.0f, 1.0f)
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
    FT_Set_Char_Size(ftface, 1024, 1024, 0, 0);
    
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

        const auto ctrl = visitor.remapped(*control);
        const auto next = visitor.remapped(*to);
        const auto prev = visitor.points.back();

        visitor.points.emplace_back(next);
        visitor.controls.emplace_back(Text::ControlAttrs{prev, prev, ctrl, next});
        visitor.controls.emplace_back(Text::ControlAttrs{ctrl, prev, ctrl, next});
        visitor.controls.emplace_back(Text::ControlAttrs{next, prev, ctrl, next});

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

    m_roughVao.bind();

    m_roughVbo.bind();
    m_roughVbo.allocate(m_roughPointsCount * sizeof(cgm::vec2), m_roughPoints.data());

    m_roughShader->enableAttributeArray("attrPosition");
    m_roughShader->setAttributeBuffer("attrPosition", EGLType::Float, 2, 0, sizeof(cgm::vec2));

    m_roughVao.release();
    m_roughPoints.clear();


    if (m_controlPointsCount == 0)
    {
        CGM_EXAMPLES_FUNC_INFO("'Control' points is empty");
    }
    else
    {
        if (!m_controlShader)
        {
            CGM_EXAMPLES_FUNC_ERROR("Text object init fails. 'Controls' shader is nullptr")
        }

        if (!m_controlVao.create())
        {
            CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Controls' VAO");
        }

        if (!m_controlVbo.create())
        {
            CGM_EXAMPLES_FUNC_ERROR("Text object init fails. Cant create 'Controls' VBO");
        }

        m_controlVao.bind();

        m_controlVbo.bind();
        m_controlVbo.allocate(m_controlPointsCount * sizeof(ControlAttrs), m_controlPoints.data());

        m_controlShader->enableAttributeArray("attrP");
        m_controlShader->setAttributeBuffer("attrP", EGLType::Float, 2, 0, sizeof(ControlAttrs));

        m_controlShader->enableAttributeArray("attrA");
        m_controlShader->setAttributeBuffer("attrA", EGLType::Float, 2, sizeof(cgm::vec2), sizeof(ControlAttrs));

        m_controlShader->enableAttributeArray("attrB");
        m_controlShader->setAttributeBuffer("attrB", EGLType::Float, 2, sizeof(cgm::vec2) * 2, sizeof(ControlAttrs));

        m_controlShader->enableAttributeArray("attrC");
        m_controlShader->setAttributeBuffer("attrC", EGLType::Float, 2, sizeof(cgm::vec2) * 3, sizeof(ControlAttrs));

        m_controlVao.release();
        m_controlPoints.clear();
    }
}