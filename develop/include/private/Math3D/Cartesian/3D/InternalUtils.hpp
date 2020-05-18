#ifndef MATH3D_XYZ_INTERNAL_UTILS_HPP
#define MATH3D_XYZ_INTERNAL_UTILS_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_x(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(1,0),
        basis(2,0),
    };
#else
    {
        basis(0,0),
        basis(0,1),
        basis(0,2),
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_get_3d_basis_x(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,T(1),0,0) * conjugated(orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_y(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,1),
        basis(1,1),
        basis(2,1)
    };
#else
    {
        basis(1,0),
        basis(1,1),
        basis(1,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_get_3d_basis_y(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,0,T(1),0) * conjugated(orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_z(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,2),
        basis(1,2),
        basis(2,2)
    };
#else
    {
        basis(2,0),
        basis(2,1),
        basis(2,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_get_3d_basis_z(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,0,0,T(1)) * conjugated(orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
_internal_set_3d_basis_x(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(1,0) = value.y;
    basis(2,0) = value.z;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
    basis(0,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
_internal_set_3d_basis_y(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,1) = value.x;
    basis(1,1) = value.y;
    basis(2,1) = value.z;
#else
    basis(1,0) = value.x;
    basis(1,1) = value.y;
    basis(1,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
_internal_set_3d_basis_z(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,2) = value.x;
    basis(1,2) = value.y;
    basis(2,2) = value.z;
#else
    basis(2,0) = value.x;
    basis(2,1) = value.y;
    basis(2,2) = value.z;
#endif
}

/* ####################################################################################### */
/* Uo, Right, Forward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_up(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return _internal_get_3d_basis_x(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return _internal_get_3d_basis_y(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return _internal_get_3d_basis_z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_up(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return _internal_get_3d_basis_x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return _internal_get_3d_basis_y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return _internal_get_3d_basis_z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_right(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return _internal_get_3d_basis_x(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return _internal_get_3d_basis_y(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return _internal_get_3d_basis_z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_right(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return _internal_get_3d_basis_x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return _internal_get_3d_basis_y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return _internal_get_3d_basis_z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_forward(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return _internal_get_3d_basis_x(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return _internal_get_3d_basis_y(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return _internal_get_3d_basis_z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_forward(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return _internal_get_3d_basis_x(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return _internal_get_3d_basis_y(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return _internal_get_3d_basis_z(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_down(const Matrix<S,S,T>& basis)
{
    return -_internal_get_3d_basis_up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_down(const Quaternion<T>& orientation)
{
    return -_internal_get_3d_basis_up(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_left(const Matrix<S,S,T>& basis)
{
    return -_internal_get_3d_basis_right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_left(const Quaternion<T>& orientation)
{
    return -_internal_get_3d_basis_right(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_backward(const Matrix<S,S,T>& basis)
{
    return -_internal_get_3d_basis_forward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
_internal_get_3d_basis_backward(const Quaternion<T>& orientation)
{
    return -_internal_get_3d_basis_forward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE void
_internal_set_3d_basis_up(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return _internal_set_3d_basis_x(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return _internal_set_3d_basis_y(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return _internal_set_3d_basis_z(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
_internal_set_3d_basis_right(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return _internal_set_3d_basis_x(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return _internal_set_3d_basis_y(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return _internal_set_3d_basis_z(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
_internal_set_3d_basis_forward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return _internal_set_3d_basis_x(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return _internal_set_3d_basis_y(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return _internal_set_3d_basis_z(basis, value);
#endif
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
_internal_get_3d_basis_position(const Matrix<4,4,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,3),
        basis(1,3),
        basis(2,3)
    };
#else
    {
        basis(3,0),
        basis(3,1),
        basis(3,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
_internal_set_3d_basis_position(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,3) = position.x;
    basis(1,3) = position.y;
    basis(2,3) = position.z;
#else
    basis(3,0) = position.x;
    basis(3,1) = position.y;
    basis(3,2) = position.z;
#endif
}

/* ####################################################################################### */
/* Other */
/* ####################################################################################### */

template <typename T>
constexpr FORCEINLINE Quaternion<T>
_internal_xyz_to_quaternion(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
{
    T s, x, y, z, w;

    T trace {mat(0,0) + mat(1,1) + mat(2,2)};

    if (trace > 0)
    {
        s = 2 * std::sqrt(trace + 1);
        x = (Z.y - Y.z) / s;
        y = (X.z - Z.x) / s;
        z = (Y.x - X.y) / s;
        w = s / 4;
    }
    else if (X.x > Y.y && X.x > Z.z)
    {
        s = std::sqrt(X.x - Y.y - Z.z + 1) * 2;
        x = s / 4;
        y = (Y.x + X.y) / s;
        z = (X.z + Z.x) / s;
        w = (Z.y - Y.z) / s;
    }
    else if (Y.y > Z.z)
    {
        s = std::sqrt(Y.y - X.x - Z.z + 1) * 2;
        x = (Y.x + X.y) / s;
        y = s / 4;
        z = (Z.y + Y.z) / s;
        w = (X.z - Z.x) / s;
    }
    else
    {
        s  = std::sqrt(Z.z - X.x - Y.y + 1) * 2;
        x = (X.z + Z.x) / s;
        y = (Z.y + Y.z) / s;
        z = s / 4;
        w = (Y.x - X.y) / s;
    }

    return {w,x,y,z};
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Quaternion<T>
_internal_matrix3x3_to_quaternion(const Matrix<3,3,T>& mat)
{
    auto X {_internal_get_3d_basis_x(mat)};
    auto Y {_internal_get_3d_basis_y(mat)};
    auto Z {_internal_get_3d_basis_z(mat)};

    T s, x, y, z, w;

    T trace {mat(0,0) + mat(1,1) + mat(2,2)};

    if (trace > 0)
    {
        s = 2 * std::sqrt(trace + 1);
        x = (Z.y - Y.z) / s;
        y = (X.z - Z.x) / s;
        z = (Y.x - X.y) / s;
        w = s / 4;
    }
    else if (X.x > Y.y && X.x > Z.z)
    {
        s = std::sqrt(X.x - Y.y - Z.z + 1) * 2;
        x = s / 4;
        y = (Y.x + X.y) / s;
        z = (X.z + Z.x) / s;
        w = (Z.y - Y.z) / s;
    }
    else if (Y.y > Z.z)
    {
        s = std::sqrt(Y.y - X.x - Z.z + 1) * 2;
        x = (Y.x + X.y) / s;
        y = s / 4;
        z = (Z.y + Y.z) / s;
        w = (X.z - Z.x) / s;
    }
    else
    {
        s  = std::sqrt(Z.z - X.x - Y.y + 1) * 2;
        x = (X.z + Z.x) / s;
        y = (Z.y + Y.z) / s;
        z = s / 4;
        w = (Y.x - X.y) / s;
    }

    return {w,x,y,z};
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Quaternion<T>
_internal_matrix4x4_to_quaternion(const Matrix<4,4,T>& mat)
{
    auto X {_internal_get_3d_basis_x(mat)};
    auto Y {_internal_get_3d_basis_y(mat)};
    auto Z {_internal_get_3d_basis_z(mat)};

    T s, x, y, z, w;

    T trace {mat(0,0) + mat(1,1) + mat(2,2)};

    if (trace > 0)
    {
        s = 2 * std::sqrt(trace + 1);
        x = (Z.y - Y.z) / s;
        y = (X.z - Z.x) / s;
        z = (Y.x - X.y) / s;
        w = s / 4;
    }
    else if (X.x > Y.y && X.x > Z.z)
    {
        s = std::sqrt(X.x - Y.y - Z.z + 1) * 2;
        x = s / 4;
        y = (Y.x + X.y) / s;
        z = (X.z + Z.x) / s;
        w = (Z.y - Y.z) / s;
    }
    else if (Y.y > Z.z)
    {
        s = std::sqrt(Y.y - X.x - Z.z + 1) * 2;
        x = (Y.x + X.y) / s;
        y = s / 4;
        z = (Z.y + Y.z) / s;
        w = (X.z - Z.x) / s;
    }
    else
    {
        s  = std::sqrt(Z.z - X.x - Y.y + 1) * 2;
        x = (X.z + Z.x) / s;
        y = (Z.y + Y.z) / s;
        z = s / 4;
        w = (Y.x - X.y) / s;
    }

    return {w,x,y,z};
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Matrix<3,3,T>
_internal_quaternion_to_matrix3x3(const Quaternion<T>& quat)
{
    auto conj = conjugated(quat);

    Matrix<3,3,T> mat;

    _internal_set_3d_basis_x(mat, (quat * Quaternion<T>{0,T(1),0,0} * conj).imaginary());
    _internal_set_3d_basis_y(mat, (quat * Quaternion<T>{0,0,T(1),0} * conj).imaginary());
    _internal_set_3d_basis_z(mat, (quat * Quaternion<T>{0,0,0,T(1)} * conj).imaginary());

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Quaternion<T>
_internal_quaternion_to_matrix4x4(const Quaternion<T>& quat)
{
    auto conj = conjugated(quat);

    Matrix<4,4,T> mat;

    _internal_set_3d_basis_x(mat, (quat * Quaternion<T>{0,T(1),0,0} * conj).imaginary());
    _internal_set_3d_basis_y(mat, (quat * Quaternion<T>{0,0,T(1),0} * conj).imaginary());
    _internal_set_3d_basis_z(mat, (quat * Quaternion<T>{0,0,0,T(1)} * conj).imaginary());

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE Matrix<3,3,T>
_internal_extract_orientation_from_4x4_matrix(const Matrix<4,4,T>& mat)
{
    return
    {
        mat(0,0), mat(0,1), mat(0,2),
        mat(1,0), mat(1,1), mat(1,2),
        mat(2,0), mat(2,1), mat(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE void
_internal_set_4x4_matrix_orientation(Matrix<4,4,T>& mat, const Matrix<3,3,T>& orient)
{
    mat(0,0) = orient(0,0);
    mat(0,1) = orient(0,1);
    mat(0,2) = orient(0,2);
    mat(1,0) = orient(1,0);
    mat(1,1) = orient(1,1);
    mat(1,2) = orient(1,2);
    mat(2,0) = orient(2,0);
    mat(2,1) = orient(2,1);
    mat(2,2) = orient(2,2);
}

/* --------------------------------------------------------------------------------------- */

template <typename T>
constexpr FORCEINLINE void
_internal_set_4x4_matrix_orientation(Matrix<4,4,T>& mat, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_3d_basis_x(mat, x);
    _internal_set_3d_basis_y(mat, y);
    _internal_set_3d_basis_z(mat, z);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XYZ_INTERNAL_UTILS_HPP
