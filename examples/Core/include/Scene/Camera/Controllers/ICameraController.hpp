#pragma once


#include <CGM/Core.hpp>
#include <memory>


class ICameraController
{
public:
    using Shared = std::shared_ptr<ICameraController>;
    using Unique = std::unique_ptr<ICameraController>;
    using Weak = std::weak_ptr<ICameraController>;

public:
    virtual
    ~ICameraController() = default;

public:
    virtual cgm::vec3
    position() const = 0;

    virtual cgm::vec3
    right() const = 0;

    virtual cgm::vec3
    up() const = 0;

    virtual cgm::vec3
    forward() const = 0;

    virtual const cgm::mat4&
    space() const = 0;

    virtual const cgm::mat4&
    inverseSpace() const = 0;

public:
    virtual void
    move(cgm::f32 horizontal, cgm::f32 vertical, cgm::f32 forward) = 0;

    virtual void
    rotate(cgm::f32 horizontal, cgm::f32 vertical) = 0;

    virtual void
    setPosition(const cgm::vec3& position) = 0;
};
