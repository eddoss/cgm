

#include "AxisAngle.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr
AxisAngle<T>::AxisAngle(const Vector<3,T>& dir, T ang)
    : direction(dir)
    , angle(ang)
{

}

CGM_NAMESPACE_END