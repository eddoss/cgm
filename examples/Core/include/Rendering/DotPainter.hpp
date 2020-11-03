#pragma once


#include <Rendering/IPainter.hpp>


class DotPainter : public IPainter
{
public:
    using Shared    = std::shared_ptr<DotPainter>;
    using Unique    = std::unique_ptr<DotPainter>;
    using Weak      = std::weak_ptr<DotPainter>;

public:
    void
    render(const Geometry& geo, const Camera& camera) override;
};