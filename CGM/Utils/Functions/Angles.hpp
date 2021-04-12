#pragma once


#include <cmath>
#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Normalize angle to [-2PI, 2PI] range.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle(T angle);

/**
 * Normalize angle to [0, 2PI] range.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle_0_2PI(T angle);

/**
 * Normalize angle to [-PI, PI] range.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
normalizedAngle_PI_PI(T angle);

/**
 * Convert degrees to radians.
 * @param angle Angle to convert.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
radians(T angle);

/**
 * Convert radians to degrees.
 * @param angle Angle to convert.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, T>
degrees(T angle);

CGM_NAMESPACE_END


#include "Angles.inl"