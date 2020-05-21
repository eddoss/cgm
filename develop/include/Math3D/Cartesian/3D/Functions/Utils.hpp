#ifndef MATH3D_XYZ_FUNCTIONS_UTILS_HPP
#define MATH3D_XYZ_FUNCTIONS_UTILS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
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
/* Uo, Right, Forward axes */
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

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/3D/Functions/Utils.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_UTILS_HPP
