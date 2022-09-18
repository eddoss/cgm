#pragma once


#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/coordinates/types/polar.hpp>
#include <cgm/modules/coordinates/types/spherical.hpp>
#include <cgm/modules/coordinates/types/cylindrical.hpp>


/* ####################################################################################### */
/* Polar */
/* ####################################################################################### */

/**
 * Checking the components of a Polar coord for equality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_COORD::Polar<T>& A, const CGM_COORD::Polar<T>& B);

/**
 * Checking the components of a Polar coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_COORD::Polar<T>& A, const CGM_COORD::Polar<T>& B);

/* ####################################################################################### */
/* Spherical */
/* ####################################################################################### */

/**
 * Checking the components of a Spherical coord for equality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_COORD::Spherical<T>& A, const CGM_COORD::Spherical<T>& B);

/**
 * Checking the components of a Spherical coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_COORD::Spherical<T>& A, const CGM_COORD::Spherical<T>& B);

/* ####################################################################################### */
/* Cylindrical */
/* ####################################################################################### */

/**
 * Checking the components of a Cylindrical coord for equality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are equal, false otherwise.
 */
template<typename T>
constexpr bool
operator == (const CGM_COORD::Cylindrical<T>& A, const CGM_COORD::Cylindrical<T>& B);

/**
 * Checking the components of a Cylindrical coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const CGM_COORD::Cylindrical<T>& A, const CGM_COORD::Cylindrical<T>& B);


#include "operators.inl"
