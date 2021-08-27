

#include "Ray.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr
Ray<T>::Ray(const Vector<3,T>& dir, const Vector<3,T>& pos)
    : direction(dir)
    , position(pos)
{

}

CGM_NAMESPACE_END