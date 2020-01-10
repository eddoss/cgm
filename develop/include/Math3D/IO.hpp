#ifndef MATH3D_IO_HPP
#define MATH3D_IO_HPP


#include <ios>
#include <iomanip>
#include <Math3D/Core/Vectors/Vector.hpp>


template<uint32_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const Vector<D,T>& vector)
{
    stream.setf(std::ios::showpos);
    stream << typeid(vector).name() << "\n{";
    stream << std::fixed;
    for (uint32_t i = 0; i < D; ++i)
    {
        stream  << "\n    "
                << std::setw(10)
                << std::left
                << std::setprecision(6)
                << vector[i];
    }
    stream << "\n}\n";
    return stream;
}

#endif //MATH3D_IO_HPP
