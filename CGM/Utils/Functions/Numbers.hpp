#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Convert value from type A to type B.
 */
template<typename AT, typename BT>
constexpr CGM_FORCEINLINE enable_if_number<AT,AT>
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