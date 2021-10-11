#pragma once


#include <CGM/Modules/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

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
    Vector<3,T>
    position {T(0), T(0), T(0)};

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all axes. Position is {0,0,0}.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     * @param Z Pivot Z axis.
     */
    constexpr
    Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z);

    /**
     * Initialize all axes. Position is {0,0,0}.
     * @param orientationAxes Pivot orientation axes.
     */
    explicit constexpr
    Pivot(const Axes<T>& orientationAxes);

    /**
     * Initialize all axes and position.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     * @param Z Pivot Z axis.
     * @param P Pivot position.
     */
    constexpr
    Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z, const Vector<3,T>& P);

    /**
     * Initialize all axes and position.
     * @param orientationAxes Pivot orientation axes.
     * @param P Pivot position.
     */
    constexpr
    Pivot(const Axes<T>& orientationAxes, const Vector<3,T>& P);
};

CGM_NAMESPACE_END


#include "Pivot.inl"