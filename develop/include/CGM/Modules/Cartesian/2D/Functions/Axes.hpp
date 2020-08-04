#pragma once


#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

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


#include <CGM/detail/Modules/Cartesian/2D/Functions/Axes.hpp>
