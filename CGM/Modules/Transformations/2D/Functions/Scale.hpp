#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/Matrix.hpp>
#include <CGM/Modules/Core/Operators/MatrixVectorMultiplication.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/2D/Functions/Converters/Vector.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/2D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/2D/Types/Transforms.hpp>
#include <CGM/Modules/Transformations/2D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Scales vector along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value);

/**
 * Scales vector related to global center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, const Vector<2,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value, const Vector<2,T>& direction);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr void
scale(Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Vector<2,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Scales 3x3 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<2,2,T>& matrix, T value);

/**
 * Scales 3x3 matrix related to local/global center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, const Vector<2,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, T value, const Vector<2,T>& direction);

/**
 * Scales 3x3 matrix related to pivot point. Pivot position is not taken in account.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<2,2,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<2,2,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Scales 4x4 matrix along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, T value);

/**
 * Scales 4x4 matrix related to local/global center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Scales pivot position along default Cartesian axes.
 * @tparam Axis Cartesian axis to scale along which.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value);


/**
 * Scales pivot position related to global center.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<2,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Vector<2,T>& direction);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const Vector<2,T>& direction, const Vector<2,T>& origin);

/**
 * Scales pivot along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

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
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value);

/**
 * Scales arbitrary axis position related to global center.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<2,T>& direction);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales arbitrary axis position related to pivot point.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales arbitrary axis position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
scale(ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms);

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
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value);

/**
 * Scales vector related to global center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Vector<2,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const Vector<2,T>& direction);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const Vector<2,T>& direction, const Vector<2,T>& origin);

/**
 * Scales vector along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales vector related to pivot point.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, pivot position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
scaled(const Vector<2,T>& vector, const Transforms<T>& transforms);

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
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, T value);

/**
 * Scales 3x3 matrix related to local/global center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Vector<2,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, T value, const Vector<2,T>& direction);

/**
 * Scales 3x3 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
scaled(const Matrix<2,2,T>& matrix, const Transforms<T>& transforms);

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
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value);

/**
 * Scales 4x4 matrix related to local/global center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<2,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<2,T>& direction, const Vector<2,T>& origin);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scaled(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

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
template<E2D Axis, typename T>
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
scaled(const Pivot<T>& pivot, const Vector<2,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const Vector<2,T>& direction);

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
scaled(const Pivot<T>& pivot, T value, const Vector<2,T>& direction, const Vector<2,T>& origin);

/**
 * Scales pivot along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
scaled(const Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

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
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value);

/**
 * Scales arbitrary axis position related to global center.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const Vector<2,T>& direction);

/**
 * Scales arbitrary axis position along to arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, T value, const ArbitraryAxis<T>& axis);

/**
 * Scales arbitrary axis position related to pivot point.
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales arbitrary axis position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param arbitraryAxis Arbitrary axis to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
scaled(const ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms);

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
template<E2D Axis, size_t N=3, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(T value);

/**
 * Create scaling matrix (related to global center).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param values How much to scale (value per axis).
 * @return Scaling matrix.
 */
template<size_t N=3, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(const Vector<2,T>& values);

/**
 * Create scaling matrix (along to arbitrary axis).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaling matrix.
 */
template<size_t N=3, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
scalingMatrix(T value, const Vector<2,T>& direction);

/**
 * Create scaling matrix (along to arbitrary axis).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(T value, const ArbitraryAxis<T>& axis);

/**
 * Create scaling matrix (related to pivot point).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Create scaling matrix (related to "transform.pivot" on "transform.scale" and "transform.uniformScale").
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaling matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
scalingMatrix(const Transforms<T>& transforms);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Scale.inl"