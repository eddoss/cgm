#ifndef MATH3D_XYZ_INTERNAL_UTILS_HPP
#define MATH3D_XYZ_INTERNAL_UTILS_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Cartesian/3D/Types/Enums.hpp>
#include <Math3D/Cartesian/Common.hpp>

MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template <EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_multiply_matrix4x4_on_vector3(const Matrix<4,4,T>& mat, const Vector<3,T>& vec)
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
constexpr FORCEINLINE Vector<3,T>
_internal_multiply_vector3_on_matrix4x4(const Vector<3,T>& vec, const Matrix<4,4,T>& mat)
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

template <typename T>
constexpr void
_internal_fast_invert_matrix4x4(Matrix<4,4,T>& mat)
{
    std::swap(mat(0,1), mat(1,0));
    std::swap(mat(0,2), mat(2,0));
    std::swap(mat(1,2), mat(2,1));

    // position = -(position * orientation)
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
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
_internal_fast_inverse_matrix4x4(const Matrix<4,4,T>& mat)
{
    Matrix<4,4,T> inv {mat};
    _internal_fast_invert_matrix4x4(inv);
    return inv;
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XYZ_INTERNAL_UTILS_HPP
