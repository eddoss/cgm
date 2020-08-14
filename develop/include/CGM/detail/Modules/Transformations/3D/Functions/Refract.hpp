

#include <CGM/Modules/Transformations/3D/Functions/Refract.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

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
    auto [x,y,z] = orientationAxes(matrix);

    refract(x, planeNormal, ior);
    refract(y, planeNormal, ior);
    refract(z, planeNormal, ior);

    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal, T ior)
{
    auto [x,y,z,p] = unpackBasis(matrix);

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
    refract(pivot.x, planeNormal, ior);
    refract(pivot.y, planeNormal, ior);
    refract(pivot.z, planeNormal, ior);
    reflect(pivot.position, planeNormal, ior);
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END