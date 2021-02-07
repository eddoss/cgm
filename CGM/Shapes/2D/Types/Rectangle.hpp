#pragma once


#include <CGM/Utils/Functions/Numbers.hpp>
#include <CGM/Utils/Functions/Comparison.hpp>
#include <CGM/Shapes/2D/ModuleGlobals.hpp>
#include <CGM/Shapes/2D/Types/Size.hpp>
#include <CGM/Core/Types/Vector.hpp>


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
    center;

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
    Rectangle(const Vector<2,T>& Position, const Size<T>& SizeValue);


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