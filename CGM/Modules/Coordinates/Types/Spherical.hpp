#pragma once


#include <CGM/Modules/Coordinates/ModuleGlobals.hpp>
#include <CGM/Modules/Primitives/Types/Constraints.hpp>
#include <CGM/Modules/Primitives/Types/Number.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

/**
 * Return only values clamped in range [0, PI].
 **/
template <typename T>
struct SphericalLatitudeConstraint
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

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
    Number<T, SphericalLatitudeConstraint<T>>
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