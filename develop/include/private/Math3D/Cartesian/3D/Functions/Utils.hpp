

#include <Math3D/Cartesian/3D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getX(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_x(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getX(const Quaternion<T>& orientation)
{
    return _internal_get_basis_x(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getY(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_y(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisY(const Quaternion<T>& orientation)
{
    return _internal_get_basis_y(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getZ(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_z(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getZ(const Quaternion<T>& orientation)
{
    return _internal_get_basis_z(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_x(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_y(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_z(basis, value);
}

/* ####################################################################################### */
/* Uo, Right, Forward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getUp(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_up(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getUp(const Quaternion<T>& orientation)
{
return _internal_get_basis_up(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getRight(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_right(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getRight(const Quaternion<T>& orientation)
{
    return _internal_get_basis_right(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getForward(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_forward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getForward(const Quaternion<T>& orientation)
{
    return _internal_get_basis_forward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getDown(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_down(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getDown(const Quaternion<T>& orientation)
{
    return _internal_get_basis_down(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getLeft(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_left(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getLeft(const Quaternion<T>& orientation)
{
    return _internal_get_basis_left(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getBackward(const Matrix<S,S,T>& basis)
{
    return _internal_get_basis_backward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getBackward(const Quaternion<T>& orientation)
{
    return _internal_get_basis_backward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_up(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_right(basis, value);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_forward(basis, value);
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
setPosition(const Matrix<4,4,T>& basis)
{
    return _internal_get_basis_position(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
    _internal_set_basis_position(basis, position);
}

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
getOrientation(const Matrix<4,4,T>& basis)
{
    return _internal_get_orientation_matrix3x3_from_matrix4x4(basis);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END