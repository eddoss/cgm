

#include <CGM/Modules/Transformations/3D/Functions/Reflect.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal)
{
    auto projected = dot(vector, planeNormal) * planeNormal;
    auto reflected = vector - projected - projected;

    return reflected;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto projected = dot(vector, planeNormal) * planeNormal;
    auto reflected = vector - projected - projected;

    T dist = dot(planeNormal + planeCenter, planeNormal); // shortest dist from given vector to plane
    reflected += planeNormal * dist * number<T>(2);

    return reflected;
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto axes = orientationAxes(matrix);

    reflect(axes.x, planeNormal);
    reflect(axes.y, planeNormal);
    reflect(axes.z, planeNormal);

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto [x,y,z,p] = unpackSpace(matrix);

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);
    reflect(p, planeNormal);

    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
    setPosition(matrix, p);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto [x,y,z,p] = unpackSpace(matrix);

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);
    reflect(p, planeNormal, planeCenter);

    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
    setPosition(matrix, p);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal)
{
    reflect(pivot.axes.x, planeNormal);
    reflect(pivot.axes.y, planeNormal);
    reflect(pivot.axes.z, planeNormal);
    reflect(pivot.position, planeNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter)
{
    reflect(pivot.axes.x, planeNormal);
    reflect(pivot.axes.y, planeNormal);
    reflect(pivot.axes.z, planeNormal);
    reflect(pivot.position, planeNormal, planeCenter);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector, const Vector<3,T>& planeNormal)
{
    auto copy = vector;
    reflect(copy, planeNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto copy = vector;
    reflect(copy, planeNormal, planeCenter);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto copy = matrix;
    reflect(copy, planeNormal);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto copy = matrix;
    reflect(copy, planeNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto copy = matrix;
    reflect(copy, planeNormal, planeCenter);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, Vector<3,T>& planeNormal)
{
    auto copy = pivot;
    reflect(copy, planeNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter)
{
    auto copy = pivot;
    reflect(copy, planeNormal, planeCenter);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END