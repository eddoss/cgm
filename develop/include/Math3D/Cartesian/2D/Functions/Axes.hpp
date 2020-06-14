#ifndef MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP
#define MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

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

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Axes.hpp>


#endif // MATH3D_XY_FUNCTIONS_AXES_CREATORS_HPP
