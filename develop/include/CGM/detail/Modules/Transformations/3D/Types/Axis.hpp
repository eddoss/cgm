

#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
Axis<T>::Axis(const Vector<3,T>& pos, const Vector<3,T>& dir)
    : origin(pos)
    , direction(dir)
{

}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END