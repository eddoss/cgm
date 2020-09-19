

#include <CGM/detail/Modules/Transformations/3D/Types/ArbitraryAxis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr
ArbitraryAxis<T>::ArbitraryAxis(const Vector<3,T>& dir, const Vector<3,T>& pos)
    : direction(dir)
    , position(pos)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END