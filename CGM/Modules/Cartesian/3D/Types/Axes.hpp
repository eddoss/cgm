#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Axes
{
    CGM_RULE_OF_FIVE(Axes)

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    Vector<3,T> x;
    Vector<3,T> y;
    Vector<3,T> z;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all axes.
     */
    constexpr
    Axes(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z);
};

CGM_NAMESPACE_END


#include "Axes.inl"