

#include "circle.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Circle<T>::Circle(Vector<2,T> Position, T Radius)
    : center(Position)
    , radius(Radius)
{

}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr
Circle<T>::Circle(T Radius)
    : center(T(0))
    , radius(Radius)
{

}

CGM_2D_NAMESPACE_END