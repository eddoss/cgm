

#include <Scene/Camera/Controllers/Aim.hpp>
#include <CGM/Transformations/3D.hpp>


AimCameraController::AimCameraController()
{
    m_space = cgm::lookAt(cgm::vec3(1), cgm::vec3(0), cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

AimCameraController::AimCameraController(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_aim = aim;
    m_space = cgm::lookAt(position, aim, cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
AimCameraController::setAim(const cgm::vec3& aim)
{
    m_aim = aim;
    calculateSpace();
}

void
AimCameraController::focus(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_aim = aim;
    cgm::setPosition(m_space, position);
    calculateSpace();
}

cgm::vec3
AimCameraController::position() const
{
    return cgm::position(m_space);
}

cgm::vec3
AimCameraController::right() const
{
    return cgm::right(m_space);
}

cgm::vec3
AimCameraController::up() const
{
    return cgm::up(m_space);
}

cgm::vec3
AimCameraController::forward() const
{
    return cgm::forward(m_space);
}

const cgm::mat4&
AimCameraController::space() const
{
    return m_space;
}

const cgm::mat4&
AimCameraController::inverseSpace() const
{
    return m_inverseSpace;
}

void
AimCameraController::move(cgm::f32 horizontal, cgm::f32 vertical, cgm::f32 forward)
{
#ifdef CGM_CFG_RHS
    const auto r = -cgm::right(m_space);
#else
    const auto r = cgm::right(m_space);
#endif
    const auto u = cgm::up(m_space);
    const auto f = cgm::forward(m_space);

    cgm::translate(m_space, r * horizontal);
    cgm::translate(m_space, u * vertical);
    cgm::translate(m_space, f * forward);

    cgm::translate(m_aim, r * horizontal);
    cgm::translate(m_aim, u * vertical);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
AimCameraController::rotate(cgm::f32 horizontal, cgm::f32 vertical)
{
    const auto axis = cgm::Ray(cgm::right(m_space), m_aim);

    cgm::rotate(m_space, cgm::radians(vertical), axis);
    cgm::rotate(m_space, cgm::radians(horizontal), cgm::up());

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
AimCameraController::setPosition(const cgm::vec3& position)
{
    cgm::setPosition(m_space, position);
    calculateSpace();
}

void
AimCameraController::calculateSpace()
{
    m_space = cgm::lookAt(position(), m_aim, cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}
