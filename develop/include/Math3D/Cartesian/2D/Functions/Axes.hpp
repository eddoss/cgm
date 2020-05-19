#ifndef MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP
#define MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

/**
 * Gets Cartesian X axis.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
x();

/**
 * Gets Cartesian Y axis.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
y();

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

/**
 * Gets Cartesian system up axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<2,T>
up();

/**
 * Gets Cartesian system right axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<2,T>
right();

/**
 * Gets Cartesian system down axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<2,T>
down();

/**
 * Gets Cartesian system left axis.
 */
template<typename T=FLOAT>
constexpr FORCEINLINE Vector<2,T>
left();

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Axes.hpp>


#endif // MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP
