

#include "Axes.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr
Axes<T>::Axes(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
    : x(X)
    , y(Y)
    , z(Z)
{

}

CGM_NAMESPACE_END