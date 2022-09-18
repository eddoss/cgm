#pragma once


#include <cmath>
#include <type_traits>
#include <cgm/modules/primitives/module_globals.hpp>


CGM_NAMESPACE_BEGIN

#define CGM_DECLARE_NUMBER_CONSTRAINT(StructName)                                   \
    template <typename T>                                                           \
    struct StructName                                                               \
    {                                                                               \
        constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>   \
        operator () (T value);                                                      \
    };

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

/**
 * Return only positive values or 0.
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintPositive)

/**
 * Return only negative values or 0.
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintNegative)

/**
 * Return only values in range [0, +1].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintRange01)

/**
 * Return only values in range [-1, 0].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintRange10)

/**
 * Return only values in range [-1, +1].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintRange11)

/* ####################################################################################### */
/* Angles */
/* ####################################################################################### */

/**
 * Return only values clamped in range [0, 2*PI].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintAngle02Pi)

/**
 * Return only values clamped in range [-PI, PI].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintAnglePiPi)

/**
 * Return only values clamped in range [-2PI, 2PI].
 **/
CGM_DECLARE_NUMBER_CONSTRAINT(NumberConstraintAngle2Pi2Pi)

#undef CGM_DECLARE_NUMBER_CONSTRAINT

CGM_NAMESPACE_END


#include "constraints.inl"
