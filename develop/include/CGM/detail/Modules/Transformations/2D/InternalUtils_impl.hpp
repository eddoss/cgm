#pragma once


#include <CGM/detail/Modules/Transformations/2D/ModuleGlobals.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Operators/Matrix.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN namespace detail {

template<typename T>
constexpr CGM_FORCEINLINE void
multiply_matrix2x2_on_matrix3x3(Matrix<2,2,T>& mat2, const Matrix<3,3,T>& mat3)
{
    mat2 *= Matrix<2,2,T>
    {
        mat3(0,0), mat3(0,1),
        mat3(1,0), mat3(1,1)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
multiply_matrix3x3_on_matrix2x2(Matrix<3,3,T>& mat3, const Matrix<2,2,T>& mat2)
{
    mat3 *= Matrix<3,3,T>
    {
        mat2(0,0), mat2(0,1), zero<T>,
        mat2(1,0), mat2(1,1), zero<T>,
        zero<T>, zero<T>, number<T>(1)
    };
}

}CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END