#pragma once


#include <cmath>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/coordinates/types/polar.hpp>
#include <cgm/modules/coordinates/types/spherical.hpp>
#include <cgm/modules/coordinates/types/cylindrical.hpp>
#include <cgm/modules/coordinates/functions/vector_components.hpp>
#include <cgm/modules/utils/type_traits.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Convert to Cartesian system */
/* ####################################################################################### */

/**
 * Create cartesian coordinate from polar coordinate.
 * @param coord Polar coordinate to create from.
 * @return 2D Cartesian coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
cartesian(const Polar<T>& coord);

/**
 * Create cartesian coordinate from spherical coordinate.
 * @param coord Spherical coordinate to create from.
 * @return 3D Cartesian coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(const Spherical<T>& coord);

/**
 * Create cartesian coordinate from cylindrical coordinate.
 * @param coord Cylindrical coordinate to create from.
 * @return 3D Cartesian coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(const Cylindrical<T>& coord);

/**
 * Create 3D cartesian coordinate independently from axes labels.
 * @param up Up component of coord.
 * @param right Right component of coord.
 * @param forward Forward component of coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<3,T>>
cartesian(T up, T right, T forward);

/**
 * Create 4D cartesian vector independently from axes labels.
 * @param up Up component of coord.
 * @param right Right component of coord.
 * @param forward Forward component of coord.
 * @param homogeneous Homogeneous component of vector.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<4,T>>
cartesian(T up, T right, T forward, T homogeneous);

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

/**
 * Create Polar coordinate from 2D Cartesian coord.
 * @param coord 2D Cartesian coordinate to create from.
 * @return Polar coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Polar<T>>
polar(const Vector<2,T>& coord);

/* ####################################################################################### */
/* Convert to Spherical system */
/* ####################################################################################### */

/**
 * Create Spherical coordinate from Cartesian coord.
 * @param coord Cartesian coordinate to create from.
 * @return Spherical coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Spherical<T>>
spherical(const Vector<3,T>& coord);

/**
 * Create Spherical coordinate from Cylindrical coord.
 * @param coord Cylindrical coordinate to create from.
 * @return Spherical coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Spherical<T>>
spherical(const Cylindrical<T>& coord);

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

/**
 * Create Cylindrical coordinate from Spherical coord.
 * @param coord Spherical coordinate to create from.
 * @return Cylindrical coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Cylindrical<T>>
cylindrical(const Spherical<T>& coord);

/**
 * Create Cylindrical coordinate from Cartesian coord.
 * @param coord Cartesian coordinate to create from.
 * @return Cylindrical coord.
 */
template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Cylindrical<T>>
cylindrical(const Vector<3,T>& coord);

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "converters.inl"
