#pragma once


#include <CGM/Core/Operators/Vector.hpp>
#include <CGM/Cartesian/3D/Operators/Axes.hpp>
#include <CGM/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Transformations/3D/Types/Ray.hpp>
#include <CGM/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Transformations/3D/Types/Transforms.hpp>


/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

/**
 * Compares two pivots for equality.
 * @param A Pivot to compare.
 * @param B Pivot to compare with.
 * @return true if the pivots are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM::Pivot<T>& A, const CGM::Pivot<T>& B);

/**
 * Compares two pivots for inequality.
 * @param A Pivot to compare.
 * @param B Pivot to compare with.
 * @return true if the pivots are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM::Pivot<T>& A, const CGM::Pivot<T>& B);

/* ####################################################################################### */
/* Transforms */
/* ####################################################################################### */

/**
 * Compares two transforms for equality.
 * @param A Transforms to compare.
 * @param B Transforms to compare with.
 * @return true if the transforms are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM::Transforms<T>& A, const CGM::Transforms<T>& B);

/**
 * Compares two transforms for inequality.
 * @param A Transforms to compare.
 * @param B Transforms to compare with.
 * @return true if the transforms are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM::Transforms<T>& A, const CGM::Transforms<T>& B);

/* ####################################################################################### */
/* Axis */
/* ####################################################################################### */

/**
 * Compares two axis for equality.
 * @param A Axis to compare.
 * @param B Axis to compare with.
 * @return true if the axis are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM::Ray<T>& A, const CGM::Ray<T>& B);

/**
 * Compares two axis for inequality.
 * @param A Axis to compare.
 * @param B Axis to compare with.
 * @return true if the axis are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM::Ray<T>& A, const CGM::Ray<T>& B);


#include "Operators.inl"