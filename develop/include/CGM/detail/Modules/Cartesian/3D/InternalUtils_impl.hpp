#pragma once


#include <CGM/detail/Modules/Core/Types/Vector.hpp>
#include <CGM/detail/Modules/Core/Types/Matrix.hpp>
#include <CGM/detail/Modules/Core/Functions/Vector.hpp>
#include <CGM/detail/Modules/Core/Operators/Vector.hpp>
#include <CGM/detail/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/detail/Modules/Cartesian/Common.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

namespace detail
{

template <EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
multiply_matrix4x4_on_vector3(const Matrix<4,4,T>& mat, const Vector<3,T>& vec)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            mat(0,0) * vec.x + mat(0,1) * vec.y + mat(0,2) * vec.z + mat(0,3),
            mat(1,0) * vec.x + mat(1,1) * vec.y + mat(1,2) * vec.z + mat(1,3),
            mat(2,0) * vec.x + mat(2,1) * vec.y + mat(2,2) * vec.z + mat(2,3)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            mat(0,0) * vec.x + mat(0,1) * vec.y + mat(0,2) * vec.z,
            mat(1,0) * vec.x + mat(1,1) * vec.y + mat(1,2) * vec.z,
            mat(2,0) * vec.x + mat(2,1) * vec.y + mat(2,2) * vec.z
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template <EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
multiply_vector3_on_matrix4x4(const Vector<3,T>& vec, const Matrix<4,4,T>& mat)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return
        {
            mat(0,0) * vec.x + mat(1,0) * vec.y + mat(2,0) * vec.z + mat(3,0),
            mat(0,1) * vec.x + mat(1,1) * vec.y + mat(2,1) * vec.z + mat(3,1),
            mat(0,2) * vec.x + mat(1,2) * vec.y + mat(2,2) * vec.z + mat(3,2)
        };
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return
        {
            mat(0,0) * vec.x + mat(1,0) * vec.y + mat(2,0) * vec.z,
            mat(0,1) * vec.x + mat(1,1) * vec.y + mat(2,1) * vec.z,
            mat(0,2) * vec.x + mat(1,2) * vec.y + mat(2,2) * vec.z
        };
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
multiply_matrix3x3_on_matrix4x4_res3x3(const Matrix<3,3,T>& A, const Matrix<4,4,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
        A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
        A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

        // row 2
        A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
        A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
        A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
multiply_matrix3x3_on_matrix4x4_res4x4(const Matrix<3,3,T>& A, const Matrix<4,4,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
        A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
        A(0,0)*B(0,3) + A(0,1)*B(1,3) + A(0,2)*B(2,3),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
        A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
        A(1,0)*B(0,3) + A(1,1)*B(1,3) + A(1,2)*B(2,3),

        // row 2
        A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
        A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
        A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
        A(2,0)*B(0,3) + A(2,1)*B(1,3) + A(2,2)*B(2,3),

        // row 3
        B(3,0),
        B(3,1),
        B(3,2),
        B(3,3)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
multiply_matrix4x4_on_matrix3x3_res3x3(const Matrix<4,4,T>& A, const Matrix<3,3,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
        A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
        A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),

        // row 2
        A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
        A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
        A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
multiply_matrix4x4_on_matrix3x3_res4x4(const Matrix<4,4,T>& A, const Matrix<3,3,T>& B)
{
    return
    {
        // row 0
        A(0,0)*B(0,0) + A(0,1)*B(1,0) + A(0,2)*B(2,0),
        A(0,0)*B(0,1) + A(0,1)*B(1,1) + A(0,2)*B(2,1),
        A(0,0)*B(0,2) + A(0,1)*B(1,2) + A(0,2)*B(2,2),
        A(0,3),

        // row 1
        A(1,0)*B(0,0) + A(1,1)*B(1,0) + A(1,2)*B(2,0),
        A(1,0)*B(0,1) + A(1,1)*B(1,1) + A(1,2)*B(2,1),
        A(1,0)*B(0,2) + A(1,1)*B(1,2) + A(1,2)*B(2,2),
        A(1,3),

        // row 2
        A(2,0)*B(0,0) + A(2,1)*B(1,0) + A(2,2)*B(2,0),
        A(2,0)*B(0,1) + A(2,1)*B(1,1) + A(2,2)*B(2,1),
        A(2,0)*B(0,2) + A(2,1)*B(1,2) + A(2,2)*B(2,2),
        A(2,3),

        // row 3
        A(3,0)*B(0,0) + A(3,1)*B(1,0) + A(3,2)*B(2,0),
        A(3,0)*B(0,1) + A(3,1)*B(1,1) + A(3,2)*B(2,1),
        A(3,0)*B(0,2) + A(3,1)*B(1,2) + A(3,2)*B(2,2),
        A(3,3)
    };
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr void
fast_invert_matrix4x4(Matrix<4,4,T>& mat)
{
    std::swap(mat(0,1), mat(1,0));
    std::swap(mat(0,2), mat(2,0));
    std::swap(mat(1,2), mat(2,1));

    // position = -(position * orientation)
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    T px = -(mat(0,0) * mat(0,3) + mat(0,1) * mat(1,3) + mat(0,2) * mat(2,3));
    T py = -(mat(1,0) * mat(0,3) + mat(1,1) * mat(1,3) + mat(1,2) * mat(2,3));
    T pz = -(mat(2,0) * mat(0,3) + mat(2,1) * mat(1,3) + mat(2,2) * mat(2,3));

    mat(0,3) = px;
    mat(1,3) = py;
    mat(2,3) = pz;
#else
    T px = -(mat(0,0) * mat(3,0) + mat(1,0) * mat(3,1) + mat(2,0) * mat(3,2));
    T py = -(mat(0,1) * mat(3,0) + mat(1,1) * mat(3,1) + mat(2,1) * mat(3,2));
    T pz = -(mat(0,2) * mat(3,0) + mat(1,2) * mat(3,1) + mat(2,2) * mat(3,2));

    mat(3,0) = px;
    mat(3,1) = py;
    mat(3,2) = pz;
#endif
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr Matrix<4,4,T>
fast_inverse_matrix4x4(const Matrix<4,4,T>& mat)
{
    Matrix<4,4,T> inv {mat};
    detail::fast_invert_matrix4x4(inv);
    return inv;
}

}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END