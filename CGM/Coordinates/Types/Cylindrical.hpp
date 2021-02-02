#pragma once


#include <CGM/Coordinates/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Cylindrical
{
    CGM_RULE_OF_FIVE(Cylindrical)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Rotation angle.
     */
    Angle<T>
    angle;

    /**
     * Cylinder radius.
     */
    Length<T>
    radius;

    /**
     * Cylinder height.
     */
    Length<T>
    height;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Constructor initializing angle, height and radius. */
    constexpr
    Cylindrical(T Angle, T Height, T Radius);
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "Cylindrical.inl"