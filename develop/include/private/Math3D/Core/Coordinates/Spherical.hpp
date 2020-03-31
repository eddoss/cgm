

#include <Math3D/Core/Coordinates/Spherical.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<typename T>
constexpr
Spherical<T>::Spherical(T longitude, T latitude, T radius)
    : m_longitude(longitude)
    , m_latitude(latitude)
    , m_radius(radius)
{

}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties getters */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE T
Spherical<T>::longitude() const
{
    return m_longitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T
Spherical<T>::latitude() const
{
    return m_latitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T
Spherical<T>::radius() const
{
    return m_radius;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties setters */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE void
Spherical<T>::setLongitude(T longitude)
{
    m_longitude = longitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
Spherical<T>::setLatitude(T latitude)
{
    if (latitude > PI)
    {
        m_latitude = PI;
    }
    else if (latitude < 0)
    {
        m_latitude = 0;
    }
    else
    {
        m_latitude = latitude;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
Spherical<T>::setRadius(T radius)
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