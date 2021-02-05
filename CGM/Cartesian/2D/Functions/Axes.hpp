#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

/**
 * Create default Cartesian axis.
 */
template<E2D Axis, typename T=FLOAT>
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

CGM_2D_NAMESPACE_END


#include "Axes.inl"
