

#include "vector_components.hpp"


#include <cgm/modules/coordinates/functions/vector_components.hpp>


CGM_NAMESPACE_BEGIN
CGM_COORD_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE T&
right(Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T&
up(Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE T&
forward(Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE const T&
right(const Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE const T&
up(const Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE const T&
forward(const Vector<3,T>& coord)
{
#ifdef CGM_CFG_AXES_ARE_ZXY
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_YXZ
    return coord.z;
#endif

#ifdef CGM_CFG_AXES_ARE_ZYX
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_YZX
    return coord.x;
#endif

#ifdef CGM_CFG_AXES_ARE_XZY
    return coord.y;
#endif

#ifdef CGM_CFG_AXES_ARE_XYZ
    return coord.z;
#endif
}

CGM_COORD_NAMESPACE_END
CGM_NAMESPACE_END