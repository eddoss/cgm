#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/vector.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>
#include <cgm/modules/transformations/2d/types/arbitrary_axis.hpp>
#include <cgm/modules/transformations/2d/types/pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Reflects vector from an arbitrary axis.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 */
template<typename T>
constexpr void
reflect(Vector<2,T>& vector, const Vector<2,T>& axisNormal);

/**
 * Reflects vector from an arbitrary axis.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 */
template<typename T>
constexpr void
reflect(Vector<2,T>& vector, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

/* ####################################################################################### */
/* Matrix2 (inplace) */
/* ####################################################################################### */

/**
 * Reflects 2x2 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 */
template<typename T>
constexpr void
reflect(Matrix<2,2,T>& matrix, const Vector<2,T>& axisNormal);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Reflects 3x3 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 */
template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal);

/**
 * Reflects 3x3 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 */
template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal, const Vector<2,T>& axisPosition);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Reflects pivot from an arbitrary axis.
 * @param pivot Pivot to reflect.
 * @param axisNormal Axis normal.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, const Vector<2,T>& axisNormal);

/**
 * Reflects pivot from an arbitrary axis.
 * @param pivot Pivot to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 */
template<typename T>
constexpr void
reflect(Pivot<T>& pivot, const Vector<2,T>& axisNormal, const Vector<2,T>& axisPosition);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Reflects axis from an arbitrary axis.
 * @param axis Axis to reflect.
 * @param axisNormal Normal of an axis to reflect from.
 */
template<typename T>
constexpr void
reflect(ArbitraryAxis<T>& axis, const Vector<2,T>& axisNormal);

/**
 * Reflects axis from an arbitrary axis.
 * @param axis Pivot to reflect.
 * @param axisNormal Normal of an axis to reflect from.
 * @param centerNormal Center of an axis to reflect from.
 */
template<typename T>
constexpr void
reflect(ArbitraryAxis<T>& axis, const Vector<2,T>& axisNormal, const Vector<2,T>& axisPosition);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Reflects vector from an arbitrary axis.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 * @return Reflected vector.
 */
template<typename T>
constexpr Vector<2,T>
reflected(const Vector<2,T>& vector, const Vector<2,T>& axisNormal);

/**
 * Reflects vector from an arbitrary axis.
 * @param vector Vector to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 * @return Reflected vector.
 */
template<typename T>
constexpr Vector<2,T>
reflected(const Vector<2,T>& vector, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

/* ####################################################################################### */
/* Matrix2 (outplace) */
/* ####################################################################################### */

/**
 * Reflects 2x2 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 * @return Reflected orientation.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr Matrix<2,2,T>
reflected(const Matrix<2,2,T>& matrix, const Vector<2,T>& axisNormal);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Reflects 3x3 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 * @return Reflected basis.
 */
template<typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal);

/**
 * Reflects 3x3 matrix from an arbitrary axis.
 * @param matrix Matrix to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 * @return Reflected basis.
 */
template<typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Reflects pivot from an arbitrary axis.
 * @param pivot Pivot to reflect.
 * @param axisNormal Axis normal.
 * @return Reflected pivot.
 */
template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, const Vector<2,T>& axisNormal);

/**
 * Reflects pivot from an arbitrary axis.
 * @param pivot Pivot to reflect.
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 * @return Reflected pivot.
 */
template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

/**
 * Reflects axis from an arbitrary axis.
 * @param axis Axis to reflect.
 * @param axisNormal Normal of an axis to reflect from.
 * @return Reflected axis.
 */
template<typename T>
constexpr ArbitraryAxis<T>
reflected(const ArbitraryAxis<T>& axis, const Vector<2,T>& axisNormal);

/**
 * Reflects axis from an arbitrary axis.
 * @param axis Pivot to reflect.
 * @param axisNormal Normal of an axis to reflect from.
 * @param centerNormal Center of an axis to reflect from.
 * @return Reflected axis.
 */
template<typename T>
constexpr ArbitraryAxis<T>
reflected(const ArbitraryAxis<T>& axis, const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create reflection matrix (from a plane).
 * @param axisNormal Axis normal.
 * @return Reflection matrix.
 */
template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
reflectionMatrix(const Vector<2,T>& axisNormal);

/**
 * Create reflection matrix (from a plane).
 * @param axisNormal Axis normal.
 * @param axisCenter Axis origin.
 * @return Reflection matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
reflectionMatrix(const Vector<2,T>& axisNormal, const Vector<2,T>& axisCenter);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "reflect.inl"
