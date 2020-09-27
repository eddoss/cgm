#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Core/Types/Matrix.hpp>
#include <CGM/detail/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/detail/Cartesian/3D/Functions/Quaternion.hpp>
#include <CGM/detail/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/detail/Cartesian/3D/Types/Axes.hpp>
#include <CGM/detail/Cartesian/3D/Types/Enums.hpp>
#include <CGM/detail/Cartesian/3D/InternalUtils_impl.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

/**
 * Gets basis X axis.
 * @param basis Basis to extract axis from.
 * @return X axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
x(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param axes Axes struct to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
x(const Axes<T>& axes);

/**
 * Gets basis X axis.
 * @param orientation Quaternion that orients space.
 * @return X axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
x(const Quaternion<T>& orientation);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
y(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param axes Axes struct to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
y(const Axes<T>& axes);

/**
 * Gets basis Y axis.
 * @param orientation Quaternion that orients space.
 * @return Y axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
y(const Quaternion<T>& orientation);

/**
 * Gets basis Z axis.
 * @param basis Basis to extract axis from.
 * @return Z axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
z(const Matrix<S,S,T>& basis);

/**
 * Gets basis Z axis.
 * @param axes Axes struct to extract from.
 * @return Z axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
z(const Axes<T>& axes);

/**
 * Gets basis Z axis.
 * @param orientation Quaternion that orients space.
 * @return Z axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
z(const Quaternion<T>& orientation);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis X axis.
 * @param axes Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setX(Axes<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param axes Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setY(Axes<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param space Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setZ(Axes<T>& axes, const Vector<3,T>& value);

/* ####################################################################################### */
/* Up, Right, Forward axes */
/* ####################################################################################### */

/**
 * Gets basis Up axis.
 * @param basis Basis to extract axis from.
 * @return Up axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
up(const Matrix<S,S,T>& basis);

/**
 * Gets basis Up axis.
 * @param orientation Quaternion that orients space.
 * @return Up axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Quaternion<T>& orientation);

/**
 * Gets basis Up axis.
 * @param axes Axes struct to extract axis from.
 * @return Up axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
up(const Axes<T>& axes);

/**
 * Gets basis Right axis.
 * @param basis Basis to extract axis from.
 * @return Right axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
right(const Matrix<S,S,T>& basis);

/**
 * Gets basis Right axis.
 * @param orientation Quaternion that orients space.
 * @return Right axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Quaternion<T>& orientation);

/**
 * Gets basis Right axis.
 * @param axes Axes struct to extract axis from.
 * @return Right axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
right(const Axes<T>& axes);

/**
 * Gets basis Forward axis.
 * @param basis Basis to extract axis from.
 * @return Forward axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
forward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Forward axis.
 * @param orientation Quaternion that orients space.
 * @return Forward axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Quaternion<T>& orientation);

/**
 * Gets basis Forward axis.
 * @param axes Axes struct to extract axis from.
 * @return Forward axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
forward(const Axes<T>& axes);

/* ####################################################################################### */
/* Down, Left, backward axes */
/* ####################################################################################### */

/**
 * Gets basis Down axis.
 * @param basis Basis to extract axis from.
 * @return Down axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
down(const Matrix<S,S,T>& basis);

/**
 * Gets basis Down axis.
 * @param orientation Quaternion that orients space.
 * @return Down axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
down(const Quaternion<T>& orientation);

/**
 * Gets basis Down axis.
 * @param axes Axes struct to extract axis from.
 * @return Down axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
down(const Axes<T>& axes);

/**
 * Gets basis Left axis.
 * @param basis Basis to extract axis from.
 * @return Left axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
left(const Matrix<S,S,T>& basis);

/**
 * Gets basis Left axis.
 * @param orientation Quaternion that orients space.
 * @return Left axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
left(const Quaternion<T>& orientation);

/**
 * Gets basis Left axis.
 * @param axes Axes struct to extract axis from.
 * @return Left axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
left(const Axes<T>& axes);

/**
 * Gets basis Backward axis.
 * @param basis Basis to extract axis from.
 * @return Backward axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
backward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Backward axis.
 * @param orientation Quaternion that orients space.
 * @return Backward axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
backward(const Quaternion<T>& orientation);

/**
 * Gets basis Backward axis.
 * @param axes Axes struct to extract axis from.
 * @return Backward axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
backward(const Axes<T>& axes);

/**
 * Set basis Up axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Up axis.
 * @param axes Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setUp(Axes<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param axes Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setRight(Axes<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param axes Axes struct to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
setForward(Axes<T>& axes, const Vector<3,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
position(const Matrix<4,4,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position);

/* ####################################################################################### */
/* Basis orientation */
/* ####################################################################################### */

