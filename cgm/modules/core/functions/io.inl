

#include "io.hpp"


template<size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Vector<D,T>& vec)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::Vector<" << D << ", " << typeid(T).name() << ">{ ";

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
            stream  << "\n    " << *(vec.data()+i);
        }
        stream << "\n}";
    }

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Matrix<M,N,T>& mat)
{
    CGM_PREPARE_IO_STREAM_FLAGS(stream)

    stream << "CGM::Matrix<" << M << ", " << N << ", " << typeid(T).name() << ">\n{";
    for (size_t r = 0; r < M; ++r)
    {
        stream << "\n  ";
        for (size_t c = 0; c < N; ++c)
        {
            stream << "  " << mat(r,c);
        }
    }
    stream << "\n}";

    CGM_RESTORE_IO_STREAM_FLAGS(stream)

    return stream;
}
