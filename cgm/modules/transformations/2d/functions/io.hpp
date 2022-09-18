#pragma once


#include <iomanip>
#include <iostream>
#include <cgm/modules/transformations/2d/types/arbitrary_axis.hpp>
#include <cgm/modules/transformations/2d/types/transforms.hpp>


template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::ArbitraryAxis<T>& axis);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Pivot<T>& pivot);

template <typename T>
constexpr std::ostream&
operator << (std::ostream& stream, const CGM_XFORM2D::Transforms<T>& transforms);


#include "io.inl"
