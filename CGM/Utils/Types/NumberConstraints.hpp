#pragma once


#include <CGM/Utils/ModuleGlobals.hpp>
#include <CGM/Utils/Functions/Angles.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Numbers */
/* ####################################################################################### */

/**
 * Return only positive values or 0.
 **/
template <typename T>
struct PositiveNumberConstraint
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

/**
 * Return only negative values or 0.
 **/
template <typename T>
struct NegativeNumberConstraint
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

/* ####################################################################################### */
/* Angle */
/* ####################################################################################### */

/**
 * Return only values clamped in range [0, 2*PI].
 **/
template <typename T>
struct AngleConstraint_0_2PI
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

/**
 * Return only values clamped in range [-PI, PI].
 **/
template <typename T>
struct AngleConstraint_PI_PI
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

/**
 * Return only values clamped in range [-2PI, 2PI].
 **/
template <typename T>
struct AngleConstraint_2PI_2PI
{
    constexpr CGM_FORCEINLINE std::enable_if_t<std::is_floating_point_v<T>,T>
    operator () (T value);
};

CGM_NAMESPACE_END


#include "NumberConstraints.inl"