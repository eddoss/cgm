#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
struct Axis
{
    Vector<3,T> origin;       ///< axis origin.
    Vector<3,T> direction;    ///< axis direction.
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END