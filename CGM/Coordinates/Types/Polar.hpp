#pragma once


#include <CGM/Coordinates/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


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
    angle;

    /**
     * Circle radius.
     */
    Length<T>
    radius;
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "Polar.inl"