#ifndef MATH3D_VECTOR_FUNCTIONS_HPP
#define MATH3D_VECTOR_FUNCTIONS_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Vector/Operators.hpp>


/**
 * Normalize vectors. If given vector length equal to zero,
 * return given vector, normalized otherwise.
 * @param vector Vector to normalize.
 * @return Normalized vector.
 */
template<size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<T>, Vector<D,T>&>
normalize(Vector<D,T>& vector);

/**
 * Get normalized copy of vector. For more details see normalize().
 * @param vector Vector to normalize.
 * @tparam TResult Type of result. It must be float or double.
 * @return Normalized vector.
 */
template<typename TResult=FLOAT, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, Vector<D,TResult>>
normalized(const Vector<D,T>& vector);

/**
 * Calculates dot product of two vectors.
 * @param A First vector.
 * @param B Second vector.
 * @tparam TResult Type of result. It must be float or double.
 * @return Dot product of A and B.
 */
template<size_t D, typename T>
constexpr T
dot(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates cross product of two vectors.
 * @param A First vector.
 * @param B Second vector.
 * @tparam TResult Type of result. It must be float or double.
 * @return Cross product of A and B.
 */
template<size_t AD, size_t BD, typename T>
constexpr auto
cross(const Vector<AD,T>& A, const Vector<BD,T>& B) -> typename std::enable_if_t<(AD<5 && BD<5), decltype(A^B)>;

/**
 * Calculates vector length.
 * @param vector Vector to calculate.
 * @tparam TResult Type of result. It must be float or double.
 * @return Vector length.
 */
template<typename TResult=FLOAT, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
length(const Vector<D,T>& vector);

/**
 * Calculates vector squared length.
 * @param vector Vector to calculate.
 * @return Vector length.
 */
template<size_t D, typename T>
constexpr T
lengthSquared(const Vector<D,T>& vector);

/**
 * Calculates distance between two vectors.
 * @param A First vector.
 * @param B Second vector.
 * @tparam TResult Type of result. It must be float or double.
 * @return Distance between A and B.
 */
template<typename TResult=FLOAT, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
distance(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates angle between two vectors (in radians).
 * @param A First vector.
 * @param B Second vector.
 * @tparam TResult Type of result. It must be float or double.
 * @return Angle between A and B.
 */
template<typename TResult=FLOAT, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, TResult>
angle(const Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<T>, Vector<D,T>&>
normalize(Vector<D,T>& vector)
{
    T len {length<T>(vector)};

    if (equal(len, zero<T>())) return vector;

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

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<typename TResult, size_t D, typename T>
constexpr typename std::enable_if_t<std::is_floating_point_v<TResult>, Vector<D,TResult>>
normalized(const Vector<D,T>& vector)
{
    T len {length<T>(vector)};

    if (equal(len, zero<T>())) return vector;

    if constexpr (D == 2)
    {
        return Vector<D,T>
        {
            vector.x/len,
            vector.y/len
        };
    }

    if constexpr (D == 3)
    {
        return Vector<D,T>
        {
            vector.x/len,
            vector.y/len,
            vector.z/len
        };
    }

    if constexpr (D == 4)
    {
        return Vector<D,T>
        {
            vector.x/len,
            vector.y/len,
            vector.z/len,
            vector.w/len
        };
    }

    if constexpr (D > 4)
    {
        Vector<D,T> vec;
        for (size_t i = 0; i < D; ++i)
        {
            vec[i] = vector[i]/len;
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
        T sum {zero<T>()};
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
    TResult zer {zero<TResult>()};

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

#endif // MATH3D_VECTOR_FUNCTIONS_HPP
