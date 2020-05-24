#ifndef MATH3D_CORE_FUNCTIONS_VECTOR_HPP
#define MATH3D_CORE_FUNCTIONS_VECTOR_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>


MATH3D_NAMESPACE_BEGIN

/**
 * Safely normalize vector.
 * @param vector Vector to normalize.
 * @param lengthTolerance If vector length less than this parameter, normalization will failed.
 * @return False if normalization failed, true otherwise.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T, bool>
normalize(Vector<D,T>& vector, T lengthTolerance=T(0.000001));

/**
 * Safely normalize vector.
 * @param vector Vector to normalize.
 * @param lengthTolerance If vector length less than this parameter, normalization will failed.
 * @param success Change this flag false if normalization failed, true otherwise.
 * @return Normalized copy of the vector.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T, Vector<D,T>>
normalized(const Vector<D,T>& vector, bool& success, T lengthTolerance=T(0.000001));

/**
 * Unsafely normalize vector.
 * @param vector Vector to normalize.
 */
template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T, void>
normalizeForce(Vector<D,T>& vector);

/**
 * Unsafely normalize vector.
 * @param vector Vector to normalize.
 * @return Normalized copy of the vector.
 */
template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T, Vector<D,T>>
normalizedForce(const Vector<D,T>& vector);

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

/**
 * Compare vector A and B (floating point based).
 * @param A First vector.
 * @param B Second vector.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
equal(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance);

/**
 * Compare vector A and B (floating point based).
 * @param A First vector.
 * @param B Second vector.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr FORCEINLINE enable_if_floating<T,bool>
notEqual(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance);

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Functions/Vector.hpp>


#endif // MATH3D_CORE_FUNCTIONS_VECTOR_HPP
