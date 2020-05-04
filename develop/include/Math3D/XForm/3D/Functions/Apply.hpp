#ifndef MATH3D_XFORM_3D_FUNCTIONS_APPLY_HPP
#define MATH3D_XFORM_3D_FUNCTIONS_APPLY_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/XForm/3D/Transforms.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XFORM_NAMESPACE_BEGIN

/**
 * Applies 3D transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms);

/**
 * Applies 3D transforms to 3D vector.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Vector<3,T>& vector, const Transforms<3,T>& transforms);

/**
 * Applies 3D transforms to 3D orientation matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Transforms<3,T>& transforms);

/**
 * Applies 3D transforms to 3D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform matrix.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms);

/**
 * Applies 3D transforms to 3D transform matrix.
 * @param vector Vector to apply transforms to.
 * @param transforms Transform values.
 */
template<typename T>
constexpr FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Transforms<3,T>& transforms);

MATH3D_XFORM_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XFORM_3D_FUNCTIONS_APPLY_HPP