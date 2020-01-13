#ifndef MATH3D_IO_HPP
#define MATH3D_IO_HPP


#include <ios>
#include <iomanip>
#include <Math3D/Core/Structs/Vectors/Vector.hpp>
#include <Math3D/Core/Structs/Matrices/Matrix.hpp>

template<size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const Matrix<M,N,T>& mat)
{
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
    stream << "\n}\n";
    return stream;
}

#endif //MATH3D_IO_HPP