

#include <Scene/Geometry.hpp>
#include <CGM/Coordinates.hpp>
#include <CGM/Transformations/3D.hpp>
#include <utility>


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
    std::vector<cgm::u32> indices {};

    points.resize(6);
    indices.resize(8);

    points[0] = Point{ null, r };
    points[1] = Point{ cgm::x(), r };
    points[2] = Point{ null, g };
    points[3] = Point{ cgm::y(), g };
    points[4] = Point{ null, b };
    points[5] = Point{ cgm::z(), b };

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE;
    indices[3] = 2;
    indices[4] = 3;
    indices[5] = CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE;
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
    std::vector<cgm::u32> indices {};

    points.resize(3);
    indices.resize(3);

    points[0] = Point{ cgm::coord::cartesian(0.0f, 0.0f, 1.0f), r };
    points[1] = Point{ cgm::coord::cartesian(1.0f, 0.0f, 0.0f), g };
    points[2] = Point{ cgm::coord::cartesian(0.0f, 1.0f, 0.0f), b };

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;

    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeCircle(cgm::f32 radius, cgm::u32 pointsCount, const cgm::vec4& color, ShaderProgram::Shared material)
{
    const auto axis = cgm::forward();
    const auto angleStep = CGM_PI2 / pointsCount;

    std::vector<Point> points {};
    points.reserve(pointsCount);

    for (size_t i = 0; i < pointsCount; ++i)
    {
        const auto angle = angleStep * i;
        const auto radiusVector = cgm::rotated(cgm::right() * radius, angle, axis);

        points.emplace_back(radiusVector, color);
    }

    return std::make_unique<Geometry>(std::move(points), std::vector<cgm::u32>{}, std::move(material));
}

Geometry::Unique
Geometry::makePyramid(cgm::f32 radius, cgm::f32 height, const cgm::vec4& color, ShaderProgram::Shared material)
{
    // Top view. P4 - top of pyramid
    //
    // 0---------------> right
    // |  p1       p2
    // |  |--------|
    // |  |   p4   |
    // |  |--------|
    // |  p0       p3
    // |
    // V
    // forward

    const auto p0 = cgm::coord::cartesian(0.0f, 0.0f, 1.0f) * radius * 2;
    const auto p1 = cgm::coord::cartesian(0.0f, 0.0f, 0.0f);
    const auto p2 = cgm::coord::cartesian(0.0f, 1.0f, 0.0f) * radius * 2;
    const auto p3 = cgm::coord::cartesian(0.0f, 0.0f, 1.0f) * radius * 2;
    const auto p4 = cgm::coord::cartesian(height, radius, radius);

    std::vector<Point> points
    {
        Point{ p0, color },
        Point{ p1, color },
        Point{ p2, color },
        Point{ p3, color },
        Point{ p4, color }
    };

    std::vector<cgm::u32> indices
    {
//        0, 1, 2, 3, primitiveRestartValue,
        1, 4, 0, CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE,
        2, 4, 1, CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE,
        3, 4, 2, CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE,
        0, 4, 3
    };

    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeCircles(cgm::f32 radius, cgm::u32 count, const cgm::vec4& color, ShaderProgram::Shared material)
{
    std::vector<Point> points {};
    std::vector<cgm::u32> indices {};

    const auto make_circle = [&points, &indices](const cgm::vec3& center, cgm::f32 radius, cgm::u32 pointsCount, const cgm::vec4& color)
    {
        const auto axis = cgm::forward();
        const auto angleStep = CGM_PI2 / pointsCount;

        for (size_t i = 0; i < pointsCount; ++i)
        {
            const auto angle = angleStep * i;
            const auto radiusVector = cgm::rotated(cgm::right() * radius, angle, axis) + center;

            indices.emplace_back(points.size());
            points.emplace_back(radiusVector, color);
        }
    };

    const auto angleStep = CGM_PI2 / count;

    for (size_t i = 0; i < count; ++i)
    {
        const auto coeff = cgm::f32(i) / count;
        const auto angle = angleStep * i;
        const auto center = cgm::rotated(cgm::right() * radius, angle, cgm::forward()) - cgm::forward() * coeff;
        make_circle(center, radius, 128, color);
        indices.emplace_back(CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE);
    }
    points.shrink_to_fit();
    indices.shrink_to_fit();
    return std::make_unique<Geometry>(std::move(points), std::move(indices), std::move(material));
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeGrid(cgm::f32 radius, size_t count, const cgm::vec4& color, ShaderProgram::Shared material)
{
    std::vector<Point> points {};
    std::vector<cgm::u32> indices {};

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

Geometry::Geometry(std::vector<Point> points, std::vector<cgm::u32> indices, ShaderProgram::Shared material)
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
    }

    if (m_points.empty())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, point count is zero");
    }

    if (!m_vao.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VAO");
    }

    if (!m_vbo.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VBO");
    }

    if (!m_ids.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create element buffer");
    }

    m_vao.bind();

    m_vbo.bind();
    m_vbo.allocate(m_pointsCount * sizeof(Point), m_points.data());

    m_ids.bind();
    m_ids.allocate(m_indicesCount * sizeof(cgm::u32), m_indices.data());

    m_vbo.bind();
    m_material->enableAttributeArray("attrPosition");
    m_material->setAttributeBuffer("attrPosition", EGLType::Float, 3, sizeof(decltype(Point::color)), sizeof(Point));
    m_material->enableAttributeArray("attrColor");
    m_material->setAttributeBuffer("attrColor", EGLType::Float, 4, 0, sizeof(Point));

    m_vao.release();

    m_points.clear();
    m_indices.clear();
}