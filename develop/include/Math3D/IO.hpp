#ifndef MATH3D_IO_HPP
#define MATH3D_IO_HPP


#include <ios>
#include <Math3D/Core/Vector.hpp>


template <typename T, uint32_t Size>
std::ostream&
operator << (std::ostream& stream, const Vector<T,Size>& vector)
{
    stream.setf(std::ios::showpos);
    stream << typeid(vector).name() << "\n{";
    stream << std::fixed;
    for (uint32_t i = 0; i < Size; ++i)
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
