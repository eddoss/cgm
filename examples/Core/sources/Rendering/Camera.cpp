

#include <Rendering/Camera.hpp>
#include <CGM/Modules/Projections.hpp>


namespace cgx = cgm::xyz;

Camera::Camera()
    : m_space(cgm::identity<4>())
    , m_spaceInverse(cgm::identity<4>())
    , m_perspective(0.0f)
    , m_position(1.0f)
    , m_target(0)
{
    calculateSpace();
    calculateNdc();
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
Camera::inverseSpace()
{
    return m_spaceInverse;
}

const cgm::mat4&
Camera::space()
{
    return m_space;
}

const cgm::mat4&
Camera::ndc()
{
    return m_perspective;
}

void
Camera::setProperties(const Camera::Properties& properties)
{
    m_properties = properties;
    calculateNdc();
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

    m_spaceInverse = m_space;
    cgm::invertForce(m_spaceInverse);
}

void
Camera::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    cgx::rotate(m_space, cgm::radians(vertical), cgx::ArbitraryAxis(cgx::right(m_space), m_target));
    cgx::rotate(m_space, cgm::radians(horizontal), cgx::up());

    m_spaceInverse = m_space;
    cgm::invertForce(m_spaceInverse);
}

void
Camera::calculateNdc()
{
    m_perspective = cgm::ndc
    (
        cgm::radians(m_properties.fov),
        m_properties.aspect,
        m_properties.near,
        m_properties.far,
        cgm::EGraphicsApi::OpenGL
    );
}

void
Camera::calculateSpace()
{
////#ifdef CGM_CFG_RHS
////    auto f = cgm::normalizedForce(m_position - m_target);
////    auto r = cgm::normalizedForce(cgm::cross(cgm::xyz::up(), f));
////    auto u = cgm::normalizedForce(cgm::cross(f, r));
////#else
////    auto f = cgm::normalizedForce(m_target - m_position);
////    auto r = cgm::normalizedForce(cgm::cross(cgm::xyz::up(), f));
////    auto u = cgm::normalizedForce(cgm::cross(f, r));
////#endif
//    auto f = cgm::normalizedForce(m_position - m_target);
//    auto r = cgm::normalizedForce(cgm::cross(cgm::xyz::up(), f));
//    auto u = cgm::normalizedForce(cgm::cross(f, r));
//
//    cgx::setRight(m_space, r);
//    cgx::setUp(m_space, u);
//    cgx::setForward(m_space, f);
//    cgx::setPosition(m_space, m_position);

    m_space = cgx::lookAt(m_position, m_target, cgx::up());
    m_spaceInverse = m_space;
    cgm::invertForce(m_spaceInverse);
}
