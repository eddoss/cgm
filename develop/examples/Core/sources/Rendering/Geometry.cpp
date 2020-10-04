

#include <Rendering/Geometry.hpp>
#include <CGM/Coordinates>


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

Geometry::Geometry()
    : vbo(VBO::EBufferType::ArrayBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
    , ids(VBO::EBufferType::IndexBuffer, VBO::EUsagePattern::StaticDraw, VBO::EAccessPattern::ReadWrite)
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

    auto geo = std::make_unique<Geometry>();
    geo->material = std::move(material);
    geo->points.resize(6);
    geo->indices.resize(8);

    geo->points[0] = Point{ null, r };
    geo->points[1] = Point{ cgm::xyz::x(), r };
    geo->points[2] = Point{ null, g };
    geo->points[3] = Point{ cgm::xyz::y(), g };
    geo->points[4] = Point{ null, b };
    geo->points[5] = Point{ cgm::xyz::z(), b };

    geo->indices[0] = 0;
    geo->indices[1] = 1;
    geo->indices[2] = primitiveRestartValue;
    geo->indices[3] = 2;
    geo->indices[4] = 3;
    geo->indices[5] = primitiveRestartValue;
    geo->indices[6] = 4;
    geo->indices[7] = 5;

    return geo;
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeTriangle(ShaderProgram::Shared material)
{
    cgm::vec4 r {1.0f, 0.0f, 0.0f, 1.0f};
    cgm::vec4 g {0.0f, 1.0f, 0.0f, 1.0f};
    cgm::vec4 b {0.0f, 0.0f, 1.0f, 1.0f};

    auto geo = std::make_unique<Geometry>();
    geo->material = std::move(material);
    geo->points.resize(3);
    geo->indices.resize(3);

    geo->points[0] = Point{ {   0.0f,  0.5f,  0.0f}, r };
    geo->points[1] = Point{ {   0.5f, -0.5f,  0.0f}, g };
    geo->points[2] = Point{ {  -0.5f, -0.5f,  0.0f}, b };

    geo->indices[0] = 0;
    geo->indices[1] = 1;
    geo->indices[2] = 2;

    return geo;
}

/* --------------------------------------------------------------------------------------- */

Geometry::Unique
Geometry::makeGrid(cgm::float32 radius, size_t count, const cgm::vec4& color, ShaderProgram::Shared material)
{
    auto geo = std::make_unique<Geometry>();
    geo->material = material;
    geo->points.reserve(count * 8);
    geo->indices.reserve(count * 6 - 2);

    const auto step = radius / count;

    size_t idIndex = 0;

    // make along forward axis
    for (int i = -count; i < int(count); ++i)
    {
        const auto forward = step * i;
        geo->points.emplace_back(cgm::coord::cartesian(0.0f, -radius, forward), color);
        geo->points.emplace_back(cgm::coord::cartesian(0.0f, radius, forward), color);
        geo->indices.emplace_back(idIndex);
        geo->indices.emplace_back(++idIndex);
        ++idIndex;
    }

    // make along right axis
    for (int i = -count; i < int(count); ++i)
    {
        const auto right = step * i;
        geo->points.emplace_back(cgm::coord::cartesian(0.0f, right, -radius), color);
        geo->points.emplace_back(cgm::coord::cartesian(0.0f, right, radius), color);
        geo->indices.emplace_back(idIndex);
        geo->indices.emplace_back(++idIndex);
        ++idIndex;
    }

    return geo;
}

/* --------------------------------------------------------------------------------------- */

void
Geometry::init()
{
    if (!material)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init geometry, material is nullptr")
        exit(-1);
    }

    if (points.empty())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, point count is zero");
        exit(-1);
    }

    if (indices.empty())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, indices count is zero");
        exit(-1);
    }

    if (!vao.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VAO");
        exit(-1);
    }

    if (!vbo.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create VBO");
        exit(-1);
    }

    if (!ids.create())
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant init Geometry, cant create element buffer");
        exit(-1);
    }

    vao.bind();

    vbo.bind();
    vbo.allocate(cgm::uint32(points.size()) * Point::size, points.data());
    ids.bind();
    ids.allocate(cgm::uint32(indices.size()) * sizeof(cgm::uint32), indices.data());
    vbo.bind();
    material->enableAttributeArray("vertexPosition");
    material->setAttributeBuffer("vertexPosition", EGLType::Float, 3, Point::positionOffset, Point::size);
    material->enableAttributeArray("vertexColor");
    material->setAttributeBuffer("vertexColor", EGLType::Float, 4, Point::colorOffset, Point::size);

    vao.release();

//    clearHostBuffers();
}

/* --------------------------------------------------------------------------------------- */

void
Geometry::render(const cgm::mat4& camera, const cgm::mat4& perspective)
{
    if (!material)
    {
        CGM_EXAMPLES_FUNC_ERROR("Cant draw geometry, material is nullptr")
    }

    material->bind();
    material->setUniform("xform", xform);
    material->setUniform("cameraSpace", camera);
    material->setUniform("cameraProjection", perspective);

    vao.bind();
//    glDrawElements(GL_TRIANGLE_FAN, GLsizei(indices.size()), GL_UNSIGNED_INT, nullptr);
    glDrawElements(GL_LINES, GLsizei(indices.size()), GL_UNSIGNED_INT, nullptr);
    vao.release();
}

/* --------------------------------------------------------------------------------------- */

void
Geometry::clearHostBuffers()
{
    points.clear();
    indices.clear();
}
