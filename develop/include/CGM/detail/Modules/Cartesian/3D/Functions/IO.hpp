

#include <CGM/Modules/Cartesian/3D/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Axes<T>& axes)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XYZ::Axes<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    stream << "\n    X " << axes.x.x << " " << axes.x.y << " " << axes.x.z;
    stream << "\n    Y " << axes.y.x << " " << axes.y.y << " " << axes.y.z;
    stream << "\n    Z " << axes.z.x << " " << axes.z.y << " " << axes.z.z;

    stream << "\n}";
    stream.setf(old_flags);

    return stream;
}

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EAxes axis)
{
    if (axis == CGM_XYZ::EAxes::X)
    {
        stream << "CGM::XYZ::EAxes::X";
    }
    else if (axis == CGM_XYZ::EAxes::Y)
    {
        stream << "CGM::XYZ::EAxes::Y";
    }
    else
    {
        stream << "CGM::XYZ::EAxes::Z";
    }

    return stream;
}
