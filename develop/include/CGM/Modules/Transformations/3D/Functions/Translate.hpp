#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Basis.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Typedefs.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

/**
 * Translate 3D vector.
 * @param vector Vector to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value);

/**
 * Translates 3D vector using "transforms.translations".
 * @param vector Vector to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

/**
 * Translates 3D transform matrix by vector.
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value);

/**
 * Translates 3D transform matrix using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param matrix Matrix to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
translate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

/**
 * Translate 3D pivot.
 * @param pivot Pivot to translate.
 * @param value How much to translate.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<3,T>& value);

/**
 * Translates 3D pivot using "transforms.translations".
 * @param pivot Pivot to translate.
 * @param transforms Transformations parameters.
 */
template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Transforms<T>& transforms);

/* ####################################################################################### */
/* SpaceTuple */
/* ####################################################################################### */

/**
 * Translates 3D space tuple by vector.
 * @tparam Space In which space to translate.
 * @param space Space tuple to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
translate(SpaceTuple<T>& space, const Vector<3,T>& value);

/**
 * Translates 3D space tuple using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param space Space tuple to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, typename T>
constexpr CGM_FORCEINLINE void
translate(SpaceTuple<T>& space, const Transforms<T>& transforms);

/* ####################################################################################### */
/* Basis struct */
/* ####################################################################################### */

/**
 * Translates 3D basis struct by vector.
 * @tparam Space In which space to translate.
 * @param basis Basis to translate.
 * @param value How much to translate.
 */
template<ESpace Space = ESpace::Local, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
translate(Basis<Base,T>& basis, const Vector<3,T>& value);

/**
 * Translates 3D basis struct using "transforms.translations".
 * @tparam Space In which space to translate.
 * @param basis Basis to translate.
 * @param transforms Transformations parameters.
 */
template<ESpace Space = ESpace::Local, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
translate(Basis<Base,T>& basis, const Transforms<T>& transforms);

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
