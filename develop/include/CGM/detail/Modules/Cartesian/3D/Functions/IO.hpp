

#include <CGM/Modules/Cartesian/3D/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::AxesTuple<T>& axes)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XYZ::AxesTuple<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    const auto& x = std::get<0>(axes);
    const auto& y = std::get<1>(axes);
    const auto& z = std::get<2>(axes);

    stream << "\n    X " << x.x << " " << x.y << " " << x.z;
    stream << "\n    Y " << y.x << " " << y.y << " " << y.z;
    stream << "\n    Z " << z.x << " " << z.y << " " << z.z;

    stream << "\n}";
    stream.setf(old_flags);

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::SpaceTuple<T>& space)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XYZ::SpaceTuple<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    const auto& x = std::get<0>(space);
    const auto& y = std::get<1>(space);
    const auto& z = std::get<2>(space);
    const auto& p = std::get<3>(space);

    stream << "\n    X " << x.x << " " << x.y << " " << x.z;
    stream << "\n    Y " << y.x << " " << y.y << " " << y.z;
    stream << "\n    Z " << z.x << " " << z.y << " " << z.z;
    stream << "\n    P " << p.x << " " << p.y << " " << p.z;

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
