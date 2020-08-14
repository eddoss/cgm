

#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle)
{
    orient(vector, quaternion(axis<Axis>(), angle));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Axis<T>& axis)
{
    vector -= axis.origin;
    orient(vector, quaternion(axis.direction, angle));
    vector += axis.origin;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    vector -= pivotPoint.position;

    orient(vector, quaternion(pivotPoint.axes.x, angles.x));
    orient(vector, quaternion(pivotPoint.axes.y, angles.y));
    orient(vector, quaternion(pivotPoint.axes.z, angles.z));

    vector += pivotPoint.position;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    vector -= pivotPoint.position;

    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            break;
        }
        case ERotationOrder::XZY:
        {
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            break;
        }
        case ERotationOrder::YXZ:
        {
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            break;
        }
        case ERotationOrder::YZX:
        {
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            break;
        }
        case ERotationOrder::ZXY:
        {
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            break;
        }
        case ERotationOrder::ZYX:
        {
            orient(vector, quaternion(pivotPoint.axes.z, angles.z));
            orient(vector, quaternion(pivotPoint.axes.y, angles.y));
            orient(vector, quaternion(pivotPoint.axes.x, angles.x));
            break;
        }
    }

    vector += pivotPoint.position;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
    orient(vector, quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    rotate(vector, transforms.rotations, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, T angle)
{
    Vector<3,T> axs = axis<Axis>();

    if constexpr (Space == ESpace::Local)
    {
        axs = localToGlobal(axs, matrix);
    }

    rotate<ESpace::World>(matrix, quaternion(axs,angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles)
{
    rotate<EAxes::X, Space>(matrix, angles.x);
    rotate<EAxes::Y, Space>(matrix, angles.y);
    rotate<EAxes::Z, Space>(matrix, angles.z);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::Z, Space>(matrix, angles.z);
        }
        case ERotationOrder::XZY:
        {
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::Y, Space>(matrix, angles.y);
        }
        case ERotationOrder::YXZ:
        {
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Z, Space>(matrix, angles.z);
        }
        case ERotationOrder::YZX:
        {
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::X, Space>(matrix, angles.x);
        }
        case ERotationOrder::ZXY:
        {
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Y, Space>(matrix, angles.y);
        }
        case ERotationOrder::ZYX:
        {
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::X, Space>(matrix, angles.x);
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion)
{
    auto X = x(matrix);
    auto Y = y(matrix);
    auto Z = z(matrix);

    if constexpr (Space == ESpace::World)
    {
        orient(X, quaternion);
        orient(Y, quaternion);
        orient(Z, quaternion);
    }
    else
    {
        auto [localSpaceAxis, angle] = axisAngle(quaternion);
        auto worldSpaceAxis = localToGlobal(localSpaceAxis, matrix);
        auto worldSpaceQuat = CGM_XFORM3D::quaternion(worldSpaceAxis, angle);

        orient(X, worldSpaceQuat);
        orient(Y, worldSpaceQuat);
        orient(Z, worldSpaceQuat);
    }

    setX(matrix, X);
    setY(matrix, Y);
    setZ(matrix, Z);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    rotate<Space>(matrix, transforms.rotations, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle)
{
    Vector<3,T> axs = axis<Axis>();

    if constexpr (Space == ESpace::Local)
    {
        axs = localToGlobal<EVectorRepresentation::Direction>(axs, matrix);
    }

    rotate<ESpace::World>(matrix, quaternion(axs,angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, T angle, const Axis<T>& axis)
{
    auto X = x(matrix);
    auto Y = y(matrix);
    auto Z = z(matrix);
    auto P = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        auto quat = quaternion(axis.direction, angle);

        orient(X, quat);
        orient(Y, quat);
        orient(Z, quat);

        P -= axis.origin;
        orient(P, quat);
        P += axis.origin;
    }
    else
    {
        auto worldSpaceAxisDir = localToGlobal<EVectorRepresentation::Direction>(axis.direction, matrix);
        auto worldSpaceAxisPos = localToGlobal<EVectorRepresentation::Point>(axis.origin, matrix);
        auto worldSpaceQuat = CGM_XFORM3D::quaternion(worldSpaceAxisDir, angle);

        orient(X, worldSpaceQuat);
        orient(Y, worldSpaceQuat);
        orient(Z, worldSpaceQuat);

        P -= worldSpaceAxisPos;
        orient(P, worldSpaceQuat);
        P += worldSpaceAxisPos;
    }

    setX(matrix, X);
    setY(matrix, Y);
    setZ(matrix, Z);
    setPosition(matrix, P);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
    rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
    rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
        }
        case ERotationOrder::XZY:
        {
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
        }
        case ERotationOrder::YXZ:
        {
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
        }
        case ERotationOrder::YZX:
        {
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
        }
        case ERotationOrder::ZXY:
        {
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
        }
        case ERotationOrder::ZYX:
        {
            rotate<Space>(matrix, angles.z, Axis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.y, Axis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.x, Axis<T>(pivotPoint.axes.x, pivotPoint.position));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion)
{
    auto X = x(matrix);
    auto Y = y(matrix);
    auto Z = z(matrix);
    auto P = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        orient(X, quaternion);
        orient(Y, quaternion);
        orient(Z, quaternion);
        orient(P, quaternion);
    }
    else
    {
        auto [localSpaceAxis, angle] = axisAngle(quaternion);
        auto worldSpaceAxis = localToGlobal<EVectorRepresentation::Direction>(localSpaceAxis, matrix);
        auto worldSpaceQuat = CGM_XFORM3D::quaternion(worldSpaceAxis, angle);

        orient(X, worldSpaceQuat);
        orient(Y, worldSpaceQuat);
        orient(Z, worldSpaceQuat);
        orient(P, worldSpaceQuat);
    }

    setX(matrix, X);
    setY(matrix, Y);
    setZ(matrix, Z);
    setPosition(matrix, P);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    rotate<Space>(matrix, transforms.rotations, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle)
{
    rotate<Axis>(pivot.axes.x, angle);
    rotate<Axis>(pivot.axes.y, angle);
    rotate<Axis>(pivot.axes.z, angle);
    rotate<Axis>(pivot.position, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const Axis<T>& axis)
{
    rotate(pivot.axes.x, angle, axis);
    rotate(pivot.axes.y, angle, axis);
    rotate(pivot.axes.z, angle, axis);
    rotate(pivot.position, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate(pivot.axes.x, angles, pivotPoint);
    rotate(pivot.axes.y, angles, pivotPoint);
    rotate(pivot.axes.z, angles, pivotPoint);
    rotate(pivot.position, angles, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    rotate(pivot.axes.x, angles, pivotPoint, rotationOrder);
    rotate(pivot.axes.y, angles, pivotPoint, rotationOrder);
    rotate(pivot.axes.z, angles, pivotPoint, rotationOrder);
    rotate(pivot.position, angles, pivotPoint, rotationOrder);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Quaternion<T>& quaternion)
{
    rotate(pivot.axes.x, quaternion);
    rotate(pivot.axes.y, quaternion);
    rotate(pivot.axes.z, quaternion);
    rotate(pivot.position, quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    rotate(pivot.axes.x, transforms);
    rotate(pivot.axes.y, transforms);
    rotate(pivot.axes.z, transforms);
    rotate(pivot.position, transforms);
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle)
{
    rotate<Space>(quaternion, CGM_XFORM3D::quaternion(axis<Axis>(), angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle, const Vector<3,T>& axis)
{
    rotate<Space>(quaternion, CGM_XFORM3D::quaternion(axis, angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
    rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
    rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
        }
        case ERotationOrder::XZY:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
        }
        case ERotationOrder::YXZ:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
        }
        case ERotationOrder::YZX:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
        }
        case ERotationOrder::ZXY:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
        }
        case ERotationOrder::ZYX:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::quaternion(pivotPoint.axes.x, angles.x));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Quaternion<T>& quat)
{
    if constexpr (Space == ESpace::World)
    {
        quaternion *= quat;
    }
    else
    {
        auto [axs, ang] = axisAngle(quat);
        auto worldSpaceAxis = localToGlobal(axs, quat);
        quaternion *= CGM_XFORM3D::quaternion(worldSpaceAxis, angle);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Transforms<T>& transforms)
{
    rotate<Space>(quaternion, transforms.rotations, transforms.pivot, transforms.rotationOrder);
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END