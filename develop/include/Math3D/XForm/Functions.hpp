#ifndef MATH3D_XFORM_FUNCTIONS_HPP
#define MATH3D_XFORM_FUNCTIONS_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/Pivot.hpp>
#include <Math3D/XForm/Transforms.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Apply transformations */
/* ####################################################################################### */

/**
 * Apply transforms to 2D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<3,3,T>& transforms);

/**
 * Apply transforms to 2D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Apply transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Apply transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Apply transforms to 4D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<4,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Apply transforms to 4D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<4,T>& vector, const Transforms<3,T>& transforms);

/**
 * Apply transforms to 2D transform matrix.
 * @param matrix Matrix to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms);

/**
 * Apply transforms to 2D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

/**
 * Apply transforms to 3D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Apply transforms to 3D transform matrix.
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
 * Translate 2D transform matrix by vector.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Matrix<3,3,T>& matrix, const Vector<2,T>& value);

/**
 * Translate 2D vector by vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Translate 2D vector by transforms.
 * @param vector Vector to translate.
 * @param transforms How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Translate 3D transform matrix by vector.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translate 3D vector by vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translate 3D vector by transforms.
 * @param vector Vector to translate.
 * @param transforms How much to translate.
 */
template<typename T>
constexpr FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/* ####################################################################################### */
/* Scaling */
/* ####################################################################################### */

/**
 * Scale 2D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value);

/**
 * Scale 2D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value, const Vector<2,T>& pivotPoint);

/**
 * Scale 2D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Vector<2,T>& value, const Pivot<2,T>& pivot);

/**
 * Scale 2D transform matrix by transforms.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<3,3,T>& matrix, const Transforms<2,T>& transforms);

/**
 * Scale 2D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Scale 2D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value, const Vector<2,T>& pivotPoint);

/**
 * Scale 2D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Vector<2,T>& value, const Pivot<2,T>& pivot);

/**
 * Scale 2D vector by transforms.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<2,T>& vector, const Transforms<2,T>& transforms);

/**
 * Scale 3D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Scale 3D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scale 3D transform matrix by vector.
 * @param matrix Matrix to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scale 3D transform matrix by transforms.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Scale 3D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Scale 3D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Vector<3,T>& pivotPoint);

/**
 * Scale 3D vector by vector.
 * @param vector Vector to scale.
 * @param value How much to scale.
 * @param pivotPoint Pivot point position.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& value, const Pivot<3,T>& pivot);

/**
 * Scale 3D vector by transforms.
 * @param vector Vector to scale.
 * @param transforms How much to scale.
 */
template<typename T>
constexpr FORCEINLINE void
scale(Vector<3,T>& vector, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_FUNCTIONS_HPP