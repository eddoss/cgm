

#include <Math3D/Cartesian/3D/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
    : m_position(position)
{
    _internal_set_basis_x(m_orientation, x);
    _internal_set_basis_y(m_orientation, y);
    _internal_set_basis_z(m_orientation, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
    : m_orientation(orientation)
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Quaternion<T>& orientation, const Vector<3,T>& position)
    : m_orientation(_internal_convert_quaternion_to_matrix3x3(orientation))
    , m_position(position)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::x() const
{
    return _internal_get_basis_x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::y() const
{
    return _internal_get_basis_y(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::z() const
{
    return _internal_get_basis_z(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::up() const
{
    return _internal_get_basis_up(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::right() const
{
    return _internal_get_basis_right(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::forward() const
{
    return _internal_get_basis_forward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::down() const
{
    return _internal_get_basis_down(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::left() const
{
    return _internal_get_basis_left(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::backward() const
{
    return _internal_get_basis_backward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<3,3,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::orientationMatrix() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Quaternion<T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::orientationQuaternion() const
{
    return _internal_convert_matrix3x3_to_quaternion(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<4,4,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::spaceMatrix() const
{
    return rawBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setPosition(const Vector<3,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_basis_x(m_orientation, x);
    _internal_set_basis_y(m_orientation, y);
    _internal_set_basis_z(m_orientation, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_orientation = _internal_convert_matrix4x4_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = rawBasis(orientation);
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    _internal_set_basis_x(m_basis, x);
    _internal_set_basis_y(m_basis, y);
    _internal_set_basis_z(m_basis, z);
    _internal_set_basis_position(m_basis, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    m_basis(3,0) = zero<T>;
    m_basis(3,1) = zero<T>;
    m_basis(3,2) = zero<T>;
#else
    m_basis(0,3) = zero<T>;
    m_basis(1,3) = zero<T>;
    m_basis(2,3) = zero<T>;
#endif

    m_basis(3,3) = number<T>(1);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    _internal_set_basis_position(position);
    _internal_set_orientation_matrix3x3_to_matrix4x4(m_basis, orientation);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    m_basis(3,0) = zero<T>;
    m_basis(3,1) = zero<T>;
    m_basis(3,2) = zero<T>;
#else
    m_basis(0,3) = zero<T>;
    m_basis(1,3) = zero<T>;
    m_basis(2,3) = zero<T>;
#endif

    m_basis(3,3) = number<T>(1);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Quaternion<T>& orientation, const Vector<3,T>& position)
    : m_basis(_internal_convert_quaternion_to_matrix4x4(orientation))
{
    _internal_set_basis_position(m_basis, position);
}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::x() const
{
    return _internal_get_basis_x(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::y() const
{
    return _internal_get_basis_y(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::z() const
{
    return _internal_get_basis_z(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::up() const
{
    return _internal_get_basis_up(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::right() const
{
    return _internal_get_basis_right(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::forward() const
{
    return _internal_get_basis_forward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::down() const
{
    return _internal_get_basis_down(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::left() const
{
    return _internal_get_basis_left(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::backward() const
{
    return _internal_get_basis_backward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::position() const
{
    return _internal_get_basis_position(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::orientationMatrix() const
{
    return _internal_get_orientation_matrix3x3_from_matrix4x4(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Quaternion<T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::orientationQuaternion() const
{
    return _internal_convert_matrix4x4_to_quaternion(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<4,4,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::spaceMatrix() const
{
    return m_basis;
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setPosition(const Vector<3,T>& position)
{
    _internal_set_basis_position(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    _internal_set_basis_x(m_basis, x);
    _internal_set_basis_y(m_basis, y);
    _internal_set_basis_z(m_basis, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    _internal_set_orientation_matrix3x3_to_matrix4x4(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Matrix<4,4,T>& orientation)
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
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Quaternion<T>& orientation)
{
    auto conj = conjugated(orientation);
    _internal_set_basis_x(m_basis, (orientation * Quaternion<T>{0,T(1),0,0} * conj).imaginary());
    _internal_set_basis_y(m_basis, (orientation * Quaternion<T>{0,0,T(1),0} * conj).imaginary());
    _internal_set_basis_z(m_basis, (orientation * Quaternion<T>{0,0,0,T(1)} * conj).imaginary());
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
    : m_orientation(_internal_convert_xyz_to_quaternion(x,y,z))
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
    : m_orientation(_internal_convert_matrix3x3_to_quaternion(orientation))
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::Basis(const Quaternion<T>& orientation, const Vector<3,T>& position)
    : m_orientation(orientation)
    , m_position(position)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::x() const
{
    Vector<3,T> vec {T(1),T(0),T(0)};
    _internal_rotate_vector3_by_quaternion(vec, m_orientation);
    return vec;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::y() const
{
    Vector<3,T> vec {T(0),T(1),T(0)};
    _internal_rotate_vector3_by_quaternion(vec, m_orientation);
    return vec;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::z() const
{
    Vector<3,T> vec {T(0),T(0),T(1)};
    _internal_rotate_vector3_by_quaternion(vec, m_orientation);
    return vec;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::up() const
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
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::right() const
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
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::forward() const
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
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::down() const
{
    return -this->up();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::left() const
{
    return -this->right();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::backward() const
{
    return -this->forward();
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::orientationMatrix() const
{
    return _internal_convert_quaternion_to_matrix3x3(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Quaternion<T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::orientationQuaternion() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<4,4,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::spaceMatrix() const
{
    return rawBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setPosition(const Vector<3,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    m_orientation = _internal_convert_xyz_to_quaternion(x, y, z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = _internal_convert_matrix3x3_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_orientation = _internal_convert_matrix4x4_to_quaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = orientation;
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END
