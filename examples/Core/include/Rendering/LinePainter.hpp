#pragma once


#include <Rendering/IPainter.hpp>


class LinePainter : public IPainter
{
public:
    using Shared    = std::shared_ptr<LinePainter>;
    using Unique    = std::unique_ptr<LinePainter>;
    using Weak      = std::weak_ptr<LinePainter>;

public:
    void
    render(const Geometry& geo, const Camera& camera) override;
};