#pragma once


#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/primitives/types/constraints.hpp>
#include <cgm/modules/primitives/types/number.hpp>


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
    longitude {T(0)};

    /**
     * Latitude angle. Vertical angle in radians [-PI, PI].
     */
    Number<T, SphericalLatitudeConstraint<T>>
    latitude {T(0)};

    /**
     * Sphere radius.
     */
    Length<T>
    radius {T(1)};
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "spherical.inl"
