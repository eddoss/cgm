

#include "Comparison.hpp"


CGM_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(T A, T B, T tolerance)
{
    return std::abs(A-B) <= tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
eq(T A, T B)
{
    return A == B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(T A, T B, T tolerance)
{
    return std::abs(A-B) > tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_integral<T,bool>
neq(T A, T B)
{
    return A != B;
}

CGM_NAMESPACE_END