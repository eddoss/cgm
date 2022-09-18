#pragma once


#include <cgm/modules/core/module_globals.hpp>
#include <cgm/modules/core/types/vector.hpp>
#include <cgm/modules/core/types/matrix.hpp>
#include <cgm/modules/core/types/size.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

using vec2          = Vector<2,FLOAT>;
using vec3          = Vector<3,FLOAT>;
using vec4          = Vector<4,FLOAT>;

using fvec2         = Vector<2,f32>;
using fvec3         = Vector<3,f32>;
using fvec4         = Vector<4,f32>;

using dvec2         = Vector<2,f64>;
using dvec3         = Vector<3,f64>;
using dvec4         = Vector<4,f64>;

using ivec2         = Vector<2,i32>;
using ivec3         = Vector<3,i32>;
using ivec4         = Vector<4,i32>;

using uvec2         = Vector<2,u32>;
using uvec3         = Vector<3,u32>;
using uvec4         = Vector<4,u32>;

using vec2f32       = Vector<2,f32>;
using vec3f32       = Vector<3,f32>;
using vec4f32       = Vector<4,f32>;

using vec2f64       = Vector<2,f64>;
using vec3f64       = Vector<3,f64>;
using vec4f64       = Vector<4,f64>;

using vec2i8        = Vector<2,i8>;
using vec3i8        = Vector<3,i8>;
using vec4i8        = Vector<4,i8>;

using vec2i16       = Vector<2,i16>;
using vec3i16       = Vector<3,i16>;
using vec4i16       = Vector<4,i16>;

using vec2i32       = Vector<2,i32>;
using vec3i32       = Vector<3,i32>;
using vec4i32       = Vector<4,i32>;

using vec2i64       = Vector<2,i64>;
using vec3i64       = Vector<3,i64>;
using vec4i64       = Vector<4,i64>;

using vec2u8        = Vector<2,u8>;
using vec3u8        = Vector<3,u8>;
using vec4u8        = Vector<4,u8>;

using vec2u16       = Vector<2,u16>;
using vec3u16       = Vector<3,u16>;
using vec4u16       = Vector<4,u16>;

using vec2u32       = Vector<2,u32>;
using vec3u32       = Vector<3,u32>;
using vec4u32       = Vector<4,u32>;

using vec2u64       = Vector<2,u64>;
using vec3u64       = Vector<3,u64>;
using vec4u64       = Vector<4,u64>;

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

using fmat2     = Matrix<2,2,f32>;
using fmat3     = Matrix<3,3,f32>;
using fmat4     = Matrix<4,4,f32>;
using fmat12    = Matrix<1,2,f32>;
using fmat13    = Matrix<1,3,f32>;
using fmat14    = Matrix<1,4,f32>;
using fmat21    = Matrix<2,1,f32>;
using fmat22    = Matrix<2,2,f32>;
using fmat23    = Matrix<2,3,f32>;
using fmat24    = Matrix<2,4,f32>;
using fmat31    = Matrix<3,1,f32>;
using fmat32    = Matrix<3,2,f32>;
using fmat33    = Matrix<3,3,f32>;
using fmat34    = Matrix<3,4,f32>;
using fmat41    = Matrix<4,1,f32>;
using fmat42    = Matrix<4,2,f32>;
using fmat43    = Matrix<4,3,f32>;
using fmat44    = Matrix<4,4,f32>;

using dmat2     = Matrix<2,2,f64>;
using dmat3     = Matrix<3,3,f64>;
using dmat4     = Matrix<4,4,f64>;
using dmat12    = Matrix<1,2,f64>;
using dmat13    = Matrix<1,3,f64>;
using dmat14    = Matrix<1,4,f64>;
using dmat21    = Matrix<2,1,f64>;
using dmat22    = Matrix<2,2,f64>;
using dmat23    = Matrix<2,3,f64>;
using dmat24    = Matrix<2,4,f64>;
using dmat31    = Matrix<3,1,f64>;
using dmat32    = Matrix<3,2,f64>;
using dmat33    = Matrix<3,3,f64>;
using dmat34    = Matrix<3,4,f64>;
using dmat41    = Matrix<4,1,f64>;
using dmat42    = Matrix<4,2,f64>;
using dmat43    = Matrix<4,3,f64>;
using dmat44    = Matrix<4,4,f64>;

