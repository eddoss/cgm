#pragma once


#include <cmath>
#include <type_traits>
#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>


CGM_NAMESPACE_BEGIN

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
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
normalizeForce(Vector<D,T>& vector);

/**
 * Unsafely normalize vector.
 * @param vector Vector to normalize.
 * @return Normalized copy of the vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<D,T>>
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
 * Convert given values from degrees to radians and pack them to 2D vector.
 * @param x Value for X component.
 * @param y Value for Y component.
 * @return Vector of radians.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<2,T>>
radians(T x, T y);

/**
 * Convert given values from degrees to radians and pack them to 3D vector.
 * @param x Value for X component.
 * @param y Value for Y component.
 * @param z Value for Z component.
 * @return Vector of radians.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<3,T>>
radians(T x, T y, T z);

/**
 * Convert vector of degrees to vector of radians.
 * @param angles Vector of degrees.
 * @return Vector of radians.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
radians(const Vector<D,T>& angles);

/**
 * Convert given values from radians to degrees and pack them to 2D vector.
 * @param x Value for X component.
 * @param y Value for Y component.
 * @return Vector of degrees.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<2,T>>
degrees(T x, T y);

/**
 * Convert given values from radians to degrees and pack them to 3D vector.
 * @param x Value for X component.
 * @param y Value for Y component.
 * @param z Value for Z component.
 * @return Vector of degrees.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<3,T>>
degrees(T x, T y, T z);

/**
 * Convert vector of radians to vector of degrees.
 * @param angles Vector of radians.
 * @return Vector of degrees.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,Vector<D,T>>
degrees(const Vector<D,T>& angles);

/**
 * Compare vector A and B (floating point based).
 * @param A First vector.
 * @param B Second vector.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance);

/**
 * Compare vector A and B (floating point based).
 * @param A First vector.
 * @param B Second vector.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Vector<D,T>& A, const Vector<D,T>& B, T tolerance);

CGM_NAMESPACE_END


#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
