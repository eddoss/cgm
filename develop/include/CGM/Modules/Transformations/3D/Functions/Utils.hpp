#pragma once


#include <tuple>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Quaternion.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Typedefs.hpp>


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
quaternion(const Vector<3,T>& axis, T angle);

/**
 * Create quaternion from axis and angle.
 * @param axisAngle Tuple of rotation axis and angle (axis must be normalized).
 * @param Constructed quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
quaternion(const AxisAngle<T>& axisAngle);

/**
 * Create tuple of rotation axis and angle.
 * @param axis Rotation axis.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE AxisAngle<T>
axisAngle(const Vector<3,T>& axis, T angle);

/**
 * Extract rotation axis and angle from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation axis and angle.
 */
template<typename T>
constexpr AxisAngle<T>
axisAngle(const Quaternion<T>& quaternion);

/**
 * Extract rotation axis from tuple of axis and angle.
 * @param axisAngle Tuple of axis and angle.
 * @param Rotation axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
axis(const AxisAngle<T>& axisAngle);

/**
 * Extract rotation axis from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation axis.
 */
template<typename T>
constexpr Vector<3,T>
axis(const Quaternion<T>& quaternion);

/**
 * Extract rotation angle from tuple of axis and angle.
 * @param axisAngle Tuple of axis and angle.
 * @param Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
angle(const AxisAngle<T>& axisAngle);

/**
 * Extract rotation angle from quaternion.
 * @param quaternion Quaternion to extract from.
 * @param Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
angle(const Quaternion<T>& quaternion);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Utils.hpp>