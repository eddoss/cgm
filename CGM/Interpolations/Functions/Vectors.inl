

#include "Vectors.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Remapping */
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

/* --------------------------------------------------------------------------------------- */

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

/* ####################################################################################### */
/* Interpolations */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
lerp(const Vector<D,T>& a, const Vector<D,T>& b, const Vector<D,T>& bias)
{
    if constexpr (D == 2)
    {
        return
        {
            lerp(a.x, b.x, bias),
            lerp(a.y, b.y, bias)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            lerp(a.x, b.x, bias),
            lerp(a.y, b.y, bias),
            lerp(a.z, b.z, bias)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            lerp(a.x, b.x, bias),
            lerp(a.y, b.y, bias),
            lerp(a.z, b.z, bias),
            lerp(a.w, b.w, bias)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = lerp(a[i], b[i], bias);
        }
        return result;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
bilerp(const Vector<D,T>& A0, const Vector<D,T>& A1, const Vector<D,T>& B0, const Vector<D,T>& B1, T biasU, T biasV)
{
    if constexpr (D == 2)
    {
        return
        {
            bilerp(A0.x, A1.x, B0.x, B1.x, biasU, biasV),
            bilerp(A0.y, A1.y, B0.y, B1.y, biasU, biasV)
        };
    }
    else if constexpr (D == 3)
    {
        return
        {
            bilerp(A0.x, A1.x, B0.x, B1.x, biasU, biasV),
            bilerp(A0.y, A1.y, B0.y, B1.y, biasU, biasV),
            bilerp(A0.z, A1.z, B0.z, B1.z, biasU, biasV)
        };
    }
    else if constexpr (D == 4)
    {
        return
        {
            bilerp(A0.x, A1.x, B0.x, B1.x, biasU, biasV),
            bilerp(A0.y, A1.y, B0.y, B1.y, biasU, biasV),
            bilerp(A0.z, A1.z, B0.z, B1.z, biasU, biasV),
            bilerp(A0.w, A1.w, B0.w, B1.w, biasU, biasV)
        };
    }
    else
    {
        Vector<D,T> result {};
        for (size_t i = 0; i < D; ++i)
        {
            result[i] = bilerp(A0[i], A1[i], B0[i], B1[i], biasU, biasV);
        }
        return result;
    }
}

CGM_NAMESPACE_END