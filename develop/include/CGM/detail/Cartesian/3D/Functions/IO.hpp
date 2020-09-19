#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/detail/Cartesian/Common.hpp>
#include <CGM/detail/Cartesian/3D/Types/Axes.hpp>
#include <CGM/detail/Cartesian/3D/Types/Enums.hpp>
#include <CGM/detail/Cartesian/3D/Types/Quaternion.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM_XYZ::EAxes axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XYZ::Quaternion<T>& quat);


#include <CGM/detail/Cartesian/3D/Functions/IO_impl.hpp>
