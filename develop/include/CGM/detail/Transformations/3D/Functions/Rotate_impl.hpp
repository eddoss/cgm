

#include <CGM/detail/Transformations/3D/Functions/Rotate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle)
{
    orient(vector, orientationQuaternion(axis<Axis,T>(), angle));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles)
{
    orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
    orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
    orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            break;
        }
        case ERotationOrder::XZY:
        {
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            break;
        }
        case ERotationOrder::YXZ:
        {
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            break;
        }
        case ERotationOrder::YZX:
        {
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            break;
        }
        case ERotationOrder::ZXY:
        {
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            break;
        }
        case ERotationOrder::ZYX:
        {
            orient(vector, orientationQuaternion(axis<EAxes::Z,T>(), angles.z));
            orient(vector, orientationQuaternion(axis<EAxes::Y,T>(), angles.y));
            orient(vector, orientationQuaternion(axis<EAxes::X,T>(), angles.x));
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Vector<3,T>& direction)
{
    orient(vector, orientationQuaternion(direction, angle));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const ArbitraryAxis<T>& axis)
{
    vector -= axis.position;
    orient(vector, orientationQuaternion(axis.direction, angle));
    vector += axis.position;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    vector -= pivotPoint.position;

    orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
    orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
    orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));

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
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            break;
        }
        case ERotationOrder::XZY:
        {
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            break;
        }
        case ERotationOrder::YXZ:
        {
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            break;
        }
        case ERotationOrder::YZX:
        {
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
            break;
        }
        case ERotationOrder::ZXY:
        {
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            break;
        }
        case ERotationOrder::ZYX:
        {
            orient(vector, orientationQuaternion(pivotPoint.axes.z, angles.z));
            orient(vector, orientationQuaternion(pivotPoint.axes.y, angles.y));
            orient(vector, orientationQuaternion(pivotPoint.axes.x, angles.x));
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
    rotate(vector, transforms.rotation, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, T angle)
{
    Vector<3,T> axs {};

    if constexpr (Space == ESpace::World)
    {
       axs = axis<Axis,T>();
    }
    else
    {
        if constexpr (Axis == EAxes::X) axs = x(matrix);
        if constexpr (Axis == EAxes::Y) axs = y(matrix);
        if constexpr (Axis == EAxes::Z) axs = z(matrix);
    }

    rotate(matrix, orientationQuaternion(axs,angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction)
{
    auto axes = orientationAxes(matrix);
    Quaternion<T> quat;

    if constexpr (Space == ESpace::World)
    {
        quat = orientationQuaternion(direction, angle);
    }
    else
    {
        quat = orientationQuaternion(converted<ESpace::World>(direction, matrix), angle);
    }

    orient(axes.x, quat);
    orient(axes.y, quat);
    orient(axes.z, quat);

    set(matrix, axes);
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
            break;
        }
        case ERotationOrder::XZY:
        {
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::Y, Space>(matrix, angles.y);
            break;
        }
        case ERotationOrder::YXZ:
        {
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Z, Space>(matrix, angles.z);
            break;
        }
        case ERotationOrder::YZX:
        {
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::X, Space>(matrix, angles.x);
            break;
        }
        case ERotationOrder::ZXY:
        {
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::X, Space>(matrix, angles.x);
            rotate<EAxes::Y, Space>(matrix, angles.y);
            break;
        }
        case ERotationOrder::ZYX:
        {
            rotate<EAxes::Z, Space>(matrix, angles.z);
            rotate<EAxes::Y, Space>(matrix, angles.y);
            rotate<EAxes::X, Space>(matrix, angles.x);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot)
{
    rotate<Space>(matrix, angles.x, pivot.axes.x);
    rotate<Space>(matrix, angles.y, pivot.axes.y);
    rotate<Space>(matrix, angles.z, pivot.axes.z);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            break;
        }
        case ERotationOrder::XZY:
        {
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            break;
        }
        case ERotationOrder::YXZ:
        {
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            break;
        }
        case ERotationOrder::YZX:
        {
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            break;
        }
        case ERotationOrder::ZXY:
        {
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            break;
        }
        case ERotationOrder::ZYX:
        {
            rotate<Space>(matrix, angles.z, pivot.axes.z);
            rotate<Space>(matrix, angles.y, pivot.axes.y);
            rotate<Space>(matrix, angles.x, pivot.axes.x);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion)
{
    auto axes = orientationAxes(matrix);

    orient(axes.x, quaternion);
    orient(axes.y, quaternion);
    orient(axes.z, quaternion);

    set(matrix, axes);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    rotate<Space>(matrix, transforms.rotation, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle)
{
    Vector<3,T> axs {};

    if constexpr (Space == ESpace::World)
    {
       axs = axis<Axis,T>();
    }
    else
    {
        if constexpr (Axis == EAxes::X) axs = x(matrix);
        if constexpr (Axis == EAxes::Y) axs = y(matrix);
        if constexpr (Axis == EAxes::Z) axs = z(matrix);
    }

    rotate(matrix, orientationQuaternion(axs,angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles)
{
    Quaternion<T> qx;
    Quaternion<T> qy;
    Quaternion<T> qz;

    if constexpr (Space == ESpace::World)
    {
        qx = orientationQuaternion(axis<EAxes::X,T>(), angles.x);
        qy = orientationQuaternion(axis<EAxes::Y,T>(), angles.y);
        qz = orientationQuaternion(axis<EAxes::Z,T>(), angles.z);
    }
    else
    {
        qx = orientationQuaternion(x(matrix), angles.x);
        qy = orientationQuaternion(y(matrix), angles.y);
        qz = orientationQuaternion(z(matrix), angles.z);
    }

    auto axes = orientationAxes(matrix);

    orient(axes.x, qx);
    orient(axes.x, qy);
    orient(axes.x, qz);

    orient(axes.y, qx);
    orient(axes.y, qy);
    orient(axes.y, qz);

    orient(axes.z, qx);
    orient(axes.z, qy);
    orient(axes.z, qz);

    if constexpr (Space == ESpace::World)
    {
        auto pos = position(matrix);

        orient(pos, qx);
        orient(pos, qy);
        orient(pos, qz);

        setPosition(matrix, pos);
    }

    setOrientation(matrix, axes);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    Quaternion<T> qx;
    Quaternion<T> qy;
    Quaternion<T> qz;

    if constexpr (Space == ESpace::World)
    {
        qx = orientationQuaternion(axis<EAxes::X,T>(), angles.x);
        qy = orientationQuaternion(axis<EAxes::Y,T>(), angles.y);
        qz = orientationQuaternion(axis<EAxes::Z,T>(), angles.z);
    }
    else
    {
        qx = orientationQuaternion(x(matrix), angles.x);
        qy = orientationQuaternion(y(matrix), angles.y);
        qz = orientationQuaternion(z(matrix), angles.z);
    }

    auto axes = orientationAxes(matrix);

    switch (rotationOrder)
    {
        case ERotationOrder::XYZ:
        {
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            break;
        }
        case ERotationOrder::XZY:
        {
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            break;
        }
        case ERotationOrder::YXZ:
        {
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            break;
        }
        case ERotationOrder::YZX:
        {
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            break;
        }
        case ERotationOrder::ZXY:
        {
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            break;
        }
        case ERotationOrder::ZYX:
        {
            orient(axes.x, qz); orient(axes.y, qz); orient(axes.z, qz);
            orient(axes.x, qy); orient(axes.y, qy); orient(axes.z, qy);
            orient(axes.x, qx); orient(axes.y, qx); orient(axes.z, qx);
            break;
        }
    }

    if constexpr (Space == ESpace::World)
    {
        auto pos = position(matrix);

        switch (rotationOrder)
        {
            case ERotationOrder::XYZ:
            {
                orient(pos, qx);
                orient(pos, qy);
                orient(pos, qz);
                break;
            }
            case ERotationOrder::XZY:
            {
                orient(pos, qx);
                orient(pos, qz);
                orient(pos, qy);
                break;
            }
            case ERotationOrder::YXZ:
            {
                orient(pos, qy);
                orient(pos, qx);
                orient(pos, qz);
                break;
            }
            case ERotationOrder::YZX:
            {
                orient(pos, qy);
                orient(pos, qz);
                orient(pos, qx);
                break;
            }
            case ERotationOrder::ZXY:
            {
                orient(pos, qz);
                orient(pos, qx);
                orient(pos, qy);
                break;
            }
            case ERotationOrder::ZYX:
            {
                orient(pos, qz);
                orient(pos, qy);
                orient(pos, qx);
                break;
            }
        }

        setPosition(matrix, pos);
    }

    setOrientation(matrix, axes);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);
    Quaternion<T> quat;

    if constexpr (Space == ESpace::World)
    {
       quat = orientationQuaternion(direction, angle);
    }
    else
    {
        quat = orientationQuaternion(converted<ESpace::World>(direction, matrix), angle);
    }

    orient(axes.x, quat);
    orient(axes.y, quat);
    orient(axes.z, quat);
    orient(pos, quat);

    set(matrix, axes, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, T angle, const ArbitraryAxis<T>& axis)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
//        auto quat = orientationQuaternion(axis.direction, angle);
//
//        orient(axes.x, quat);
//        orient(axes.y, quat);
//        orient(axes.z, quat);
//
//        pos -= axis.position;
//        orient(pos, quat);
//        pos += axis.position;

        rotate(axes.x, angle, axis.direction);
        rotate(axes.y, angle, axis.direction);
        rotate(axes.z, angle, axis.direction);
        rotate(pos, angle, axis);
    }
    else
    {
        auto wsAxisDir = converted<ESpace::World,EVectorRepresentation::Direction>(axis.direction, matrix);
        auto wsAxisPos = converted<ESpace::World,EVectorRepresentation::Point>(axis.position, matrix);
        auto wsQuat = orientationQuaternion(wsAxisDir, angle);

        orient(axes.x, wsQuat);
        orient(axes.y, wsQuat);
        orient(axes.z, wsQuat);

        pos -= wsAxisPos;
        orient(pos, wsQuat);
        pos += wsAxisPos;
    }

    set(matrix, axes, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
    rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
    rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
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
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            break;
        }
        case ERotationOrder::XZY:
        {
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            break;
        }
        case ERotationOrder::YXZ:
        {
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            break;
        }
        case ERotationOrder::YZX:
        {
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            break;
        }
        case ERotationOrder::ZXY:
        {
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            break;
        }
        case ERotationOrder::ZYX:
        {
            rotate<Space>(matrix, angles.z, ArbitraryAxis<T>(pivotPoint.axes.z, pivotPoint.position));
            rotate<Space>(matrix, angles.y, ArbitraryAxis<T>(pivotPoint.axes.y, pivotPoint.position));
            rotate<Space>(matrix, angles.x, ArbitraryAxis<T>(pivotPoint.axes.x, pivotPoint.position));
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion)
{
    auto axes = orientationAxes(matrix);
    auto pos = position(matrix);

    orient(axes.x, quaternion);
    orient(axes.y, quaternion);
    orient(axes.z, quaternion);
    orient(pos, quaternion);

    setX(matrix, axes.x);
    setY(matrix, axes.y);
    setZ(matrix, axes.z);
    setPosition(matrix, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    rotate<Space>(matrix, transforms.rotation, transforms.pivot, transforms.rotationOrder);
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
rotate(Pivot<T>& pivot, T angle, const Vector<3,T>& direction)
{
    const auto quat = orientationQuaternion(direction, angle);

    orient(pivot.axes.x, quat);
    orient(pivot.axes.y, quat);
    orient(pivot.axes.z, quat);
    orient(pivot.position, quat);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const ArbitraryAxis<T>& axis)
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
    rotate(pivot, transforms.rotation, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Axis (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle)
{
    rotate<Axis>(arbitraryAxis.direction, angle);
    rotate<Axis>(arbitraryAxis.position, angle);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles)
{
    rotate(arbitraryAxis.direction, angles);
    rotate(arbitraryAxis.position, angles);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    rotate(arbitraryAxis.direction, angles, rotationOrder);
    rotate(arbitraryAxis.position, angles, rotationOrder);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle, const Vector<3,T>& direction)
{
    rotate(arbitraryAxis.direction, angle, direction);
    rotate(arbitraryAxis.position, angle, direction);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, T angle, const ArbitraryAxis<T>& axis)
{
    rotate(arbitraryAxis.direction, angle, axis);
    rotate(arbitraryAxis.position, angle, axis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate(arbitraryAxis.direction, angles, pivotPoint);
    rotate(arbitraryAxis.position, angles, pivotPoint);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    rotate(arbitraryAxis.direction, angles, pivotPoint, rotationOrder);
    rotate(arbitraryAxis.position, angles, pivotPoint, rotationOrder);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Quaternion<T>& quaternion)
{
    rotate(arbitraryAxis.direction, quaternion);
    rotate(arbitraryAxis.position, quaternion);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    rotate(arbitraryAxis.direction, transforms);
    rotate(arbitraryAxis.position, transforms);
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle)
{
    rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(axis<Axis,T>(), angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle, const Vector<3,T>& direction)
{
    rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(direction, angle));
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
    rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
    rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
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
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
        }
        case ERotationOrder::XZY:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
        }
        case ERotationOrder::YXZ:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
        }
        case ERotationOrder::YZX:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
        }
        case ERotationOrder::ZXY:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
        }
        case ERotationOrder::ZYX:
        {
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.z, angles.z));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.y, angles.y));
            rotate<Space>(quaternion, CGM_XFORM3D::orientationQuaternion(pivotPoint.axes.x, angles.x));
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
        auto worldSpaceAxis = converted<ESpace::World>(axs, quat);
        quaternion *= CGM_XFORM3D::orientationQuaternion(worldSpaceAxis, angle);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Transforms<T>& transforms)
{
    rotate<Space>(quaternion, transforms.rotation, transforms.pivot, transforms.rotationOrder);
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle)
{
    auto copy = vector;
    rotate<Axis,T>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles)
{
    auto copy = vector;
    rotate(copy, angles);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    auto copy = vector;
    rotate(copy, angles, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle, const Vector<3,T>& direction)
{
    auto copy = vector;
    rotate(copy, angle, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, T angle, const ArbitraryAxis<T>& axis)
{
    auto copy = vector;
    rotate(copy, angle, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto copy = vector;
    rotate(copy, angles, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto copy = vector;
    rotate(copy, angles, pivotPoint, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
    auto copy = vector;
    rotate(copy, quaternion);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
rotated(const Vector<3,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    rotate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix3 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle)
{
    auto copy = matrix;
    rotate<Axis, Space>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, T angle, const Vector<3,T>& direction)
{
    auto copy = matrix;
    rotate<Space>(copy, angle, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles)
{
    auto copy = matrix;
    rotate<Space>(copy, angles);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, pivot);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivot, ERotationOrder rotationOrder)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, pivot, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion)
{
    auto copy = matrix;
    rotate<Space>(copy, quaternion);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
rotated(const Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    rotate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, T angle)
{
    auto copy = matrix;
    rotate<Axis,Space>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles)
{
    auto copy = matrix;
    rotate<Space>(copy, angles);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, T angle, const Vector<3,T>& direction)
{
    auto copy = matrix;
    rotate<Space>(copy, angle, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, T angle, const ArbitraryAxis<T>& axis)
{
    auto copy = matrix;
    rotate<Space>(copy, angle, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto copy = matrix;
    rotate<Space>(copy, angles, pivotPoint, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion)
{
    auto copy = matrix;
    rotate<Space>(copy, quaternion);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotated(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    rotate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle)
{
    auto copy = pivot;
    rotate<Axis>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(Pivot<T>& pivot, T angle, const Vector<3,T>& direction)
{
    auto copy = pivot;
    rotate(copy, angle, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, T angle, const ArbitraryAxis<T>& axis)
{
    auto copy = pivot;
    rotate(copy, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto copy = pivot;
    rotate(copy, angles, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto copy = pivot;
    rotate(copy, angles, pivotPoint, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Quaternion<T>& quaternion)
{
    auto copy = pivot;
    rotate(copy, quaternion);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
rotated(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    rotate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Axis (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle)
{
    auto copy = arbitraryAxis;
    rotate<Axis>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles)
{
    auto copy = arbitraryAxis;
    rotate(copy, angles);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    auto copy = arbitraryAxis;
    rotate(copy, angles, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle, const Vector<3,T>& direction)
{
    auto copy = arbitraryAxis;
    rotate(copy, angle, direction);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, T angle, const ArbitraryAxis<T>& axis)
{
    auto copy = arbitraryAxis;
    rotate(copy, angle, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto copy = arbitraryAxis;
    rotate(copy, angles, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto copy = arbitraryAxis;
    rotate(copy, angles, pivotPoint, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Quaternion<T>& quaternion)
{
    auto copy = arbitraryAxis;
    rotate(copy, quaternion);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE ArbitraryAxis<T>
rotated(const ArbitraryAxis<T>& arbitraryAxis, const Transforms<T>& transforms)
{
    auto copy = arbitraryAxis;
    rotate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Quaternion (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle)
{
    auto copy = quaternion;
    rotate<Axis, Space>(copy, angle);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, T angle, const Vector<3,T>& axis)
{
    auto copy = quaternion;
    rotate<Space>(copy, angle, axis);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto copy = quaternion;
    rotate<Space>(copy, angles, pivotPoint);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto copy = quaternion;
    rotate<Space>(copy, angles, pivotPoint, rotationOrder);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Quaternion<T>& quat)
{
    auto copy = quaternion;
    rotate<Space>(copy, quat);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Quaternion<T>
rotated(const Quaternion<T>& quaternion, const Transforms<T>& transforms)
{
    auto copy = quaternion;
    rotate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<EAxes Axis, size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(T angle)
{
    auto mat = CGM::identity<N,T>();
    rotate<Axis>(mat, angle);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(const Vector<3,T>& angles)
{
    auto mat = CGM::identity<N,T>();
    rotate(mat, angles);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(const Vector<3,T>& angles, ERotationOrder rotationOrder)
{
    auto mat = CGM::identity<N,T>();
    rotate(mat, angles, rotationOrder);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<size_t N, typename T>
constexpr CGM_FORCEINLINE std::enable_if_t<(N==3 || N==4), Matrix<N,N,T>>
rotationMatrix(T angle, const Vector<3,T>& direction)
{
    auto mat = CGM::identity<N,T>();
    rotate(mat, angle, direction);

    if constexpr (N == 3)
    {
        transpose(mat);
    }
    else
    {
        transposeOrientation(mat);
    }

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(T angle, const ArbitraryAxis<T>& axis)
{
    auto mat = CGM::identity<4,T>();
    rotate(mat, angle, axis);

    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint)
{
    auto mat = CGM::identity<4,T>();
    rotate(mat, angles, pivotPoint);

    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    auto mat = CGM::identity<4,T>();
    rotate(mat, angles, pivotPoint, rotationOrder);

    transposeOrientation(mat);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
rotationMatrix(const Transforms<T>& transforms)
{
    auto mat = CGM::identity<4,T>();
    rotate(mat, transforms);

    transposeOrientation(mat);

    return mat;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
