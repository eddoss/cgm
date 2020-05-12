#ifndef MATH3D_COORDINATE_SYSTEMS_FUNCTIONS_HPP
#define MATH3D_COORDINATE_SYSTEMS_FUNCTIONS_HPP


#include <cmath>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Coordinates/Polar.hpp>
#include <Math3D/Coordinates/Spherical.hpp>
#include <Math3D/Coordinates/Cylindrical.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_COORD_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector component extractors */
/* ####################################################################################### */

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
right(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
up(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Reference to component.
 */
template<typename T>
constexpr FORCEINLINE T&
forward(Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Right" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
right(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Up" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
up(const Vector<3,T>& coord);

/**
 * Extracts the vector component responsible for "Forward" axis coordinate.
 * @return Const reference to component.
 */
template<typename T>
constexpr FORCEINLINE const T&
forward(const Vector<3,T>& coord);

/* ####################################################################################### */
/* Convert to Cartesian system */
/* ####################################################################################### */

/**
 * Create cartesian coordinate from polar coordinate.
 * @param coord Polar coordinate to create from.
 * @return 2D Cartesian coord.
 */
template<typename T>
constexpr FORCEINLINE Vector<2,T>
cartesian(const Polar<T>& coord);

/**
 * Create cartesian coordinate from spherical coordinate.
 * @param coord Spherical coordinate to create from.
 * @return 3D Cartesian coord.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
cartesian(const Spherical<T>& coord);

/**
 * Create cartesian coordinate from cylindrical coordinate.
 * @param coord Cylindrical coordinate to create from.
 * @return 3D Cartesian coord.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
cartesian(const Cylindrical<T>& coord);

/**
 * Create Cartesian coordinate independently from axes labels.
 * @param right Right component of coord.
 * @param up Up component of coord.
 * @param forward Forward component of coord.
 */
template<typename T>
constexpr FORCEINLINE Vector<3,T>
cartesian(T right, T up, T forward);

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

/**
 * Create Polar coordinate from 2D Cartesian coord.
 * @param coord 2D Cartesian coordinate to create from.
 * @return Polar coord.
 */
template<typename T>
constexpr FORCEINLINE Polar<T>
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
constexpr FORCEINLINE Spherical<T>
spherical(const Vector<3,T>& coord);

/**
 * Create Spherical coordinate from Cylindrical coord.
 * @param coord Cylindrical coordinate to create from.
 * @return Spherical coord.
 */
template<typename T>
constexpr FORCEINLINE Spherical<T>
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
constexpr FORCEINLINE Cylindrical<T>
cylindrical(const Spherical<T>& coord);

/**
 * Create Cylindrical coordinate from Cartesian coord.
 * @param coord Cartesian coordinate to create from.
 * @return Cylindrical coord.
 */
template<typename T>
constexpr FORCEINLINE Cylindrical<T>
cylindrical(const Vector<3,T>& coord);

MATH3D_COORD_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Coordinates/Functions.hpp>


#endif // MATH3D_COORDINATES_SYSTEMS_FUNCTIONS_HPP
