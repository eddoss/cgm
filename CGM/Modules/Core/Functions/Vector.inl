

#include "Vector.hpp"


CGM_NAMESPACE_BEGIN

template<size_t D, typename T>
constexpr enable_if_floating<T, bool>
normalizeSafe(Vector<D,T>& vector, T lengthTolerance)
{
    const T len {length(vector)};

    if (std::abs(len) < lengthTolerance)
    {
        return false;
    }

    if constexpr (D == 2)
    {
        vector.x /= len;
        vector.y /= len;
    }

    if constexpr (D == 3)
    {
        vector.x /= len;
        vector.y /= len;
        vector.z /= len;
    }

    if constexpr (D == 4)
    {
        vector.x /= len;
        vector.y /= len;
        vector.z /= len;
        vector.w /= len;
    }

    if constexpr (D > 4)
    {
        for (size_t i = 0; i < D; ++i)
        {
            vector[i] /= len;
        }
    }

    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr enable_if_floating<T, Vector<D,T>>
normalizedSafe(const Vector<D,T>& vector, bool& success, T lengthTolerance)
{
    const T len {length(vector)};

    if (std::abs(len) < lengthTolerance)
    {
        success = false;
        return vector;
    }

    success = true;

    if constexpr (D == 2)
    {
        return
        {
            vector.x / len,
            vector.y / len
        };
    }

    if constexpr (D == 3)
    {
        return
        {
            vector.x / len,
            vector.y / len,
            vector.z / len
        };
    }

    if constexpr (D == 4)
    {
        return
        {
            vector.x / len,
            vector.y / len,
            vector.z / len,
            vector.w / len
        };
    }

    if constexpr (D > 4)
    {
        Vector<D,T> vec;
        for (size_t i = 0; i < D; ++i)
        {
            vec[i] = vector[i] / len;
        }
        return vec;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
normalize(Vector<D,T>& vector)
{
    const T len {length(vector)};

    if constexpr (D == 2)
    {
        vector.x /= len;
        vector.y /= len;
    }

    if constexpr (D == 3)
    {
        vector.x /= len;
        vector.y /= len;
        vector.z /= len;
    }

    if constexpr (D == 4)
    {
        vector.x /= len;
        vector.y /= len;
        vector.z /= len;
        vector.w /= len;
    }

    if constexpr (D > 4)
    {
        for (size_t i = 0; i < D; ++i)
        {
            vector[i] /= len;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<D,T>>
normalized(const Vector<D,T>& vector)
{
    const T len {length(vector)};

    if constexpr (D == 2)
    {
        return
        {
            vector.x / len,
            vector.y / len
        };
    }

    if constexpr (D == 3)
    {
        return
        {
            vector.x / len,
            vector.y / len,
            vector.z / len
        };
    }

    if constexpr (D == 4)
    {
        return
        {
            vector.x / len,
            vector.y / len,
            vector.z / len,
            vector.w / len
        };
    }

    if constexpr (D > 4)
    {
        Vector<D,T> vec;
        for (size_t i = 0; i < D; ++i)
        {
            vec[i] = vector[i] / len;
        }
        return vec;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr T
dot(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return A.x * B.x + A.y * B.y;
    }
    if constexpr (D == 3)
    {
        return A.x * B.x + A.y * B.y + A.z * B.z;
    }
    if constexpr (D == 4)
    {
        return A.x * B.x + A.y * B.y + A.z * B.z + A.w * B.w;
    }
    if constexpr (D > 4)
    {
        T sum {T(0)};
        for (size_t i = 0; i < D; ++i)
        {
            sum += A[i] * B[i];
        }
        return sum;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t AD, size_t BD, typename T>
constexpr auto
cross(const Vector<AD,T>& A, const Vector<BD,T>& B) -> typename std::enable_if_t<(AD<5 && BD<5), decltype(A^B)>
{
    return A ^ B;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr enable_if_floating<T,T>
length(const Vector<D,T>& vector)
{
    const T sum {dot(vector, vector)};

    if (eq(sum, T(0)))
    {
        return T(0);
    }
    else
    {
        return static_cast<T>(std::sqrt(sum));
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr T
lengthSquared(const Vector<D,T>& vector)
{
    return dot(vector, vector);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr enable_if_floating<T,T>
distance(const Vector<D,T>& A, const Vector<D,T>& B)
{
    return length(A-B);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr enable_if_floating<T,T>
angle(const Vector<D,T>& A, const Vector<D,T>& B)
{
    return std::acos(A | B);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance)
{
    if constexpr (D == 2)
    {
        return  CGM::eq(A.x, B.x, tolerance) &&
                CGM::eq(A.y, B.y, tolerance);
    }
    else if constexpr (D == 3)
    {
        return  CGM::eq(A.x, B.x, tolerance) &&
                CGM::eq(A.y, B.y, tolerance) &&
                CGM::eq(A.z, B.z, tolerance);
    }
    else if constexpr (D == 4)
    {
        return  CGM::eq(A.x, B.x, tolerance) &&
                CGM::eq(A.y, B.y, tolerance) &&
                CGM::eq(A.z, B.z, tolerance) &&
                CGM::eq(A.w, B.w, tolerance);
    }
    else
    {
        for (size_t i = 0; i < D; ++i)
        {
            if (CGM::neq(A[i], B[i], tolerance)) return false;
        }
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance)
{
    if constexpr (D == 2)
    {
        return  CGM::neq(A.x, B.x, tolerance) ||
                CGM::neq(A.y, B.y, tolerance);
    }
    else if constexpr (D == 3)
    {
        return  CGM::neq(A.x, B.x, tolerance) ||
                CGM::neq(A.y, B.y, tolerance) ||
                CGM::neq(A.z, B.z, tolerance);
    }
    else if constexpr (D == 4)
    {
        return  CGM::neq(A.x, B.x, tolerance) ||
                CGM::neq(A.y, B.y, tolerance) ||
                CGM::neq(A.z, B.z, tolerance) ||
                CGM::neq(A.w, B.w, tolerance);
    }
    else
    {
        for (size_t i = 0; i < D; ++i)
        {
            if (CGM::neq(A[i], B[i]), tolerance) return true;
        }
        return false;
    }
}

CGM_NAMESPACE_END