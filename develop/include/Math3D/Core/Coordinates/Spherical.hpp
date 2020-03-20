#ifndef MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Utils.hpp>


namespace coord
{

template<typename T=FLOAT>
struct Spherical
{
    MATH3D_RULE_OF_FIVE_CONSTEXPR(Spherical)

/* ####################################################################################### */
/* Components */
/* ####################################################################################### */

    T longitude;    // azimuth, horizontal
    T latitude;     // elevation, vertical
    T radius;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    constexpr
    Spherical(T InLongitude, T InLatitude, T InRadius=number<T>(1))
        : longitude(InLongitude)
        , latitude(InLatitude)
        , radius(InRadius) {}
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP
