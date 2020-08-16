#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Operators/MatrixVectorMultiplication.hpp>
#include <CGM/Modules/Core/Functions/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>
#include <CGM/Modules/Transformations/3D/Functions/Utils.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

/**
 * Scales vector related to world center.
 * @tparam Space In which space to transform.
 * @param vector Vector to scale.
 * @param values How much to scale (value per axis).
 */
 template<typename T>
constexpr CGM_FORCEINLINE void
scale(Vector<3,T>& vector, const Vector<3,T>& values);

/**
 * Scales vector related to pivot point.
 * @param vector Vector to scale.
 * @param value How much to scale (value per axis).
 * @param pivot Pivot point.
 */
template<typename T>
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
/* Matrix3 */
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
/* Matrix4 */
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
/* Pivot */
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

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Scale.hpp>