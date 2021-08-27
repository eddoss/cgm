

#include "Spherical.hpp"


#include <CGM/Modules/Coordinates/Types/Spherical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
SphericalLatitudeConstraint<T>::operator () (T value)
{
    return value > val<T>(CGM_PI) ? val<T>(CGM_PI) : value < val<T>(0) ? val<T>(0) : value;
}

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