using imat2     = Matrix<2,2,i32>;
using imat3     = Matrix<3,3,i32>;
using imat4     = Matrix<4,4,i32>;
using imat12    = Matrix<1,2,i32>;
using imat13    = Matrix<1,3,i32>;
using imat14    = Matrix<1,4,i32>;
using imat21    = Matrix<2,1,i32>;
using imat22    = Matrix<2,2,i32>;
using imat23    = Matrix<2,3,i32>;
using imat24    = Matrix<2,4,i32>;
using imat31    = Matrix<3,1,i32>;
using imat32    = Matrix<3,2,i32>;
using imat33    = Matrix<3,3,i32>;
using imat34    = Matrix<3,4,i32>;
using imat41    = Matrix<4,1,i32>;
using imat42    = Matrix<4,2,i32>;
using imat43    = Matrix<4,3,i32>;
using imat44    = Matrix<4,4,i32>;

using umat2     = Matrix<2,2,u32>;
using umat3     = Matrix<3,3,u32>;
using umat4     = Matrix<4,4,u32>;
using umat12    = Matrix<1,2,u32>;
using umat13    = Matrix<1,3,u32>;
using umat14    = Matrix<1,4,u32>;
using umat21    = Matrix<2,1,u32>;
using umat22    = Matrix<2,2,u32>;
using umat23    = Matrix<2,3,u32>;
using umat24    = Matrix<2,4,u32>;
using umat31    = Matrix<3,1,u32>;
using umat32    = Matrix<3,2,u32>;
using umat33    = Matrix<3,3,u32>;
using umat34    = Matrix<3,4,u32>;
using umat41    = Matrix<4,1,u32>;
using umat42    = Matrix<4,2,u32>;
using umat43    = Matrix<4,3,u32>;
using umat44    = Matrix<4,4,u32>;

using mat2i8    = Matrix<2,2,i8>;
using mat3i8    = Matrix<3,3,i8>;
using mat4i8    = Matrix<4,4,i8>;
using mat12i8   = Matrix<1,2,i8>;
using mat13i8   = Matrix<1,3,i8>;
using mat14i8   = Matrix<1,4,i8>;
using mat21i8   = Matrix<2,1,i8>;
using mat22i8   = Matrix<2,2,i8>;
using mat23i8   = Matrix<2,3,i8>;
using mat24i8   = Matrix<2,4,i8>;
using mat31i8   = Matrix<3,1,i8>;
using mat32i8   = Matrix<3,2,i8>;
using mat33i8   = Matrix<3,3,i8>;
using mat34i8   = Matrix<3,4,i8>;
using mat41i8   = Matrix<4,1,i8>;
using mat42i8   = Matrix<4,2,i8>;
using mat43i8   = Matrix<4,3,i8>;
using mat44i8   = Matrix<4,4,i8>;

using mat2i16   = Matrix<2,2,i16>;
using mat3i16   = Matrix<3,3,i16>;
using mat4i16   = Matrix<4,4,i16>;
using mat12i16  = Matrix<1,2,i16>;
using mat13i16  = Matrix<1,3,i16>;
using mat14i16  = Matrix<1,4,i16>;
using mat21i16  = Matrix<2,1,i16>;
using mat22i16  = Matrix<2,2,i16>;
using mat23i16  = Matrix<2,3,i16>;
using mat24i16  = Matrix<2,4,i16>;
using mat31i16  = Matrix<3,1,i16>;
using mat32i16  = Matrix<3,2,i16>;
using mat33i16  = Matrix<3,3,i16>;
using mat34i16  = Matrix<3,4,i16>;
using mat41i16  = Matrix<4,1,i16>;
using mat42i16  = Matrix<4,2,i16>;
using mat43i16  = Matrix<4,3,i16>;
using mat44i16  = Matrix<4,4,i16>;

