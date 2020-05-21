

#include <Math3D/Cartesian/2D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
getX(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_x(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
getY(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_y(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setX(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
    _internal_set_basis_x(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setY(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
    _internal_set_basis_y(basis, value);
}

/* ####################################################################################### */
/* Up, Right axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
getUp(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
getRight(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
getDown(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_down(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<3,T>>
getLeft(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_left(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_up(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_2d_basis_right(basis, value);
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
getPosition(const Matrix<3,3,T>& basis)
{
    return _internal_get_basis_position(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position)
{
    _internal_set_2d_basis_(basis, position);
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<2,2,T>
extractOrientation(const Matrix<3,3,T>& basis)
{
    return _internal_get_orientation_matrix2x2_from_matrix3x3(basis);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END