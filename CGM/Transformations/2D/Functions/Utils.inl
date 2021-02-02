

#include "Utils.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE T
shortestDistance(const Vector<2,T>& point, const Vector<2,T>& axisNormal)
{
    return dot(point, axisNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
zeroPivot()
{
    return
    {
        x<T>(),
        y<T>(),
        Vector<2,T>(val<T>(0))
    };
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END