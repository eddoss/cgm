#ifndef MATH3D_IO_HPP
#define MATH3D_IO_HPP


#include <iomanip>
#include <iostream>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Coordinates/Polar.hpp>
#include <Math3D/Coordinates/Spherical.hpp>
#include <Math3D/Coordinates/Cylindrical.hpp>


template <size_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Vector<D,T>& vec);

template <size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Matrix<M,N,T>& mat);

template <typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::Quaternion<T>& quat);

template <typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Polar<T>& polarCoord);

template <typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Spherical<T>& sphericalCoord);

template <typename T>
std::ostream&
operator << (std::ostream& stream, const MATH3D_NAMESPACE::MATH3D_COORD_NAMESPACE::Cylindrical<T>& cylindricalCoord);

#include <private/Math3D/IO.hpp>


#endif //MATH3D_IO_HPP
