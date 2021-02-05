

#include "Circle.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Circle<T>::Circle(Vector<2,T> Position, T Radius)
    : position(Position)
    , radius(Radius)
{

}

template <typename T>
constexpr
Circle<T>::Circle(T Radius)
    : position(val<T>(0))
    , radius(Radius)
{

}

CGM_2D_NAMESPACE_END