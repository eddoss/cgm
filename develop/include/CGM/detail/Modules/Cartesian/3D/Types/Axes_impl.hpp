

#include <CGM/detail/Modules/Cartesian/3D/Types/Axes.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

template<typename T>
constexpr
Axes<T>::Axes(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
    : x(X)
    , y(Y)
    , z(Z)
{

}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END