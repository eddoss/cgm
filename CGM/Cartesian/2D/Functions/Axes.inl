

#include "Axes.hpp"


CGM_NAMESPACE_BEGIN
CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
axis()
{
    if constexpr (Axis == E2D::X)
    {
        return {val<T>(1), val<T>(0)};
    }
    else
    {
        return {val<T>(0), val<T>(1)};
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
x()
{
    return {val<T>(1), val<T>(0)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
y()
{
    return {val<T>(0), val<T>(1)};
}

CGM_2D_NAMESPACE_END
CGM_NAMESPACE_END
