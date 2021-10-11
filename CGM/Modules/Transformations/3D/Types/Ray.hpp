#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Ray
{
    CGM_RULE_OF_FIVE(Ray)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<3,T> direction {T(1), T(0), T(0)};    ///< ray direction.
    Vector<3,T> position {T(0), T(0), T(0)};     ///< ray position.

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

    /**
     * Initialize origin and direction.
     * @param dir Ray direction.
     * @param pos Ray origin.
     */
    constexpr
    Ray(const Vector<3,T>& dir, const Vector<3,T>& pos);
};

CGM_NAMESPACE_END


#include "Ray.inl"