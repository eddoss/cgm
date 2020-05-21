#ifndef MATH3D_XYZ_FUNCTIONS_AXES_HPP
#define MATH3D_XYZ_FUNCTIONS_AXES_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Gets Cartesian x axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
x();

/**
 * Gets Cartesian Y axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
y();

/**
 * Gets Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Gets Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
up();

/**
 * Gets Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
right();

/**
 * Gets Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
forward();

/**
 * Gets Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
down();

/**
 * Gets Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
left();

/**
 * Gets Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
backward();

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Axes.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_AXES_HPP
