#pragma once


#include <cgm/modules/primitives/functions/numbers.hpp>
#include <cgm/modules/primitives/functions/comparison.hpp>
#include <cgm/shapes/2d/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>


CGM_2D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Range
{
    CGM_RULE_OF_FIVE(Range)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    /**
     * Range min.
     */
    Vector<2,T>
    min {T(0), {T(0)}};

    /**
     * Range max.
     */
    Vector<2,T>
    max {T(0), {T(0)}};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize minimum and maximum.
     */
    constexpr
    Range(const Vector<2,T>& minimum, const Vector<2,T>& maximum);
};

CGM_2D_NAMESPACE_END


#include "range.inl"
