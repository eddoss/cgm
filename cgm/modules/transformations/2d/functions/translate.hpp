#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/cartesian/2d/functions/axes.hpp>
#include <cgm/modules/cartesian/2d/functions/orientation.hpp>
#include <cgm/modules/cartesian/2d/functions/converters/vector.hpp>
#include <cgm/modules/transformations/common.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>
#include <cgm/modules/transformations/2d/types/pivot.hpp>
#include <cgm/modules/transformations/2d/types/arbitrary_axis.hpp>
#include <cgm/modules/transformations/2d/types/transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Translate vector along default Cartesian axis.
 * @tparam Axis Cartesian axis to translate along which.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, T value);

/**
 * Translate vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Translate vector along other vector. Result offset is depend on other vector length.
 * @param vector Vector to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, T value, const Vector<2,T>& along);

/**
 * Translate vector along pivot axes.
 * @param vector Vector to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Vector<2,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Translates basis matrix along default Cartesian axis.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, T value);

/**
 * Translates basis matrix by vector.
 * @tparam Axis Cartesian axis to translate along which.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Vector<2,T>& value);

/**
 * Translate basis matrix along other vector. Result offset is depend on other vector length.
 * @tparam Space In which space to translate.
 * @tparam AlongRepr Representation of 'along' vector. Its affect when 'Space == Local'.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 */
template<ESpace Space = ESpace::Global, EVectorRepresentation AlongRepr=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, T value, const Vector<2,T>& along);

/**
 * Translate basis matrix along pivot axes.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates basis matrix using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Matrix<3,3,T>& basis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Translates pivot along default Cartesian axis.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, T value);

/**
 * Translate pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Vector<2,T>& value);

/**
 * Translate pivot along other vector. Result offset is depend on vector length.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, T value, const Vector<2,T>& along);

/**
 * Translate pivot along other pivot axes.
 * @param pivot Pivot to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivotPoint Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Translates pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Translates axis along default Cartesian axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, T value);

/**
 * Translate axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& value);

/**
 * Translate axis along other vector. Result offset is depend on other vector length.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along);

/**
 * Translate axis along pivot axes.
 * @param axis Arbitrary axis to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates axis using "transforms.translations".
 * @param axis Arbitrary axis to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
translate(ArbitraryAxis<T>& axis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

/**
 * Translate vector along default Cartesian axis.
 * @tparam Axis Cartesian axis to translate along which.
 * @param vector Vector to translate.
 * @param value How much to translate.
 * @return Translated vector.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, T value);

/**
 * Translate vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Vector<2,T>& value);

/**
 * Translate vector along other vector. Result offset is depend on other vector length.
 * @param vector Vector to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, T value, const Vector<2,T>& along);

/**
 * Translate vector along pivot axes.
 * @param vector Vector to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
translated(const Vector<2,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

/**
 * Translates transform matrix along default Cartesian axis.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 * @return Translated matrix.
 */
template<E2D Axis, ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, T value);

/**
 * Translates transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, const Vector<2,T>& value);

/**
 * Translate basis matrix along other vector. Result offset is depend on other vector length.
 * @tparam Space In which space to translate.
 * @tparam AlongRepr Representation of 'along' vector.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::Global, EVectorRepresentation AlongRepr=EVectorRepresentation::Point, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& basis, T value, const Vector<2,T>& along);

/**
 * Translate basis matrix along pivot axes.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& basis, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates transform matrix using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param transforms Transformations parameters.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::Global, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Translates pivot along default Cartesian axis.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 * @return Translated pivot.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, T value);

/**
 * Translate pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Vector<2,T>& value);

/**
 * Translate axis along other vector. Result offset is depend on other vector length.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, T value, const Vector<2,T>& along);

/**
 * Translate axis along pivot axes.
 * @param axis Arbitrary axis to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivotPoint Pivot point.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Vector<2,T>& values, const Pivot<T>& pivotPoint);

/**
 * Translates pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
translated(const Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

/**
 * Translates axis along default Cartesian axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @return Translated axis.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, T value);

/**
 * Translate axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& value);

/**
 * Translate axis along other vector. Result offset is depend on other vector length.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @param along Vector to translate along to.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, T value, const Vector<2,T>& along);

/**
 * Translate axis along pivot axes.
 * @param axis Arbitrary axis to translate.
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Translates axis using "transforms.translations".
 * @param axis Arbitrary axis to translate.
 * @param transforms Transformations parameters.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
translated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create 4x4 translation matrix (along default Cartesian axis in global space).
 * @tparam Axis Cartesian axis to translate along which.
 * @param value How much to translate.
 * @return Translation matrix.
 */
template<E2D Axis, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(T value);

/**
 * Create 4x4 translation matrix (on given value in global space).
 * @param values How much to translate.
 * @return Translation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Vector<2,T>& values);

/**
 * Create 4x4 translation matrix (along other vector, result offset is depend on other vector length).
 * @param value How much to translate.
 * @param along Vector to translate along to.
 * @return Translation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(T value, const Vector<2,T>& along);

/**
 * Create 4x4 translation matrix (along pivot axes).
 * @param values How much to translate (value per pivot axis).
 * @param pivot Pivot point.
 * @return Translation axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Vector<2,T>& values, const Pivot<T>& pivot);

/**
 * Create 4x4 translation matrix (on value from "transforms.translations" in global space).
 * @param value How much to translate.
 * @return Translation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
translationMatrix(const Transforms<T>& transforms);

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "translate.inl"
