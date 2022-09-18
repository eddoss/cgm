#pragma once


#include <cgm/modules/cartesian/2d/types/axes.hpp>
#include <cgm/modules/transformations/2d/module_globals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Pivot
{
    CGM_RULE_OF_FIVE(Pivot)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    /** Orientation axes. */
    Axes<T>
    axes {};

    /** Pivot position. */
    Vector<2,T>
    position {T(0), T(0)};

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all axes. Position is {0,0}.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     */
    constexpr
    Pivot(const Vector<2,T>& X, const Vector<2,T>& Y);

    /**
     * Initialize all axes. Position is {0,0}.
     * @param orientationAxes Pivot orientation axes.
     */
    explicit constexpr
    Pivot(const Axes<T>& orientationAxes);

    /**
     * Initialize all axes and position.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     * @param P Pivot position.
     */
    constexpr
    Pivot(const Vector<2,T>& X, const Vector<2,T>& Y, const Vector<2,T>& P);

    /**
     * Initialize all axes and position.
     * @param orientationAxes Pivot orientation axes.
     * @param P Pivot position.
     */
    constexpr
    Pivot(const Axes<T>& orientationAxes, const Vector<2,T>& P);
};

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "pivot.inl"
