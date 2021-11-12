#pragma once


#include <CGM/Modules/Cartesian/3D/Types/Quaternion.hpp>


CGM_NAMESPACE_BEGIN

using quat      = Quaternion<FLOAT>;
using fquat     = Quaternion<f32>;
using dquat     = Quaternion<f64>;

using quatf32   = Quaternion<f32>;
using quatf64   = Quaternion<f64>;

CGM_NAMESPACE_END
