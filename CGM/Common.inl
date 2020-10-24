

#include "Common.hpp"


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

/* ####################################################################################### */
/* Value remapping */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE T
clamp(const T& value, T min, T max)
{
    return value > max ? max : value < min ? min : value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
fit(T value, T omin, T omax, T nmin, T nmax)
{
    return (clamp(value, omin, omax) - omin) / (omax - omin) * (nmax - nmin) + nmin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
fit01(T value, T newMin, T newMax)
{
    return clamp(value, number<T>(0), number<T>(1)) / (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
fit10(T value, T newMin, T newMax)
{
    return (clamp(value, number<T>(1), number<T>(0)) - number<T>(1)) / number<T>(-1) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
fit11(T value, T newMin, T newMax)
{
    return (clamp(value, number<T>(-1), number<T>(1)) - number<T>(-1)) / number<T>(2) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
ufit(T value, T omin, T omax, T nmin, T nmax)
{
    return (value - omin) / (omax - omin) * (nmax - nmin) + nmin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
ufit01(T value, T newMin, T newMax)
{
    return value / (newMax - newMin) + newMax;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
ufit10(T value, T newMin, T newMax)
{
    return -(value - number<T>(1)) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
ufit11(T value, T newMin, T newMax)
{
    return (value - number<T>(-1)) * number<T>(0.5) * (newMax - newMin) + newMin;
}

/* ####################################################################################### */
/* Interpolations */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE T
lerp(T A, T B, T bias)
{
    return bias * (B - A) + A;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T
blerp(T Ax, T Ay, T Bx, T By, T biasX, T biasY)
{
    return lerp
    (
        lerp(Ax, Ay, biasX),
        lerp(Bx, By, biasX),
        biasY
    );
}