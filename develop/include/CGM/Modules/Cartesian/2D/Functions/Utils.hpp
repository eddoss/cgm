#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Axes.hpp>
#include <CGM/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/2D/ModuleGlobals.hpp>
#include <CGM/detail/Modules/Cartesian/2D/InternalUtils.hpp>


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
/* Basis orientation */
/* ####################################################################################### */

/**
 * Extract 2x2 orientation matrix from 3x3 matrix.
 * @param basis 3x3 matrix to extract from.
 * @returb 2x2 orientation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
orientation(const Matrix<3,3,T>& basis);

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

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/2D/Functions/Utils.hpp>
