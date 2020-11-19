

#include <Scene/Camera/Controllers/Aim.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


namespace cgx = cgm::xyz;

AimCameraController::AimCameraController()
{
    m_space = cgx::lookAt(cgm::vec3(1), cgm::vec3(0), cgx::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

AimCameraController::AimCameraController(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_aim = aim;
    m_space = cgx::lookAt(position, aim, cgx::up());
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
    cgx::setPosition(m_space, position);
    calculateSpace();
}

cgm::vec3
AimCameraController::position() const
{
    return cgx::position(m_space);
}

cgm::vec3
AimCameraController::right() const
{
    return cgx::right(m_space);
}

cgm::vec3
AimCameraController::up() const
{
    return cgx::up(m_space);
}

cgm::vec3
AimCameraController::forward() const
{
    return cgx::forward(m_space);
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
AimCameraController::move(cgm::float32 horizontal, cgm::float32 vertical, cgm::float32 forward)
{
#ifdef CGM_CFG_RHS
    const auto r = -cgx::right(m_space);
#else
    const auto r = cgx::right(m_space);
#endif
    const auto u = cgx::up(m_space);
    const auto f = cgx::forward(m_space);

    cgx::translate(m_space, r * horizontal);
    cgx::translate(m_space, u * vertical);
    cgx::translate(m_space, f * forward);

    cgx::translate(m_aim, r * horizontal);
    cgx::translate(m_aim, u * vertical);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
AimCameraController::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    const auto axis = cgx::Ray(cgx::right(m_space), m_aim);

    cgx::rotate(m_space, cgm::radians(vertical), axis);
    cgx::rotate(m_space, cgm::radians(horizontal), cgx::up());

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
AimCameraController::setPosition(const cgm::vec3& position)
{
    cgx::setPosition(m_space, position);
    calculateSpace();
}

void
AimCameraController::calculateSpace()
{
    m_space = cgx::lookAt(position(), m_aim, cgx::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}
