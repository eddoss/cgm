#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/functions/matrix.hpp>
#include <cgm/modules/cartesian/3d/types/quaternion.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/core/operators/matrix.hpp>
#include <cgm/modules/cartesian/3d/operators/quaternion.hpp>
#include <cgm/modules/cartesian/3d/types/axes.hpp>
#include <cgm/modules/cartesian/3d/functions/axes.hpp>
#include <cgm/modules/cartesian/3d/functions/converters/vector.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/enums.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>
#include <cgm/modules/transformations/3d/functions/utils.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Rotates vector around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, T angle);

/**
 * Rotates vector around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Vector<3,T>& angles);

/**
 * Rotates vector around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates vector around arbitrary direction.
 * @param vector Vector to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, T angle, const Vector<3,T>& direction);

/**
 * Rotates vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, T angle, const Ray<T>& axis);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotates vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3x3 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in given rotation order).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix around pivot axes in 'XYZ' rotation order (pivot position is not taken in account).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot);

/**
 * Rotates 3x3 matrix around pivot axes in given rotation order (pivot position is not taken in account).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3x3 matrix around default Cartesian axes on angle contained in "transform.rotations".
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 4x4 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, T angle);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 4x4 matrix around arbitrary axis.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, T angle, const Ray<T>& axis);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 4x4 matrix around each axis of pivot on angle contained in "transform.rotations".
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Rotates pivot around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param pivot Pivot to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary direction.
 * @param pivot Pivot to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle, const Vector<3,T>& direction);

/**
 * Rotates pivot around arbitrary axis.
 * @param pivot Pivot to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle, const Ray<T>& axis);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in 'XYZ' rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in given rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates pivot by Quaternion.
 * @param pivot Pivot to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, const Quaternion<T>& quaternion);

/**
 * Rotates pivot around each axis of pivot on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Rotates arbitrary axis around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, T angle);

/**
 * Rotates arbitrary axis around default Cartesian axes (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Vector<3,T>& angles);

/**
 * Rotates arbitrary axis around default Cartesian axes (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis around arbitrary direction.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, T angle, const Vector<3,T>& direction);

/**
 * Rotates arbitrary axis around arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, T angle, const Ray<T>& axis);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis by Quaternion.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Quaternion<T>& quaternion);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "transform.rotations".
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Ray<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Quaternion (inplace) */
/* ####################################################################################### */

/**
 * Rotates quaternion around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param quaternion Quaternion to rotate.
 * @param angle Rotation angle.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, T angle);

/**
 * Rotates quaternion around arbitrary axis.
 * @param quaternion Quaternion to rotate.
 * @param direction Arbitrary direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, T angle, const Vector<3,T>& direction);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates quaternion by Quaternion.
 * @param quaternion Quaternion to rotate.
 * @param quat Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, const Quaternion<T>& quat);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "transform.rotations".
 * @param quaternion Quaternion to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Quaternion<T>& quaternion, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Rotates vector around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of vector.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, T angle);

/**
 * Rotates vector around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles);

/**
 * Rotates vector around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates vector around arbitrary direction.
 * @param vector Vector to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, T angle, const Vector<3,T>& direction);

/**
 * Rotates vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, T angle, const Ray<T>& axis);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotates vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
rotated(const Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<E3D Axis, typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3x3 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in given rotation order).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix around pivot axes in 'XYZ' rotation order (pivot position is not taken in account).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot);

/**
 * Rotates 3x3 matrix around pivot axes in given rotation order (pivot position is not taken in account).
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3x3 matrix around default Cartesian axes on angle contained in "transform.rotations".
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 4x4 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, T angle);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotated(Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 4x4 matrix around arbitrary axis.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, T angle, const Ray<T>& axis);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 4x4 matrix around each axis of pivot on angle contained in "transform.rotations".
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotated(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Rotates pivot around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param pivot Pivot to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of pivot.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary direction.
 * @param pivot Pivot to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(Pivot<T>& pivot, T angle, const Vector<3,T>& direction);

/**
 * Rotates pivot around arbitrary axis.
 * @param pivot Pivot to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, T angle, const Ray<T>& axis);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in 'XYZ' rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in given rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates pivot by Quaternion.
 * @param pivot Pivot to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, const Quaternion<T>& quaternion);

/**
 * Rotates pivot around each axis of pivot on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

/**
 * Rotates arbitrary axis around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of axis.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, T angle);

/**
 * Rotates arbitrary axis around default Cartesian axes (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Vector<3,T>& angles);

/**
 * Rotates arbitrary axis around default Cartesian axes (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis around arbitrary direction.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, T angle, const Vector<3,T>& direction);

/**
 * Rotates arbitrary axis around arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, T angle, const Ray<T>& axis);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis by Quaternion.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Quaternion<T>& quaternion);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "transform.rotations".
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Ray<T>>
rotated(const Ray<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Rotates quaternion around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param quaternion Quaternion to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of quaternion.
 */
template<E3D Axis, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle);

/**
 * Rotates quaternion around arbitrary axis.
 * @param quaternion Quaternion to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle, const Vector<3,T>& axis);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of quaternion.
 */
template<typename T>
constexpr Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates quaternion by Quaternion.
 * @param quaternion Quaternion to rotate.
 * @param quat Quaternion to rotate by.
 * @return Rotated copy of quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Quaternion<T>& quat);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "transform.rotations".
 * @param quaternion Quaternion to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of quaternion.
 */
template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create rotation matrix (around default Cartesian axis).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @tparam Axis Cartesian axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotation matrix.
 */
template<E3D Axis, size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(T angle);

/**
 * Create rotation matrix (around default Cartesian axes in 'XYZ' rotation order).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @tparam Axis Cartesian axis to rotate around.
 * @param angles Rotation angles (angle per axis).
 * @return Rotation matrix.
 */
template<size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(const Vector<3,T>& angles);

/**
 * Create rotation matrix (around default Cartesian axes (in given rotation order).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @tparam Axis Cartesian axis to rotate around.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotation matrix.
 */
template<size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Create rotation matrix (around arbitrary direction).
 * @tparam N Size of matrix need to create (must be 3 or 4).
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotation matrix.
 */
template<size_t N=4, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(T angle, const Vector<3,T>& direction);

/**
 * Create rotation matrix (around arbitrary axis).
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotationMatrix(T angle, const Ray<T>& axis);

/**
 * Create rotation matrix (around each axis of pivot on angle contained from "angles" in 'XYZ' rotation order).
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Create rotation matrix (around each axis of pivot on angle contained from "angles" in given rotation order).
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Create rotation matrix (around each axis of pivot on angle contained in "transform.rotations").
 * @param transforms Transformations parameters.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<4,4,T>>
rotationMatrix(const Transforms<T>& transforms);

CGM_NAMESPACE_END


#include "rotate.inl"
