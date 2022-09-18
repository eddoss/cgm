

#include "cylindrical.hpp"


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template <typename T>
constexpr
Cylindrical<T>::Cylindrical(T Angle, T Height, T Radius)
    : angle(Angle)
    , height(Height)
    , radius(Radius)
{

}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END