using mat2i32   = Matrix<2,2,i32>;
using mat3i32   = Matrix<3,3,i32>;
using mat4i32   = Matrix<4,4,i32>;
using mat12i32  = Matrix<1,2,i32>;
using mat13i32  = Matrix<1,3,i32>;
using mat14i32  = Matrix<1,4,i32>;
using mat21i32  = Matrix<2,1,i32>;
using mat22i32  = Matrix<2,2,i32>;
using mat23i32  = Matrix<2,3,i32>;
using mat24i32  = Matrix<2,4,i32>;
using mat31i32  = Matrix<3,1,i32>;
using mat32i32  = Matrix<3,2,i32>;
using mat33i32  = Matrix<3,3,i32>;
using mat34i32  = Matrix<3,4,i32>;
using mat41i32  = Matrix<4,1,i32>;
using mat42i32  = Matrix<4,2,i32>;
using mat43i32  = Matrix<4,3,i32>;
using mat44i32  = Matrix<4,4,i32>;

using mat2i64   = Matrix<2,2,i64>;
using mat3i64   = Matrix<3,3,i64>;
using mat4i64   = Matrix<4,4,i64>;
using mat12i64  = Matrix<1,2,i64>;
using mat13i64  = Matrix<1,3,i64>;
using mat14i64  = Matrix<1,4,i64>;
using mat21i64  = Matrix<2,1,i64>;
using mat22i64  = Matrix<2,2,i64>;
using mat23i64  = Matrix<2,3,i64>;
using mat24i64  = Matrix<2,4,i64>;
using mat31i64  = Matrix<3,1,i64>;
using mat32i64  = Matrix<3,2,i64>;
using mat33i64  = Matrix<3,3,i64>;
using mat34i64  = Matrix<3,4,i64>;
using mat41i64  = Matrix<4,1,i64>;
using mat42i64  = Matrix<4,2,i64>;
using mat43i64  = Matrix<4,3,i64>;
using mat44i64  = Matrix<4,4,i64>;

using mat2u8    = Matrix<2,2,u8>;
using mat3u8    = Matrix<3,3,u8>;
using mat4u8    = Matrix<4,4,u8>;
using mat12u8   = Matrix<1,2,u8>;
using mat13u8   = Matrix<1,3,u8>;
using mat14u8   = Matrix<1,4,u8>;
using mat21u8   = Matrix<2,1,u8>;
using mat22u8   = Matrix<2,2,u8>;
using mat23u8   = Matrix<2,3,u8>;
using mat24u8   = Matrix<2,4,u8>;
using mat31u8   = Matrix<3,1,u8>;
using mat32u8   = Matrix<3,2,u8>;
using mat33u8   = Matrix<3,3,u8>;
using mat34u8   = Matrix<3,4,u8>;
using mat41u8   = Matrix<4,1,u8>;
using mat42u8   = Matrix<4,2,u8>;
using mat43u8   = Matrix<4,3,u8>;
using mat44u8   = Matrix<4,4,u8>;

using mat2u16   = Matrix<2,2,u16>;
using mat3u16   = Matrix<3,3,u16>;
using mat4u16   = Matrix<4,4,u16>;
using mat12u16  = Matrix<1,2,u16>;
using mat13u16  = Matrix<1,3,u16>;
using mat14u16  = Matrix<1,4,u16>;
using mat21u16  = Matrix<2,1,u16>;
using mat22u16  = Matrix<2,2,u16>;
using mat23u16  = Matrix<2,3,u16>;
using mat24u16  = Matrix<2,4,u16>;
using mat31u16  = Matrix<3,1,u16>;
using mat32u16  = Matrix<3,2,u16>;
using mat33u16  = Matrix<3,3,u16>;
using mat34u16  = Matrix<3,4,u16>;
using mat41u16  = Matrix<4,1,u16>;
using mat42u16  = Matrix<4,2,u16>;
using mat43u16  = Matrix<4,3,u16>;
using mat44u16  = Matrix<4,4,u16>;

using mat2u32   = Matrix<2,2,u32>;
using mat3u32   = Matrix<3,3,u32>;
using mat4u32   = Matrix<4,4,u32>;
using mat12u32  = Matrix<1,2,u32>;
using mat13u32  = Matrix<1,3,u32>;
using mat14u32  = Matrix<1,4,u32>;
using mat21u32  = Matrix<2,1,u32>;
using mat22u32  = Matrix<2,2,u32>;
using mat23u32  = Matrix<2,3,u32>;
using mat24u32  = Matrix<2,4,u32>;
using mat31u32  = Matrix<3,1,u32>;
using mat32u32  = Matrix<3,2,u32>;
using mat33u32  = Matrix<3,3,u32>;
using mat34u32  = Matrix<3,4,u32>;
using mat41u32  = Matrix<4,1,u32>;
using mat42u32  = Matrix<4,2,u32>;
using mat43u32  = Matrix<4,3,u32>;
using mat44u32  = Matrix<4,4,u32>;

