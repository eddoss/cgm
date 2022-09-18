#pragma once


#include <cgm/modules/core/operators/vector.hpp>
#include <cgm/modules/cartesian/3d/operators/axes.hpp>
#include <cgm/modules/transformations/3d/module_globals.hpp>
#include <cgm/modules/transformations/3d/types/ray.hpp>
#include <cgm/modules/transformations/3d/types/pivot.hpp>
#include <cgm/modules/transformations/3d/types/transforms.hpp>


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


#include "operators.inl"
