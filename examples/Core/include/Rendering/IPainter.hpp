#pragma once


#include <Scene/Camera.hpp>
#include <Scene/Geometry.hpp>


class IPainter
{
public:
    virtual
    ~IPainter() = default;

public:
    using Shared    = std::shared_ptr<IPainter>;
    using Unique    = std::unique_ptr<IPainter>;
    using Weak      = std::weak_ptr<IPainter>;

public:
    virtual void
    render(const Geometry& geo, const Camera& camera) = 0;
};