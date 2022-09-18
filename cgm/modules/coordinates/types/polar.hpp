#pragma once


#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/primitives/types/number.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Polar
{
    CGM_RULE_OF_FIVE(Polar)

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Constructor initializing angle and radius. */
    constexpr
    Polar(T Angle, T Radius);

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Rotation angle.
     */
    Angle<T>
    angle {T(0)};

    /**
     * Circle radius.
     */
    Length<T>
    radius {T(1)};
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "polar.inl"
