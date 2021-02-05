#pragma once


#include <CGM/Shapes/2D/ModuleGlobals.hpp>
#include <CGM/Utils/Types/Number.hpp>


CGM_NAMESPACE_BEGIN
CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Size
{
    CGM_RULE_OF_FIVE(Size)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Rectangle width.
     */
    Length<T>
    w;

    /**
     * Rectangle height.
     */
    Length<T>
    h;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize width and height.
     * @param width Rectangle width.
     * @param height Rectangle height.
     */
    constexpr
    Size(T width, T height);

    /**
     * Initialize width and height by the same value.
     * @param value Rectangle width and height value.
     */
    constexpr explicit
    Size(T value);
};

CGM_2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Size.inl"