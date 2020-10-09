#pragma once


#include <CGM/Modules/Core.hpp>
#include <vector>
#include "IRenderable.hpp"
#include <OpenGL/VertexArrayObject.hpp>
#include <OpenGL/VertexBufferObject.hpp>
#include <OpenGL/ShaderProgram.hpp>


class Geometry : public IRenderable
{
public:
    struct Point
    {
        cgm::vec4
        color;

        cgm::vec3
        position;

        const static uint32_t
        size;

        const static uint32_t
        positionOffset;

        const static uint32_t
        colorOffset;

        Point() = default;
        Point(const cgm::vec3& p, const cgm::vec4& c);
    };

public:
    const static uint32_t
    primitiveRestartValue = std::numeric_limits<uint32_t>::max();

    static Geometry::Unique
    makeAxes(ShaderProgram::Shared material);

    static Geometry::Unique
    makeTriangle(ShaderProgram::Shared material);

    static Geometry::Unique
    makeGrid(cgm::float32 radius, size_t count, const cgm::vec4& color, ShaderProgram::Shared material);

public:
    cgm::mat4
    xform {cgm::identity<4>()};

    std::vector<Point>
    points;

    std::vector<cgm::uint32>
    indices;

    VAO
    vao;

    VBO
    vbo;

    VBO
    ids;

    ShaderProgram::Shared
    material {nullptr};

public:
    Geometry();

public:
    void
    init() override;

    void
    render(const cgm::mat4& cameraInverse, const cgm::mat4& ndc) override;

    void
    clearHostBuffers();
};
