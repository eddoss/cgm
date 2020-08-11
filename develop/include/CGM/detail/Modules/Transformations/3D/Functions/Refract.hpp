

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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(AxesTuple<T>& axes, const Vector<3,T>& planeNormal, T ior)
{
    auto& [x,y,z] = axes;

    refract(x, planeNormal, ior);
    refract(y, planeNormal, ior);
    refract(z, planeNormal, ior);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
refract(SpaceTuple<T>& space, const Vector<3,T>& planeNormal, T ior)
{
    auto& [x,y,z,p] = space;

    refract(x, planeNormal, ior);
    refract(y, planeNormal, ior);
    refract(z, planeNormal, ior);
    refract(p, planeNormal, ior);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr void
refract(Basis<Base,T>& basis, const Vector<3,T>& planeNormal, T ior)
{
    if constexpr (Base == EBasisBase::Matrix3 || Base == EBasisBase::Matrix4)
    {
        auto x = basis.x();
        auto y = basis.y();
        auto z = basis.z();
        auto p = basis.position();

        refract(x, planeNormal, ior);
        refract(y, planeNormal, ior);
        refract(z, planeNormal, ior);
        refract(p, planeNormal);

        basis.setOrientation(orientationMatrix(x,y,z));
        basis.setPosition(p);
    }
    else
    {
        auto quat = basis.orientationQuaternion();
        auto pos = basis.position();

        auto angle = std::acos(quat.scalar) * 2;
        auto sin = std::sin(angle / 2);
        auto axis = quat.vector / sin;

        refract(axis, planeNormal, ior);
        refract(pos, planeNormal, ior);

        quat.vector = axis * sin;

        basis.setOrientation(quat);
        basis.setPosition(pos);
    }
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END