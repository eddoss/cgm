#pragma once


#include <CGM/Coordinates/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Spherical
{
    CGM_RULE_OF_FIVE(Spherical)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing longitude (horizontal) angle,
     * latitude (vertical) angle and sphere radius.
     */
    constexpr
    Spherical(T Longitude, T Latitude, T Radius);

/* ####################################################################################### */
public: /* Properties getters */
/* ####################################################################################### */

    /**
     * Longitude angle. Horizontal angle in radians [-2PI, 2PI].
     */
    Angle<T>
    longitude;

    /**
     * Latitude angle. Vertical angle in radians [-PI, PI].
     */
    Angle_PI_PI<T>
    latitude;

    /**
     * Sphere radius.
     */
    Length<T>
    radius;
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "Spherical.inl"