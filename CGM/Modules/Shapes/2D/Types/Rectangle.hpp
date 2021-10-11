#pragma once


#include <CGM/Modules/Primitives/Functions/Numbers.hpp>
#include <CGM/Modules/Primitives/Functions/Comparison.hpp>
#include <CGM/Shapes/2D/ModuleGlobals.hpp>
#include <CGM/Modules/Core/Types/Size.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>


CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Rectangle
{
    CGM_RULE_OF_FIVE(Rectangle)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Rectangle position.
     */
    Vector<2,T>
    center {T(0), {T(0)}};

    /**
     * Rectangle size.
     */
    Size<2,T>
    size {T(1), {T(1)}};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize position and size.
     */
    constexpr
    Rectangle(const Vector<2,T>& Position, const Size<2,T>& SizeValue);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets top let corner position.
     * @return Top let corner position
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    topLeft() const;
    
    /**
     * Gets top right corner position.
     * @return Top right corner position
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    topRight() const;
    
    /**
     * Gets bottom let corner position.
     * @return Bottom let corner position
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    bottomLeft() const;
    
    /**
     * Gets bottom right corner position.
     * @return Bottom right corner position
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    bottomRight() const;
};

CGM_2D_NAMESPACE_END


#include "Rectangle.inl"