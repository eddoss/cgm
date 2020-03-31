

#include <Math3D/Core/Coordinates/Polar.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<typename T>
constexpr
Polar<T>::Polar(T angle, T radius)
    : m_angle(angle)
    , m_radius(radius)
{

}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties getters */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE T
Polar<T>::angle() const
{
    return m_angle;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T
Polar<T>::radius() const
{
    return m_radius;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties setters */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE void
Polar<T>::setAngle(T angle)
{
    m_angle = angle;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
Polar<T>::setRadius(T radius)
{
    if (radius < 0)
    {
        m_radius = 0;
    }
    else
    {
        m_radius = radius;
    }
}

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END