

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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getX(const Basis<Base,T>& basis)
{
    return basis.x();
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
getY(const Quaternion<T>& orientation)
{
    return _internal_get_basis_y(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getY(const Basis<Base,T>& basis)
{
    return basis.y();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getZ(const Basis<Base,T>& basis)
{
    return basis.z();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getUp(const Basis<Base,T>& basis)
{
    return basis.up();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getRight(const Basis<Base,T>& basis)
{
    return basis.right();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getForward(const Basis<Base,T>& basis)
{
    return basis.forward();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getDown(const Basis<Base,T>& basis)
{
    return basis.down();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getLeft(const Basis<Base,T>& basis)
{
    return basis.left();
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

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getBackward(const Basis<Base,T>& basis)
{
    return basis.backward();
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
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
    _internal_set_basis_forward(basis, value);
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getPosition(const Matrix<4,4,T>& basis)
{
    return _internal_get_basis_position(basis);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
getPosition(const Basis<Base,T>& basis)
{
    return basis.position();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
    _internal_set_basis_position(basis, position);
}

/* --------------------------------------------------------------------------------------- */

template<EBasisBase Base, typename T>
constexpr FORCEINLINE void
setPosition(Basis<Base,T>& basis, const Vector<3,T>& position)
{
    basis.setPosition(position);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Matrix<3,3,T>& orientation)
{
    _internal_set_orientation_matrix3x3_to_matrix4x4(basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_orientation_matrix3x3_to_matrix4x4(basis, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
setOrientation(Matrix<3,3,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_basis_x(basis, x);
    _internal_set_basis_y(basis, y);
    _internal_set_basis_z(basis, z);
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END