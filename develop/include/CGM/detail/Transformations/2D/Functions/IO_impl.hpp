

#include <CGM/detail/Transformations/2D/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::ArbitraryAxis<T>& axis)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XY::ArbitraryAxis<" << typeid(T).name() << ">\n{";
    stream << "\n    Direction: " << axis.direction.x << " " << axis.direction.y;
    stream << "\n    Position : " << axis.origin.x << " " << axis.origin.y;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Pivot<T>& pivot)
{

    auto x = pivot.axes.x;
    auto y = pivot.axes.y;
    auto p = pivot.position;

    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XY::Pivot<" << typeid(T).name() << ">\n{";
    stream << "\n    X " << x.x << " " << x.y;
    stream << "\n    Y " << y.x << " " << y.y;
    stream << "\n    P " << p.x << " " << p.y;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Transforms<T>& transforms)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XY::Transforms<" << typeid(T).name() << ">\n{";
    stream << "\n        Order: [ ";

    switch (transforms.transformOrder)
    {
        case CGM::ETransformOrder::RST: stream << "Tr Ts Tt"; break;
        case CGM::ETransformOrder::RTS: stream << "Tr Tt Ts"; break;
        case CGM::ETransformOrder::SRT: stream << "Ts Tr Tt"; break;
        case CGM::ETransformOrder::STR: stream << "Ts Tt Tr"; break;
        case CGM::ETransformOrder::TRS: stream << "Tt Tr Ts"; break;
        case CGM::ETransformOrder::TSR: stream << "Tt Ts Tr"; break;
    }

    stream << " ]\n";

    auto x = transforms.pivot.axes.x;
    auto y = transforms.pivot.axes.y;
    auto p = transforms.pivot.position;

    stream << "\n      Pivot.x: " << x.x << " " << x.y;
    stream << "\n            y: " << y.x << " " << y.y;
    stream << "\n            p: " << p.x << " " << p.y << "\n";

    stream << "\n    Translate: " << transforms.translation.x << " " << transforms.translation.y;
    stream << "\n       Rotate: " << transforms.rotation.x << " " << transforms.rotation.y;
    stream << "\n        Scale: " << transforms.scale.x << " " << transforms.scale.y;
    stream << "\n       UScale: " << transforms.uniformScale;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

