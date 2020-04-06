#ifndef MATH3D_QUATERNION_FUNCTIONS_HPP
#define MATH3D_QUATERNION_FUNCTIONS_HPP


#include <cmath>
#include <type_traits>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Quaternion/Operators.hpp>


MATH3D_NAMESPACE_BEGIN

/**
 * Calculates dot product of two quaternions.
 * @return The dot product.
 */
template<typename T>
constexpr T
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
constexpr Quaternion<T>
conjugated(const Quaternion<T>& quaternion);

/**
 * Get the length of the quaternion.
 * @return The length of this quaternion.
 */
template<typename T>
constexpr T
length(const Quaternion<T>& quaternion);

/**
 * Normalize the quaternion if it is large enough.
 * If it is too small, returns an no changed quaternion.
 */
template<typename T>
constexpr Quaternion<T>&
normalize(Quaternion<T>& quaternion);

/**
 * Return normalized copy of the quaternion if it is large enough.
 * If it is too small, returns an no changed copy.
 * @return normalized quternion.
 */
template<typename T>
constexpr Quaternion<T>
normalized(const Quaternion<T>& quaternion);

/**
 * Invert the quaternion if it is large enough.
 * If it is too small, returns an no changed quaternion.
 * @return Inverted quaternion.
 */
template<typename T>
constexpr Quaternion<T>&
invert(Quaternion<T>& quaternion);

/**
 * Get inverted copy of the quaternion if it is large enough.
 * If it is too small, returns an no changed copy.
 * @return Inverted quaternion.
 */
template<typename T>
constexpr Quaternion<T>
inverted(const Quaternion<T>& quaternion);

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

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Quaternion/Functions.hpp>


#endif // MATH3D_QUATERNION_FUNCTIONS_HPP
