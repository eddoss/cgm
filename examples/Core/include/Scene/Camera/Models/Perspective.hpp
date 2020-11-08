#pragma once


#include <Scene/Camera/Models/ICameraModel.hpp>


class PerspectiveCameraModel : public ICameraModel
{
public:
    using Shared = std::shared_ptr<PerspectiveCameraModel>;
    using Unique = std::unique_ptr<PerspectiveCameraModel>;
    using Weak = std::weak_ptr<PerspectiveCameraModel>;

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
        far = 1000.0f;
    };

public:
    PerspectiveCameraModel();
    PerspectiveCameraModel(const Properties& properties);
    PerspectiveCameraModel(cgm::float32 aspect, cgm::float32 fov, cgm::float32 near, cgm::float32 far);

public:
    CGM_FORCEINLINE const Properties&
    properties() const {return m_properties;};

    void
    setProperties(const Properties& properties);

public:
    virtual const cgm::mat4&
    projection() const override;

    virtual const cgm::mat4&
    inverseProjection() const override;

    virtual const cgm::vec2&
    viewport() const override;

protected:
    void
    calculateProjection();

protected:
    cgm::mat4
    m_projection;

    cgm::mat4
    m_inverseProjection;

    Properties
    m_properties;

    cgm::vec2
    m_viewport {0,0};
};