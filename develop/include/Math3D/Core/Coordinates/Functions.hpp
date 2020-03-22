#ifndef MATH3D_COORDINATES_SYSTEMS_FUNCTIONS_HPP
#define MATH3D_COORDINATES_SYSTEMS_FUNCTIONS_HPP


#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Coordinates/Polar.hpp>
#include <Math3D/Core/Coordinates/Spherical.hpp>
#include <Math3D/Core/Coordinates/Cylindrical.hpp>


namespace coord
{

/* ####################################################################################### */
/* Convert to Cartesian system */
/* ####################################################################################### */

/**
 * Convert polar coordinate to cartesian coordinate.
 * @param coord Polar coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Vector<2,T>
cartesian(const Polar<T>& coord);

/**
 * Convert spherical coordinate to cartesian coordinate.
 * @param coord Spherical coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Vector<3,T>
cartesian(const Spherical<T>& coord);

/**
 * Convert cylindrical coordinate to cartesian coordinate.
 * @param coord Cylindrical coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Vector<3,T>
cartesian(const Cylindrical<T>& coord);

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

/**
 * Convert cartesian coordinate to polar coordinate.
 * @param coord Cartesian coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Polar<T>
polar(const Vector<2,T>& coord);

/* ####################################################################################### */
/* Convert to Spherical system */
/* ####################################################################################### */

/**
 * Convert cartesian coordinate to spherical coordinate.
 * @param coord Cartesian coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Spherical<T>
spherical(const Vector<3,T>& coord);

/**
 * Convert cylindrical coordinate to cylindrical coordinate.
 * @param coord Cylindrical coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Spherical<T>
spherical(const Cylindrical<T>& coord);

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

/**
 * Convert spherical coordinate to cylindrical coordinate.
 * @param coord Cylindrical coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Cylindrical<T>
cylindrical(const Spherical<T>& coord);

/**
 * Convert cartesian coordinate to cylyndrical coordinate.
 * @param coord Cartesian coordinate to convert.
 * @return converted coordinate.
 */
template<typename T>
Cylindrical<T>
cylindrical(const Vector<3,T>& coord);

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<typename T>
Vector<2,T>
cartesian(const Polar<T>& coord)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Spherical<T>& coord)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
cartesian(const Cylindrical<T>& coord)
{

}

/* ####################################################################################### */
/* Convert to Polar system */
/* ####################################################################################### */

template<typename T>
Polar<T>
polar(const Vector<2,T>& coord)
{

}

/* ####################################################################################### */
/* Convert to Spherical system */
/* ####################################################################################### */

template<typename T>
Spherical<T>
spherical(const Vector<3,T>& coord)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Spherical<T>
spherical(const Cylindrical<T>& coord)
{

}

/* ####################################################################################### */
/* Convert to Cylindrical system */
/* ####################################################################################### */

template<typename T>
Cylindrical<T>
cylindrical(const Spherical<T>& coord)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Cylindrical<T>
cylindrical(const Vector<3,T>& coord)
{

}

};

#endif // MATH3D_COORDINATES_SYSTEMS_FUNCTIONS_HPP
