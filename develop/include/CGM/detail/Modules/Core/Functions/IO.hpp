

#include <CGM/Modules/Core/Functions/IO.hpp>


template<size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Vector<D,T>& vec)
{
    std::ios_base::fmtflags old_flags {stream.flags()};
    stream.setf(std::ios::showpos);
    stream << std::fixed << std::left << std::setprecision(6);
    stream << "CGM::Vector<" << D << "," << typeid(CGM::Vector<D,T>::value_type).name() << ">{ ";

    if constexpr (D == 2)
    {
        stream << vec.x << " ";
        stream << vec.y << " }";
    }
    else if constexpr (D == 3)
    {
        stream << vec.x << " ";
        stream << vec.y << " ";
        stream << vec.z << " }";
    }
    else if constexpr (D == 4)
    {
        stream << vec.x << " ";
        stream << vec.y << " ";
        stream << vec.z << " ";
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
    stream << "CGM::Matrix<" << M << "," << N << "," << typeid(CGM::Matrix<M,N,T>::value_type).name() << ">\n{";
    stream << std::fixed;
    for (size_t r = 0; r < M; ++r)
    {
        stream << "\n  ";
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
    stream << "CGM::Quaternion<" << typeid(CGM::Quaternion<T>::value_type).name() << ">{ ";
    stream << std::fixed << std::left << std::setprecision(6);
    stream << quat.vector.x << " ";
    stream << quat.vector.y << " ";
    stream << quat.vector.z << " | ";
    stream << quat.scalar << " }";
    stream.setf(old_flags);
    return stream;
}
