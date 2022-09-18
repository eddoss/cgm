

#include "spherical.hpp"


#include <cgm/modules/coordinates/types/spherical.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template <typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
SphericalLatitudeConstraint<T>::operator () (T value)
{
    return value > T(CGM_PI) ? T(CGM_PI) : value < T(0) ? T(0) : value;
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