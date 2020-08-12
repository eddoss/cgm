#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Transformations/3D/Types/Axis.hpp>
#include <CGM/Modules/Transformations/3D/Types/Pivot.hpp>
#include <CGM/Modules/Transformations/3D/Types/Transforms.hpp>


template <size_t D, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Axis<T>& axis);

template <size_t M, size_t N, typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM3D::Transforms<T>& transforms);


#include <CGM/detail/Modules/Transformations/3D/Functions/IO.hpp>
