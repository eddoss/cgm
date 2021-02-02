#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Convert value from type A to type B.
 */
template<typename AT, typename BT>
constexpr CGM_FORCEINLINE std::enable_if_t<(std::is_floating_point_v<AT> || std::is_integral_v<AT>), AT>
val(BT value);

/**
 * Creates constrained number.
 */
template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE Number<T, Constraint>
num(T value);

/**
 * Creates positive constrained number.
 */
template<typename T>
constexpr CGM_FORCEINLINE PositiveNumber<T>
posnum(T value);

/**
 * Creates negative constrained number.
 */
template<typename T>
constexpr CGM_FORCEINLINE NegativeNumber<T>
negnum(T value);

CGM_NAMESPACE_END


#include "Numbers.inl"