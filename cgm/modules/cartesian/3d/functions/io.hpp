#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/cartesian/common.hpp>
#include <cgm/modules/cartesian/3d/types/axes.hpp>
#include <cgm/modules/cartesian/3d/types/quaternion.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Axes<T>& axes);

constexpr std::ostream&
operator << (std::ostream& stream, CGM::E3D axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM::Quaternion<T>& quat);


#include "io.inl"
