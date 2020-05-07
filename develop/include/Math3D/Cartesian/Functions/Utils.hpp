#ifndef MATH3D_XYZ_FUNCTIONS_HPP
#define MATH3D_XYZ_FUNCTIONS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* 2D */
/* ####################################################################################### */

/**
 * Gets basis X axis.
 * @param basis Basis to extract axis from.
 * @return X axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
get2DBasisX(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
get2DBasisY(const Matrix<S,S,T>& basis);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisX(const Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisY(const Matrix<S,S,T>& basis, const Vector<2,T>& value);

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
get2DBasisPosition(const Matrix<3,3,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
set2DBasisPosition(const Matrix<3,3,T>& basis, const Vector<2,T>& position);

/* ####################################################################################### */
/* 3D */
/* ####################################################################################### */

/**
 * Gets basis X axis.
 * @param basis Basis to extract axis from.
 * @return X axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisX(const Matrix<S,S,T>& basis);

/**
 * Gets basis Y axis.
 * @param basis Basis to extract axis from.
 * @return Y axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisY(const Matrix<S,S,T>& basis);

/**
 * Gets basis Z axis.
 * @param basis Basis to extract axis from.
 * @return Z axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisZ(const Matrix<S,S,T>& basis);

/**
 * Gets basis X axis.
 * @param orientation Quaternion that orients space.
 * @return X axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisX(const Quaternion<T>& orientation);

/**
 * Gets basis Y axis.
 * @param orientation Quaternion that orients space.
 * @return Y axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisY(const Quaternion<T>& orientation);

/**
 * Gets basis Z axis.
 * @param orientation Quaternion that orients space.
 * @return Z axis value.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisZ(const Quaternion<T>& orientation);

/**
 * Set basis X axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisX(const Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Y axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisY(const Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Set basis Z axis.
 * @param basis Basis to set axis to.
 * @param value New axis value.
 */
template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisZ(const Matrix<S,S,T>& basis, const Vector<3,T>& value);

/**
 * Gets basis position.
 * @return Basis position.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisPosition(const Matrix<4,4,T>& basis);

/**
 * Set basis position.
 * @param basis Basis to set position to.
 * @param value New position value.
 */
template<typename T>
constexpr FORCEINLINE void
set3DBasisPosition(const Matrix<4,4,T>& basis, const Vector<3,T>& position);

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/Functions/Utils.hpp>


#endif // MATH3D_XYZ_FUNCTIONS_HPP
