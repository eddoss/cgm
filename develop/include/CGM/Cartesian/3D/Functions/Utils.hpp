#pragma once


#include <tuple>
#include <type_traits>
#include <CGM/Core/Vector.hpp>
#include <CGM/Core/Matrix.hpp>
#include <CGM/Core/Quaternion.hpp>
#include <CGM/Core/Functions/Quaternion.hpp>
#include <CGM/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Cartesian/3D/Types/Typedefs.hpp>
#include <private/CGM/Cartesian/3D/InternalUtils.hpp>


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
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
x(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param axes Axes tuple to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
x(const AxesTuple<T>& axes);

/**
 * Gets basis X axis.
 * @param space Space tuple to extract from.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
x(const SpaceTuple<T>& space);

/**
 * Gets basis X axis.
 * @param orientation Quaternion that orients space.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
x(const Quaternion<T>& orientation);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
y(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param axes Axes tuple to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
y(const AxesTuple<T>& axes);

/**
 * Gets basis Y axis.
 * @param space Space tuple to extract from.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
y(const SpaceTuple<T>& space);

/**
 * Gets basis Y axis.
 * @param orientation Quaternion that orients space.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
y(const Quaternion<T>& orientation);

/**
 * Gets basis Z axis.
 * @param basis Basis to extract axis from.
 * @return Z axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
z(const Matrix<S,S,T>& basis);

/**
 * Gets basis Z axis.
 * @param axes Axes tuple to extract from.
 * @return Z axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
z(const AxesTuple<T>& axes);

/**
 * Gets basis Z axis.
 * @param space Space tuple to extract from.
 * @return Z axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
z(const SpaceTuple<T>& axes);

/**
 * Gets basis Z axis.
 * @param orientation Quaternion that orients space.
 * @return Z axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
z(const Quaternion<T>& orientation);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis X axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setX(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis X axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setX(SpaceTuple<T>& space, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setY(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setY(SpaceTuple<T>& space, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param space Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setZ(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setZ(SpaceTuple<T>& space, const Vector<3,T>& value);

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
up(const Matrix<S,S,T>& basis);

/**
 * Gets basis Up axis.
 * @param orientation Quaternion that orients space.
 * @return Up axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const Quaternion<T>& orientation);

/**
 * Gets basis Up axis.
 * @param axes Axes tuple to extract axis from.
 * @return Up axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const AxesTuple<T>& axes);

/**
 * Gets basis Up axis.
 * @param space Space tuple to extract axis from.
 * @return Up axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
up(const SpaceTuple<T>& space);

/**
 * Gets basis Right axis.
 * @param basis Basis to extract axis from.
 * @return Right axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
right(const Matrix<S,S,T>& basis);

/**
 * Gets basis Right axis.
 * @param orientation Quaternion that orients space.
 * @return Right axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const Quaternion<T>& orientation);

/**
 * Gets basis Right axis.
 * @param axes Axes tuple to extract axis from.
 * @return Right axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const AxesTuple<T>& axes);

/**
 * Gets basis Right axis.
 * @param space Space tuple to extract axis from.
 * @return Right axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
right(const SpaceTuple<T>& space);

/**
 * Gets basis Forward axis.
 * @param basis Basis to extract axis from.
 * @return Forward axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
forward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Forward axis.
 * @param orientation Quaternion that orients space.
 * @return Forward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const Quaternion<T>& orientation);

/**
 * Gets basis Forward axis.
 * @param axes Axes tuple to extract axis from.
 * @return Forward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const AxesTuple<T>& axes);

/**
 * Gets basis Forward axis.
 * @param space Space tuple to extract axis from.
 * @return Forward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
forward(const SpaceTuple<T>& space);

/* ####################################################################################### */
/* Down, Left, backward axes */
/* ####################################################################################### */

/**
 * Gets basis Down axis.
 * @param basis Basis to extract axis from.
 * @return Down axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
down(const Matrix<S,S,T>& basis);

/**
 * Gets basis Down axis.
 * @param orientation Quaternion that orients space.
 * @return Down axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const Quaternion<T>& orientation);

/**
 * Gets basis Down axis.
 * @param axes Axes tuple to extract axis from.
 * @return Down axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const AxesTuple<T>& axes);

/**
 * Gets basis Down axis.
 * @param space Space tuple to extract axis from.
 * @return Down axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
down(const SpaceTuple<T>& space);

/**
 * Gets basis Left axis.
 * @param basis Basis to extract axis from.
 * @return Left axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
left(const Matrix<S,S,T>& basis);

/**
 * Gets basis Left axis.
 * @param orientation Quaternion that orients space.
 * @return Left axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const Quaternion<T>& orientation);

/**
 * Gets basis Left axis.
 * @param axes Axes tuple to extract axis from.
 * @return Left axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const AxesTuple<T>& axes);

/**
 * Gets basis Left axis.
 * @param space Space tuple to extract axis from.
 * @return Left axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
left(const SpaceTuple<T>& space);

/**
 * Gets basis Backward axis.
 * @param basis Basis to extract axis from.
 * @return Backward axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
backward(const Matrix<S,S,T>& basis);

/**
 * Gets basis Backward axis.
 * @param orientation Quaternion that orients space.
 * @return Backward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const Quaternion<T>& orientation);

/**
 * Gets basis Backward axis.
 * @param axes Axes tuple to extract axis from.
 * @return Backward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const AxesTuple<T>& axes);

/**
 * Gets basis Backward axis.
 * @param space Space tuple to extract axis from.
 * @return Backward axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
backward(const SpaceTuple<T>& space);

/**
 * Set basis Up axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Up axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setUp(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Up axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setUp(SpaceTuple<T>& space, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setRight(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Right axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setRight(SpaceTuple<T>& space, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setForward(AxesTuple<T>& axes, const Vector<3,T>& value);

/**
 * Set basis Forward axis.
 * @param space Space tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
setForward(SpaceTuple<T>& space, const Vector<3,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
position(const Matrix<4,4,T>& basis);

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
position(const SpaceTuple<T>& space);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(SpaceTuple<T>& space, const Vector<3,T>& position);

/* ####################################################################################### */
/* Basis orientation */
/* ####################################################################################### */

/**
 * Extract 3x3 orientation matrix from 4x4 matrix.
 * @param basis 4x4 matrix to extract from.
 * @returb 3x3 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
orientation(const Matrix<4,4,T>& basis);

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

/**
 * Set orientation axes to basis (4x4 matrix).
 * @param basis Basis to set to.
 * @param axes Orientation axes.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const AxesTuple<T>& axes);

/**
 * Extracts orientation axes and set it to 'basis'.
 * @param basis Basis to set orientation to.
 * @param space Space tuple to extract orientation axes from.
 */
template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const SpaceTuple<T>& space);

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <private/CGM/Cartesian/3D/Functions/Utils.hpp>
