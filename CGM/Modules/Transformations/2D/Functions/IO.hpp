#pragma once


#include <iomanip>
#include <iostream>
#include <CGM/Modules/Transformations/2D/Types/ArbitraryAxis.hpp>
#include <CGM/Modules/Transformations/2D/Types/Transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::ArbitraryAxis<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Transforms<T>& transforms);


#include "IO.inl"