#ifndef MATH3D_XYZ_FUNCTIONS_UTILS_HPP
#define MATH3D_XYZ_FUNCTIONS_UTILS_HPP


#include <tuple>
#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Cartesian/Enums.hpp>
#include <private/Math3D/Cartesian/3D/InternalUtils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Gets basis X axis.
 * @param basis Basis to extract axis from.
 * @return X axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getX(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param orientation Quaternion that orients space.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getX(const Quaternion<T>& orientation);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getY(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param orientation Quaternion that orients space.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getY(const Quaternion<T>& orientation);

/**
 * Gets basis Z axis.
 * @param basis Basis to extract axis from.
 * @return Z axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getZ(const Matrix<S,S,T>& basis);

/**
 * Gets basis Z axis.
 * @param orientation Quaternion that orients space.
 * @return Z axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getZ(const Quaternion<T>& orientation);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/* ####################################################################################### */
/* Up, Right, Forward axes */
/* ####################################################################################### */

/**
 * Gets basis Up axis.
 * @param basis Basis to extract axis from.
 * @return Up axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getUp(const Matrix<S,S,T>& basis);

/**
 * Gets basis Up axis.
 * @param orientation Quaternion that orients space.
 * @return Up axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getUp(const Quaternion<T>& orientation);

/**
 * Gets basis Right axis.
 * @param basis Basis to extract axis from.
 * @return Right axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getRight(const Matrix<S,S,T>& basis);

/**
 * Gets basis Right axis.
 * @param orientation Quaternion that orients space.
 * @return Right axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getRight(const Quaternion<T>& orientation);

/**
 * Gets basis Forward axis.
 * @param basis Basis to extract axis from.
 * @return Forward axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getForward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Forward axis.
 * @param orientation Quaternion that orients space.
 * @return Forward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getForward(const Quaternion<T>& orientation);

/**
 * Gets basis Down axis.
 * @param basis Basis to extract axis from.
 * @return Down axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getDown(const Matrix<S,S,T>& basis);

/**
 * Gets basis Down axis.
 * @param orientation Quaternion that orients space.
 * @return Down axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getDown(const Quaternion<T>& orientation);

/**
 * Gets basis Left axis.
 * @param basis Basis to extract axis from.
 * @return Left axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getLeft(const Matrix<S,S,T>& basis);

/**
 * Gets basis Left axis.
 * @param orientation Quaternion that orients space.
 * @return Left axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getLeft(const Quaternion<T>& orientation);

/**
 * Gets basis Backward axis.
 * @param basis Basis to extract axis from.
 * @return Backward axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getBackward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Backward axis.
 * @param orientation Quaternion that orients space.
 * @return Backward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getBackward(const Quaternion<T>& orientation);

/**
 * Set basis Up axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
getPosition(const Matrix<4,4,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position);

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

/**
 * Extract 3x3 orientation matrix from 4x4 matrix.
 * @param basis Basis to extract from.
 * @returb 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
getOrientation(const Matrix<4,4,T>& basis);

/**
 * Set orientation axes to basis (3x3 matrix).
 * @param orientation 3x3 orientation to set to.
 * @param x X orientation axis.
 * @param y Y orientation axis.
 * @param z Z orientation axis.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& orientation, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Set orientation axes to basis (4x4 matrix).
 * @param basis Basis to set to.
 * @param x X orientation axis.
 * @param y Y orientation axis.
 * @param z Z orientation axis.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Set 3x3 orientation matrix to 4x4 matrix.
 * @param basis Basis to set to.
 * @param orientation 3x3 orientation matrix.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<3,3,T>& orientation);

/**
 * Set 3x3 orientation matrix to 4x4 matrix.
 * @param basis Basis to set to.
 * @param orientation Orientation quaternion.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Quaternion<T>& orientation);

/**
 * Extracts 3x3 orientation matrix from 'other' and set it to 'basis'.
 * @param basis Basis to set orientation to.
 * @param other Basis to extract orientation from.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<4,4,T>& other);

/* ####################################################################################### */
/* Orientation to axes */
/* ####################################################################################### */

/**
 * Extract X,Y,Z axes from orientation matrix.
 * @param orientation 3x3 orientation matrix to extract from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<3,3,T>& orientation);

/**
 * Extract X,Y,Z axes from orientation quaternion.
 * @param orientation Orientation quaternion to extract from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Quaternion<T>& orientation);

/**
 * Extract X,Y,Z axes from space.
 * @param space Space to extract from.
 * @return Tuple of axes.
 */
template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<4,4,T>& space);

/* ####################################################################################### */
/* Orientation converters */
/* ####################################################################################### */

/**
 * Convert orientation quaternion to 3x3 orientation matrix.
 * @param quaternion Quaternion to convert.
 * @return 3x3 orientation matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& quaternion);

/**
 * Convert orientation axes to 3x3 orientation matrix.
 * @param x X orientation axes.
 * @param y Y orientation axes.
 * @param z Z orientation axes.
 * @return Orientation matrix.
 */
template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Convert 3x3 orientation matrix to orientation quaternion.
 * @param orientation Orientation matrix to convert from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& orientation);

/**
 * Extract 3x3 orientation matrix and convert it to orientation quaternion.
 * @param space 4x4 space matrix to extract from.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& space);

/**
 * Convert orientation axes to orientation quaternion.
 * @param x X orientation axes.
 * @param y Y orientation axes.
 * @param z Z orientation axes.
 * @return Orientation quaternion.
 */
template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z);

/* ####################################################################################### */
/* Space creators */
/* ####################################################################################### */

/**
 * Creates 3D space from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @param position Basis position.
 * @return 3D space represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

/**
 * Creates 3D space from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Creates 3D space from Quaternion and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D Space represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
space(const Quaternion<T>& orientation, const Vector<3,T>& position);

/**
 * Unpack 4x4 matrix to X,Y,Z axes and position.
 * @param matrix Matrix to unpack.
 * @return Tuple of space orientation axes and space position.
 */
template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>
unpackSpace(const Matrix<4,4,T>& matrix);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Utils.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_UTILS_HPP
