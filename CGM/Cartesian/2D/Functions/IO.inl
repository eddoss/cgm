

#include "IO.hpp"


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_2D::Axes<T>& axes)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::XY::Axes<" << typeid(T).name() << ">\n{";
    stream << "\n    X " << axes.x.x << " " << axes.x.y;
    stream << "\n    Y " << axes.y.x << " " << axes.y.y;
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E2D axis)
{
    switch (axis)
    {
        case CGM::E2D::X: stream << "CGM::XY::E2D::X"; break;
        case CGM::E2D::Y: stream << "CGM::XY::E2D::Y"; break;
    }
    return stream;
}