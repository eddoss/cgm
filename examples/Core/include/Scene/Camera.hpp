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
    CGM_FORCEINLINE const cgm::vec3&
    position() const;

    CGM_FORCEINLINE cgm::vec3
    right() const;

    CGM_FORCEINLINE cgm::vec3
    up() const;

    CGM_FORCEINLINE cgm::vec3
    forward() const;

    CGM_FORCEINLINE const cgm::vec3&
    target() const;

    CGM_FORCEINLINE const Properties&
    properties() const;

    CGM_FORCEINLINE const cgm::mat4&
    space() const;

    CGM_FORCEINLINE const cgm::mat4&
    inverseSpace() const;

    CGM_FORCEINLINE const cgm::mat4&
    perspective() const;

    CGM_FORCEINLINE const cgm::mat4&
    inversePerspective() const;

    CGM_FORCEINLINE const cgm::vec2&
    Camera::viewport() const;

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
    calculatePerspective();

    void
    calculateSpace();

protected:
    cgm::mat4
    m_space;

    cgm::mat4
    m_spaceInverse;

    cgm::mat4
    m_perspective;

    cgm::mat4
    m_perspectiveInverse;

    Properties
    m_properties;

    cgm::vec3
    m_position {cgm::vec3(1)};

    cgm::vec3
    m_target {cgm::vec3(0)};

    cgm::vec2
    m_viewport {cgm::vec2(0)};
};

std::ostream&
operator << (std::ostream& stream, const Camera& camera);

CGM_FORCEINLINE const cgm::vec3&
Camera::position() const
{
    return m_position;
}

CGM_FORCEINLINE cgm::vec3
Camera::right() const
{
    return cgm::xyz::right(m_space);
}

CGM_FORCEINLINE cgm::vec3
Camera::up() const
{
    return cgm::xyz::up(m_space);
}

CGM_FORCEINLINE cgm::vec3
Camera::forward() const
{
    return cgm::xyz::forward(m_space);
}

CGM_FORCEINLINE const cgm::vec3&
Camera::target() const
{
    return m_target;
}

CGM_FORCEINLINE const Camera::Properties&
Camera::properties() const
{
    return m_properties;
}

CGM_FORCEINLINE const cgm::mat4&
Camera::space() const
{
    return m_space;
}

CGM_FORCEINLINE const cgm::mat4&
Camera::inverseSpace() const
{
    return m_spaceInverse;
}

CGM_FORCEINLINE const cgm::mat4&
Camera::perspective() const
{
    return m_perspective;
}

CGM_FORCEINLINE const cgm::mat4&
Camera::inversePerspective() const
{
    return m_perspectiveInverse;
}

CGM_FORCEINLINE const cgm::vec2&
Camera::viewport() const
{
    return m_viewport;
}