#pragma once


#include <CGM/detail/Modules/Common.hpp>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/detail/Modules/Cartesian/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

/**
 * Create default Cartesian axis.
 */
template<EAxes Axis, typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<2,T>
axis();

/**
 * Gets Cartesian X axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<2,T>
x();

/**
 * Gets Cartesian Y axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<2,T>
y();

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/2D/Functions/Axes_impl.hpp>
