

#include "IO.hpp"


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Axes<T>& axes)
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
operator << (std::ostream& stream, CGM_XY::EAxes axis)
{
    switch (axis)
    {
        case CGM_XY::EAxes::X: stream << "CGM::XY::EAxes::X"; break;
        case CGM_XY::EAxes::Y: stream << "CGM::XY::EAxes::Y"; break;
    }
    return stream;
}