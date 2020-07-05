

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
        oriented({T(1),0,0}, orientation),
        oriented({0,T(1),0}, orientation),
        oriented({0,0,T(1)}, orientation)
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

    T qxx(orientation.x * orientation.x);
    T qyy(orientation.y * orientation.y);
    T qzz(orientation.z * orientation.z);
    T qxz(orientation.x * orientation.z);
    T qxy(orientation.x * orientation.y);
    T qyz(orientation.y * orientation.z);
    T qsx(orientation.s * orientation.x);
    T qsy(orientation.s * orientation.y);
    T qsz(orientation.s * orientation.z);

    #ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        mat(0,0) = number<T>(1) - number<T>(2) * (qyy +  qzz);
        mat(0,1) = number<T>(2) * (qxy - qsz);
        mat(0,2) = number<T>(2) * (qxz + qsy);

        mat(1,0) = number<T>(2) * (qxy + qsz);
        mat(1,1) = number<T>(1) - number<T>(2) * (qxx +  qzz);
        mat(1,2) = number<T>(2) * (qyz - qsx);

        mat(2,0) = number<T>(2) * (qxz - qsy);
        mat(2,1) = number<T>(2) * (qyz + qsx);
        mat(2,2) = number<T>(1) - number<T>(2) * (qxx +  qyy);
    #else
        mat(0,0) = number<T>(1) - number<T>(2) * (qyy +  qzz);
        mat(1,0) = number<T>(2) * (qxy - qsz);
        mat(2,0) = number<T>(2) * (qxz + qsy);

        mat(0,1) = number<T>(2) * (qxy + qsz);
        mat(1,1) = number<T>(1) - number<T>(2) * (qxx +  qzz);
        mat(2,1) = number<T>(2) * (qyz - qsx);

        mat(0,2) = number<T>(2) * (qxz - qsy);
        mat(1,2) = number<T>(2) * (qyz + qsx);
        mat(2,2) = number<T>(1) - number<T>(2) * (qxx +  qyy);
    #endif

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
            q = {Z.y - Y.z, t, Y.x + X.y, X.z + Z.x};
        }
        else
        {
            t = 1 - X.x + Y.y - Z.z;
            q = {X.z - Z.x, Y.x + X.y, t, Z.y + Y.z};
        }
    }
    else
    {
        if (X.x < -Y.y)
        {
            t = 1 - X.x - Y.y + Z.z;
            q = {Y.x - X.y, X.z + Z.x, Z.y + Y.z, t};
        }
        else
        {
            t = 1 + X.x + Y.y + Z.z;
            q = {t, Z.y - Y.z, X.z - Z.x, Y.x - X.y};
        }
    }

    return q *= T(0.5) / std::sqrt(t);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END