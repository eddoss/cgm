#ifndef MATH3D_XY_FUNCTIONS_UTILS_HPP
#define MATH3D_XY_FUNCTIONS_UTILS_HPP


#include <tuple>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Aliases */
/* ####################################################################################### */

template<typename T> using AxesTuple    = std::tuple<Vector<2,T>, Vector<2,T>>;
template<typename T> using SpaceTuple   = std::tuple<Vector<2,T>, Vector<2,T>, Vector<2,T>>;

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
getX(const Matrix<S,S,T>& basis);

/**
 * Gets X axis from axes tuple.
 * @param axes Axes tuple to extract axis from.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
getX(const AxesTuple<T>& axes);

/**
 * Gets Y axis from axes tuple.
 * @param axes Axes tuple to extract axis from.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE AxesTuple<T>
getY(const AxesTuple<T>& axes);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
getY(const Matrix<S,S,T>& basis);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set axes tuple X axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setX(AxesTuple<T>& axes, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set axes tuple Y axis.
 * @param axes Axes tuple to set axis to.
 * @param value New axis value.
 */
template<typename T>
constexpr FORCEINLINE void
setY(AxesTuple<T>& axes, const Vector<2,T>& value);

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
getPosition(const Matrix<3,3,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position);

/* ####################################################################################### */
/* Basis orientation */
/* ####################################################################################### */

/**
 * Extract 2x2 orientation matrix from 3x3 matrix.
 * @param basis Basis to extract from.
 * @returb 2x2 orientation matrix.
 */
template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
getOrientation(const Matrix<3,3,T>& basis);

/**
 * Set orientation axes to basis (3x3 matrix).
 * @param orientation 3x3 orientation to set to.
 * @param x X orientation axis.
 * @param y Y orientation axis.
 */
template<typename T>
constexpr void
setOrientation(Matrix<2,2,T>& orientation, const Vector<2,T>& x, const Vector<2,T>& y);

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

/* ####################################################################################### */
/* Space */
/* ####################################################################################### */

/**
 * Unpack 3x3 matrix to X,Y axes and position.
 * @param matrix Matrix to unpack.
 * @return Tuple of basis orientation axes and basis position.
 */
template<typename T>
constexpr FORCEINLINE SpaceTuple<T>
unpackSpace(const Matrix<3,3,T>& matrix);

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Functions/Utils.hpp>


#endif // MATH3D_XY_FUNCTIONS_UTILS_HPP
