#pragma once


#include <Rendering/IPainter.hpp>


class LinePainter : public IPainter
{
public:
    using Shared    = std::shared_ptr<IPainter>;
    using Unique    = std::unique_ptr<IPainter>;
    using Weak      = std::weak_ptr<IPainter>;

public:
    void
    render(const Geometry& geo, const Camera& camera) override;
};