#ifndef MATH3D_XYZ_INTERNAL_UTILS_HPP
#define MATH3D_XYZ_INTERNAL_UTILS_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Core/Functions/Vector.hpp>
#include <Math3D/Core/Functions/Quaternion.hpp>
#include <Math3D/Core/Operators/Vector.hpp>
#include <Math3D/Core/Operators/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

template <typename T>
constexpr FORCEINLINE void
_internal_rotate_vector3_by_quaternion(Vector<3,T>& vec, const Quaternion<T>& quat)
{
#ifdef MATH3D_USE_LEFT_HANDED_CARTESIAN_SYSTEM
    auto t = MATH3D_NAMESPACE::cross(vec, quat.imaginary());
    t *= static_cast<T>(2);
    vec += MATH3D_NAMESPACE::cross(t, quat.imaginary());
#else
    auto t = MATH3D_NAMESPACE::cross(quat.imaginary(), vec);
    t *= static_cast<T>(2);
    vec += MATH3D_NAMESPACE::cross(quat.imaginary(), t);
#endif

    vec += quat.s * t;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr Vector<3,T>
_internal_rotated_vector3_by_quaternion(const Vector<3,T>& vec, const Quaternion<T>& quat)
{
    Vector<3,T> res {vec};
    _internal_rotate_vector3_by_quaternion(res, quat);
    return res;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_multiply_matrix4x4_on_vector3(const Matrix<4,4,T>& mat, const Vector<3,T>& vec)
{
    return
    {
        mat(0,0) * vec.x + mat(0,1) * vec.y + mat(0,2) * vec.z + mat(0,3),
        mat(1,0) * vec.x + mat(1,1) * vec.y + mat(1,2) * vec.z + mat(1,3),
        mat(2,0) * vec.x + mat(2,1) * vec.y + mat(2,2) * vec.z + mat(2,3)
    };
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_multiply_vector3_on_matrix4x4(const Vector<3,T>& vec, const Matrix<4,4,T>& mat)
{
    return
    {
        mat(0,0) * vec.x + mat(1,0) * vec.y + mat(2,0) * vec.z + mat(3,0),
        mat(0,1) * vec.x + mat(1,1) * vec.y + mat(2,1) * vec.z + mat(3,1),
        mat(0,2) * vec.x + mat(1,2) * vec.y + mat(2,2) * vec.z + mat(3,2)
    };
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XYZ_INTERNAL_UTILS_HPP