using mat2u64   = Matrix<2,2,u64>;
using mat3u64   = Matrix<3,3,u64>;
using mat4u64   = Matrix<4,4,u64>;
using mat12u64  = Matrix<1,2,u64>;
using mat13u64  = Matrix<1,3,u64>;
using mat14u64  = Matrix<1,4,u64>;
using mat21u64  = Matrix<2,1,u64>;
using mat22u64  = Matrix<2,2,u64>;
using mat23u64  = Matrix<2,3,u64>;
using mat24u64  = Matrix<2,4,u64>;
using mat31u64  = Matrix<3,1,u64>;
using mat32u64  = Matrix<3,2,u64>;
using mat33u64  = Matrix<3,3,u64>;
using mat34u64  = Matrix<3,4,u64>;
using mat41u64  = Matrix<4,1,u64>;
using mat42u64  = Matrix<4,2,u64>;
using mat43u64  = Matrix<4,3,u64>;
using mat44u64  = Matrix<4,4,u64>;

using mat2f32   = Matrix<2,2,f32>;
using mat3f32   = Matrix<3,3,f32>;
using mat4f32   = Matrix<4,4,f32>;
using mat12f32  = Matrix<1,2,f32>;
using mat13f32  = Matrix<1,3,f32>;
using mat14f32  = Matrix<1,4,f32>;
using mat21f32  = Matrix<2,1,f32>;
using mat22f32  = Matrix<2,2,f32>;
using mat23f32  = Matrix<2,3,f32>;
using mat24f32  = Matrix<2,4,f32>;
using mat31f32  = Matrix<3,1,f32>;
using mat32f32  = Matrix<3,2,f32>;
using mat33f32  = Matrix<3,3,f32>;
using mat34f32  = Matrix<3,4,f32>;
using mat41f32  = Matrix<4,1,f32>;
using mat42f32  = Matrix<4,2,f32>;
using mat43f32  = Matrix<4,3,f32>;
using mat44f32  = Matrix<4,4,f32>;

using mat2f64   = Matrix<2,2,f64>;
using mat3f64   = Matrix<3,3,f64>;
using mat4f64   = Matrix<4,4,f64>;
using mat12f64  = Matrix<1,2,f64>;
using mat13f64  = Matrix<1,3,f64>;
using mat14f64  = Matrix<1,4,f64>;
using mat21f64  = Matrix<2,1,f64>;
using mat22f64  = Matrix<2,2,f64>;
using mat23f64  = Matrix<2,3,f64>;
using mat24f64  = Matrix<2,4,f64>;
using mat31f64  = Matrix<3,1,f64>;
using mat32f64  = Matrix<3,2,f64>;
using mat33f64  = Matrix<3,3,f64>;
using mat34f64  = Matrix<3,4,f64>;
using mat41f64  = Matrix<4,1,f64>;
using mat42f64  = Matrix<4,2,f64>;
using mat43f64  = Matrix<4,3,f64>;
using mat44f64  = Matrix<4,4,f64>;

/* ####################################################################################### */
/* Size */
/* ####################################################################################### */

using size2     = Size<2,FLOAT>;
using size3     = Size<3,FLOAT>;

using fsize2    = Size<2,f32>;
using fsize3    = Size<3,f32>;

using dsize2    = Size<2,f64>;
using dsize3    = Size<3,f64>;

using usize2    = Size<2,u32>;
using usize3    = Size<3,u32>;

using size2u8   = Size<2,u8>;
using size3u8   = Size<3,u8>;

using size2u16  = Size<2,u16>;
using size3u16  = Size<3,u16>;

using size2u32  = Size<2,u32>;
using size3u32  = Size<3,u32>;

using size2u64  = Size<2,u64>;
using size3u64  = Size<3,u64>;

using size2f32  = Size<2,f32>;
using size3f32  = Size<3,f32>;

using size2f64  = Size<2,f64>;
using size3f64  = Size<3,f64>;

CGM_NAMESPACE_END
