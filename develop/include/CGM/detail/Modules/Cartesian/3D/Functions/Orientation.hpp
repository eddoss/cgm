

#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Axes */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    return std::make_tuple(x,y,z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const SpaceTuple<T>& space)
{
    return std::make_tuple
    (
        x(space),
        y(space),
        z(space)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<3,3,T>& orientation)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return std::make_tuple
    (
        Vector<3,T>{orientation(0,0), orientation(0,1), orientation(0,2)},
        Vector<3,T>{orientation(1,0), orientation(1,1), orientation(1,2)},
        Vector<3,T>{orientation(2,0), orientation(2,1), orientation(2,2)}
    );
#else
    return std::make_tuple
    (
        Vector<3,T>{orientation(0,0), orientation(1,0), orientation(2,0)},
        Vector<3,T>{orientation(0,1), orientation(1,1), orientation(2,1)},
        Vector<3,T>{orientation(0,2), orientation(1,2), orientation(2,2)}
    );
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Quaternion<T>& orientation)
{
    return std::make_tuple
    (
        oriented({T(1),T(0),T(0)}, orientation),
        oriented({T(0),T(1),T(0)}, orientation),
        oriented({T(0),T(0),T(1)}, orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE AxesTuple<T>
orientationAxes(const Matrix<4,4,T>& space)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return std::make_tuple
    (
        Vector<3,T>{space(0,0), space(0,1), space(0,2)},
        Vector<3,T>{space(1,0), space(1,1), space(1,2)},
        Vector<3,T>{space(2,0), space(2,1), space(2,2)}
    );
#else
    return std::make_tuple
    (
        Vector<3,T>{space(0,0), space(1,0), space(2,0)},
        Vector<3,T>{space(0,1), space(1,1), space(2,1)},
        Vector<3,T>{space(0,2), space(1,2), space(2,2)}
    );
#endif
}

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        x.x, x.y, x.z,
        y.x, y.y, y.z,
        z.x, z.y, z.z
    };
#else
    return
    {
        x.x, y.x, z.x,
        x.y, y.y, z.y,
        x.z, y.z, z.z
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const AxesTuple<T>& axes)
{
    return orientationMatrix
    (
        x(axes),
        y(axes),
        z(axes)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
orientationMatrix(const SpaceTuple<T>& space)
{
    return orientationMatrix
    (
        x(space),
        y(space),
        z(space)
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
        } else
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
orientationQuaternion(const AxesTuple<T>& axes)
{
    return orientationQuaternion
    (
        x(axes),
        y(axes),
        z(axes)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
orientationQuaternion(const SpaceTuple<T>& space)
{
    return orientationQuaternion
    (
        x(space),
        y(space),
        z(space)
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