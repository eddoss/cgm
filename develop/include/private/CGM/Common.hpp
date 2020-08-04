

#include <CGM/Common.hpp>


template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
eq(T A, T B, T tolerance)
{
    return std::abs(A-B) <= tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_integral<T,bool>
eq(T A, T B)
{
    return A == B;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
neq(T A, T B, T tolerance)
{
    return std::abs(A-B) > tolerance;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE enable_if_integral<T,bool>
neq(T A, T B)
{
    return A != B;
}

/* ####################################################################################### */
/* Number converter */
/* ####################################################################################### */

template<typename AT, typename BT>
constexpr FORCEINLINE enable_if_floating_or_integral<AT,AT>
number(BT value)
{
    return static_cast<AT>(value);
}