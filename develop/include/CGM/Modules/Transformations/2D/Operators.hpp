#pragma once


#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/Modules/Cartesian/2D/Operators.hpp>
#include <CGM/Modules/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/2D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/2D/Types/Transforms.hpp>


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
operator == (const CGM_XFORM2D::Pivot<T>& A, const CGM_XFORM2D::Pivot<T>& B);

/**
 * Compares two pivots for inequality.
 * @param A Pivot to compare.
 * @param B Pivot to compare with.
 * @return true if the pivots are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::Pivot<T>& A, const CGM_XFORM2D::Pivot<T>& B);

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
operator == (const CGM_XFORM2D::Transforms<T>& A, const CGM_XFORM2D::Transforms<T>& B);

/**
 * Compares two transforms for inequality.
 * @param A Transforms to compare.
 * @param B Transforms to compare with.
 * @return true if the transforms are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::Transforms<T>& A, const CGM_XFORM2D::Transforms<T>& B);

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
operator == (const CGM_XFORM2D::ArbitraryAxis<T>& A, const CGM_XFORM2D::ArbitraryAxis<T>& B);

/**
 * Compares two axis for inequality.
 * @param A Axis to compare.
 * @param B Axis to compare with.
 * @return true if the axis are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_XFORM2D::ArbitraryAxis<T>& A, const CGM_XFORM2D::ArbitraryAxis<T>& B);


#include <CGM/detail/Modules/Transformations/2D/Operators.hpp>