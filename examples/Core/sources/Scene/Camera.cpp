

#include <Scene/Camera.hpp>
#include <CGM/Modules/Projections.hpp>


namespace cgx = cgm::xyz;

Camera::Camera()
    : m_position(1.0f)
    , m_target(0)
{
    calculateSpace();
    calculatePerspective();
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

    m_spaceInverse = m_space;
    cgm::invert(m_spaceInverse);
}

void
Camera::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    cgx::rotate(m_space, cgm::radians(vertical), cgx::ArbitraryAxis(cgx::right(m_space), m_target));
    cgx::rotate(m_space, cgm::radians(horizontal), cgx::up());

    m_spaceInverse = m_space;
    cgm::invert(m_spaceInverse);
}

void
Camera::calculatePerspective()
{
    const auto fov = cgm::radians(m_properties.fov);

    m_viewport = cgm::perspectiveViewport(fov, m_properties.aspect, 1.0f);
    m_perspective = cgm::perspective<cgm::EGraphicsApi::OpenGL>
    (
        cgm::radians(m_properties.fov),
        m_properties.aspect,
        m_properties.near,
        m_properties.far
    );
    cgm::invert(m_perspectiveInverse);
}

void
Camera::calculateSpace()
{
    m_space = cgx::lookAt(m_position, m_target, cgx::up());
    m_spaceInverse = m_space;
    cgm::invert(m_spaceInverse);
}

std::ostream&
operator << (std::ostream& stream, const Camera& camera)
{
    stream << "   FOV: " << camera.properties().fov << std::endl;
    stream << "Aspect: " << camera.properties().aspect << std::endl;
    stream << "  Near: " << camera.properties().near << std::endl;

    return stream;
}