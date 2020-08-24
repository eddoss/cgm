

#include <CGM/Modules/Transformations/3D/Functions/Refract.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

template<typename T>
constexpr void
refract(Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    T cosi = -dot(vector, planeNormal);
    T sint = ior * ior * (1 - cosi * cosi);

    if (sint > 1)
    {
        return Vector<3,T>(zero<T>);
    }

    T cost = std::sqrt(1 - sint);

    return ior * vector + (ior * cosi - cost) * planeNormal;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto axes = orientationAxes(matrix);

    refract(axes.x, planeNormal, ior);
    refract(axes.y, planeNormal, ior);
    refract(axes.z, planeNormal, ior);

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto [x,y,z,p] = unpackSpace(matrix);

    refract(x, planeNormal, ior);
    refract(y, planeNormal, ior);
    refract(z, planeNormal, ior);
    refract(p, planeNormal, ior);

    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
    setPosition(matrix, p);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Pivot<T>& pivot, Vector<3,T>& planeNormal, T ior)
{
    refract(pivot.axes.x, planeNormal, ior);
    refract(pivot.axes.y, planeNormal, ior);
    refract(pivot.axes.z, planeNormal, ior);
    reflect(pivot.position, planeNormal, ior);
}

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

template<typename T>
constexpr Vector<3,T>
refracted(const Vector<3,T>& vector, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = vector;
    refract(copy, planeNormal, ior);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
refracted(const Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto copy = matrix;
    refract(copy, planeNormal, ior);
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