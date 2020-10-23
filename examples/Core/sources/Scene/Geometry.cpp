

#include <Scene/Geometry.hpp>
#include <CGM/Modules/Coordinates.hpp>
#include <utility>


const uint32_t Geometry::Point::size            = sizeof(Geometry::Point);
const uint32_t Geometry::Point::positionOffset  = sizeof(decltype(Geometry::Point::color));
const uint32_t Geometry::Point::colorOffset     = 0;

/* --------------------------------------------------------------------------------------- */

Geometry::Point::Point(const cgm::vec3& p, const cgm::vec4& c)
    : color(c)
    , position(p)
{

}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeAxes(ShaderProgram::Shared material)
{
    cgm::vec3 null(0.0f);

    cgm::vec4 r {1.0f, 0.0f, 0.0f, 1.0f};
    cgm::vec4 g {0.0f, 1.0f, 0.0f, 1.0f};
    cgm::vec4 b {0.0f, 0.0f, 1.0f, 1.0f};

    std::vector<Point> points {};
    std::vector<cgm::uint32> indices {};

    points.resize(6);
    indices.resize(8);

    points[0] = Point{ null, r };
    points[1] = Point{ cgm::xyz::x(), r };
    points[2] = Point{ null, g };
    points[3] = Point{ cgm::xyz::y(), g };
    points[4] = Point{ null, b };
    points[5] = Point{ cgm::xyz::z(), b };

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = primitiveRestartValue;
    indices[3] = 2;
    indices[4] = 3;
    indices[5] = primitiveRestartValue;
    indices[6] = 4;
    indices[7] = 5;

    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeTriangle(ShaderProgram::Shared material)
{
    cgm::vec4 r {1.0f, 0.0f, 0.0f, 1.0f};
    cgm::vec4 g {0.0f, 1.0f, 0.0f, 1.0f};
    cgm::vec4 b {0.0f, 0.0f, 1.0f, 1.0f};

    std::vector<Point> points {};
    std::vector<cgm::uint32> indices {};

    points.resize(3);
    indices.resize(3);

    points[0] = Point{ {   0.0f,  0.5f,  0.0f}, r };
    points[1] = Point{ {   0.5f, -0.5f,  0.0f}, g };
    points[2] = Point{ {  -0.5f, -0.5f,  0.0f}, b };

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;

    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeGrid(cgm::float32 radius, size_t count, const cgm::vec4& color, ShaderProgram::Shared material)
{
    std::vector<Point> points {};
    std::vector<cgm::uint32> indices {};

    points.reserve(count * 8);
    indices.reserve(count * 6 - 2);

    const auto step = radius / count;

    size_t idIndex = 0;

    // make along forward axis
    for (int i = -count; i < int(count); ++i)
    {
        const auto forward = step * float(i);
        points.emplace_back(cgm::coord::cartesian(0.0f, -radius, forward), color);
        points.emplace_back(cgm::coord::cartesian(0.0f, radius, forward), color);
        indices.emplace_back(idIndex);
        indices.emplace_back(++idIndex);
        ++idIndex;
    }

    // make along right axis
    for (int i = -count; i < int(count); ++i)
    {
        const auto right = step * float(i);
        points.emplace_back(cgm::coord::cartesian(0.0f, right, -radius), color);
        points.emplace_back(cgm::coord::cartesian(0.0f, right, radius), color);
        indices.emplace_back(idIndex);
        indices.emplace_back(++idIndex);
        ++idIndex;
    }

    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Geometry(std::vector<Point> points, std::vector<cgm::uint32> indices, ShaderProgram::Shared material)
    : m_points(std::move(points))
    , m_indices(std::move(indices))
    , m_pointsCount(m_points.size())
    , m_indicesCount(m_indices.size())
    , m_material(std::move(material))
    , m_vbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
    , m_ids(VBO::EBufferType::IndexBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
{

}

/* --------------------------------------------------------------------------------------- */

void
Geometry::init()
{
    if (!m_material)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init geometry, material is nullptr")
        exit(-1);
    }

    if (m_points.empty())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, point count is zero");
        exit(-1);
    }

    if (m_indices.empty())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, indices count is zero");
        exit(-1);
    }

    if (!m_vao.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VAO");
        exit(-1);
    }

    if (!m_vbo.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VBO");
        exit(-1);
    }

    if (!m_ids.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create element buffer");
        exit(-1);
    }

    m_vao.bind();

    m_vbo.bind();
    m_vbo.allocate(cgm::uint32(m_points.size()) * Point::size, m_points.data());
    m_ids.bind();
    m_ids.allocate(cgm::uint32(m_indices.size()) * sizeof(cgm::uint32), m_indices.data());
    m_vbo.bind();
    m_material->enableAttributeArray("vertexPosition");
    m_material->setAttributeBuffer("vertexPosition", EGLType::Float, 3, Point::positionOffset, Point::size);
    m_material->enableAttributeArray("vertexColor");
    m_material->setAttributeBuffer("vertexColor", EGLType::Float, 4, Point::colorOffset, Point::size);

    m_vao.release();

    m_points.clear();
    m_indices.clear();
}