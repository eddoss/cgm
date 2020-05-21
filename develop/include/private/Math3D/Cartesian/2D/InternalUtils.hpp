#ifndef MATH3D_XY_INTERNAL_UTILS_HPP
#define MATH3D_XY_INTERNAL_UTILS_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
_internal_get_basis_x(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(1,0)
    };
#else
    {
        basis(0,0),
        basis(0,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
_internal_get_basis_y(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,1),
        basis(1,1)
    };
#else
    {
        basis(1,0),
        basis(1,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
_internal_set_basis_x(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(1,0) = value.y;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
_internal_set_basis_y(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,1) = value.x;
    basis(1,1) = value.y;
#else
    basis(1,0) = value.x;
    basis(1,1) = value.y;
#endif
}

/* ####################################################################################### */
/* Up, Right axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
_internal_get_basis_up(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return _internal_get_basis_x(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return _internal_get_basis_y(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return _internal_get_2d_basis_z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
_internal_get_basis_right(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return _internal_get_basis_x(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return _internal_get_basis_y(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return _internal_get_2d_basis_z(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
_internal_get_basis_down(const Matrix<S,S,T>& basis)
{
    return -_internal_get_basis_up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
_internal_get_basis_left(const Matrix<S,S,T>& basis)
{
    return -_internal_get_basis_right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE void
_internal_set_basis_up(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return _internal_set_basis_x(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return _internal_set_basis_y(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return _internal_set_2d_basis_z(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
_internal_set_2d_basis_right(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return _internal_set_basis_x(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return _internal_set_basis_y(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return _internal_set_2d_basis_z(basis, value);
#endif
}

/* ####################################################################################### */
/* Basis components */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
_internal_get_basis_position(const Matrix<3,3,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(2,0),
        basis(2,1)
    };
#else
    {
        basis(0,2),
        basis(1,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
_internal_set_basis_position(Matrix<3,3,T>& basis, const Vector<2,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(2,0) = position.x;
    basis(2,1) = position.y;
#else
    basis(0,2) = position.x;
    basis(1,2) = position.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
_internal_get_orientation_matrix2x2_from_matrix3x3(const Matrix<3,3,T>& basis)
{
    return 
    {
        basis(0,0), basis(0,1),
        basis(1,0), basis(1,1)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
_internal_set_orientation_matrix2x2_to_matrix3x3(Matrix<3,3,T>& basis, const Matrix<2,2,T>& orientation)
{
    basis(0,0) = orientation(0,0);
    basis(0,1) = orientation(0,1);
    basis(1,0) = orientation(1,0);
    basis(1,1) = orientation(1,1);
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END

#endif // MATH3D_XY_INTERNAL_UTILS_HPP
