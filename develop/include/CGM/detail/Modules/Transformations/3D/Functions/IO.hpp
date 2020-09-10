

#include <CGM/Modules/Transformations/3D/Functions/IO.hpp>


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
    stream << "\n       Orders [ ";

    switch (transforms.transformOrder)
    {
        case CGM::ETransformOrder::RST: stream << "Rotate Scale Translate"; break;
        case CGM::ETransformOrder::RTS: stream << "Rotate Translate Scale"; break;
        case CGM::ETransformOrder::SRT: stream << "Scale Rotate Translate"; break;
        case CGM::ETransformOrder::STR: stream << "Scale Translate Rotate"; break;
        case CGM::ETransformOrder::TRS: stream << "Translate Rotate Scale"; break;
        case CGM::ETransformOrder::TSR: stream << "Translate Scale Rotate"; break;
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

    stream << "\n      Pivot.x " << x.x << " " << x.y << " " << x.z;
    stream << "\n      Pivot.y " << y.x << " " << y.y << " " << y.z;
    stream << "\n      Pivot.z " << z.x << " " << z.y << " " << z.z;
    stream << "\n      Pivot.p " << p.x << " " << p.y << " " << p.z << "\n";

    stream << "\n    Translate " << transforms.translations.x << " " << transforms.translations.y << " " << transforms.translations.z;
    stream << "\n       Rotate " << transforms.rotations.x << " " << transforms.rotations.y << " " << transforms.rotations.z;
    stream << "\n        Scale " << transforms.scales.x << " " << transforms.scales.y << " " << transforms.scales.z;
    stream << "\n       UScale " << transforms.uniformScale;
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

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ETransformOrder transformOrder)
{
    switch (transformOrder)
    {
        case CGM::ETransformOrder::RST: stream << "CGM::ETransformOrder::RST"; break;
        case CGM::ETransformOrder::RTS: stream << "CGM::ETransformOrder::RTS"; break;
        case CGM::ETransformOrder::SRT: stream << "CGM::ETransformOrder::SRT"; break;
        case CGM::ETransformOrder::STR: stream << "CGM::ETransformOrder::STR"; break;
        case CGM::ETransformOrder::TRS: stream << "CGM::ETransformOrder::TRS"; break;
        case CGM::ETransformOrder::TSR: stream << "CGM::ETransformOrder::TSR"; break;
    }

    return stream;
}
