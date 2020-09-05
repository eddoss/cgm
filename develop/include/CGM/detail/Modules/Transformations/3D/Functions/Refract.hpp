

#include <CGM/Modules/Transformations/3D/Functions/Refract.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr void
refract(Vector<3,T>& vector, T ior)
{
    T cosi;
    
    if constexpr (Plane == EPlane::XY)
    {
        cosi = -vector.z;
    }
    else if constexpr (Plane == EPlane::YZ)
    {
        cosi = -vector.x;
    }
    else
    {
        cosi = -vector.y;
    }
    
    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return;
    }

    T cost = std::sqrt(1 - sint);
    
    vector *= ior;
    
    if constexpr (Plane == EPlane::XY)
    {
        vector.z += ior * cosi - cost;
    }
    else if constexpr (Plane == EPlane::YZ)
    {
        vector.x += ior * cosi - cost;
    }
    else
    {
        vector.y += ior * cosi - cost;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    T cosi = -dot(vector, planeNormal);
    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return;
    }

    T cost = std::sqrt(1 - sint);

    return ior * vector + (ior * cosi - cost) * planeNormal;
}

/* ####################################################################################### */
/* Matrix3 (inplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, T ior)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::World)
    {
        refract<Plane>(axes.x, ior);
        refract<Plane>(axes.y, ior);
        refract<Plane>(axes.z, ior);
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

        refract(axes.x, planeNormal);
        refract(axes.y, planeNormal);
        refract(axes.z, planeNormal);
    }

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::World)
    {
        refract(axes.x, planeNormal, ior);
        refract(axes.y, planeNormal, ior);
        refract(axes.z, planeNormal, ior);
    }
    else
    {
        auto pn = converted<ESpace::World>(planeNormal, matrix);

        refract(axes.x, pn, ior);
        refract(axes.y, pn, ior);
        refract(axes.z, pn, ior);
    }

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, T ior)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        refract<Plane>(axes.x, ior);
        refract<Plane>(axes.y, ior);
        refract<Plane>(axes.z, ior);
        refract<Plane>(pos, ior);
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

        refract(axes.x, planeNormal);
        refract(axes.y, planeNormal);
        refract(axes.z, planeNormal);
        refract(pos, planeNormal);
    }

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
    setPosition(matrix, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        refract(axes.x, planeNormal, ior);
        refract(axes.y, planeNormal, ior);
        refract(axes.z, planeNormal, ior);
        refract(pos, planeNormal, ior);
    }
    else
    {
        auto pn = converted<ESpace::World>(planeNormal, matrix);

        refract(axes.x, pn, ior);
        refract(axes.y, pn, ior);
        refract(axes.z, pn, ior);
        refract(pos, pn, ior);
    }

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
    setPosition(matrix, pos);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr void
refract(Pivot<T>& pivot, T ior)
{
    refract<Plane>(pivot.axes.x, ior);
    refract<Plane>(pivot.axes.y, ior);
    refract<Plane>(pivot.axes.z, ior);
    refract<Plane>(pivot.position, ior);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior)
{
    refract(pivot.axes.x, planeNormal, ior);
    refract(pivot.axes.y, planeNormal, ior);
    refract(pivot.axes.z, planeNormal, ior);
    refract(pivot.position, planeNormal, ior);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, T ior)
{
    auto copy = vector;
    refract<Plane>(copy, ior);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = vector;
    refract(copy, planeNormal, ior);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr Matrix<3,3,T>
refracted(const Matrix<3,3,T>& matrix, T ior)
{
    auto copy = matrix;
    refract<Plane>(copy, ior);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
refracted(const Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = matrix;
    refract(copy, planeNormal, ior);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EPlane Plane, ESpace Space, typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, T ior)
{
    auto copy = matrix;
    refract<Plane>(copy, ior);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = matrix;
    refract(copy, planeNormal, ior);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EPlane Plane, typename T>
constexpr Pivot<T>
refracted(const Pivot<T>& pivot, T ior)
{
    auto copy = pivot;
    refract<Plane>(copy, ior);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Pivot<T>
refracted(const Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior)
{
    auto copy = pivot;
    refract(copy, planeNormal, ior);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END