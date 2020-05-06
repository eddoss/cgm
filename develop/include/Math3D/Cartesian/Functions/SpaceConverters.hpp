#ifndef MATH3D_XYZ_FUNCTIONS_HPP
#define MATH3D_XYZ_FUNCTIONS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Local to world */
/* ####################################################################################### */

/**
 * Converts 2D vector from local space to world space.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToWorld(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace);

/**
 * Converts 2D vector from local space to world space.
 * @param vector Vector in local space.
 * @@param localSpace Local space represented as 3x3 matrix.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToWorld(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Converts 3D vector from local space to world space.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Converts 3D vector from local space to world space.
 * @param vector Vector in local space.
 * @param localSpace Local space represented as 4x4 matrix.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace);

/**
 * Converts 3D vector from local space to world space.
 * @param vector Vector in local space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation);

/**
 * Converts 3D vector from local space to world space.
 * @param vector Vector in local space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @tparam localSpacePosition Position of local space.
 * @return converted to world space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition);

/* ####################################################################################### */
/* World to local */
/* ####################################################################################### */

/**
 * Converts 2D vector from world space to local space.
 * @param vector Vector in world space.
 * @param localSpace Local space represented as 2x2 matrix.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace);

/**
 * Converts 2D vector from world space to local space.
 * @param vector Vector in world space.
 * @@param localSpace Local space represented as 3x3 matrix.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Converts 3D vector from world space to local space.
 * @param vector Vector in world space.
 * @param localSpace Local space represented as 3x3 matrix.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace);

/**
 * Converts 3D vector from world space to local space.
 * @param vector Vector in world space.
 * @param localSpace Local space represented as 4x4 matrix.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace);

/**
 * Converts 3D vector from world space to local space.
 * @param vector Vector in world space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation);

/**
 * Converts 3D vector from world space to local space.
 * @param vector Vector in world space.
 * @param localSpaceOrientation Quaternion that orients local space.
 * @tparam localSpacePosition Position of local space.
 * @return converted to local space vector.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XYZ_FUNCTIONS_HPP
