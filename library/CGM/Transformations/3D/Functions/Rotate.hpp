#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Functions/Matrix.hpp>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>
#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Core/Operators/Matrix.hpp>
#include <CGM/Cartesian/3D/Operators/Quaternion.hpp>
#include <CGM/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Cartesian/3D/Functions/Axes.hpp>
#include <CGM/Cartesian/3D/Functions/Converters/Vector.hpp>
#include <CGM/Transformations/Common.hpp>
#include <CGM/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Transformations/3D/Types/Enums.hpp>
#include <CGM/Transformations/3D/Types/ArbitraryAxis.hpp>
#include <CGM/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Transformations/3D/Types/Transforms.hpp>
#include <CGM/Transformations/3D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Rotates vector around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angle Rotation angle.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle);

/**
 * Rotates vector around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles);

/**
 * Rotates vector around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates vector around arbitrary direction.
 * @param vector Vector to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Vector<3,T>& direction);

/**
 * Rotates vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotates vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3x3 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in given rotation order).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix around pivot axes in 'XYZ' rotation order (pivot position is not taken in account).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot);

/**
 * Rotates 3x3 matrix around pivot axes in given rotation order (pivot position is not taken in account).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3x3 matrix around default Cartesian axes on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 4x4 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Space matrix to rotate.
 * @param angle Rotation angle.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 4x4 matrix around arbitrary axis.
 * @tparam Space In which space to transform.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix by Quaternion.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 4x4 matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary direction.
 * @param pivot Pivot to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const Vector<3,T>& direction);

/**
 * Rotates pivot around arbitrary axis.
 * @param pivot Pivot to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in 'XYZ' rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in given rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates pivot by Quaternion.
 * @param pivot Pivot to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Quaternion<T>& quaternion);

/**
 * Rotates pivot around each axis of pivot on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle);

/**
 * Rotates arbitrary axis around default Cartesian axes (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles);

/**
 * Rotates arbitrary axis around default Cartesian axes (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis around arbitrary direction.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle, const Vector<3,T>& direction);

/**
 * Rotates arbitrary axis around arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis by Quaternion.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Quaternion<T>& quaternion);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "transform.rotations".
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Quaternion (inplace) */
/* ####################################################################################### */

/**
 * Rotates quaternion around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param quaternion Quaternion to rotate.
 * @param angle Rotation angle.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle);

/**
 * Rotates quaternion around arbitrary axis.
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param direction Arbitrary direction to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle, const Vector<3,T>& direction);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates quaternion by Quaternion.
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param quat Quaternion to rotate by.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Quaternion<T>& quat);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle);

/**
 * Rotates vector around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
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
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates vector around arbitrary direction.
 * @param vector Vector to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle, const Vector<3,T>& direction);

/**
 * Rotates vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates vector around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param vector Vector to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
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
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotates vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3x3 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 3x3 matrix around default Cartesian axes (in given rotation order).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix around pivot axes in 'XYZ' rotation order (pivot position is not taken in account).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot);

/**
 * Rotates 3x3 matrix around pivot axes in given rotation order (pivot position is not taken in account).
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angles Rotation angles.
 * @param rotationOrder Rotation order.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder);

/**
 * Rotates 3x3 matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 3x3 matrix around default Cartesian axes on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 4x4 matrix around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, T angle);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in 'XYZ' rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles);

/**
 * Rotates 4x4 matrix around default Cartesian axes (in given rotation order).
 * @tparam Axis Cartesian axis to rotate around.
 * @param matrix Space matrix to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix around arbitrary direction.
 * @param matrix Orientation matrix to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction);

/**
 * Rotates 4x4 matrix around arbitrary axis.
 * @tparam Space In which space to transform.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates orientation matrix around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates 4x4 matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotates 4x4 matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary direction.
 * @param pivot Pivot to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(Pivot<T>& pivot, T angle, const Vector<3,T>& direction);

/**
 * Rotates pivot around arbitrary axis.
 * @param pivot Pivot to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates pivot around each axis of pivot point on angle contained in "angles" (in 'XYZ' rotation order).
 * @param pivot Pivot to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
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
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates pivot by Quaternion.
 * @param pivot Pivot to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Quaternion<T>& quaternion);

/**
 * Rotates pivot around each axis of pivot on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle);

/**
 * Rotates arbitrary axis around default Cartesian axes (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles);

/**
 * Rotates arbitrary axis around default Cartesian axes (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per axis).
 * @tparam rotationOrder Rotation order.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis around arbitrary direction.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param direction Direction to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle, const Vector<3,T>& direction);

/**
 * Rotates arbitrary axis around arbitrary axis.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle, const ArbitraryAxis<T>& axis);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates arbitrary axis by Quaternion.
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param quaternion Quaternion to rotate by.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Quaternion<T>& quaternion);

/**
 * Rotates arbitrary axis around each axis of pivot on angle contained in "transform.rotations".
 * @param arbitraryAxis Arbitrary axis to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Quaternion (outplace) */
/* ####################################################################################### */

/**
 * Rotates quaternion around default Cartesian axis.
 * @tparam Axis Cartesian axis to rotate around.
 * @tparam Space In which space to rotate.
 * @param quaternion Quaternion to rotate.
 * @param angle Rotation angle.
 * @return Rotated copy of quaternion.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle);

/**
 * Rotates quaternion around arbitrary axis.
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param axis Arbitrary axis to rotate around.
 * @param angle Rotation angle.
 * @return Rotated copy of quaternion.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle, const Vector<3,T>& axis);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in 'XYZ' rotation order).
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotated copy of quaternion.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "angles" (in given rotation order).
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotated copy of quaternion.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Rotates quaternion by Quaternion.
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param quat Quaternion to rotate by.
 * @return Rotated copy of quaternion.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Quaternion<T>& quat);

/**
 * Rotates quaternion around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param quaternion Quaternion to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated copy of quaternion.
 */
template<ESpace Space = ESpace::World, typename T>
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
template<EAxes Axis, size_t N=4, typename T>
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
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(T angle, const ArbitraryAxis<T>& axis);

/**
 * Create rotation matrix (around each axis of pivot on angle contained from "angles" in 'XYZ' rotation order).
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint);

/**
 * Create rotation matrix (around each axis of pivot on angle contained from "angles" in given rotation order).
 * @param angles Rotation angles (angle per pivot axis).
 * @param pivotPoint Rotation pivot.
 * @param rotationOrder Rotation order.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder);

/**
 * Create rotation matrix (around each axis of pivot on angle contained in "transform.rotations").
 * @param transforms Transformations parameters.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Transforms<T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/Transformations/3D/Functions/Rotate.inl>
