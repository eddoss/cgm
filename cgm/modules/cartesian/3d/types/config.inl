

#include "config.hpp"


CGM_NAMESPACE_BEGIN

constexpr
Config::Config()
#ifdef CGM_CFG_AXES_ARE_XYZ
    : right(E3D::X)
    , up(E3D::Y)
    , forward(E3D::Z)
#elif defined(CGM_CFG_AXES_ARE_XZY)
    : right(E3D::X)
    , up(E3D::Z)
    , forward(E3D::Y)
#elif defined(CGM_CFG_AXES_ARE_YXZ)
    : right(E3D::Y)
    , up(E3D::X)
    , forward(E3D::Z)
#elif defined(CGM_CFG_AXES_ARE_YZX)
    : right(E3D::Y)
    , up(E3D::Z)
    , forward(E3D::X)
#elif defined(CGM_CFG_AXES_ARE_ZXY)
    : right(E3D::Z)
    , up(E3D::X)
    , forward(E3D::Y)
#elif defined(CGM_CFG_AXES_ARE_ZYX)
    : right(E3D::Z)
    , up(E3D::Y)
    , forward(E3D::X)
#endif
#ifdef CGM_CFG_RHS
    , handedness(EHandedness::Right)
#else
    , handedness(EHandedness::Left)
#endif
{

}

CGM_NAMESPACE_END