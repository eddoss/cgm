

#include "range.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr
Range<T>::Range(const Vector<2,T>& minimum, const Vector<2,T>& maximum)
    : min(minimum)
    , max(maximum)
{

}

CGM_2D_NAMESPACE_END