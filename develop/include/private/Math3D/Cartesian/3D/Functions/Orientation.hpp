

#include <Math3D/Cartesian/3D/Functions/Orientation.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<3,3,T>& orientation)
{
    return std::make_tuple(getX(orientation), getY(orientation), getZ(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Quaternion<T>& orientation)
{
    return std::make_tuple
    (
        _internal_rotated_vector3_by_quaternion({T(1),0,0}, orientation),
        _internal_rotated_vector3_by_quaternion({0,T(1),0}, orientation),
        _internal_rotated_vector3_by_quaternion({0,0,T(1)}, orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<4,4,T>& space)
{
    return std::make_tuple(getX(space), getY(space), getZ(space));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& orientation)
{
    Matrix<3,3,T> mat;

    setX(mat, _internal_rotated_vector3_by_quaternion({T(1),T(0),T(0)}, orientation));
    setY(mat, _internal_rotated_vector3_by_quaternion({T(0),T(1),T(0)}, orientation));
    setZ(mat, _internal_rotated_vector3_by_quaternion({T(0),T(0),T(1)}, orientation));

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    Matrix<3,3,T> mat;

    setX(mat, x);
    setY(mat, y);
    setZ(mat, z);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& orientation)
{
    return orientationQuaternion
    (
        getX(orientation),
        getY(orientation),
        getZ(orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& space)
{
    return orientationQuaternion
    (
        getX(space),
        getY(space),
        getZ(space)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
{
    Quaternion<T> q; T t;

    if (Z.z < 0)
    {
        if (X.x > Y.y)
        {
            t = 1 + X.x - Y.y - Z.z;
            q = {Y.z - Z.y, t, X.y + Y.x, Z.x + X.z};
        }
        else
        {
            t = 1 - X.x + Y.y - Z.z;
            q = {Z.x - X.z, X.y + Y.x, t, Y.z + Z.y};
        }
    }
    else
    {
        if (X.x < -Y.y)
        {
            t = 1 - X.x - Y.y + Z.z;
            q = {X.y - Y.x, Z.x + X.z, Y.z + Z.y, t};
        }
        else
        {
            t = 1 + X.x + Y.y + Z.z;
            q = {t, Y.z - Z.y, Z.x - X.z, X.y - Y.x};
        }
    }

    return q *= 0.5 / std::sqrt(t);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END