

#include <Math3D/Cartesian/3D/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::x() const
{
    return _internal_get_3d_basis_x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::y() const
{
    return _internal_get_3d_basis_y(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::z() const
{
    return _internal_get_3d_basis_z(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::up() const
{
    return _internal_get_3d_basis_up(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::right() const
{
    return _internal_get_3d_basis_right(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::forward() const
{
    return _internal_get_3d_basis_forward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::down() const
{
    return _internal_get_3d_basis_down(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::left() const
{
    return _internal_get_3d_basis_left(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::backward() const
{
    return _internal_get_3d_basis_backward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<3,3,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::orientationMatrix() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Quaternion<T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::orientationQuaternion() const
{
    return _internal_matrix3x3_to_quaternion(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<4,4,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::spaceMatrix() const
{
    return rawBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setPosition(const Vector<3,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_3d_basis_x(m_orientation, x);
    _internal_set_3d_basis_y(m_orientation, y);
    _internal_set_3d_basis_z(m_orientation, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_orientation = _internal_matrix4x4_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = rawBasis(orientation);
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::x() const
{
    return _internal_get_3d_basis_x(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::y() const
{
    return _internal_get_3d_basis_y(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::z() const
{
    return _internal_get_3d_basis_z(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::up() const
{
    return _internal_get_3d_basis_up(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::right() const
{
    return _internal_get_3d_basis_right(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::forward() const
{
    return _internal_get_3d_basis_forward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::down() const
{
    return _internal_get_3d_basis_down(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::left() const
{
    return _internal_get_3d_basis_left(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::backward() const
{
    return _internal_get_3d_basis_backward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::position() const
{
    return _internal_get_3d_basis_position(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::orientationMatrix() const
{
    return _internal_extract_orientation_from_4x4_matrix(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Quaternion<T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::orientationQuaternion() const
{
    return _internal_matrix4x4_to_quaternion(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<4,4,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::spaceMatrix() const
{
    return m_basis;
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::setPosition(const Vector<3,T>& position)
{
    _internal_set_3d_basis_position(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_3d_basis_x(m_basis, x);
    _internal_set_3d_basis_y(m_basis, y);
    _internal_set_3d_basis_z(m_basis, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    _internal_set_4x4_matrix_orientation(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_basis(0,0) = orientation(0,0);
    m_basis(0,1) = orientation(0,1);
    m_basis(0,2) = orientation(0,2);
    m_basis(1,0) = orientation(1,0);
    m_basis(1,1) = orientation(1,1);
    m_basis(1,2) = orientation(1,2);
    m_basis(2,0) = orientation(2,0);
    m_basis(2,1) = orientation(2,1);
    m_basis(2,2) = orientation(2,2);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4),void>>::setOrientation(const Quaternion<T>& orientation)
{
    auto conj = conjugated(orientation);
    _internal_set_3d_basis_x(m_basis, (orientation * Quaternion<T>{0,T(1),0,0} * conj).imaginary());
    _internal_set_3d_basis_y(m_basis, (orientation * Quaternion<T>{0,0,T(1),0} * conj).imaginary());
    _internal_set_3d_basis_z(m_basis, (orientation * Quaternion<T>{0,0,0,T(1)} * conj).imaginary());
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::x() const
{
    return (m_orientation * Quaternion<T>{0,T(1),0,0} * conjugated(m_orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::y() const
{
    return (m_orientation * Quaternion<T>{0,0,T(1),0} * conjugated(m_orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::z() const
{
    return (m_orientation * Quaternion<T>{0,0,0,T(1)} * conjugated(m_orientation)).imaginary();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::up() const
{
#ifdef MATH3D_CARTESIAN_UP_X
    return this->x();
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return this->y();
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return this->z();
#endif
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::right() const
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return this->x();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return this->y();
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return this->z();
#endif
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::forward() const
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return this->x();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return this->y();
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return this->z();
#endif
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::down() const
{
    return -this->up();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::left() const
{
    return -this->right();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::backward() const
{
    return -this->forward();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::orientationMatrix() const
{
    return _internal_quaternion_to_matrix3x3(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Quaternion<T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::orientationQuaternion() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<4,4,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::spaceMatrix() const
{
    return rawBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::setPosition(const Vector<3,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    m_orientation = _internal_xyz_to_quaternion(x,y,z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = _internal_matrix3x3_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_orientation = _internal_matrix4x4_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion),void>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = orientation;
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END
