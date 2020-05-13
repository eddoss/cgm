#ifndef MATH3D_VECTOR_FUNCTIONS_HPP
#define MATH3D_VECTOR_FUNCTIONS_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


MATH3D_NAMESPACE_BEGIN

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

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Functions/Vector.hpp>


#endif // MATH3D_VECTOR_FUNCTIONS_HPP
