

#include <CGM/Modules/Cartesian/2D/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Axes<T>& axes)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XY::Axes<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    stream << "\n    X " << axes.x.x << " " << axes.x.y;
    stream << "\n    Y " << axes.y.x << " " << axes.y.y;

    stream << "\n}";
    stream.setf(old_flags);

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XY::EAxes axis)
{
    if (axis == CGM_XY::EAxes::X)
    {
        stream << "CGM::XY::EAxes::X";
    }
    else
    {
        stream << "CGM::XY::EAxes::Y";
    }

    return stream;
}