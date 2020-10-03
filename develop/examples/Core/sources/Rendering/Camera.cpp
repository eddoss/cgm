
#include <Rendering/Camera.hpp>

namespace cgx = cgm::xyz;

Camera::Camera()
    : m_space(cgm::identity<4>())
    , m_perspective(0.0f)
    , m_position(1.0f)
    , m_target(0)
{
    calculateSpace();
    calculatePerspective();
}

const cgm::vec3&
Camera::position()
{
    return m_position;
}

const cgm::vec3&
Camera::target()
{
    return m_target;
}

const Camera::Properties&
Camera::properties()
{
    return m_properties;
}

const cgm::mat4&
Camera::space()
{
    return m_space;
}

const cgm::mat4&
Camera::perspective()
{
    return m_perspective;
}

void
Camera::setProperties(const Camera::Properties& properties)
{
    m_properties = properties;
    calculatePerspective();
}

void
Camera::setPosition(const cgm::vec3& position)
{
    m_position = position;
    calculateSpace();
}

void
Camera::setTarget(const cgm::vec3& position)
{
    m_target = position;
    calculateSpace();
}

void
Camera::move(cgm::float32 horizontal, cgm::float32 vertical, cgm::float32 forward)
{
    cgx::translate(m_space, cgx::right(m_space) * horizontal);
    cgx::translate(m_space, cgx::up(m_space) * vertical);
    cgx::translate(m_space, cgx::forward(m_space) * forward);
}

void
Camera::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    cgx::rotate(m_space, cgm::radians(vertical), cgx::ArbitraryAxis(cgx::right(m_space), m_target));
    cgx::rotate(m_space, cgm::radians(horizontal), cgx::up());
}

void
Camera::calculatePerspective()
{
    cgm::float32 angle = cgm::radians(m_properties.fov);
    cgm::float32 n = m_properties.near;
    cgm::float32 f = m_properties.far;
    cgm::float32 t = std::tan(angle * 0.5f) * n;
    cgm::float32 b = -t;
    cgm::float32 r = t * m_properties.aspect;
    cgm::float32 l = -r;

    m_perspective(0,0) = 2.0f * n / (r - l);
    m_perspective(1,1) = 2.0f * n / (t - b);
    m_perspective(2,2) = -(f + n) / (f - n);
    m_perspective(3,2) = -1.0f;
    m_perspective(2,3) = -2.0f * f * n / (f - n);
}

void
Camera::calculateSpace()
{
    auto z = cgm::normalizedForce(m_position - m_target);
    auto x = cgm::normalizedForce(cgm::cross(cgm::xyz::up(), z));
    auto y = cgm::normalizedForce(cgm::cross(z, x));

    cgx::set(m_space, x, y, z, m_position);
}
