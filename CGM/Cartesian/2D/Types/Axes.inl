

#include "Axes.hpp"


CGM_NAMESPACE_BEGIN
CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Axes<T>::Axes(const Vector<2,T>& X, const Vector<2,T>& Y)
    : x(X)
    , y(Y)
{

}

CGM_2D_NAMESPACE_END
CGM_NAMESPACE_END