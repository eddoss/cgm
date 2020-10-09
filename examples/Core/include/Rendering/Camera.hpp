#pragma once


#include <CGM/Modules/Core.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


class Camera
{
public:
    using Shared = std::shared_ptr<Camera>;
    using Unique = std::unique_ptr<Camera>;
    using Weak = std::weak_ptr<Camera>;

public:
    struct Properties
    {
        cgm::float32
        aspect = 1.0f;

        cgm::float32
        fov = 45.0f;

        cgm::float32
        near = 0.01f;

        cgm::float32
        far = 500.0f;
    };

public:
    Camera();

public:
    const cgm::vec3&
    position();

    const cgm::vec3&
    target();

    const Properties&
    properties();

    const cgm::mat4&
    space();

    const cgm::mat4&
    inverseSpace();

    const cgm::mat4&
    ndc();

public:
    void
    setProperties(const Properties& properties);

    void
    setPosition(const cgm::vec3& position);

    void
    setTarget(const cgm::vec3& position);

public:
    void
    move(cgm::float32 horizontal, cgm::float32 vertical, cgm::float32 forward);

    void
    rotate(cgm::float32 horizontal, cgm::float32 vertical);

protected:
    void
    calculateNdc();

    void
    calculateSpace();

protected:
    cgm::mat4
    m_space;

    cgm::mat4
    m_spaceInverse;

    cgm::mat4
    m_perspective;

    Properties
    m_properties;

    cgm::vec3
    m_position {cgm::vec3(1)};

    cgm::vec3
    m_target {cgm::vec3(0)};
};