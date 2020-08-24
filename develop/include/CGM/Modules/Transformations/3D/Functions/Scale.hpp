#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Core/Operators/MatrixVectorMultiplication.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Scales vector related to world center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Vector<3,T>& direction);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales vector along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<EVectorRepresentation Representation = EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, T value, const Axis<T>& axis);

/**
 * Scales vector related to pivot point.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, pivot position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<EVectorRepresentation Representation = EVectorRepresentation::Point, typename T>
constexpr void
scale(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Scales 3x3 matrix related to local/world center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, T value, const Axis<T>& axis);

/**
 * Scales 3x3 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Scales 4x4 matrix related to local/world center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, T value, const Axis<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Scales pivot position related to world center.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction);

/**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales pivot along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, T value, const Axis<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales pivot position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param pivot Pivot position to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
scale(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Scales vector related to world center.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values);

/**
 * Scales vector along to arbitrary axis.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
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
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales vector along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of vector.
 */
template<EVectorRepresentation Representation = EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, T value, const Axis<T>& axis);

/**
 * Scales vector related to pivot point.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, pivot position gets in account.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 * @return Scaled copy of vector.
 */
template<EVectorRepresentation Representation = EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
scaled(const Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Scales 3x3 matrix related to local/world center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param origin Axis origin.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales 3x3 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, T value, const Axis<T>& axis);

/**
 * Scales 3x3 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 3x3 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
scaled(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Scales 4x4 matrix related to local/world center.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction);

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
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

/**
 * Scales 4x4 matrix along to arbitrary axis.
 * @tparam Representation How to represent vector. If vector
 * are represented as point, axis position gets in account.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param axis The axis along which to scale.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, T value, const Axis<T>& axis);

/**
 * Scales 4x4 matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param values How much to scale.
 * @param pivotPoint Pivot point position.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<T>& pivot);

/**
 * Scales 4x4 matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of matrix.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
scaled(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Scales pivot position related to world center.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values);

 /**
 * Scales pivot along to arbitrary axis.
 * @param pivot Pivot position to scale.
 * @param value How much to scale.
 * @param direction Axis direction.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
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
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value, const Vector<3,T>& direction, const Vector<3,T>& origin);

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
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, T value, const Axis<T>& axis);

/**
 * Scales pivot position related to pivot point.
 * @param pivot Pivot position to scale.
 * @param values How much to scale (value per axis).
 * @param pivotPoint Pivot point.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Vector<3,T>& values, const Pivot<T>& pivotPoint);

/**
 * Scales pivot position related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param pivot Pivot position to scale.
 * @param transforms Transformations parameters.
 * @return Scaled copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
scaled(const Pivot<T>& pivot, const Transforms<T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Scale.hpp>
