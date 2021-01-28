

#include "Numbers.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Remapping */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,T>
clamp(T value, T a, T b)
{
    if (a < b)
    {
        return value > b ? b : value < a ? a : value;
    }
    else
    {
        return value > a ? a : value < b ? b : value;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit(T value, T omin, T omax, T nmin, T nmax)
{
    if (omin < omax)
    {
        return ((value > omax ? omax : value < omin ? omin : value) - omin) / (omax - omin) * (nmax - nmin) + nmin;
    }
    else
    {
        return ((value > omin ? omin : value < omax ? omax : value) - omax) / (omin - omax) * (nmin - nmax) + nmax;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit01(T value, T newMin, T newMax)
{
    return (value > number<T>(1) ? number<T>(1) : value < number<T>(0) ? number<T>(0) : value) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit10(T value, T newMin, T newMax)
{
    return ((value > number<T>(1) ? number<T>(1) : value < number<T>(0) ? number<T>(0) : value) - number<T>(1)) * (newMin - newMax) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
fit11(T value, T newMin, T newMax)
{
    return ((value > number<T>(1) ? number<T>(1) : value < number<T>(-1) ? number<T>(-1) : value) - number<T>(-1)) / number<T>(2) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit(T value, T omin, T omax, T nmin, T nmax)
{
    return (value - omin) / (omax - omin) * (nmax - nmin) + nmin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit01(T value, T newMin, T newMax)
{
    return value * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit10(T value, T newMin, T newMax)
{
    return -(value - number<T>(1)) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit11(T value, T newMin, T newMax)
{
    return (value - number<T>(-1)) * number<T>(0.5) * (newMax - newMin) + newMin;
}

/* ####################################################################################### */
/* Interpolations */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
lerp(T a, T b, T bias)
{
    return bias * (b - a) + a;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
bilerp(T A0, T A1, T B0, T B1, T biasU, T biasV)
{
    return lerp
    (
        lerp(A0, A1, biasU),
        lerp(B0, B1, biasU),
        biasV
    );
}

CGM_NAMESPACE_END