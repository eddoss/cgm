#pragma once

#include <CGM/Core>
#include <GL/glew.h>


enum EDrawMode
{
    Points      = GL_POINTS,
    Lines       = GL_LINES,
    LineStrip   = GL_LINE_STRIP,
    LineLoop    = GL_LINE_LOOP,
    Triangles   = GL_TRIANGLES,
    Polygon     = GL_TRIANGLE_FAN
};

class IRenderable
{
public:
    virtual
    ~IRenderable() = default;

public:
    using Shared    = std::shared_ptr<IRenderable>;
    using Unique    = std::unique_ptr<IRenderable>;
    using Weak      = std::weak_ptr<IRenderable>;

public:
    virtual void
    init() = 0;

    virtual void
    render(const cgm::mat4& camera, const cgm::mat4& perspective) = 0;
};