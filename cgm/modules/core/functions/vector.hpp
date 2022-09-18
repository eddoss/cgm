#pragma once


#include <cmath>
#include <cgm/modules/core/module_globals.hpp>
#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN

/**
 * Safely normalize vector.
 * @param vector Vector to normalize.
 * @param lengthTolerance If vector length less than this parameter, normalization will failed.
 * @return False if normalization failed, true otherwise.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T, bool>
normalizeSafe(Vector<D,T>& vector, T lengthTolerance=T(0.000001));

/**
 * Safely normalize vector.
 * @param vector Vector to normalize.
 * @param lengthTolerance If vector length less than this parameter, normalization will failed.
 * @param success Change this flag false if normalization failed, true otherwise.
 * @return Normalized copy of the vector.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T, Vector<D,T>>
normalizedSafe(const Vector<D,T>& vector, bool& success, T lengthTolerance=T(0.000001));

/**
 * Unsafely normalize vector.
 * @param vector Vector to normalize.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
normalize(Vector<D,T>& vector);

/**
 * Unsafely normalize vector.
 * @param vector Vector to normalize.
 * @return Normalized copy of the vector.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<D,T>>
normalized(const Vector<D,T>& vector);

/**
 * Calculates dot product of two vectors.
 * @param A First vector.
 * @param B Second vector.
 * @return Dot product of A and B.
 */
template<size_t D, typename T>
constexpr T
dot(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates cross product of two vectors.
 * @param A First vector.
 * @param B Second vector.
 * @return Cross product of A and B.
 */
template<size_t AD, size_t BD, typename T>
constexpr auto
cross(const Vector<AD,T>& A, const Vector<BD,T>& B) -> typename std::enable_if_t<(AD<5 && BD<5), decltype(A^B)>;

/**
 * Calculates floating vector length.
 * @param vector Vector to calculate.
 * @return Vector length.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T,T>
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
 * @return Distance between A and B.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T,T>
distance(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates angle between two floating/double vectors (in radians).
 * @param A First vector.
 * @param B Second vector.
 * @return Angle between A and B.
 */
template<size_t D, typename T>
constexpr enable_if_floating<T,T>
angle(const Vector<D,T>& A, const Vector<D,T>& B);

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


#include "vector.inl"
