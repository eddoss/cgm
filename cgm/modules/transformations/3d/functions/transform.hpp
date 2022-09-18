#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>
#include <cgm/modules/transformations/3d/functions/translate.hpp>
#include <cgm/modules/transformations/3d/functions/scale.hpp>
#include <cgm/modules/transformations/3d/functions/rotate.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

/**
 * Transform vector.
 * @param vector Vector to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Vector<3,T>& vector, const Transforms<T>& parameters);

/**
 * Transform 3x3 matrix (just rotate and scale).
 * @param matrix 3x3 matrix to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Matrix<3,3,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform 4x4 matrix.
 * @param matrix 4x4 matrix to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Matrix<4,4,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform pivot. All transformations for pivot position and just
 * rotate for axes.
 * @param pivot Pivot to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Pivot<T>& pivot, const Transforms<T>& parameters);

/**
 * Transform arbitrary axis. All transformations for axis position
 * and just rotate for direction.
 * @param axis Axis to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Ray<T>& axis, const Transforms<T>& parameters);

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

/**
 * Transform vector.
 * @param vector Vector to transform.
 * @param parameters Transformation parameters.
 * @return Transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
transformed(const Vector<3,T>& vector, const Transforms<T>& parameters);

/**
 * Transform 3x3 matrix (just rotate and scale).
 * @param matrix 3x3 matrix to transform.
 * @param parameters Transformation parameters.
 * @return Transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
transformed(const Matrix<3,3,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform 4x4 matrix.
 * @param matrix 4x4 matrix to transform.
 * @param parameters Transformation parameters.
 * @return Transformed matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
transformed(const Matrix<4,4,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform pivot. All transformations for pivot position and just
 * rotate for axes.
 * @param pivot Pivot to transform.
 * @param parameters Transformation parameters.
 * @return Transformed pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
transformed(const Pivot<T>& pivot, const Transforms<T>& parameters);

/**
 * Transform arbitrary axis. All transformations for axis position
 * and just rotate for direction.
 * @param axis Axis to transform.
 * @param parameters Transformation parameters.
 * @return Transformed axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
transformed(const Ray<T>& axis, const Transforms<T>& parameters);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create 4x4 transformation matrix.
 * @param parameters Transformation parameters.
 * @return Transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
transformMatrix(const Transforms<T>& parameters);

CGM_NAMESPACE_END


#include "transform.inl"
