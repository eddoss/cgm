

#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
Axis<T>::Axis(const Vector<3,T>& dir, const Vector<3,T>& pos)
    : direction(dir)
    , position(pos)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END