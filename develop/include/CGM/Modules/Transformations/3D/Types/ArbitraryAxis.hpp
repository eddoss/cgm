#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct ArbitraryAxis
{
    CGM_RULE_OF_FIVE(ArbitraryAxis)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<3,T> direction;    ///< axis direction.
    Vector<3,T> position;     ///< axis position.

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize origin and direction.
     * @param dir Axis direction.
     * @param pos Axis origin.
     */
    ArbitraryAxis(const Vector<3,T>& dir, const Vector<3,T>& pos);
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Transformations/3D/Types/Axis.hpp>