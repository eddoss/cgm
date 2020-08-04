

#include <CGM/Cartesian/2D/Functions/Axes.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

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

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
