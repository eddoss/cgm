

#include <Math3D/Cartesian/2D/Functions/Axes.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
x()
{
    return {T(1), T(0)};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
y()
{
    return {T(0), T(1)};
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END
