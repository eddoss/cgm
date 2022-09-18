

#include "comparison.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, bool>
eq(T A, T B, T tolerance)
{
    return std::abs(A-B) <= tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
eq(const Number<T,Constraint>& A, const Number<T,Constraint>& B, T tolerance)
{
    return eq(A.get(), B.get(), tolerance);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_integral_v<T>, bool>
eq(T A, T B)
{
    return A == B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>, bool>
neq(T A, T B, T tolerance)
{
    return std::abs(A-B) > tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, typename Constraint>
constexpr CGM_FORCEINLINE bool
neq(const Number<T,Constraint>& A, const Number<T,Constraint>& B, T tolerance)
{
    return neq(A.get(), B.get(), tolerance);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<std::is_integral_v<T>, bool>
neq(T A, T B)
{
    return A != B;
}

CGM_NAMESPACE_END