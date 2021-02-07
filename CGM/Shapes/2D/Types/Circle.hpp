#pragma once


#include <CGM/Shapes/2D/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>
#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Core/Types/Vector.hpp>


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
    center;

    /**
     * Circle radius.
     */
    Length<T>
    radius;

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


#include "Circle.inl"