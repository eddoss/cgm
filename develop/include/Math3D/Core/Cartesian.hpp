#ifndef MATH3D_CARTESIAN_AXES_HPP
#define MATH3D_CARTESIAN_AXES_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Cartesian x axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
x();

/**
 * Cartesian system y axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
y();

/**
 * Cartesian system z axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
z();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Return Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
up();

/**
 * Return Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
right();

/**
 * Return Cartesian system forward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
forward();

/**
 * Return Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
down();

/**
 * Return Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
left();

/**
 * Return Cartesian system backward axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<3,T>
backward();

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Cartesian.hpp>


#endif // MATH3D_CARTESIAN_AXES_HPP
