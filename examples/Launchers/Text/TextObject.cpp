

#include <TextObject.hpp>
#include <CGM/Modules/Coordinates.hpp>
#include <freetype/ftoutln.h>
#include <harfbuzz/hb.h>
#include <harfbuzz/hb-ft.h>
#include <fstream>

struct Visitor
{
    Text&
    ref;

    Visitor(Text& text) : ref(text) {}
};

Text::~Text() noexcept
{
//    FT_Done_Face(m_ftFace);
}

Text::Text(FT_Library& libInstance, ShaderProgram::Shared roughShader, ShaderProgram::Shared controlShader)
    : m_ftLibrary(libInstance)
    , m_roughShader(std::move(roughShader))
    , m_controlShader(std::move(controlShader))
    , m_roughVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
    , m_controlVbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{

}

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

void
Text::setText(const std::string& text)
{
    hb_buffer_t *buf;
    buf = hb_buffer_create();
    hb_buffer_add_utf8(buf, text.c_str(), -1, 0, -1);

    hb_buffer_set_direction(buf, HB_DIRECTION_LTR);
    hb_buffer_set_script(buf, HB_SCRIPT_LATIN);
    hb_buffer_set_language(buf, hb_language_from_string("en", -1));

    hb_font_t *font = hb_ft_font_create(m_ftFace, nullptr);
    hb_shape(font, buf, nullptr, 0);

    uint32_t glyph_count = 0;
    hb_glyph_info_t *glyphs_info    = hb_buffer_get_glyph_infos(buf, &glyph_count);
    hb_glyph_position_t *glyphs_pos = hb_buffer_get_glyph_positions(buf, &glyph_count);

    offset.x = 0;
    offset.y = 0;

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (i > 0)
        {
            hb_position_t kerning_correction_x = 0;
            hb_position_t kerning_correction_y = 0;

            if (i < text.size() - 1)
            {
                hb_font_get_glyph_kerning_for_direction
                (
                    font,
                    glyphs_info[i-1].codepoint,
                    glyphs_info[i].codepoint,
                    hb_direction_t::HB_DIRECTION_LTR,
                    &kerning_correction_x,
                    &kerning_correction_y
                );
            }

            const auto glyphPos = glyphs_pos[i-1];
            offset.x += glyphPos.x_advance + kerning_correction_x;
            offset.y += glyphPos.y_advance + kerning_correction_y;
        }
        setupCharacter(text[i]);
    }

    offset.x = 0;
    offset.y = 0;

    hb_buffer_destroy(buf);
    hb_font_destroy(font);
}

void
Text::setFont(const std::string& fontFile)
{
    FT_New_Face(m_ftLibrary, fontFile.data(), 0, &m_ftFace);
    FT_Load_Glyph(m_ftFace, 0, FT_LOAD_NO_SCALE);
    FT_Set_Char_Size(m_ftFace, m_ftFace->units_per_EM, m_ftFace->units_per_EM, 0, 0);
}

void
Text::setupCharacter(FT_ULong character)
{
    FT_Load_Char(m_ftFace, character, FT_LOAD_NO_SCALE);

    FT_Outline_Funcs funcs;
    funcs.delta = 0;
    funcs.shift = 0;

    funcs.move_to = [](const FT_Vector* to, void* user) -> int
    {
        auto& self = reinterpret_cast<Visitor*>(user)->ref;
        self.m_roughPoints.emplace_back(cgm::vec2(0.0f));
        self.m_roughPoints.emplace_back(self.calculatePosition(*to));
        return 0;
    };

    funcs.line_to = [](const FT_Vector* to, void* user) -> int
    {
        auto& self = reinterpret_cast<Visitor*>(user)->ref;
        self.m_roughPoints.emplace_back(self.calculatePosition(*to));
        return 0;
    };

    funcs.conic_to = [](const FT_Vector* control, const FT_Vector* to, void* user) -> int
    {
        auto& self = reinterpret_cast<Visitor*>(user)->ref;
        const auto ctrl = self.calculatePosition(*control);
        const auto next = self.calculatePosition(*to);
        const auto prev = self.m_roughPoints.back();

        self.m_roughPoints.emplace_back(next);
        self.m_controlPoints.emplace_back(Text::ControlAttrs{prev, prev, ctrl, next});
        self.m_controlPoints.emplace_back(Text::ControlAttrs{ctrl, prev, ctrl, next});
        self.m_controlPoints.emplace_back(Text::ControlAttrs{next, prev, ctrl, next});

        return 0;
    };

    funcs.cubic_to = [](const FT_Vector* control1, const FT_Vector* control2, const FT_Vector* to, void* user) -> int
    {
        CGM_EXAMPLES_FUNC_ERROR("Cubic interpolation in fonts does not support !!!");
    };

    Visitor visitor(*this);
    FT_Outline_Decompose(&m_ftFace->glyph->outline, &funcs, &visitor);

    const auto w = m_ftFace->glyph->metrics.width;
    const auto em = m_ftFace->bbox;

    currentOffset.x += cgm::fit<cgm::float32>(w, em.xMin, em.xMax, 0.0f, 1.0f);

    m_controlPointsCount = m_controlPoints.size();
    m_roughPointsCount = m_roughPoints.size();
}

cgm::vec2
Text::calculatePosition(const FT_Vector& vec)
{
    return
    {
        cgm::float32(vec.x) + offset.x,
        cgm::float32(vec.y) + offset.y
    };
}