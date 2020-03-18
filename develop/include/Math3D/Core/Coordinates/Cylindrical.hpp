#ifndef MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP
#define MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP


#include <Math3D/Global.hpp>


namespace coord
{

template<typename T>
struct Cylindrical
{

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

    ~Cylindrical()                      = default;

    constexpr
    Cylindrical()                       = default;

    constexpr
    Cylindrical(Cylindrical&&) noexcept = default;

    constexpr
    Cylindrical(const Cylindrical&)     = default;
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_CYLINDRICAL_HPP
