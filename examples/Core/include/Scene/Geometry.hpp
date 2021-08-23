#pragma once


#include <CGM/Modules/Core.hpp>
#include <OpenGL/VertexArrayObject.hpp>
#include <OpenGL/VertexBufferObject.hpp>
#include <OpenGL/ShaderProgram.hpp>
#include <vector>


#define CGM_EXAMPLES_PRIMITIVE_RESTART_VALUE std::numeric_limits<cgm::u32>::max()

class Geometry
{
public:
    struct Point
    {
        cgm::vec4
        color;

        cgm::vec3
        position;

        Point() = default;
        Point(const cgm::vec3& p, const cgm::vec4& c);
    };

public:
    using Shared    = std::shared_ptr<Geometry>;
    using Unique    = std::unique_ptr<Geometry>;
    using Weak      = std::weak_ptr<Geometry>;

public:
    static Geometry::Unique
    makeAxes(ShaderProgram::Shared material);

    static Geometry::Unique
    makeTriangle(ShaderProgram::Shared material);

    static Geometry::Unique
    makeCircle(cgm::f32 radius, cgm::u32 pointsCount, const cgm::vec4& color, ShaderProgram::Shared material);

    static Geometry::Unique
    makePyramid(cgm::f32 radius, cgm::f32 height, const cgm::vec4& color, ShaderProgram::Shared material);

    static Geometry::Unique
    makeCircles(cgm::f32 radius, cgm::u32 count, const cgm::vec4& color, ShaderProgram::Shared material);

    static Geometry::Unique
    makeGrid(cgm::f32 radius, size_t count, const cgm::vec4& color, ShaderProgram::Shared material);

public:
    cgm::mat4
    xform {cgm::identity<4>()};

public:
    Geometry(std::vector<Point> points, std::vector<cgm::u32> indices, ShaderProgram::Shared material);

    void
    init();

    CGM_FORCEINLINE cgm::u32
    pointsCount() const;

    CGM_FORCEINLINE cgm::u32
    indicesCount() const;

    CGM_FORCEINLINE ShaderProgram::Shared
    material() const;

    CGM_FORCEINLINE const VAO&
    vao() const;

private:
    std::vector<Point>
    m_points;

    std::vector<cgm::u32>
    m_indices;

    ShaderProgram::Shared
    m_material;

    cgm::u32
    m_pointsCount {0};

    cgm::u32
    m_indicesCount {0};

    VAO
    m_vao;

    VBO
    m_vbo;

    VBO
    m_ids;
};


CGM_FORCEINLINE cgm::u32
Geometry::pointsCount() const
{
    return m_pointsCount;
};

CGM_FORCEINLINE cgm::u32
Geometry::indicesCount() const
{
    return m_indicesCount;
};

CGM_FORCEINLINE ShaderProgram::Shared
Geometry::material() const
{
    return m_material;
};

CGM_FORCEINLINE const VAO&
Geometry::vao() const
{
    return m_vao;
};