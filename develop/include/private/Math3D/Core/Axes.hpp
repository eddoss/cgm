

#include <Math3D/Core/Axes.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_AXES_NAMESPACE_BEGIN

template<typename T>
constexpr Vector<3,T>
x()
{
    return
    {
        number<T>(1),
        number<T>(0),
        number<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
y()
{
    return
    {
        number<T>(0),
        number<T>(1),
        number<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
z()
{
    return
    {
        number<T>(0),
        number<T>(0),
        number<T>(1)
    };
}

/* ####################################################################################### */
/* Cartesian system axes */
/* ####################################################################################### */

template<typename T>
constexpr Vector<3,T>
up()
{
#ifdef MATH3D_CARTESIAN_UP_X
    return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
right()
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
forward()
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return x<T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return y<T>();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return z<T>();
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
down()
{
    return -up<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
left()
{
    return -right<T>();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
backward()
{
    return -forward<T>();
}

/* ####################################################################################### */
/* Utils */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
makeCoord(T right, T up, T forward)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return {up, forward, right};
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return {up, right, forward};
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return {forward, up, right};
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return {forward, right, up};
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return {right, forward, up};
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return {right, up, forward};
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T&
rightComponent(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T&
upComponent(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE T&
forwardComponent(Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
rightComponent(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.x;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
upComponent(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE const T&
forwardComponent(const Vector<3,T>& coord)
{
#ifdef MATH3D_CARTESIAN_ZXY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_YXZ
    return coord.z;
#endif

#ifdef MATH3D_CARTESIAN_ZYX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_YZX
    return coord.x;
#endif

#ifdef MATH3D_CARTESIAN_XZY
    return coord.y;
#endif

#ifdef MATH3D_CARTESIAN_XYZ
    return coord.z;
#endif
}

MATH3D_AXES_NAMESPACE_END
MATH3D_NAMESPACE_END
