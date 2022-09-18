#pragma once


#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>


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


#include "axes.inl"
