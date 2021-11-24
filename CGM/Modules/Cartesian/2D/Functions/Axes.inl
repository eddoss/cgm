

#include "Axes.hpp"


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
        return {T(1), T(0)};
    }
    else
    {
        return {T(0), T(1)};
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
x()
{
    return {T(1), T(0)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
y()
{
    return {T(0), T(1)};
}

CGM_2D_NAMESPACE_END
