

#include "Orientation.hpp"


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    return Axes<T>(x,y,z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<3,3,T>& orientation)
{
    return Axes<T>
    (
        x(orientation),
        y(orientation),
        z(orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Quaternion<T>& orientation)
{
    return Axes<T>
    (
        oriented({number<T>(1),zero<T>,zero<T>}, orientation),
        oriented({zero<T>,number<T>(1),zero<T>}, orientation),
        oriented({zero<T>,zero<T>,number<T>(1)}, orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Axes<T>
orientationAxes(const Matrix<4,4,T>& space)
{
    return Axes<T>
    (
        x(space),
        y(space),
        z(space)
    );
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
#ifdef CGM_CFG_MATRIX_POSTMULT
    return
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#else
    return
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Axes<T>& axes)
{
    return orientationMatrix
    (
        axes.x,
        axes.y,
        axes.z
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& orientation)
{
    return orientationMatrix(orientationAxes(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Matrix<4,4,T>& space)
{
    return
    {
        space(0,0), space(0,1), space(0,2),
        space(1,0), space(1,1), space(1,2),
        space(2,0), space(2,1), space(2,2)
    };
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    Quaternion<T> q; T t;

    if (z.z < 0)
    {
        if (x.x > y.y)
        {
            t = 1 + x.x - y.y - z.z;
            q = {t, y.x + x.y, x.z + z.x, z.y - y.z};
        }
        else
        {
            t = 1 - x.x + y.y - z.z;
            q = {y.x + x.y, t, z.y + y.z, x.z - z.x};
        }
    } 
    else
    {
        if (x.x < -y.y)
        {
            t = 1 - x.x - y.y + z.z;
            q = {x.z + z.x, z.y + y.z, t, y.x - x.y};
        }
        else
        {
            t = 1 + x.x + y.y + z.z;
            q = {z.y - y.z, x.z - z.x, y.x - x.y, t};
        }
    }

    q *= static_cast<T>(0.5) / std::sqrt(t);

    return q;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Axes<T>& axes)
{
    return orientationQuaternion
    (
        axes.x,
        axes.y,
        axes.z
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& orientation)
{
    return orientationQuaternion
    (
        x(orientation),
        y(orientation),
        z(orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& space)
{
    return orientationQuaternion
    (
        x(space),
        y(space),
        z(space)
    );
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END