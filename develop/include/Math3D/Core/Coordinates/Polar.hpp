#ifndef MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
#define MATH3D_COORDINATES_SYSTEMS_POLAR_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Utils.hpp>


namespace coord
{

template<typename T=FLOAT>
struct Polar
{
    MATH3D_RULE_OF_FIVE_CONSTEXPR(Polar)

/* ####################################################################################### */
/* Components */
/* ####################################################################################### */

    T angle;
    T radius;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    constexpr explicit
    Polar(T InAngle, T InRadius=number<T>(1))
        : angle(InAngle)
        , radius(InRadius) {}
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
