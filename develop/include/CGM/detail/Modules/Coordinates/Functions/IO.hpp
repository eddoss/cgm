

#include <CGM/Modules/Coordinates/Functions/IO.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Polar<T>& polarCoord)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(polarCoord).name() << "\n{\n";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << "    ang = " << polarCoord.angle() << "\n";
    stream << "    rad = " << polarCoord.radius() << "\n";
    stream << "}";
    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Spherical<T>& sphericalCoord)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(sphericalCoord).name() << "\n{\n";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << "    lon = " << sphericalCoord.longitude() << "\n";
    stream << "    lat = " << sphericalCoord.latitude() << "\n";
    stream << "    rad = " << sphericalCoord.radius() << "\n";
    stream << "}";
    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_COORD::Cylindrical<T>& cylindricalCoord)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(cylindricalCoord).name() << "\n{\n";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << "    ang = " << cylindricalCoord.angle() << "\n";
    stream << "    hei = " << cylindricalCoord.height() << "\n";
    stream << "    rad = " << cylindricalCoord.radius() << "\n";
    stream << "}";
    stream.setf(old_flags);
    return stream;
}