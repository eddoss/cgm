

#include <CGM/IO.hpp>


template<size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Vector<D,T>& vec)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << std::fixed << std::left << std::setprecision(6);

    if constexpr (D == 2)
    {
        stream << typeid(vec).name() << "{ ";
        stream << vec.x << ", ";
        stream << vec.y << " }";
    }
    else if constexpr (D == 3)
    {
        stream << typeid(vec).name() << "{ ";
        stream << vec.x << ", ";
        stream << vec.y << ", ";
        stream << vec.z << " }";
    }
    else if constexpr (D == 4)
    {
        stream << typeid(vec).name() << "{ ";
        stream << vec.x << ", ";
        stream << vec.y << ", ";
        stream << vec.z << ", ";
        stream << vec.w << " }";
    }
    else
    {
        stream << typeid(vec).name() << "\n{";
        for (size_t i = 0; i < D; ++i)
        {
            stream  << "\n    "
                    << std::setw(10)
                    << std::left
                    << std::setprecision(6)
                    << *(vec.data()+i);
        }
        stream << "\n}";
    }

    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Matrix<M,N,T>& mat)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(mat).name() << "\n{";
    stream << std::fixed;
    for (size_t r = 0; r < M; ++r)
    {
        stream << "\n    ";
        for (size_t c = 0; c < N; ++c)
        {
            stream  << "  "
                    << std::setw(10)
                    << std::left
                    << std::setprecision(6)
                    << mat(r,c);
        }
    }
    stream << "\n}";
    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Quaternion<T>& quat)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(quat).name() << "{ [x]: ";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << quat.vector.x << ", [y]: ";
    stream << quat.vector.y << ", [z]: ";
    stream << quat.vector.z << ", [w]: ";
    stream << quat.scalar << " }";
    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::CGM_COORD::Polar<T>& polarCoord)
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
operator << (std::ostream& stream, const CGM::CGM_COORD::Spherical<T>& sphericalCoord)
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
operator << (std::ostream& stream, const CGM::CGM_COORD::Cylindrical<T>& cylindricalCoord)
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