#pragma once


#include <cmath>
#include <cgm/modules/primitives/module_globals.hpp>


CGM_NAMESPACE_BEGIN

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


#include "angles.inl"
