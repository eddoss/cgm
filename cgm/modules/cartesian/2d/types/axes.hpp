#pragma once


#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/cartesian/2d/module_globals.hpp>


CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Axes
{
    CGM_RULE_OF_FIVE(Axes)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<2,T> x {T(1), T(0)};
    Vector<2,T> y {T(0), T(1)};

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


#include "axes.inl"
