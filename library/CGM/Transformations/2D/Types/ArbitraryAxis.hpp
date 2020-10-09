#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Transformations/2D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct ArbitraryAxis
{
    CGM_RULE_OF_FIVE(ArbitraryAxis)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<2,T> direction;    ///< axis direction.
    Vector<2,T> position;     ///< axis position.

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize origin and direction.
     * @param dir Axis direction.
     * @param pos Axis origin.
     */
    constexpr
    ArbitraryAxis(const Vector<2,T>& dir, const Vector<2,T>& pos);
};

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END


#include "ArbitraryAxis.inl"