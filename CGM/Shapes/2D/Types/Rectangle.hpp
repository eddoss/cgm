#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Shapes/2D/ModuleGlobals.hpp>
#include <CGM/Shapes/2D/Types/Size.hpp>
#include <CGM/Core/Types/Vector.hpp>


CGM_NAMESPACE_BEGIN
CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Rectangle
{
    CGM_RULE_OF_FIVE(Rectangle)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Rectangle position (rectangle center).
     */
    Vector<2,T>
    position;

    /**
     * Rectangle size.
     */
    Size<T>
    size;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize position and size.
     */
    constexpr
    Rectangle(const Vector<2,T>& Position, const Size<T>& Size);
};

CGM_2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Rectangle.inl"