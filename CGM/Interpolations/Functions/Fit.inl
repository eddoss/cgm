

#include "Fit.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

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

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit(const Vector<D,T>& value, const Vector<D,T>& omin, const Vector<D,T>& omax, const Vector<D,T>& nmin, const Vector<D,T>& nmax)
{
    if constexpr (D == 2)
    {
        return
        {
            fit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            fit(value.y, omin.y, omax.y, nmin.y, nmax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            fit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            fit(value.y, omin.y, omax.y, nmin.y, nmax.y),
            fit(value.z, omin.z, omax.z, nmin.z, nmax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            fit(value.x, omin.x, omax.x, nmin.x, nmax.x),
            fit(value.y, omin.y, omax.y, nmin.y, nmax.y),
            fit(value.z, omin.z, omax.z, nmin.z, nmax.z),
            fit(value.w, omin.w, omax.w, nmin.w, nmax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = fit(value[i], omin[i], omax[i], nmin[i], nmax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit01(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            fit01(value.x, newMin.x, newMax.x),
            fit01(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            fit01(value.x, newMin.x, newMax.x),
            fit01(value.y, newMin.y, newMax.y),
            fit01(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            fit01(value.x, newMin.x, newMax.x),
            fit01(value.y, newMin.y, newMax.y),
            fit01(value.z, newMin.z, newMax.z),
            fit01(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = fit01(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit10(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            fit10(value.x, newMin.x, newMax.x),
            fit10(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            fit10(value.x, newMin.x, newMax.x),
            fit10(value.y, newMin.y, newMax.y),
            fit10(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            fit10(value.x, newMin.x, newMax.x),
            fit10(value.y, newMin.y, newMax.y),
            fit10(value.z, newMin.z, newMax.z),
            fit10(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = fit10(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
fit11(const Vector<D,T>& value, const Vector<D,T>& newMin, const Vector<D,T>& newMax)
{
    if constexpr (D == 2)
    {
        return
        {
            fit11(value.x, newMin.x, newMax.x),
            fit11(value.y, newMin.y, newMax.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            fit11(value.x, newMin.x, newMax.x),
            fit11(value.y, newMin.y, newMax.y),
            fit11(value.z, newMin.z, newMax.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            fit11(value.x, newMin.x, newMax.x),
            fit11(value.y, newMin.y, newMax.y),
            fit11(value.z, newMin.z, newMax.z),
            fit11(value.w, newMin.w, newMax.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = fit11(value[i], newMin[i], newMax[i]);
        }
        return result;
    }
}

CGM_NAMESPACE_END