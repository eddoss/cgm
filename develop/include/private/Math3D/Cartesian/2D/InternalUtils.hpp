#pragma once


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Cartesian/2D/Types/Enums.hpp>
#include <Math3D/Cartesian/Common.hpp>

MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template <EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
_internal_multiply_matrix3x3_on_vector2(const Matrix<3,3,T>& mat, const Vector<2,T>& vec)
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
constexpr FORCEINLINE Vector<2,T>
_internal_multiply_vector2_on_matrix3x3(const Vector<2,T>& vec, const Matrix<3,3,T>& mat)
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

template <typename T>
constexpr void
_internal_fast_invert_matrix3x3(Matrix<3,3,T>& mat)
{
    std::swap(mat(0,1), mat(1,0));

    // position = -(position * orientation)
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
_internal_fast_inverse_matrix3x3(const Matrix<3,3,T>& mat)
{
    Matrix<3,3,T> inv {mat};
    _internal_fast_invert_matrix3x3(inv);
    return inv;
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END
