

#include "Interps.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
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

/* ####################################################################################### */
/* Vectors */
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