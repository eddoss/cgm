#ifndef MATH3D_XFORM_3D_FUNCTIONS_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>
#include <Math3D/Core/Axis.hpp>
#include <Math3D/XForm/3D/Pivot.hpp>
#include <Math3D/XForm/3D/Transforms.hpp>
#include <Math3D/XForm/3D/EulerAngles.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Apply transformations */
/* ####################################################################################### */

/**
 * Apply 3D transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Apply 3D transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Apply 3D transforms to 3D orientation matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Apply 3D transforms to 3D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Apply 3D transforms to 3D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/* ####################################################################################### */
/* Translating */
/* ####################################################################################### */

/**
 * Translate 3D vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translate 3D vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Translate 3D transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translate 3D transform matrix using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/* ####################################################################################### */
/* Scaling */
/* ####################################################################################### */

/**
 * Scale 3D vector.
 * @tparam Space In which space to transform.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
 template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Scale 3D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scale 3D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivot Pivot point.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scale 3D vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Scale 3D transform matrix.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Scale 3D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scale 3D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scale 3D transform matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/* ####################################################################################### */
/* Rotating */
/* ####################################################################################### */

/**
 * Rotate 3D vector by Euler angles.
 * @param vector Vector to rotate.
 * @param eulerAngles Euler angles.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const EulerAngles<T>& eulerAngles, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D vector around arbitrary axis.
 * @param vector Vector to rotate.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Axis<T>& axis);

/**
 * Rotate 3D vector around each axis of pivot on angle contained in "values".
 * @param vector Vector to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D vector by Quaternion.
 * @param vector Vector to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion);

/**
 * Rotate 3D vector around each axis of pivot on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Rotate 3D orientation matrix by Euler angles.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param eulerAngles Euler angles.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const EulerAngles<T>& eulerAngles, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D orientation matrix around axis.
 * @tparam Space In which space to transform.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Axis<T>& axis);

/**
 * Rotate 3D orientation matrix around each axis of pivot on angle contained in "values".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D orientation matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotate 3D orientation matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Rotate 3D transformation matrix by Euler angles.
 * @tparam Space In which space to rotate.
 * @param matrix Orientation matrix to rotate.
 * @param eulerAngles Euler angles.
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const EulerAngles<T>& eulerAngles, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D transformation matrix around axis.
 * @tparam Space In which space to transform.
 * @param axis Rotation axis (contain axis position, direction).
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle, const Axis<T>& axis);

/**
 * Rotate 3D transformation matrix around each axis of pivot on angle contained in "values".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param values Rotation angles (angle per pivot axis).
 * @param rotationOrder Rotation order. By default is "XYZ".
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& values, const Pivot<3,T>& pivot, ERotationOrder rotationOrder = ERotationOrder::XYZ);

/**
 * Rotate 3D transformation matrix by Quaternion.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param quaternion Quaternion to rotate by.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion);

/**
 * Rotate 3D transformation matrix around each axis of pivot on angle contained in "transform.rotations".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_HPP