#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Axis
{
    CGM_RULE_OF_FIVE(Axis)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<3,T> origin;       ///< axis origin.
    Vector<3,T> direction;    ///< axis direction.

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize origin and direction.
     * @param pos Axis origin.
     * @param dir Axis direction.
     */
    Axis(const Vector<3,T>& pos, const Vector<3,T>& dir);
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Types/Axis.hpp>