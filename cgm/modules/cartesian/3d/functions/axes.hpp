#pragma once


#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/3d/module_globals.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Create default Cartesian axis.
 */
template<E3D Axis, typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
axis();

/**
 * Gets Cartesian x axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
x();

/**
 * Gets Cartesian Y axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
y();

/**
 * Gets Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Gets Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
up();

/**
 * Gets Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
right();

/**
 * Gets Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
forward();

/**
 * Gets Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
down();

/**
 * Gets Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
left();

/**
 * Gets Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr CGM_FORCEINLINE Vector<3,T>
backward();

CGM_NAMESPACE_END


#include "axes.inl"
