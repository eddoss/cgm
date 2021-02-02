#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
eq(T A, T B);

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
neq(T A, T B);

CGM_NAMESPACE_END


#include "Comparison.inl"