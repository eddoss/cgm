#pragma once


#include <CGM/Modules/Utils/ModuleGlobals.hpp>
#include <CGM/Modules/Utils/Functions/Numbers.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, bool>
eq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare constraintable number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
eq(const Number<T,Constraint>& A, const Number<T,Constraint>& B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_integral_v<T>, bool>
eq(T A, T B);

/**
 * Compare number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, bool>
neq(T A, T B, T tolerance=CGM_TOLERANCE);

/**
 * Compare constraintable number A and B (floating point numbers).
 * @param A First number.
 * @param B Second number.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
neq(const Number<T,Constraint>& A, const Number<T,Constraint>& B, T tolerance=CGM_TOLERANCE);

/**
 * Compare number A and B (integral numbers).
 * @param A First number.
 * @param B Second number.
 * @return true if A not equal to B, false otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_integral_v<T>, bool>
neq(T A, T B);

CGM_NAMESPACE_END


#include "Comparison.inl"