/**
 * Set orientation axes to basis (4x4 matrix).
 * @param basis Basis to set to.
 * @param x X orientation axis.
 * @param y Y orientation axis.
 * @param z Z orientation axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Set orientation axes to basis (4x4 matrix).
 * @param basis Basis to set to.
 * @param axes Orientation axes to set.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Axes<T>& axes);

/**
 * Set 3x3 orientation matrix to 4x4 matrix.
 * @param basis Basis to set to.
 * @param orientation 3x3 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Matrix<3,3,T>& orientation);

/**
 * Set 3x3 orientation matrix to 4x4 matrix.
 * @param basis Basis to set to.
 * @param orientation Orientation quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Quaternion<T>& orientation);

/**
 * Extracts 3x3 orientation matrix from 'other' and set it to 'basis'.
 * @param basis Basis to set orientation to.
 * @param other Basis to extract orientation from.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Matrix<4,4,T>& other);

/* ####################################################################################### */
/* Setup all */
/* ####################################################################################### */

/**
 * Set X,Y,Z axes to 3x3 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param x X axis.
 * @param y Y axis.
 * @param z Z axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

/**
 * Set X,Y,Z axes to 3x3 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param axes Axes to set.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Axes<T>& axes);

/**
 * Set X,Y,Z axes and position to 4x4 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param x X axis.
 * @param y Y axis.
 * @param z Z axis.
 * @param position Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<4,4,T>& matrix, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& position);

/**
 * Set X,Y,Z axes and position to 4x4 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param axes Axes to set.
 * @param position Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<4,4,T>& matrix, const Axes<T>& axes, const Vector<3,T>& position);

/* ####################################################################################### */
/* Space matrix */
/* ####################################################################################### */

/**
 * Creates 3D space matrix from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param z Basis Z axis.
 * @param position Basis position.
 * @return 3D space represented by 4x4 matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

/**
 * Creates 3D space matrix from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D basis represented by 4x4 matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
spaceMatrix(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

/**
 * Creates 3D space matrix from Quaternion and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 3D Space represented by 4x4 matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
spaceMatrix(const Quaternion<T>& orientation, const Vector<3,T>& position);

/**
 * Unpack 4x4 space matrix.
 * @param space 4x4 space matrix.
 * @return tuple of X, Y, Z axes and position of space.
 */
template<typename T>
constexpr std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>
unpackSpace(const Matrix<4,4,T>& space);

/* ####################################################################################### */
/* 4x4 orientation manipulations */
/* ####################################################################################### */

/**
 * Transpose orientation of 4x4 basis matrix.
 * @param basis Matrix to transpose.
 */
template<typename T>
constexpr void
transposeOrientation(Matrix<4,4,T>& basis);

/**
 * Transpose orientation of 4x4 basis matrix.
 * @param basis Matrix to transpose.
 * @return Transposed matrix.
 */
template<typename T>
constexpr Matrix<4,4,T>
transposedOrientation(const Matrix<4,4,T>& basis);

/**
 * Safely invert orientation of 4x4 basis matrix.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr bool
invertOrientation(Matrix<4,4,T>& basis, T determinantTolerance=T(0.000001));

/**
 * Safely calculates inverse orientation of 4x4 basis matrix.
 * @param[in] basis Matrix to invert.
 * @param[out] success Set this false if cant calculate inverse matrix.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr Matrix<4,4,T>
inverseOrientation(const Matrix<4,4,T>& basis, bool& success, T determinantTolerance=T(0.000001));

/**
 * Unsafely invert orientation of 4x4 basis matrix. Does not check the determinants for equality to 0.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr void
invertOrientationForce(Matrix<4,4,T>& basis);

/**
 * Unsafely calculates inverse orientation of 4x4 basis matrix. Does not check the determinants for
 * equality to 0.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr Matrix<4,4,T>
inverseOrientationForce(const Matrix<4,4,T>& basis);

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Cartesian/3D/Functions/Utils_impl.hpp>