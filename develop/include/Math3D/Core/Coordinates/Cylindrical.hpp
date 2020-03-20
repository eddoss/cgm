#ifndef MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP


#include <Math3D/Global.hpp>
#include <Math3D/Utils.hpp>

namespace coord
{

template<typename T=FLOAT>
struct Cylindrical
{
    MATH3D_RULE_OF_FIVE_CONSTEXPR(Cylindrical)

/* ####################################################################################### */
/* Components */
/* ####################################################################################### */

    T angle;
    T height;
    T radius;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    constexpr
    Cylindrical(T InAngle, T InHeight, T InRadius=number<T>(1))
        : angle(InAngle)
        , height(InHeight)
        , radius(InRadius) {}
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP
