#ifndef MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
#define MATH3D_COORDINATES_SYSTEMS_POLAR_HPP


#include <Math3D/Global.hpp>


namespace coord
{

template<typename T>
struct Polar
{

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

    ~Polar()                    = default;

    constexpr
    Polar()                     = default;

    constexpr
    Polar(Polar&&) noexcept     = default;

    constexpr
    Polar(const Polar&)         = default;
};

};

#endif // MATH3D_COORDINATES_SYSTEMS_POLAR_HPP
