#pragma once


#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/detail/Modules/Cartesian/2D/Types/Enums.hpp>
#include <CGM/detail/Modules/Cartesian/Common.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN
namespace detail {

template <EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply_matrix3x3_on_vector2(const Matrix<3,3,T>& mat, const Vector<2,T>& vec)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            mat(0,0) * vec.x + mat(0,1) * vec.y + mat(0,2),
            mat(1,0) * vec.x + mat(1,1) * vec.y + mat(1,2)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            mat(0,0) * vec.x + mat(0,1) * vec.y,
            mat(1,0) * vec.x + mat(1,1) * vec.y
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template <EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
multiply_vector2_on_matrix3x3(const Vector<2,T>& vec, const Matrix<3,3,T>& mat)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            mat(0,0) * vec.x + mat(1,0) * vec.y + mat(2,0),
            mat(0,1) * vec.x + mat(1,1) * vec.y + mat(2,1)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            mat(0,0) * vec.x + mat(1,0) * vec.y,
            mat(0,1) * vec.x + mat(1,1) * vec.y
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
multiply_matrix2x2_on_matrix3x3_res2x2(const Matrix<2,2,T>& A, const Matrix<3,3,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1),
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
multiply_matrix2x2_on_matrix3x3_res3x3(const Matrix<2,2,T>& A, const Matrix<3,3,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1),
        A(0,0)*B(0,2) + A(0,1)*B(1,2),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1),
        A(1,0)*B(0,2) + A(1,1)*B(1,2),

        // row 2
        B(2,0),
        B(2,1),
        B(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
multiply_matrix3x3_on_matrix2x2_res2x2(const Matrix<3,3,T>& A, const Matrix<2,2,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1),
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
multiply_matrix3x3_on_matrix2x2_res3x3(const Matrix<3,3,T>& A, const Matrix<2,2,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1),
        A(0,2),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1),
        A(1,2),

        // row 2
        A(2,0)*B(0,0) + A(2,1)*B(1,0),
        A(2,0)*B(0,1) + A(2,1)*B(1,1),
        A(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr void
fast_invert_matrix3x3(Matrix<3,3,T>& mat)
{
    std::swap(mat(0,1), mat(1,0));

    // position = -(position * orientation)
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    T px = -(mat(0,0) * mat(0,2) + mat(0,1) * mat(1,2));
    T py = -(mat(1,0) * mat(0,2) + mat(1,1) * mat(1,2));

    mat(0,2) = px;
    mat(1,2) = py;
#else
    T px = -(mat(0,0) * mat(2,0) + mat(1,0) * mat(2,1));
    T py = -(mat(0,1) * mat(2,0) + mat(1,1) * mat(2,1));

    mat(2,0) = px;
    mat(2,1) = py;
#endif
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr Matrix<3,3,T>
fast_inverse_matrix3x3(const Matrix<3,3,T>& mat)
{
    Matrix<3,3,T> inv {mat};
    detail::fast_invert_matrix3x3(inv);
    return inv;
}

}
CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
