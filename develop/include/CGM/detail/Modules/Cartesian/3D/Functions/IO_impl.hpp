

#include <CGM/detail/Modules/Cartesian/3D/Functions/IO.hpp>


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
operator << (std::ostream& stream, CGM_XYZ::EAxes axis)
{
    switch (axis)
    {
        case CGM_XYZ::EAxes::X: stream << "CGM::XYZ::EAxes::X"; break;
        case CGM_XYZ::EAxes::Y: stream << "CGM::XYZ::EAxes::Y"; break;
        case CGM_XYZ::EAxes::Z: stream << "CGM::XYZ::EAxes::Z"; break;
    }

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM::ESpace space)
{
    switch (space)
    {
        case CGM::ESpace::World: stream << "CGM::ESpace::World"; break;
        case CGM::ESpace::Local: stream << "CGM::ESpace::Local"; break;
    }

    return stream;
}