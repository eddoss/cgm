

#include "Polar.hpp"


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<typename T>
constexpr
Polar<T>::Polar(T Angle, T Radius)
    : angle(Angle)
    , radius(Radius)
{

}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END