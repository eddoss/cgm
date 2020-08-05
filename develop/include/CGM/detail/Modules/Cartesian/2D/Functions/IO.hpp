

#include <CGM/Modules/Cartesian/2D/Functions/IO.hpp>


template <CGM_XY::EBasisBase Base, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::Basis<Base,T>& basis)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XY::Basis<";

    if constexpr (Base == CGM_XY::EBasisBase::Matrix2)
    {
        stream << "Matrix2, ";
    }
    else
    {
        stream << "Matrix3, ";
    }

    stream << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    auto x = basis.x();
    auto y = basis.y();
    auto p = basis.position();

    stream << "\n    X " << x.x << " " << x.y;
    stream << "\n    Y " << y.x << " " << y.y;
    stream << "\n    P " << p.x << " " << p.y;

    stream << "\n}";
    stream.setf(old_flags);

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::AxesTuple<T>& axes)
{
    std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XY::AxesTuple<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    const auto& x = std::get<0>(axes);
    const auto& y = std::get<1>(axes);

    stream << "\n    X " << x.x << " " << x.y;
    stream << "\n    Y " << y.x << " " << y.y;

    stream << "\n}";
    stream.setf(old_flags);

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::SpaceTuple<T>& space)
{
        std::ios_base::fmtflags old_flags {stream.flags()};

    stream.setf(std::ios::showpos);
    stream << "CGM::XY::SpaceTuple<" << typeid(T).name() << ">\n{";
    stream << std::fixed << std::left << std::setprecision(6);

    const auto& x = std::get<0>(space);
    const auto& y = std::get<1>(space);
    const auto& z = std::get<2>(space);
    const auto& p = std::get<3>(space);

    stream << "\n    X " << x.x << " " << x.y;
    stream << "\n    Y " << y.x << " " << y.y;
    stream << "\n    P " << p.x << " " << p.y;

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

/* --------------------------------------------------------------------------------------- */

constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XY::EBasisBase basisBase)
{
    if (basisBase == CGM_XY::EBasisBase::Matrix2)
    {
        stream << "CGM::XY::EBasisBase::Matrix2";
    }
    else
    {
        stream << "CGM::XY::EBasisBase::Matrix3";
    }

    return stream;
}