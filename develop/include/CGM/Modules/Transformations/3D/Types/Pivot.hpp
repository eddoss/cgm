#pragma once


#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Transformations/3D/ModuleGlobals.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
struct Pivot
{
    Vector<3,T> x;           ///< X axes.
    Vector<3,T> y;           ///< Y axes.
    Vector<3,T> z;           ///< Z axes.
    Vector<3,T> position;    ///< Pivot position.
};

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END