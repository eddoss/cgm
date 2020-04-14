#ifndef MATH3D_XFORM_OPERATORS_HPP
#define MATH3D_XFORM_OPERATORS_HPP


#include <Math3D/Common.hpp>
#include <Math3D/XForm/Pivot.hpp>
#include <Math3D/XForm/Transforms.hpp>
#include <Math3D/XForm/EulerAngles.hpp>


/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

/**
 * Compares two pivots for equality.
 * @param A Pivot to compare.
 * @param B Pivot to compare with.
 * @return true if the pivots are equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& B);

/**
 * Compares two pivots for inequality.
 * @param A Pivot to compare.
 * @param B Pivot to compare with.
 * @return true if the pivots are not equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Pivot<D,T>& B);

/* ####################################################################################### */
/* Transforms */
/* ####################################################################################### */

/**
 * Compares two transforms for equality.
 * @param A Transforms to compare.
 * @param B Transforms to compare with.
 * @return true if the transforms are equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& B);

/**
 * Compares two transforms for inequality.
 * @param A Transforms to compare.
 * @param B Transforms to compare with.
 * @return true if the transforms are not equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::Transforms<D,T>& B);

/* ####################################################################################### */
/* Euler angles */
/* ####################################################################################### */

/**
 * Compares two Euler angles for equality.
 * @param A Angles to compare.
 * @param B Angles to compare with.
 * @return true if the angles are equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator == (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& B);

/**
 * Compares two Euler angles for inequality.
 * @param A Angles to compare.
 * @param B Angles to compare with.
 * @return true if the angles are not equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& A, const MATH3D_NAMESPACE::MATH3D_XFORM_NAMESPACE::EulerAngles<T>& B);


#include <private/Math3D/XForm/Operators.hpp>


#endif // MATH3D_XFORM_OPERATORS_HPP
