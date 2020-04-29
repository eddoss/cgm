#ifndef MATH3D_XFORM_2D_FUNCTIONS_HPP
#define MATH3D_XFORM_2D_FUNCTIONS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Common.hpp>
#include <Math3D/XForm/2D/Pivot.hpp>
#include <Math3D/XForm/2D/Transforms.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Apply transformations */
/* ####################################################################################### */

/**
 * Apply 2D transforms to 2D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Apply 2D transforms to 2D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Apply 2D transforms to 2D orientation matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<2,2,T>& matrix, const Transforms<2,T>& transforms);

/**
 * Apply 2D transforms to 2D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Apply 2D transforms to 2D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

/* ####################################################################################### */
/* Translating */
/* ####################################################################################### */

/**
 * Translate 2D vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Translate 2D vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Translate 2D transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<3,3,T>& matrix, const Vector<2,T>& value);

/**
 * Translate 2D transform matrix using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
translate(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

/* ####################################################################################### */
/* Scaling */
/* ####################################################################################### */

/**
 * Scale 2D vector.
 * @tparam Space In which space to transform.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
 template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Scale 2D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value, const Vector<2,T>& pivotPoint);

/**
 * Scale 2D vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivot Pivot point.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value, const Pivot<2,T>& pivot);

/**
 * Scale 2D vector related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Scale 2D transform matrix.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value);

/**
 * Scale 2D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value, const Vector<2,T>& pivotPoint);

/**
 * Scale 2D transform matrix related to pivot point.
 * @tparam Space In which space to scale.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value, const Pivot<2,T>& pivot);

/**
 * Scale 2D transform matrix related to "transform.pivot" on "transform.scale" and "transform.uniformScale".
 * @tparam Space In which space to scale.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

/* ####################################################################################### */
/* Rotating */
/* ####################################################################################### */

/**
 * Rotate 2D vector around origin.
 * @param vector Vector to rotate.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<2,T>& vector, T angle);

/**
 * Rotate 2D vector around arbitrary point.
 * @param vector Vector to rotate.
 * @param pivotPoint Rotation center.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<2,T>& vector, T angle, const Vector<2,T>& pivotPoint);

/**
 * Rotate 2D vector around each axis of pivot on "transform.angle".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr FORCEINLINE void
rotate(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Rotate 2D basis around origin.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<2,2,T>& matrix, T angle);

/**
 * Rotate 2D basis around arbitrary point.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param rotationPoint Rotation center.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<2,2,T>& matrix, T angle, const Vector<2,T>& pivotPoint);

/**
 * Rotate 2D basis around each axis of pivot on "transform.angle".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<2,2,T>& matrix, const Transforms<2,T>& transforms);

/**
 * Rotate 2D transformation matrix around origin.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle);

/**
 * Rotate 2D transformation matrix around arbitrary point.
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param pivotPoint Rotation center.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<2,T>& pivotPoint);

/**
 * Rotate 2D transformation matrix around each axis of pivot on "transform.angle".
 * @tparam Space In which space to transform.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_2D_FUNCTIONS_HPP