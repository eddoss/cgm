#pragma once


#include <CGM/detail/Core/ModuleGlobals.hpp>
#include <CGM/detail/Core/Types/Vector.hpp>
#include <CGM/detail/Core/Types/Matrix.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

using vec2      = Vector<2,FLOAT>;
using vec3      = Vector<3,FLOAT>;
using vec4      = Vector<4,FLOAT>;

using vec2_32   = Vector<2,float32>;
using vec3_32   = Vector<3,float32>;
using vec4_32   = Vector<4,float32>;

using vec2_64   = Vector<2,float64>;
using vec3_64   = Vector<3,float64>;
using vec4_64   = Vector<4,float64>;

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

using mat2      = Matrix<2,2,FLOAT>;
using mat3      = Matrix<3,3,FLOAT>;
using mat4      = Matrix<4,4,FLOAT>;
using mat12     = Matrix<1,2,FLOAT>;
using mat13     = Matrix<1,3,FLOAT>;
using mat14     = Matrix<1,4,FLOAT>;
using mat21     = Matrix<2,1,FLOAT>;
using mat22     = Matrix<2,2,FLOAT>;
using mat23     = Matrix<2,3,FLOAT>;
using mat24     = Matrix<2,4,FLOAT>;
using mat31     = Matrix<3,1,FLOAT>;
using mat32     = Matrix<3,2,FLOAT>;
using mat33     = Matrix<3,3,FLOAT>;
using mat34     = Matrix<3,4,FLOAT>;
using mat41     = Matrix<4,1,FLOAT>;
using mat42     = Matrix<4,2,FLOAT>;
using mat43     = Matrix<4,3,FLOAT>;
using mat44     = Matrix<4,4,FLOAT>;

using mat2_32   = Matrix<2,2,float32>;
using mat3_32   = Matrix<3,3,float32>;
using mat4_32   = Matrix<4,4,float32>;
using mat12_32  = Matrix<1,2,float32>;
using mat13_32  = Matrix<1,3,float32>;
using mat14_32  = Matrix<1,4,float32>;
using mat21_32  = Matrix<2,1,float32>;
using mat22_32  = Matrix<2,2,float32>;
using mat23_32  = Matrix<2,3,float32>;
using mat24_32  = Matrix<2,4,float32>;
using mat31_32  = Matrix<3,1,float32>;
using mat32_32  = Matrix<3,2,float32>;
using mat33_32  = Matrix<3,3,float32>;
using mat34_32  = Matrix<3,4,float32>;
using mat41_32  = Matrix<4,1,float32>;
using mat42_32  = Matrix<4,2,float32>;
using mat43_32  = Matrix<4,3,float32>;
using mat44_32  = Matrix<4,4,float32>;

using mat2_64   = Matrix<2,2,float64>;
using mat3_64   = Matrix<3,3,float64>;
using mat4_64   = Matrix<4,4,float64>;
using mat12_64  = Matrix<1,2,float64>;
using mat13_64  = Matrix<1,3,float64>;
using mat14_64  = Matrix<1,4,float64>;
using mat21_64  = Matrix<2,1,float64>;
using mat22_64  = Matrix<2,2,float64>;
using mat23_64  = Matrix<2,3,float64>;
using mat24_64  = Matrix<2,4,float64>;
using mat31_64  = Matrix<3,1,float64>;
using mat32_64  = Matrix<3,2,float64>;
using mat33_64  = Matrix<3,3,float64>;
using mat34_64  = Matrix<3,4,float64>;
using mat41_64  = Matrix<4,1,float64>;
using mat42_64  = Matrix<4,2,float64>;
using mat43_64  = Matrix<4,3,float64>;
using mat44_64  = Matrix<4,4,float64>;

CGM_NAMESPACE_END
