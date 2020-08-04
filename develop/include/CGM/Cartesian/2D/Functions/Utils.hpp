#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Core/Vector.hpp>
#include <CGM/Core/Matrix.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>
#include <CGM/Cartesian/2D/Types/Enums.hpp>
#include <CGM/Cartesian/2D/Types/Typedefs.hpp>
#include <private/CGM/Cartesian/2D/InternalUtils.hpp>


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
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
x(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param axes Axes tuple to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
x(const AxesTuple<T>& axes);

/**
 * Gets basis X axis.
 * @param space Space tuple to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
x(const SpaceTuple<T>& axes);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
y(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param axes Axes tuple to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
y(const AxesTuple<T>& axes);

/**
 * Gets basis Y axis.
 * @param space Space tuple to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
y(const SpaceTuple<T>& axes);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set basis X axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setX(AxesTuple<T>& axes, const Vector<2,T>& value);

/**
 * Set basis X axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setX(SpaceTuple<T>& space, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setY(AxesTuple<T>& axes, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setY(SpaceTuple<T>& space, const Vector<2,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
position(const Matrix<3,3,T>& basis);

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
position(const SpaceTuple<T>& space);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(SpaceTuple<T>& space, const Vector<2,T>& position);

/* ####################################################################################### */
/* Basis orientation */
/* ####################################################################################### */

/**
 * Extract 2x2 orientation matrix from 3x3 matrix.
 * @param basis 3x3 matrix to extract from.
 * @returb 2x2 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
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
setOrientation(Matrix<3,3,T>& basis, const AxesTuple<T>& axes);

/**
 * Extracts orientation axes and set it to 'basis'.
 * @param basis Basis to set orientation to.
 * @param space Space tuple to extract orientation axes from.
 */
template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& basis, const SpaceTuple<T>& space);

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <private/CGM/Cartesian/2D/Functions/Utils.hpp>
