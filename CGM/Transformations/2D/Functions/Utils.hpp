#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Cartesian/2D/Functions/Axes.hpp>
#include <CGM/Transformations/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/**
 * Calculates shortest distance from point to plane.
 * @param point Point to calculate distance from.
 * @param axisNormal Normal of axis to calculate distance to.
 * @return Shortest distance from point to plane.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
shortestDistance(const Vector<2,T>& point, const Vector<2,T>& axisNormal);

/**
 * Create zero pivot. Axes has default value, position is zero.
 * @return Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
zeroPivot();

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Utils.inl"