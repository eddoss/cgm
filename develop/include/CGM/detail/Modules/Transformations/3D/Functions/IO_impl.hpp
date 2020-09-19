

#include <CGM/detail/Modules/Transformations/3D/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::ArbitraryAxis<T>& axis)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XYZ::ArbitraryAxis<" << typeid(T).name() << ">\n{";
    stream << "\n    Direction: " << axis.direction.x << " " << axis.direction.y << " " << axis.direction.z;
    stream << "\n    Position : " << axis.origin.x << " " << axis.origin.y << " " << axis.origin.z;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Pivot<T>& pivot)
{

    auto x = pivot.axes.x;
    auto y = pivot.axes.y;
    auto z = pivot.axes.z;
    auto p = pivot.position;

    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XYZ::Pivot<" << typeid(T).name() << ">\n{";
    stream << "\n    X " << x.x << " " << x.y << " " << x.z;
    stream << "\n    Y " << y.x << " " << y.y << " " << y.z;
    stream << "\n    Z " << z.x << " " << z.y << " " << z.z;
    stream << "\n    P " << p.x << " " << p.y << " " << p.z;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Transforms<T>& transforms)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XYZ::Transforms<" << typeid(T).name() << ">\n{";
    stream << "\n       Orders: [ ";

    switch (transforms.transformOrder)
    {
        case CGM::ETransformOrder::RST: stream << "Tr Ts Tt"; break;
        case CGM::ETransformOrder::RTS: stream << "Tr Tt Ts"; break;
        case CGM::ETransformOrder::SRT: stream << "Ts Tr Tt"; break;
        case CGM::ETransformOrder::STR: stream << "Ts Tt Tr"; break;
        case CGM::ETransformOrder::TRS: stream << "Tt Tr Ts"; break;
        case CGM::ETransformOrder::TSR: stream << "Tt Ts Tr"; break;
    }

    stream << " ][ ";
    switch (transforms.rotationOrder)
    {
        case CGM_XFORM3D::ERotationOrder::XYZ: stream << "Rx Ry Rz"; break;
        case CGM_XFORM3D::ERotationOrder::XZY: stream << "Rx Rz Ry"; break;
        case CGM_XFORM3D::ERotationOrder::YXZ: stream << "Ry Rx Rz"; break;
        case CGM_XFORM3D::ERotationOrder::YZX: stream << "Ry Rz Rx"; break;
        case CGM_XFORM3D::ERotationOrder::ZXY: stream << "Rz Rx Ry"; break;
        case CGM_XFORM3D::ERotationOrder::ZYX: stream << "Rz Ry Rx"; break;
    }
    stream << " ]\n";

    auto x = transforms.pivot.axes.x;
    auto y = transforms.pivot.axes.y;
    auto z = transforms.pivot.axes.z;
    auto p = transforms.pivot.position;

    stream << "\n      Pivot.x: " << x.x << " " << x.y << " " << x.z;
    stream << "\n            y: " << y.x << " " << y.y << " " << y.z;
    stream << "\n            z: " << z.x << " " << z.y << " " << z.z;
    stream << "\n            p: " << p.x << " " << p.y << " " << p.z << "\n";

    stream << "\n    Translate: " << transforms.translation.x << " " << transforms.translation.y << " " << transforms.translation.z;
    stream << "\n       Rotate: " << transforms.rotation.x << " " << transforms.rotation.y << " " << transforms.rotation.z;
    stream << "\n        Scale: " << transforms.scale.x << " " << transforms.scale.y << " " << transforms.scale.z;
    stream << "\n       UScale: " << transforms.uniformScale;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::AxisAngle<T>& axisAngle)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XYZ::AxisAngle<" << typeid(T).name() << ">{";
    stream << " " << axisAngle.axis.x << " " << axisAngle.axis.y << " " << axisAngle.axis.z;
    stream << " | " << axisAngle.angle << " }";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XFORM3D::ERotationOrder rotationOrder)
{
    switch (rotationOrder)
    {
        case CGM_XFORM3D::ERotationOrder::XYZ: stream << "CGM::XYZ::ERotationOrder::XYZ"; break;
        case CGM_XFORM3D::ERotationOrder::XZY: stream << "CGM::XYZ::ERotationOrder::XZY"; break;
        case CGM_XFORM3D::ERotationOrder::YXZ: stream << "CGM::XYZ::ERotationOrder::YXZ"; break;
        case CGM_XFORM3D::ERotationOrder::YZX: stream << "CGM::XYZ::ERotationOrder::YZX"; break;
        case CGM_XFORM3D::ERotationOrder::ZXY: stream << "CGM::XYZ::ERotationOrder::ZXY"; break;
        case CGM_XFORM3D::ERotationOrder::ZYX: stream << "CGM::XYZ::ERotationOrder::ZYX"; break;
    }

    return stream;
}
