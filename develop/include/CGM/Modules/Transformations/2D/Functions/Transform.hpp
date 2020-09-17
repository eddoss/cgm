#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Functions/Matrix.hpp>
#include <CGM/Modules/Cartesian/Common.hpp>
#include <CGM/Modules/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/2D/Types/Transforms.hpp>
#include <CGM/Modules/Transformations/2D/Functions/Translate.hpp>
#include <CGM/Modules/Transformations/2D/Functions/Scale.hpp>
#include <CGM/Modules/Transformations/2D/Functions/Rotate.hpp>
#include <CGM/Modules/Transformations/2D/Functions/Converters/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

/**
 * Transform vector.
 * @param vector Vector to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
transform(Vector<2,T>& vector, const Transforms<T>& parameters);

/**
 * Transform 3x3 matrix (just rotate and scale).
 * @param matrix 3x3 matrix to transform.
 * @param parameters Transformation parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
transform(Matrix<2,2,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform 4x4 matrix.
 * @param matrix 4x4 matrix to transform.
 * @param parameters Transformation parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
transform(Matrix<3,3,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform pivot. All transformations for pivot position and just
 * rotate for axes.
 * @param pivot Pivot to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
transform(Pivot<T>& pivot, const Transforms<T>& parameters);

/**
 * Transform arbitrary axis. All transformations for axis position
 * and just rotate for direction.
 * @param axis Axis to transform.
 * @param parameters Transformation parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
transform(ArbitraryAxis<T>& axis, const Transforms<T>& parameters);

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

/**
 * Transform vector.
 * @param vector Vector to transform.
 * @param parameters Transformation parameters.
 * @return Transformed vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
transformed(const Vector<2,T>& vector, const Transforms<T>& parameters);

/**
 * Transform 3x3 matrix (just rotate and scale).
 * @param matrix 3x3 matrix to transform.
 * @param parameters Transformation parameters.
 * @return Transformed matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
transformed(const Matrix<2,2,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform 4x4 matrix.
 * @param matrix 4x4 matrix to transform.
 * @param parameters Transformation parameters.
 * @return Transformed matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
transformed(const Matrix<3,3,T>& matrix, const Transforms<T>& parameters);

/**
 * Transform pivot. All transformations for pivot position and just
 * rotate for axes.
 * @param pivot Pivot to transform.
 * @param parameters Transformation parameters.
 * @return Transformed pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
transformed(const Pivot<T>& pivot, const Transforms<T>& parameters);

/**
 * Transform arbitrary axis. All transformations for axis position
 * and just rotate for direction.
 * @param axis Axis to transform.
 * @param parameters Transformation parameters.
 * @return Transformed axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
transformed(const ArbitraryAxis<T>& axis, const Transforms<T>& parameters);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create 4x4 transformation matrix.
 * @param parameters Transformation parameters.
 * @return Transformation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
transformMatrix(const Transforms<T>& parameters);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/2D/Functions/Transform.hpp>
