#pragma once


#include <cgm/modules/cartesian/3d/types/quaternion.hpp>


CGM_NAMESPACE_BEGIN

using quat      = Quaternion<FLOAT>;
using fquat     = Quaternion<f32>;
using dquat     = Quaternion<f64>;

using quatf32   = Quaternion<f32>;
using quatf64   = Quaternion<f64>;

CGM_NAMESPACE_END
