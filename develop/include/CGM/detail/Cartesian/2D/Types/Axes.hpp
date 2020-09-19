#pragma once


#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Cartesian/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

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

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Cartesian/2D/Types/Axes_impl.hpp>