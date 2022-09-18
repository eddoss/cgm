#pragma once


#include <cgm/modules/coordinates/module_globals.hpp>
#include <cgm/modules/primitives/types/number.hpp>


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
    angle {T(0)};

    /**
     * Cylinder radius.
     */
    Length<T>
    radius {T(1)};

    /**
     * Cylinder height.
     */
    Length<T>
    height {T(1)};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Constructor initializing angle, height and radius. */
    constexpr
    Cylindrical(T Angle, T Height, T Radius);
};

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END


#include "cylindrical.inl"
