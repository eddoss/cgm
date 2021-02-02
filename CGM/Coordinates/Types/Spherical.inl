

#include "Spherical.hpp"


#include <CGM/Coordinates/Types/Spherical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<typename T>
constexpr
Spherical<T>::Spherical(T Longitude, T Latitude, T Radius)
    : longitude(Longitude)
    , latitude(Latitude)
    , radius(Radius)
{

}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END