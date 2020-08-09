#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/Common.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Transformations/3D/Types/Enums.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
struct Transforms
{
    /**
     * Transformations pivot point.
     */
    Pivot<T>
    pivot;

    /**
     * Describe translations.
     */
    Vector<3,T>
    translations;

    /**
     * Describe Rotations (in radians).
     */
    Vector<3,T>
    rotations;

    /**
     * Describe scales.
     */
    Vector<3,T>
    scales;

    /**
     * Describe uniform scale.
     */
    T
    uniformScale;

    /**
     * Describe transformation order.
     */
    ETransformOrder
    transformOrder;

    /**
     * Describe rotation order.
     */
    ERotationOrder
    rotationOrder;
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
