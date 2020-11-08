#pragma once


#include <Scene/Camera/Controllers/ICameraController.hpp>


class AimCameraController : public ICameraController
{
public:
    using Shared = std::shared_ptr<AimCameraController>;
    using Unique = std::unique_ptr<AimCameraController>;
    using Weak = std::weak_ptr<AimCameraController>;

public:
    AimCameraController();
    AimCameraController(const cgm::vec3& aim, const cgm::vec3& position);

public:
    CGM_FORCEINLINE bool
    isAimMovable() const {return m_isAimMovable;};

    CGM_FORCEINLINE cgm::vec3
    aim() const {return m_aim;};

    void
    setAim(const cgm::vec3& aim);

    CGM_FORCEINLINE void
    setAimMovable(bool movable) {m_isAimMovable = movable;};

    void
    focus(const cgm::vec3& aim, const cgm::vec3& position);

public:
    cgm::vec3
    position() const override;

    cgm::vec3
    right() const override;

    cgm::vec3
    up() const override;

    cgm::vec3
    forward() const override;

    const cgm::mat4&
    space() const override;

    const cgm::mat4&
    inverseSpace() const override;

public:
    void
    move(cgm::float32 horizontal, cgm::float32 vertical, cgm::float32 forward) override;

    void
    rotate(cgm::float32 horizontal, cgm::float32 vertical) override;

    void
    setPosition(const cgm::vec3& position) override;

protected:
    void
    calculateSpace();

protected:
    cgm::mat4
    m_space;

    cgm::mat4
    m_inverseSpace;

    cgm::vec3
    m_aim;

    bool
    m_isAimMovable = true;
};