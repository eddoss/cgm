

#include "Spherical.hpp"


#include <CGM/Coordinates/Types/Spherical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

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
constexpr CGM_FORCEINLINE T
Spherical<T>::longitude() const
{
    return m_longitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
Spherical<T>::latitude() const
{
    return m_latitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
Spherical<T>::radius() const
{
    return m_radius;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Properties setters */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
Spherical<T>::setLongitude(T longitude)
{
    m_longitude = longitude;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
Spherical<T>::setLatitude(T latitude)
{
    if (latitude > CGM_PI)
    {
        m_latitude = CGM_PI;
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
constexpr CGM_FORCEINLINE void
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

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END