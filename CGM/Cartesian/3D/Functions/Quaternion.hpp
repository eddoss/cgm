#pragma once


#include <cmath>
#include <type_traits>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Cartesian/3D/Operators/Quaternion.hpp>
#include <CGM/Core/Functions/Vector.hpp>
#include <CGM/Core/Operators/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/**
 * Calculates dot product of two quaternions.
 * @return The dot product.
 */
template<typename T>
constexpr CGM_FORCEINLINE T
dot(const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Calculates quaternion norm.
 * @return The quaternion norm.
 */
template<typename T>
constexpr T
norm(const Quaternion<T>& quaternion);

/**
 * Make quaternion conjugated.
 * @return The conjugated quaternion.
 */
template<typename T>
constexpr Quaternion<T>&
conjugate(Quaternion<T>& quaternion);

/**
 * Get the conjugate of the quaternion.
 * @return The conjugated quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
conjugated(const Quaternion<T>& quaternion);

/**
 * Get the length of the quaternion.
 * @return The length of this quaternion.
 */
template<typename T>
constexpr T
length(const Quaternion<T>& quaternion);

/**
 * Safely normalize quaternion.
 * @param quaternion Quaternion to normalize.
 * @param lengthTolerance If quaternion length less than this parameter, normalization will failed.
 * @return False if normalization failed, true otherwise.
 */
template<typename T>
constexpr bool
normalizeSafe(Quaternion<T>& quaternion, T lengthTolerance=T(0.000001));

/**
 * Safely normalize quaternion.
 * @param quaternion Quaternion to normalize.
 * @param lengthTolerance If quaternion length less than this parameter, normalization will failed.
 * @param success Change this flag false if normalization failed, true otherwise.
 * @return Normalized copy of the quaternion.
 */
template<typename T>
constexpr Quaternion<T>
normalizedSafe(const Quaternion<T>& quaternion, bool& success, T lengthTolerance=T(0.000001));

/**
 * Unsafely normalize quaternion.
 * @param quaternion Quaternion to normalize.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
normalize(Quaternion<T>& quaternion);

/**
 * Unsafely normalize quaternion.
 * @param quaternion Quaternion to normalize.
 * @return Normalized copy of the quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
normalized(const Quaternion<T>& quaternion);

/**
 * Safely calculate inverse quaternion. Change flag to false, if cant calculate.
 * @param normTolerance If quaternion norm less than this parameter, inverting will failed.
 * @param quaternion Quaternion for which it is necessary to calculate the inverse.
 * @return False if cant calculate inverse matrix. true otherwise.
 */
template<typename T>
constexpr bool
invertSafe(Quaternion<T>& quaternion, T normTolerance=T(0.000001));

/**
 * Safely calculate inverse quaternion. Change flag to false, if cant calculate.
 * @param[in] quaternion Quaternion for which it is necessary to calculate the inverse.
 * @param[out] success Set this false if cant calculate inverse quaternion.
 * @return Inverse quaternion if could calculate, trash otherwise.
 */
template<typename T>
constexpr Quaternion<T>
inverseSafe(const Quaternion<T>& quaternion, bool& success, T normTolerance=T(0.000001));

/**
 * Unsafely calculate inverse quaternion.
 * @param[in] quaternion Quaternion to calculate.
 * @param[out] success Set this false if cant calculate inverse quaternion.
 * @return Inverted copy of the quaternion if could calculate, trash otherwise.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
invert(Quaternion<T>& quaternion);

/**
 * Get inverse copy of the quaternion if it is large enough.
 * If it is too small, returns an no changed copy.
 * @return Inverted quaternion.
 */
template<typename T>
constexpr Quaternion<T>
inverse(const Quaternion<T>& quaternion);

/**
 * Orients vector by Quaternion.
 * @param vector Vector to orient.
 * @param quaternion Quaternion to orient by (must be normalized).
 */
template<typename T>
constexpr void
orient(Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Orients vector by Quaternion.
 * @param vector Vector to orient.
 * @param quaternion Quaternion to orient by (must be normalized).
 * @return Oriented vector.
 */
template<typename T>
constexpr Vector<3,T>
oriented(const Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Get angle between two quaternions.
 * @param A First quaternion.
 * @param B Second quaternion.
 * @return Shortest angle between two quaternions.
 */
template<typename T>
constexpr T
angle(const Quaternion<T>& A, const Quaternion<T>& B);

/**
 * Create identity quaternion.
 * @return Identity quaternion.
 */
template<typename T=FLOAT>
constexpr Quaternion<T>
identity();

/**
 * Compare quaternion A and B (floating point based).
 * @param A First quaternion.
 * @param B Second quaternion.
 * @param tolerance Compare tolerance.
 * @return true if A equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
eq(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance);

/**
 * Compare quaternion A and B (floating point based).
 * @param A First quaternion.
 * @param B Second quaternion.
 * @param tolerance Compare tolerance.
 * @return true if A not equal to B, false otherwise.
 */
template<size_t D, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T,bool>
neq(const Quaternion<T>& A, const Quaternion<T>& B, T tolerance);

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include "Quaternion.inl"