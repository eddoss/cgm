#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/core/operators/matrix.hpp>
#include <cgm/modules/cartesian/2d/types/axes.hpp>
#include <cgm/modules/cartesian/2d/functions/axes.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/vector.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>
#include <cgm/modules/transformations/2d/types/transforms.hpp>
#include <cgm/modules/transformations/2d/types/arbitrary_axis.hpp>
#include <cgm/modules/transformations/2d/functions/utils.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Rotates vector around origin.
 * @param vector Vector to rotate.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<2,T>& vector, T angle);

/**
 * Rotates vector around arbitrary point.
 * @param vector Vector to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<2,T>& vector, T angle, const Vector<2,T>& point);

/**
 * Rotates vector around pivot.
 * @param vector Vector to rotate.
 * @param pivot Pivot to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<2,T>& vector, T angle, const Pivot<T>& pivot);

/**
 * Rotates vector around "transform.pivot" on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Vector<2,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix2 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 2x2 orientation matrix around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix 2x2 orientation matrix.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<2,2,T>& matrix, T angle);

/**
 * Rotates vector around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix 2x2 orientation matrix.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<2,2,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 basis matrix around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix Vector to rotate.
 * @param angle Rotation angle (in radians).
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates vector around arbitrary point.
 * @tparam Space Space in which to rotate.
 * @param vector Vector to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<2,T>& point);

/**
 * Rotates vector around pivot.
 * @tparam Space Space in which to rotate.
 * @param vector Vector to rotate.
 * @param pivot Pivot to rotate around.
 * @param angle Rotation angle.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, T angle, const Pivot<T>& pivot);

/**
 * Rotates vector around "transform.pivot" on angle contained in "transform.rotations".
 * @tparam Space Space in which to rotate.
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Rotates pivot around origin.
 * @param pivot Pivot to rotate.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary point.
 * @param pivot Pivot to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle, const Vector<2,T>& point);

/**
 * Rotates pivot around pivot.
 * @param pivot Pivot to rotate.
 * @param pivotPoint Pivot to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(Pivot<T>& pivot, T angle, const Pivot<T>& pivotPoint);

/**
 * Rotates pivot around "transform.pivot" on angle contained in "transform.rotations".
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
 * Rotates axis around origin.
 * @param axis Pivot to rotate.
 * @param angle Rotation angle (in radians).
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(ArbitraryAxis<T>& axis, T angle);

/**
 * Rotates axis around arbitrary point.
 * @param axis Pivot to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(ArbitraryAxis<T>& axis, T angle, const Vector<2,T>& point);

/**
 * Rotates axis around axis.
 * @param axis Pivot to rotate.
 * @param pivotPoint Pivot to rotate around.
 * @param angle Rotation angle.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(ArbitraryAxis<T>& axis, T angle, const Pivot<T>& pivotPoint);

/**
 * Rotates axis around "transform.axis" on angle contained in "transform.rotations".
 * @param pivot Vector to rotate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
rotate(ArbitraryAxis<T>& axis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Rotates vector around origin.
 * @param vector Vector to rotate.
 * @param angle Rotation angle (in radians).
 * @return Rotated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
rotated(const Vector<2,T>& vector, T angle);

/**
 * Rotates vector around arbitrary point.
 * @param vector Vector to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 * @return Rotated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
rotated(const Vector<2,T>& vector, T angle, const Vector<2,T>& point);

/**
 * Rotates vector around pivot.
 * @param vector Vector to rotate.
 * @param pivot Pivot to rotate around.
 * @param angle Rotation angle.
 * @return Rotated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
rotated(const Vector<2,T>& vector, T angle, const Pivot<T>& pivot);

/**
 * Rotates vector around "transform.pivot" on angle contained in "transform.rotations".
 * @param vector Vector to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
rotated(const Vector<2,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix2 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 2x2 orientation matrix around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix 2x2 orientation matrix.
 * @param angle Rotation angle (in radians).
 * @return Rotated matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
rotated(const Matrix<2,2,T>& matrix, T angle);

/**
 * Rotates vector around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix 2x2 orientation matrix.
 * @param angle Rotation angle (in radians).
 * @return Rotated matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
rotated(const Matrix<2,2,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

/**
 * Rotates 3x3 basis matrix around origin.
 * @tparam Space Space in which to rotate.
 * @param matrix Matrix to rotate.
 * @param angle Rotation angle (in radians).
 * @return Rotated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, T angle);

/**
 * Rotates 3x3 basis matrix around arbitrary point.
 * @tparam Space Space in which to rotate.
 * @param matrix Matrix to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 * @return Rotated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, T angle, const Vector<2,T>& point);

/**
 * Rotates 3x3 basis matrix around pivot.
 * @tparam Space Space in which to rotate.
 * @param matrix Matrix to rotate.
 * @param pivot Pivot to rotate around.
 * @param angle Rotation angle.
 * @return Rotated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, T angle, const Pivot<T>& pivot);

/**
 * Rotates 3x3 basis matrix around "transform.pivot" on angle contained in "transform.rotations".
 * @tparam Space Space in which to rotate.
 * @param matrix Matrix to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Rotates pivot around origin.
 * @param pivot Pivot to rotate.
 * @param angle Rotation angle (in radians).
 * @return Rotated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, T angle);

/**
 * Rotates pivot around arbitrary point.
 * @param pivot Pivot to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 * @return Rotated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, T angle, const Vector<2,T>& point);

/**
 * Rotates pivot around pivot.
 * @param pivot Pivot to rotate.
 * @param pivotPoint Pivot to rotate around.
 * @param angle Rotation angle.
 * @return Rotated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, T angle, const Pivot<T>& pivotPoint);

/**
 * Rotates pivot around "transform.pivot" on angle contained in "transform.rotations".
 * @param pivot Pivot to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
rotated(const Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

/**
 * Rotates axis around origin.
 * @param axis Pivot to rotate.
 * @param angle Rotation angle (in radians).
 * @return Rotated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
rotated(const ArbitraryAxis<T>& axis, T angle);

/**
 * Rotates axis around arbitrary point.
 * @param axis Pivot to rotate.
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 * @return Rotated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
rotated(const ArbitraryAxis<T>& axis, T angle, const Vector<2,T>& point);

/**
 * Rotates axis around axis.
 * @param axis Pivot to rotate.
 * @param pivotPoint Pivot to rotate around.
 * @param angle Rotation angle.
 * @return Rotated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
rotated(const ArbitraryAxis<T>& axis, T angle, const Pivot<T>& pivotPoint);

/**
 * Rotates axis around "transform.axis" on angle contained in "transform.rotations".
 * @param pivot Vector to rotate.
 * @param transforms Transformations parameters.
 * @return Rotated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
rotated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create rotation matrix (around origin).
 * @param angle Rotation angle (in radians).
 * @return Rotation matrix.
 */
template<size_t N=3, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==2 || N==3), Matrix<N,N,T>>
rotationMatrix(T angle);

/**
 * Create rotation matrix (around arbitrary point).
 * @param point Point to rotate around.
 * @param angle Rotation angle.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotationMatrix(T angle, const Vector<2,T>& point);

/**
 * Create rotation matrix (around pivot).
 * @param pivot Pivot to rotate around.
 * @param angle Rotation angle.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotationMatrix(T angle, const Pivot<T>& pivot);

/**
 * Create rotation matrix (around "transform.pivot" on angle contained in "transform.rotations").
 * @param transforms Transformations parameters.
 * @return Rotation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
rotationMatrix(const Transforms<T>& transforms);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "rotate.inl"
