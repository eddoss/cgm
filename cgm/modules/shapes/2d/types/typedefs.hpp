#pragma once


#include <cgm/modules/shapes/module_globals.hpp>
#include <cgm/modules/shapes/2d/types/range.hpp>
#include <cgm/modules/shapes/2d/types/rectangle.hpp>
#include <cgm/modules/shapes/2d/types/circle.hpp>


CGM_2D_NAMESPACE_BEGIN

using circle    = Circle<FLOAT>;
using fcircle   = Circle<f32>;
using dcircle   = Circle<f64>;

using rect      = Rectangle<FLOAT>;
using frect     = Rectangle<f32>;
using drect     = Rectangle<f64>;

using aabb      = Range<FLOAT>;
using faabb     = Range<f32>;
using daabb     = Range<f64>;

CGM_2D_NAMESPACE_END
