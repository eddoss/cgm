#pragma once


#include <CGM/Modules/Core/ModuleGlobals.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Types/Quaternion.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

using vec2  = Vector<2,FLOAT>;
using vec3  = Vector<3,FLOAT>;
using vec4  = Vector<4,FLOAT>;

/* ####################################################################################### */
/* Matrix */
/* ####################################################################################### */

using mat2  = Matrix<2,2,FLOAT>;
using mat3  = Matrix<3,3,FLOAT>;
using mat4  = Matrix<4,4,FLOAT>;
using mat12 = Matrix<1,2,FLOAT>;
using mat13 = Matrix<1,3,FLOAT>;
using mat14 = Matrix<1,4,FLOAT>;
using mat21 = Matrix<2,1,FLOAT>;
using mat22 = Matrix<2,2,FLOAT>;
using mat23 = Matrix<2,3,FLOAT>;
using mat24 = Matrix<2,4,FLOAT>;
using mat31 = Matrix<3,1,FLOAT>;
using mat32 = Matrix<3,2,FLOAT>;
using mat33 = Matrix<3,3,FLOAT>;
using mat34 = Matrix<3,4,FLOAT>;
using mat41 = Matrix<4,1,FLOAT>;
using mat42 = Matrix<4,2,FLOAT>;
using mat43 = Matrix<4,3,FLOAT>;
using mat44 = Matrix<4,4,FLOAT>;

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

using quat = Quaternion<FLOAT>;

CGM_NAMESPACE_END
