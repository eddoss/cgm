

#include "Config.hpp"


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

constexpr
Config::Config()
#ifdef CGM_CFG_AXES_ARE_XYZ
    : right(EAxes::X)
    , up(EAxes::Y)
    , forward(EAxes::Z)
#elif defined(CGM_CFG_AXES_ARE_XZY)
    : right(EAxes::X)
    , up(EAxes::Z)
    , forward(EAxes::Y)
#elif defined(CGM_CFG_AXES_ARE_YXZ)
    : right(EAxes::Y)
    , up(EAxes::X)
    , forward(EAxes::Z)
#elif defined(CGM_CFG_AXES_ARE_YZX)
    : right(EAxes::Y)
    , up(EAxes::Z)
    , forward(EAxes::X)
#elif defined(CGM_CFG_AXES_ARE_ZXY)
    : right(EAxes::Z)
    , up(EAxes::X)
    , forward(EAxes::Y)
#elif defined(CGM_CFG_AXES_ARE_ZYX)
    : right(EAxes::Z)
    , up(EAxes::Y)
    , forward(EAxes::X)
#endif
#ifdef CGM_CFG_RHS
    , handedness(EHandedness::Right)
#else
    , handedness(EHandedness::Left)
#endif
{

}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END