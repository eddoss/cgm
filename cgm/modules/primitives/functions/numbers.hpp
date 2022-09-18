#pragma once


#include <cgm/modules/primitives/module_globals.hpp>
#include <cgm/modules/primitives/types/number.hpp>
#include <cgm/modules/primitives/types/constraints.hpp>


CGM_NAMESPACE_BEGIN

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
constexpr CGM_FORCEINLINE NumberPositive<T>
posnum(T value);

/**
 * Creates negative constrained number.
 */
template<typename T>
constexpr CGM_FORCEINLINE NumberNegative<T>
negnum(T value);

/**
 * Creates number constrained in ranger[-1, 0].
 */
template<typename T>
constexpr CGM_FORCEINLINE Number10<T>
num10(T value);

/**
 * Creates number constrained in ranger[0, +1].
 */
template<typename T>
constexpr CGM_FORCEINLINE Number01<T>
num01(T value);

/**
 * Creates number constrained in ranger[-1, +1].
 */
template<typename T>
constexpr CGM_FORCEINLINE Number11<T>
num11(T value);

CGM_NAMESPACE_END


#include "numbers.inl"
