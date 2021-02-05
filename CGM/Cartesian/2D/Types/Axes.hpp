#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Cartesian/2D/ModuleGlobals.hpp>


CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Axes
{
    CGM_RULE_OF_FIVE(Axes)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<2,T> x;
    Vector<2,T> y;

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all axes.
     */
    constexpr
    Axes(const Vector<2,T>& X, const Vector<2,T>& Y);
};

CGM_2D_NAMESPACE_END


#include "Axes.inl"