

#include <Math3D/Core/Functions/Vector.hpp>


MATH3D_NAMESPACE_BEGIN

template<size_t D, typename T>
constexpr enable_if_floating<T, bool>
normalize(Vector<D,T>& vector, T lengthTolerance)
{
    T len {length<T>(vector)};

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
normalized(const Vector<D,T>& vector, bool& success, T lengthTolerance)
{
    T len {length<T>(vector)};

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
constexpr FORCEINLINE enable_if_floating<T, void>
normalizeForce(Vector<D,T>& vector)
{
    T len {length<T>(vector)};

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
constexpr FORCEINLINE enable_if_floating<T, Vector<D,T>>
normalizedForce(const Vector<D,T>& vector)
{
    T len {length<T>(vector)};

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
        T sum {zero<T>};
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

template<typename TResult, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
length(const Vector<D,T>& vector)
{
    TResult sum {dot(vector, vector)};
    TResult zer {zero<TResult>};

    if (equal(sum,zer))
    {
        return zer;
    }
    else
    {
        return static_cast<TResult>(sqrt(sum));
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

template<typename TResult, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
distance(const Vector<D,T>& A, const Vector<D,T>& B)
{
    return length<TResult,D,T>(A-B);
}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
angle(const Vector<D,T>& A, const Vector<D,T>& B)
{
    return std::acos(A | B);
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
equal(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance)
{
    if constexpr (D == 2)
    {
        return  MATH3D_NAMESPACE::equal(A.x, B.x, tolerance) &&
                MATH3D_NAMESPACE::equal(A.y, B.y, tolerance);
    }
    else if constexpr (D == 3)
    {
        return  MATH3D_NAMESPACE::equal(A.x, B.x, tolerance) &&
                MATH3D_NAMESPACE::equal(A.y, B.y, tolerance) &&
                MATH3D_NAMESPACE::equal(A.z, B.z, tolerance);
    }
    else if constexpr (D == 4)
    {
        return  MATH3D_NAMESPACE::equal(A.x, B.x, tolerance) &&
                MATH3D_NAMESPACE::equal(A.y, B.y, tolerance) &&
                MATH3D_NAMESPACE::equal(A.z, B.z, tolerance) &&
                MATH3D_NAMESPACE::equal(A.w, B.w, tolerance);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (MATH3D_NAMESPACE::notEqual(A[i], B[i], tolerance)) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
notEqual(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance)
{
    if constexpr (D == 2)
    {
        return  MATH3D_NAMESPACE::notEqual(A.x, B.x, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.y, B.y, tolerance);
    }
    else if constexpr (D == 3)
    {
        return  MATH3D_NAMESPACE::notEqual(A.x, B.x, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.y, B.y, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.z, B.z, tolerance);
    }
    else if constexpr (D == 4)
    {
        return  MATH3D_NAMESPACE::notEqual(A.x, B.x, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.y, B.y, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.z, B.z, tolerance) ||
                MATH3D_NAMESPACE::notEqual(A.w, B.w, tolerance);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (MATH3D_NAMESPACE::notEqual(A[i], B[i]), tolerance) return true;
        return false;
    }
}

MATH3D_NAMESPACE_END