#ifndef MATH3D_COORDINATE_SYSTEMS_OPERATORS_HPP
#define MATH3D_COORDINATE_SYSTEMS_OPERATORS_HPP


#include <Math3D/Common.hpp>
#include <Math3D/Core/Coordinates/Polar.hpp>
#include <Math3D/Core/Coordinates/Spherical.hpp>
#include <Math3D/Core/Coordinates/Cylindrical.hpp>


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
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& B);

/**
 * Checking the components of a Polar coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& B);

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
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& B);

/**
 * Checking the components of a Spherical coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& B);

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
operator == (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& B);

/**
 * Checking the components of a Cylindrical coord for inequality.
 * @param A First coord.
 * @param B Second coord.
 * @return true if components of the coord are not equal, false otherwise.
 */
template<typename T>
constexpr bool
operator != (const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& A, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& B);


#include <private/Math3D/Core/Coordinates/Operators.hpp>


#endif // MATH3D_COORDINATE_SYSTEMS_OPERATORS_HPP
