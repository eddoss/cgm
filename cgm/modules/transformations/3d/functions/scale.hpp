#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/core/operators/matrix_vector_multiplication.hpp>
#include <cgm/modules/core/functions/vector.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/transformations/3d/functions/converters/pivot.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>
#include <cgm/modules/transformations/3d/functions/utils.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Scales vector along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<3,T>& vector, T value);

/**
 * Scales vector related to global center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<3,T>& vector, const Vector<3,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<3,T>& vector, T value, const Vector<3,T>& direction);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<3,T>& vector, T value, const Ray<T>& axis);

/**
 * Scales vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Scales 3x3 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, T value);

/**
 * Scales 3x3 matrix related to local/global center.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 3x3 matrix related to pivot point. Pivot position is not taken in account.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Scales 4x4 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, T value);

/**
 * Scales 4x4 matrix related to local/global center.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, T value, const Ray<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Scales pivot position along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value);


/**
 * Scales pivot position related to global center.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<3,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Ray<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales pivot position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param pivot Pivot position to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Scales arbitrary axis position along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, T value);

/**
 * Scales arbitrary axis position related to global center.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, const Vector<3,T>& values);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, T value, const Vector<3,T>& direction);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, T value, const Ray<T>& axis);

/**
 * Scales arbitrary axis position related to pivot point.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales arbitrary axis position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Ray<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Scales vector along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @return Scaled copy of vector.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, T value);

/**
 * Scales vector related to global center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, T value, const Vector<3,T>& direction);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, T value, const Ray<T>& axis);

/**
 * Scales vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
scaled(const Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Scales 3x3 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @return Scaled copy of matrix.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value);

/**
 * Scales 3x3 matrix related to local/global center.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 3x3 matrix related to pivot point.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Scales 4x4 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @return Scaled copy of matrix.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, T value);

/**
 * Scales 4x4 matrix related to local/global center.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, T value, const Ray<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scaled(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Scales pivot position along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @return Scaled copy of pivot.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value);

/**
 * Scales pivot position related to global center.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Vector<3,T>& direction);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Ray<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales pivot position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param pivot Pivot position to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Scales arbitrary axis position along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @return Scaled copy of axis.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, T value);

/**
 * Scales arbitrary axis position related to global center.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, const Vector<3,T>& values);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, T value, const Vector<3,T>& direction);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, T value, const Ray<T>& axis);

/**
 * Scales arbitrary axis position related to pivot point.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales arbitrary axis position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
scaled(const Ray<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create scaling matrix (along default Cartesian axes).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @tparam Axis Cartesian axis to scale along which.
 * @param value How much to scale.
 * @return Scaling matrix.
 */
template<E3D Axis, size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(T value);

/**
 * Create scaling matrix (related to global center).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param values How much to scale (value per axis).
 * @return Scaling matrix.
 */
template<size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(const Vector<3,T>& values);

/**
 * Create scaling matrix (along to arbitrary axis).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaling matrix.
 */
template<size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
scalingMatrix(T value, const Vector<3,T>& direction);

/**
 * Create scaling matrix (along to arbitrary axis).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scalingMatrix(T value, const Ray<T>& axis);

/**
 * Create scaling matrix (related to pivot point).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scalingMatrix(const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Create scaling matrix (related to "transform.pivot" on "transform.scale" and "transform.uniformScale").
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
scalingMatrix(const Transforms<T>& transforms);

CGM_NAMESPACE_END


#include "scale.inl"
