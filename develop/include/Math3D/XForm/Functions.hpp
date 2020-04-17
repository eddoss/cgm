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

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_FUNCTIONS_HPP