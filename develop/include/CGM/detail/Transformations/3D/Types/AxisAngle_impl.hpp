

#include <CGM/detail/Transformations/3D/Types/AxisAngle.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr
AxisAngle<T>::AxisAngle(const Vector<3,T>& dir, T ang)
    : direction(dir)
    , angle(ang)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END