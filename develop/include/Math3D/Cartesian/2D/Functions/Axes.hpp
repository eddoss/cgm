#pragma once


#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>
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

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Axes.hpp>