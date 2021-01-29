

#include "Clamp.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
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

template<typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,T>
clamp01(T value)
{
    return value > number<T>(1) ? number<T>(1) : value < number<T>(0) ? number<T>(0) : value;
}

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,T>
clamp11(T value)
{
    return value > number<T>(1) ? number<T>(1) : value < number<T>(-1) ? number<T>(-1) : value;
}

/* ####################################################################################### */
/* Vectors */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,Vector<D,T>>
clamp(const Vector<D,T>& value, const Vector<D,T>& a, const Vector<D,T>& b)
{
    if constexpr (D == 2)
    {
        return
        {
            clamp(value.x, a.x, b.x),
            clamp(value.y, a.y, b.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            clamp(value.x, a.x, b.x),
            clamp(value.y, a.y, b.y),
            clamp(value.z, a.z, b.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            clamp(value.x, a.x, b.x),
            clamp(value.y, a.y, b.y),
            clamp(value.z, a.z, b.z),
            clamp(value.w, a.w, b.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = clamp(value[i], a[i], b[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_number<T,Vector<D,T>>
clamp01(const Vector<D,T>& value)
{
    if constexpr (D == 2)
    {
        return
        {
            clamp01(value.x),
            clamp01(value.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            clamp01(value.x),
            clamp01(value.y),
            clamp01(value.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            clamp01(value.x),
            clamp01(value.y),
            clamp01(value.z),
            clamp01(value.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = clamp01(value[i]);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
clamp11(const Vector<D,T>& value)
{
    if constexpr (D == 2)
    {
        return
        {
            clamp11(value.x),
            clamp11(value.y)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            clamp11(value.x),
            clamp11(value.y),
            clamp11(value.z)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            clamp11(value.x),
            clamp11(value.y),
            clamp11(value.z),
            clamp11(value.w)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = clamp11(value[i]);
        }
        return result;
    }
}

CGM_NAMESPACE_END