#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Axes.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/AxisAngle.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/**
 * Create quaternion from axis and angle.
 * @param axis Rotation axis (must be normalized).
 * @param angle Angle to rotate around axis (in radians).
 * @param Constructed quaternion.
 */
template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& axis, T angle);

/**
 * Create quaternion from axis and angle.
 * @param axisAngle Struct of rotation axis and angle (axis must be normalized).
 * @param Constructed quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const AxisAngle<T>& axisAngle);

/**
 * Extract rotation axis and angle from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation axis and angle.
 */
template<typename T>
constexpr AxisAngle<T>
axisAngle(const Quaternion<T>& quaternion);

/**
 * Extract rotation axis from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation axis.
 */
template<typename T>
constexpr Vector<3,T>
axis(const Quaternion<T>& quaternion);

/**
 * Extract rotation angle from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
angle(const Quaternion<T>& quaternion);

/**
 * Calculates shortest distance from point to plane.
 * @param point Point to calculate distance from.
 * @param planeNormal Normal of plane to calculate distance to.
 * @return Shortest distance from point to plane.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
shortestDistance(const Vector<3,T>& point, const Vector<3,T>& planeNormal);

/**
 * Create zero pivot. Axes has default value, position is zero.
 * @return Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
zeroPivot();

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Utils.hpp>