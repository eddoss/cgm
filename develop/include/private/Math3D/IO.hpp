#ifndef MATH3D_PRIVATE_IO_HPP
#define MATH3D_PRIVATE_IO_HPP


#include <Math3D/IO.hpp>


template<size_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Vector<D,T>& vec)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(vec).name() << "\n{";
    stream << std::fixed;
    for (size_t i = 0; i < D; ++i)
    {
        stream  << "\n    "
                << std::setw(10)
                << std::left
                << std::setprecision(6)
                << *(vec.data()+i);
    }
    stream << "\n}";
    stream.setf(old_flags);
    return stream;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Matrix<M,N,T>& mat)
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
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Quaternion<T>& quat)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << typeid(quat).name() << "\n{\n";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << "    s = " << quat.s << "\n";
    stream << "    a = " << quat.a << "\n";
    stream << "    a = " << quat.a << "\n";
    stream << "    b = " << quat.b << "\n";
    stream << "    c = " << quat.c << "\n";
    stream << "}";
    stream.setf(old_flags);
    return stream;
}

#endif //MATH3D_PRIVATE_IO_HPP