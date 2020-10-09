#pragma once


#include <CGM/Transformations/3D/ModuleGlobals.hpp>
#include <CGM/Core/Types/Matrix.hpp>
#include <CGM/Core/Operators/Matrix.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN namespace detail {

template<typename T>
constexpr CGM_FORCEINLINE void
multiply_matrix3x3_on_matrix4x4(Matrix<3,3,T>& mat3, const Matrix<4,4,T>& mat4)
{
    mat3 *= Matrix<3,3,T>
    {
        mat4(0,0), mat4(0,1), mat4(0,2),
        mat4(1,0), mat4(1,1), mat4(1,2),
        mat4(2,0), mat4(2,1), mat4(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
multiply_matrix4x4_on_matrix3x3(Matrix<4,4,T>& mat4, const Matrix<3,3,T>& mat3)
{
    mat4 *= Matrix<4,4,T>
    {
        mat3(0,0), mat3(0,1), mat3(0,2), zero<T>,
        mat3(1,0), mat3(1,1), mat3(1,2), zero<T>,
        mat3(2,0), mat3(2,1), mat3(2,2), zero<T>,
        zero<T>, zero<T>, zero<T>, number<T>(1)
    };
}

}CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END