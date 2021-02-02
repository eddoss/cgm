#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Cartesian/Common.hpp>
#include <CGM/Cartesian/2D/Types/Axes.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>
#include <CGM/Utils/TypeTraits.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

/**
 * Gets basis X axis.
 * @param basis Basis to extract axis from.
 * @return X axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
x(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param axes Axes tuple to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
x(const Axes<T>& axes);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
y(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param axes Axes tuple to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
y(const Axes<T>& axes);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set basis X axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setX(Axes<T>& axes, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setY(Axes<T>& axes, const Vector<2,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
position(const Matrix<3,3,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position);

/* ####################################################################################### */
/* Setup all */
/* ####################################################################################### */

/**
 * Set X,Y axes to 2x2 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param x X axis.
 * @param y Y axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<2,2,T>& matrix, const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Set X,Y axes to 2x2 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param axes Axes to set.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<2,2,T>& matrix, const Axes<T>& axes);

/**
 * Set X,Y axes and position to 3x3 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param x X axis.
 * @param y Y axis.
 * @param position Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Set X,Y axes and position to 3x3 orientation matrix.
 * @param matrix Matrix to set axes to.
 * @param axes Axes to set.
 * @param position Basis position.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
set(Matrix<3,3,T>& matrix, const Axes<T>& axes, const Vector<2,T>& position);

/* ####################################################################################### */
/* Basis orientation */
/* ####################################################################################### */

/**
 * Set orientation axes to basis (3x3 matrix).
 * @param basis Basis to set to.
 * @param x X orientation axis.
 * @param y Y orientation axis.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Vector<2,T>& x, const Vector<2,T>& y);

/**
 * Set 2x2 orientation matrix to 3x3 matrix.
 * @param basis Basis to set to.
 * @param orientation 2x2 orientation matrix.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Matrix<2,2,T>& orientation);

/**
 * Extracts 2x2 orientation matrix from 'other' and set it to 'basis'.
 * @param basis Basis to set orientation to.
 * @param other Basis to extract orientation from.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Matrix<3,3,T>& other);

/**
 * Set orientation axes to basis (3x3 matrix).
 * @param basis Basis to set to.
 * @param axes Orientation axes.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const Axes<T>& axes);

/**
 * Creates 2D space matrix from axes and position.
 * @param x Basis X axis.
 * @param y Basis Y axis.
 * @param position Basis position.
 * @return 2D space represented by 3x3 matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
spaceMatrix(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position);

/**
 * Creates 2D space matrix from orientation matrix and position.
 * @param orientation Space orientation.
 * @param position Space position.
 * @return 2D space represented by 3x3 matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
spaceMatrix(const Matrix<2,2,T>& orientation, const Vector<2,T>& position);

/**
 * Unpack 3x3 space matrix.
 * @param space 3x3 space matrix.
 * @return tuple of X, Y axes and position of space.
 */
template<typename T>
constexpr std::tuple<Vector<2,T>, Vector<2,T>, Vector<2,T>>
unpackSpace(const Matrix<3,3,T>& space);

/* ####################################################################################### */
/* 3x3 orientation manipulations */
/* ####################################################################################### */

/**
 * Transpose orientation of 3x3 basis matrix.
 * @param basis Matrix to transpose.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
transposeOrientation(Matrix<3,3,T>& basis);

/**
 * Transpose orientation of 3x3 basis matrix.
 * @param basis Matrix to transpose.
 * @return Transposed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
transposedOrientation(const Matrix<3,3,T>& basis);

/**
 * Safely invert orientation of 3x3 basis matrix.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr enable_if_floating<T, bool>
invertOrientationSafe(Matrix<3,3,T>& basis, T determinantTolerance=T(0.000001));

/**
 * Safely calculates inverse orientation of 3x3 basis matrix.
 * @param[in] basis Matrix to invert.
 * @param[out] success Set this false if cant calculate inverse matrix.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
inverseOrientationSafe(const Matrix<3,3,T>& basis, bool& success, T determinantTolerance=T(0.000001));

/**
 * Unsafely invert orientation of 3x3 basis matrix. Does not check the determinants for equality to 0.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr enable_if_floating<T, void>
invertOrientation(Matrix<3,3,T>& basis);

/**
 * Unsafely calculates inverse orientation of 3x3 basis matrix. Does not check the determinants for
 * equality to 0.
 * @param basis Matrix to invert.
 * @param determinantTolerance If determinant less than this parameter, inverting will failed.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
inverseOrientation(const Matrix<3,3,T>& basis);

/* ####################################################################################### */
/* Multiplication */
/* ####################################################################################### */

/**
 * Multiplies 2D row-vector by 3x3 matrix.
 * @tparam Representation How to represent input vector. If its 'Point'
 * given vector will be represented as Vector3D(x,y,1), and Vector3D(x,y,0)
 * otherwise.
 * @param vector Vector to multiply.
 * @param matrix Matrix to multiply by.
 * @return Result vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply(const Vector<2,T>& vector, const Matrix<3,3,T>& matrix);

/**
 * Multiplies 3x3 matrix by 2D column-vector.
 * @tparam Representation How to represent input vector. If its 'Point'
 * given vector will be represented as Vector3D(x,y,1), and Vector3D(x,y,0)
 * otherwise.
 * @param vector Vector to multiply.
 * @param matrix Matrix to multiply by.
 * @return Result vector.
 */
template<EVectorRepresentation Representation=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply(const Matrix<3,3,T>& matrix, const Vector<2,T>& vector);

/**
 * Represents 2x2 matrix as not translated basis and multiplies it by 3x3 matrix.
 * @tparam N Size of result matrix.
 * @param A Matrix to multiply.
 * @param B Matrix to multiply by.
 * @return Result matrix.
 */
template<size_t N, typename T>
constexpr std::enable_if_t<(N == 2 || N == 3), Matrix<N,N,T>>
multiply(const Matrix<2,2,T>& A, const Matrix<3,3,T>& B);

/**
 * Multiplies 2x2 matrix by 3x3 matrix (2x2 matrix represents as not translated basis).
 * @tparam N Size of result matrix.
 * @param A Matrix to multiply.
 * @param B Matrix to multiply by.
 * @return Result matrix.
 */
template<size_t N, typename T>
constexpr std::enable_if_t<(N == 2 || N == 3), Matrix<N,N,T>>
multiply(const Matrix<3,3,T>& A, const Matrix<2,2,T>& B);

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include "Utils.inl"
