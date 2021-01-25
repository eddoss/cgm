

#include <Scene/Camera/Controllers/Flyable.hpp>
#include <CGM/Modules/Transformations/3D.hpp>


FlyableCameraController::FlyableCameraController()
{
    m_space = cgm::lookAt(cgm::vec3(1), cgm::vec3(0), cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

FlyableCameraController::FlyableCameraController(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_space = cgm::lookAt(position, aim, cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::focus(const cgm::vec3& aim, const cgm::vec3& position)
{
    m_space = cgm::lookAt(position, aim, cgm::up());
    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

cgm::vec3
FlyableCameraController::position() const
{
    return cgm::position(m_space);
}

cgm::vec3
FlyableCameraController::right() const
{
    return cgm::right(m_space);
}

cgm::vec3
FlyableCameraController::up() const
{
    return cgm::up(m_space);
}

cgm::vec3
FlyableCameraController::forward() const
{
    return cgm::forward(m_space);
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
    cgm::translate(m_space, -this->right() * horizontal);
#else
    cgm::translate(m_space, this->right() * horizontal);
#endif
    cgm::translate(m_space, this->up() * vertical);
    cgm::translate(m_space, this->forward() * forward);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::rotate(cgm::float32 horizontal, cgm::float32 vertical)
{
    const auto pos = position();

    const auto rightAxis = cgm::Ray(right(), pos);
    cgm::rotate(m_space, cgm::radians(vertical), rightAxis);

    const auto upAxis = cgm::Ray(cgm::up(), pos);
    cgm::rotate(m_space, cgm::radians(horizontal), upAxis);

    m_inverseSpace = m_space;
    cgm::invert(m_inverseSpace);
}

void
FlyableCameraController::setPosition(const cgm::vec3& position)
{
    cgm::setPosition(m_space, position);
}