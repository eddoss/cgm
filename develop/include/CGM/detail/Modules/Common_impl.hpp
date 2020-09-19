

#include <CGM/detail/Modules/Common.hpp>


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

/* ####################################################################################### */
/* Number converters */
/* ####################################################################################### */

template<typename AT, typename BT>
constexpr CGM_FORCEINLINE enable_if_floating_or_integral<AT,AT>
number(BT value)
{
    return static_cast<AT>(value);
}

/* ####################################################################################### */
/* Angle converters */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
radians(T angle)
{
    return angle * number<T>(0.01745329251994329576923690768489);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
degrees(T angle)
{
    return angle * number<T>(57.295779513082320876798154814105);
}