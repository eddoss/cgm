
#include <Scene/Camera/Models/Orthographic.hpp>
#include <CGM/Modules/Projections.hpp>

OrthographicCameraModel::OrthographicCameraModel()
{
    calculateProjection();
}

OrthographicCameraModel::OrthographicCameraModel(const Properties& properties)
    : m_properties(properties)
{
    calculateProjection();
}

OrthographicCameraModel::OrthographicCameraModel(cgm::float32 aspect, cgm::float32 zoom, cgm::float32 near, cgm::float32 far)
{
    m_properties.aspect = aspect;
    m_properties.near = near;
    m_properties.far = far;
    m_properties.zoom = zoom;

    calculateProjection();
}

void
OrthographicCameraModel::setProperties(const Properties& properties)
{
    m_properties = properties;

    calculateProjection();
};

const cgm::mat4&
OrthographicCameraModel::projection() const
{
    return m_projection;
}

const cgm::mat4&
OrthographicCameraModel::inverseProjection() const
{
    return m_inverseProjection;
}

const cgm::vec2&
OrthographicCameraModel::viewport() const
{
    return m_viewport;
}

void
OrthographicCameraModel::calculateProjection()
{
    m_projection = cgm::orthographic<cgm::EGraphicsApi::OpenGL>
    (
        m_properties.aspect,
        m_properties.zoom,
        m_properties.near,
        m_properties.far
    );
    m_inverseProjection = m_projection;
    cgm::invert(m_inverseProjection);
}