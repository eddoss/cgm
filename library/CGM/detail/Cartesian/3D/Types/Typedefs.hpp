#pragma once


#include <CGM/detail/Cartesian/3D/Types/Quaternion.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

using quat      = Quaternion<FLOAT>;
using quat_32   = Quaternion<float32>;
using quat_64   = Quaternion<float64>;

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END
