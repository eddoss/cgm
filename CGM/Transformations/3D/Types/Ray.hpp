#pragma once


#include <CGM/Core/Types/Vector.hpp>
#include <CGM/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T=FLOAT>
struct Ray
{
    CGM_RULE_OF_FIVE(Ray)

/* ####################################################################################### */
/* Attributes */
/* ####################################################################################### */

    Vector<3,T> direction;    ///< ray direction.
    Vector<3,T> position;     ///< ray position.

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

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END


#include "Ray.inl"