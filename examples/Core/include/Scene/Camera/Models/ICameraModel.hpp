#pragma once


#include <CGM/Core.hpp>
#include <memory>

class ICameraModel
{
public:
    using Shared = std::shared_ptr<ICameraModel>;
    using Unique = std::unique_ptr<ICameraModel>;
    using Weak = std::weak_ptr<ICameraModel>;

public:
    virtual ~ICameraModel() = default;

public:
    virtual const cgm::mat4&
    projection() const = 0;

    virtual const cgm::mat4&
    inverseProjection() const = 0;

    virtual const cgm::vec2&
    viewport() const = 0;
};