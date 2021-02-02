#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Creates constrained angle [-2PI, 2PI].
 */
template<typename T>
constexpr CGM_FORCEINLINE Angle<T>
angle(T value);

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