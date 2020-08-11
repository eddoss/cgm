#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Pivot
{
    CGM_RULE_OF_FIVE(Pivot)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<3,T> x;           ///< X axes.
    Vector<3,T> y;           ///< Y axes.
    Vector<3,T> z;           ///< Z axes.
    Vector<3,T> position;    ///< Pivot position.

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all axes. Position is {0,0,0}.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     * @param Z Pivot Z axis.
     */
    Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z);

    /**
     * Initialize all axes and position.
     * @param X Pivot X axis.
     * @param Y Pivot Y axis.
     * @param Z Pivot Z axis.
     * @param P Pivot position.
     */
    Pivot(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z, const Vector<3,T>& P);
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Types/Pivot.hpp>