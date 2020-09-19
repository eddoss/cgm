#pragma once


#include <CGM/Modules/Common.hpp>
#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Create default Cartesian axis.
 */
template<EAxes Axis, typename T=FLOAT>
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

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/3D/Functions/Axes.hpp>