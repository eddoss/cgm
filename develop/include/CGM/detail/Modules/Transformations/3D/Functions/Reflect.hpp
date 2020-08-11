

#include <CGM/Modules/Transformations/3D/Functions/Reflect.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
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
/* Matrix3 */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Matrix<3,3,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto [x,y,z] = orientationAxes(matrix);

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);

    setX(matrix, x);
    setY(matrix, y);
    setZ(matrix, z);
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Matrix<4,4,T>& matrix, const Vector<3,T>& planeNormal)
{
    auto [x,y,z,p] = unpackBasis(matrix);

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
    auto [x,y,z,p] = unpackBasis(matrix);

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
/* Pivot */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal)
{
    reflect(pivot.x, planeNormal);
    reflect(pivot.y, planeNormal);
    reflect(pivot.z, planeNormal);
    reflect(pivot.position, planeNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(Pivot<T>& pivot, Vector<3,T>& planeNormal, Vector<3,T>& planeCenter)
{
    reflect(pivot.x, planeNormal);
    reflect(pivot.y, planeNormal);
    reflect(pivot.z, planeNormal);
    reflect(pivot.position, planeNormal, planeCenter);
}

/* ####################################################################################### */
/* Axes tuple */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(AxesTuple<T>& axes, const Vector<3,T>& planeNormal)
{
    auto& [x,y,z] = axes;

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);
}

/* ####################################################################################### */
/* Space tuple */
/* ####################################################################################### */

template<typename T>
constexpr void
reflect(SpaceTuple<T>& space, const Vector<3,T>& planeNormal)
{
    auto& [x,y,z,p] = space;

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);
    reflect(p, planeNormal);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
reflect(SpaceTuple<T>& space, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    auto& [x,y,z,p] = space;

    reflect(x, planeNormal);
    reflect(y, planeNormal);
    reflect(z, planeNormal);
    reflect(p, planeNormal, planeCenter);
}

/* ####################################################################################### */
/* Basis struct */
/* ####################################################################################### */

template<EBasisBase Base, typename T>
constexpr void
reflect(Basis<Base,T>& basis, const Vector<3,T>& planeNormal)
{
    if constexpr (Base == EBasisBase::Matrix3 || Base == EBasisBase::Matrix4)
    {
        auto x = basis.x();
        auto y = basis.y();
        auto z = basis.z();
        auto p = basis.position();

        reflect(x, planeNormal);
        reflect(y, planeNormal);
        reflect(z, planeNormal);
        reflect(p, planeNormal);

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

        reflect(axis, planeNormal);
        reflect(pos, planeNormal);

        quat.vector = axis * sin;

        basis.setOrientation(quat);
        basis.setPosition(pos);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr void
reflect(Basis<Base,T>& basis, const Vector<3,T>& planeNormal, const Vector<3,T>& planeCenter)
{
    if constexpr (Base == EBasisBase::Matrix3 || Base == EBasisBase::Matrix4)
    {
        auto x = basis.x();
        auto y = basis.y();
        auto z = basis.z();
        auto p = basis.position();

        reflect(x, planeNormal);
        reflect(y, planeNormal);
        reflect(z, planeNormal);
        reflect(p, planeNormal, planeCenter);

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

        reflect(axis, planeNormal);
        reflect(pos, planeNormal, planeCenter);

        quat.vector = axis * sin;

        basis.setOrientation(quat);
        basis.setPosition(pos);
    }
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END