#ifndef MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP


#include <Math3D/Global.hpp>


namespace coord
{

template<typename T>
struct Spherical
{

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

    ~Spherical()                    = default;

    constexpr
    Spherical()                     = default;

    constexpr
    Spherical(Spherical&&) noexcept = default;

    constexpr
    Spherical(const Spherical&)     = default;
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_SPHERICAL_HPP
