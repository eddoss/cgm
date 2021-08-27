

#include <Scene/Camera/Models/Perspective.hpp>
#include <CGM/Projections.hpp>


PerspectiveCameraModel::PerspectiveCameraModel()
{
    calculateProjection();
}

PerspectiveCameraModel::PerspectiveCameraModel(const Properties& properties)
    : m_properties(properties)
{
    calculateProjection();
}

PerspectiveCameraModel::PerspectiveCameraModel(cgm::f32 aspect, cgm::f32 fov, cgm::f32 near, cgm::f32 far)
{
    m_properties.aspect = aspect;
    m_properties.fov = fov;
    m_properties.near = near;
    m_properties.far = far;

    calculateProjection();
}

void
PerspectiveCameraModel::setProperties(const Properties& properties)
{
    m_properties = properties;
    calculateProjection();
};

const cgm::mat4&
PerspectiveCameraModel::projection() const
{
    return m_projection;
}

const cgm::mat4&
PerspectiveCameraModel::inverseProjection() const
{
    return m_inverseProjection;
}

const cgm::vec2&
PerspectiveCameraModel::viewport() const
{
    return m_viewport;
}

void
PerspectiveCameraModel::calculateProjection()
{
    const auto fov = cgm::radians(m_properties.fov);

    m_viewport = cgm::perspectiveViewport(fov, m_properties.aspect, 1.0f);
    m_projection = cgm::perspective<cgm::EGraphicsApi::OpenGL>
    (
        fov,
        m_properties.aspect,
        m_properties.near,
        m_properties.far
    );
    m_inverseProjection = m_projection;
    cgm::invert(m_inverseProjection);
}