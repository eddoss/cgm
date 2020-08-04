

#include <CGM/Coordinates/Types/Cylindrical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template <typename T>
constexpr
Cylindrical<T>::Cylindrical(T angle, T height, T radius)
    : m_angle(angle)
    , m_height(height)
    , m_radius(radius)
{

}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties getters */
/* ####################################################################################### */

template<typename T>
constexpr T
Cylindrical<T>::angle() const
{
    return m_angle;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
Cylindrical<T>::radius() const
{
    return m_radius;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr T
Cylindrical<T>::height() const
{
    return m_height;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties setters */
/* ####################################################################################### */

template<typename T>
constexpr void
Cylindrical<T>::setAngle(T angle)
{
    m_angle = angle;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
Cylindrical<T>::setRadius(T radius)
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
Cylindrical<T>::setHeight(T height)
{
    m_height = height;
}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END