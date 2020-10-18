

#include "IO.hpp"


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Axes<T>& axes)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XYZ::Axes<" << typeid(T).name() << ">\n{";
    stream << "\n    X " << axes.x.x << " " << axes.x.y << " " << axes.x.z;
    stream << "\n    Y " << axes.y.x << " " << axes.y.y << " " << axes.y.z;
    stream << "\n    Z " << axes.z.x << " " << axes.z.y << " " << axes.z.z;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E3D axis)
{
    switch (axis)
    {
        case CGM::E3D::X: stream << "CGM::XYZ::E3D::X"; break;
        case CGM::E3D::Y: stream << "CGM::XYZ::E3D::Y"; break;
        case CGM::E3D::Z: stream << "CGM::XYZ::E3D::Z"; break;
    }

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Quaternion<T>& quat)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM_XYZ::Quaternion<" << typeid(T).name() << ">{ ";
    stream << quat.vector.x << " ";
    stream << quat.vector.y << " ";
    stream << quat.vector.z << " | ";
    stream << quat.scalar << " }";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}