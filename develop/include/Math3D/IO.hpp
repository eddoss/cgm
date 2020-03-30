#ifndef MATH3D_IO_HPP
#define MATH3D_IO_HPP


#include <iomanip>
#include <iostream>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>
#include <Math3D/Core/Quaternion/Quaternion.hpp>


template <size_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Vector<D,T>& vec);

template <size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Matrix<M,N,T>& mat);

template <typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Quaternion<T>& quat);

#include <private/Math3D/IO.hpp>


#endif //MATH3D_IO_HPP
