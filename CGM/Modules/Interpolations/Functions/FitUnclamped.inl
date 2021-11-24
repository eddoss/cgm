

#include "FitUnclamped.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

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
    return -(value - T(1)) * (newMax - newMin) + newMin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
ufit11(T value, T newMin, T newMax)
{
    return (value - T(-1)) * T(0.5) * (newMax - newMin) + newMin;
}

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit(const Vector<D,T>& value, const Vector<D,T>& omin, const Vector<D,T>& omax, const Vector<D,T>& nmin, const Vector<D,T>& nmax)
{
    if constexpr (D == 2)
    {
        return
        {
            ufit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            ufit(value.y, omin.y, omax.y, nmin.y, nmax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            ufit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            ufit(value.y, omin.y, omax.y, nmin.y, nmax.y),
            ufit(value.z, omin.z, omax.z, nmin.z, nmax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            ufit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            ufit(value.y, omin.y, omax.y, nmin.y, nmax.y),
            ufit(value.z, omin.z, omax.z, nmin.z, nmax.z),
            ufit(value.w, omin.w, omax.w, nmin.w, nmax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = ufit(value[i], omin[i], omax[i], nmin[i], nmax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit01(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            ufit01(value.x, newMin.x, newMax.x),
            ufit01(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            ufit01(value.x, newMin.x, newMax.x),
            ufit01(value.y, newMin.y, newMax.y),
            ufit01(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            ufit01(value.x, newMin.x, newMax.x),
            ufit01(value.y, newMin.y, newMax.y),
            ufit01(value.z, newMin.z, newMax.z),
            ufit01(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = ufit01(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit10(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            ufit10(value.x, newMin.x, newMax.x),
            ufit10(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            ufit10(value.x, newMin.x, newMax.x),
            ufit10(value.y, newMin.y, newMax.y),
            ufit10(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            ufit10(value.x, newMin.x, newMax.x),
            ufit10(value.y, newMin.y, newMax.y),
            ufit10(value.z, newMin.z, newMax.z),
            ufit10(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = ufit10(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
ufit11(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            ufit11(value.x, newMin.x, newMax.x),
            ufit11(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            ufit11(value.x, newMin.x, newMax.x),
            ufit11(value.y, newMin.y, newMax.y),
            ufit11(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            ufit11(value.x, newMin.x, newMax.x),
            ufit11(value.y, newMin.y, newMax.y),
            ufit11(value.z, newMin.z, newMax.z),
            ufit11(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = ufit11(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

CGM_NAMESPACE_END