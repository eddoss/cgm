

#include <Scene/Camera/Controllers/Flyable.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


namespace cgx = cgm::xyz;

FlyableCameraController::FlyableCameraController()
{
    m_space = cgx::lookAt(cgm::vec3(1), cgm::vec3(0), cgx::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

FlyableCameraController::FlyableCameraController(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_space = cgx::lookAt(position, aim, cgx::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::focus(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_space = cgx::lookAt(position, aim, cgx::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

cgm::vec3
FlyableCameraController::position() const
{
    return cgx::position(m_space);
}

cgm::vec3
FlyableCameraController::right() const
{
    return cgx::right(m_space);
}

cgm::vec3
FlyableCameraController::up() const
{
    return cgx::up(m_space);
}

cgm::vec3
FlyableCameraController::forward() const
{
    return cgx::forward(m_space);
}

const cgm::mat4&
FlyableCameraController::space() const
{
    return m_space;
}

const cgm::mat4&
FlyableCameraController::inverseSpace() const
{
    return m_inverseSpace;
}

void
FlyableCameraController::move(cgm::float32 horizontal, cgm::float32 vertical, cgm::float32 forward)
{
#ifdef CGM_CFG_RHS
    cgx::translate(m_space, -this->right() * horizontal);
#else
    cgx::translate(m_space, this->right() * horizontal);
#endif
    cgx::translate(m_space, this->up() * vertical);
    cgx::translate(m_space, this->forward() * forward);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    const auto pos = position();

    const auto rightAxis = cgx::ArbitraryAxis(right(), pos);
    cgx::rotate(m_space, cgm::radians(vertical), rightAxis);

    const auto upAxis = cgx::ArbitraryAxis(cgx::up(), pos);
    cgx::rotate(m_space, cgm::radians(horizontal), upAxis);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::setPosition(const cgm::vec3& position)
{
    cgx::setPosition(m_space, position);
}