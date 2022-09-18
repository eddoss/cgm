#pragma once


#include <cgm/shapes/2d/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/primitives/types/number.hpp>


CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Circle
{
    CGM_RULE_OF_FIVE(Circle)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Circle center.
     */
    Vector<2,T>
    center {T(0), T(0)};

    /**
     * Circle radius.
     */
    Length<T>
    radius {T(1)};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize position and size.
     * @param position Circle center.
     * @param radius Circle radius.
     */
    constexpr
    Circle(Vector<2,T> Position, T Radius);

    /**
     * Initialize radius (position is 0).
     * @param radius Circle radius.
     */
    constexpr explicit
    Circle(T Radius);
};

CGM_2D_NAMESPACE_END


#include "circle.inl"
