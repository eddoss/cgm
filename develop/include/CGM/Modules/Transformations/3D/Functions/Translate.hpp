#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Axes.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Converters/Vector.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

/**
 * Translate vector along default Cartesian axis.
 * @tparam Axis Cartesian axis to translate along which.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, T value);

/**
 * Translate vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translates vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

/**
 * Translates transform matrix along default Cartesian axis.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, T value);

/**
 * Translates transform matrix by vector.
 * @tparam Axis Cartesian axis to translate along which.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translates transform matrix using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

/**
 * Translates pivot along default Cartesian axis.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, T value);

/**
 * Translate pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<3,T>& value);

/**
 * Translates pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

/**
 * Translates axis along default Cartesian axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, T value);

/**
 * Translate axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(ArbitraryAxis<T>& axis, const Vector<3,T>& value);

/**
 * Translates axis using "transforms.translations".
 * @param axis Arbitrary axis to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, T value);

/**
 * Translate vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translates vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 * @return Translated vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, const Transforms<T>& transforms);

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
template<EAxes Axis, ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, T value);

/**
 * Translates transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translates transform matrix using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param transforms Transformations parameters.
 * @return Translated matrix.
 */
template<ESpace Space = ESpace::World, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

/**
 * Translates pivot along default Cartesian axis.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 * @return Translated pivot.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, T value);

/**
 * Translate pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Vector<3,T>& value);

/**
 * Translates pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 * @return Translated pivot.
 */
template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
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
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, T value);

/**
 * Translate axis.
 * @param axis Arbitrary axis to translate.
 * @param value How much to translate.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, const Vector<3,T>& value);

/**
 * Translates axis using "transforms.translations".
 * @param axis Arbitrary axis to translate.
 * @param transforms Transformations parameters.
 * @return Translated axis.
 */
template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
translated(const ArbitraryAxis<T>& axis, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

/**
 * Create 4x4 translation matrix (along default Cartesian axis in world space).
 * @tparam Axis Cartesian axis to translate along which.
 * @param value How much to translate.
 * @return Translation matrix.
 */
template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(T value);

/**
 * Create 4x4 translation matrix (on given value in world space).
 * @param values How much to translate.
 * @return Translation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Vector<3,T>& values);

/**
 * Create 4x4 translation matrix (on value from "transforms.translations" in world space).
 * @param value How much to translate.
 * @return Translation matrix.
 */
template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Transforms<T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Functions/Translate.hpp>
