#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/cartesian/3d/types/quaternion.hpp>
#include <cgm/modules/cartesian/2d/functions/axes.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/**
 * Calculates shortest distance from point to plane.
 * @param point Point to calculate distance from.
 * @param axisNormal Normal of axis to calculate distance to.
 * @return Shortest distance from point to plane.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
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


#include "utils.inl"
