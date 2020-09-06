

#include <CGM/Modules/Transformations/3D/Functions/Reflect.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr void
reflect(Vector<3,T>& vector)
{
    if constexpr (Plane == EPlane::XY)
    {
        vector.z = -vector.z;
    }
    else if constexpr (Plane == EPlane::YZ)
    {
        vector.x = -vector.x;
    }
    else
    {
        vector.y = -vector.y;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal)
{
    vector -= number<T>(2) * dot(vector, planeNormal) * planeNormal;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Vector<3,T>& vector, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto projected = dot(vector, planeNormal) * planeNormal;
    auto reflected = vector - projected - projected;

    T dist = dot(planeCenter, planeNormal);
    reflected += planeNormal * dist * number<T>(2);

    vector = reflected;
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect<Plane>(axes.x);
        reflect<Plane>(axes.y);
        reflect<Plane>(axes.z);
    }
    else
    {
        Vector<3,T> planeNormal {};

        if constexpr (Plane == EPlane::XY)
        {
            planeNormal = z(matrix);
        }
        else if constexpr (Plane == EPlane::YZ)
        {
            planeNormal = x(matrix);
        }
        else
        {
            planeNormal = y(matrix);
        }

        reflect(axes.x, planeNormal);
        reflect(axes.y, planeNormal);
        reflect(axes.z, planeNormal);
    }

    set(matrix, axes);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, planeNormal);
        reflect(axes.y, planeNormal);
        reflect(axes.z, planeNormal);
    }
    else
    {
        auto pn = converted<ESpace::World>(planeNormal, matrix);

        reflect(axes.x, pn);
        reflect(axes.y, pn);
        reflect(axes.z, pn);
    }

    set(matrix, axes);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect<Plane>(axes.x);
        reflect<Plane>(axes.y);
        reflect<Plane>(axes.z);
        reflect<Plane>(pos);
    }
    else
    {
        Vector<3,T> planeNormal {};

        if constexpr (Plane == EPlane::XY)
        {
            planeNormal = z(matrix);
        }
        else if constexpr (Plane == EPlane::YZ)
        {
            planeNormal = x(matrix);
        }
        else
        {
            planeNormal = y(matrix);
        }

        reflect(axes.x, planeNormal);
        reflect(axes.y, planeNormal);
        reflect(axes.z, planeNormal);
        reflect(pos, planeNormal);
    }

    set(matrix, axes, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, planeNormal);
        reflect(axes.y, planeNormal);
        reflect(axes.z, planeNormal);
        reflect(pos, planeNormal);
    }
    else
    {
        auto pn = converted<ESpace::World>(planeNormal, matrix);

        reflect(axes.x, pn);
        reflect(axes.y, pn);
        reflect(axes.z, pn);
        reflect(pos, pn);
    }

    set(matrix, axes, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        reflect(axes.x, planeNormal);
        reflect(axes.y, planeNormal);
        reflect(axes.z, planeNormal);
        reflect(pos, planeNormal, planeCenter);
    }
    else
    {
        auto pn = converted<ESpace::World>(planeNormal, matrix);
        auto pc = converted<ESpace::World>(planeCenter, matrix);

        reflect(axes.x, pn);
        reflect(axes.y, pn);
        reflect(axes.z, pn);
        reflect(pos, pn, pc);
    }

    set(matrix, axes, pos);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr void
reflect(Pivot<T>& pivot)
{
    reflect<Plane>(pivot.axes.x);
    reflect<Plane>(pivot.axes.y);
    reflect<Plane>(pivot.axes.z);
    reflect<Plane>(pivot.position);
}

/* --------------------------------------------------------------------------------------- */

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

template<EPlane Plane, typename T>
constexpr Vector<3,T>
reflected(const Vector<3,T>& vector)
{
    auto copy = vector;
    reflect<Plane>(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

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

template<EPlane Plane, ESpace Space, typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix)
{
    auto copy = matrix;
    reflect<Plane,Space>(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
reflected(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto copy = matrix;
    reflect<Space>(copy, planeNormal);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix)
{
    auto copy = matrix;
    reflect<Plane,Space>(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto copy = matrix;
    reflect<Space>(copy, planeNormal);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
reflected(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto copy = matrix;
    reflect<Space>(copy, planeNormal, planeCenter);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr Pivot<T>
reflected(const Pivot<T>& pivot)
{
    auto copy = pivot;
    reflect<Plane>(copy);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

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