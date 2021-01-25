#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Cartesian/Common.hpp>
#include <CGM/Cartesian/3D/Types/Axes.hpp>
#include <CGM/Cartesian/3D/Types/Quaternion.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E3D axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Quaternion<T>& quat);


#include "IO.inl"