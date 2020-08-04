

#include <CGM/Cartesian/3D/Types/Basis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
    : m_position(position)
    , m_orientation(CGM_XYZ::orientationMatrix(x,y,z))
{

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
    : m_orientation(CGM_XYZ::orientationMatrix(orientation))
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Matrix<4,4,T>& matrix)
    : m_orientation(CGM_XYZ::orientationMatrix(matrix))
    , m_position(CGM_XYZ::position(matrix))
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::x() const
{
    return CGM_XYZ::x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::y() const
{
    return CGM_XYZ::y(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::z() const
{
    return CGM_XYZ::z(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::up() const
{
    return CGM_XYZ::up(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::right() const
{
    return CGM_XYZ::right(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::forward() const
{
    return CGM_XYZ::forward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::down() const
{
    return CGM_XYZ::down(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::left() const
{
    return CGM_XYZ::left(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::backward() const
{
    return CGM_XYZ::backward(m_orientation);
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
    return CGM_XYZ::orientationQuaternion(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<4,4,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::spaceMatrix() const
{
    return CGM_XYZ::packBasis(m_orientation, m_position);
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
    CGM_XYZ::setOrientation(m_orientation, x,y,z);
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
    m_orientation = CGM_XYZ::orientationMatrix(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = CGM_XYZ::orientationMatrix(orientation);
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
    : m_basis(CGM_XYZ::packBasis(x, y, z, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
    : m_basis(CGM_XYZ::packBasis(orientation, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Quaternion<T>& orientation, const Vector<3,T>& position)
    : m_basis(CGM_XYZ::packBasis(orientation, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::Basis(const Matrix<4,4,T>& matrix)
    : m_basis(matrix)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::x() const
{
    return CGM_XYZ::x(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::y() const
{
    return CGM_XYZ::y(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::z() const
{
    return CGM_XYZ::z(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::up() const
{
    return CGM_XYZ::up(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::right() const
{
    return CGM_XYZ::right(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::forward() const
{
    return CGM_XYZ::forward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::down() const
{
    return CGM_XYZ::down(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::left() const
{
    return CGM_XYZ::left(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::backward() const
{
    return CGM_XYZ::backward(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::position() const
{
    return CGM_XYZ::position(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::orientationMatrix() const
{
    return CGM_XYZ::orientation(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Quaternion<T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::orientationQuaternion() const
{
    return CGM_XYZ::orientationQuaternion(m_basis);
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
    CGM_XYZ::setPosition(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    CGM_XYZ::setOrientation(m_basis, x,y,z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    CGM_XYZ::setOrientation(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    CGM_XYZ::setOrientation(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>::setOrientation(const Quaternion<T>& orientation)
{
    CGM_XYZ::setOrientation(m_basis, CGM_XYZ::orientationMatrix(orientation));
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
    : m_orientation(CGM_XYZ::orientationQuaternion(x,y,z))
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
    : m_orientation(CGM_XYZ::orientationQuaternion(orientation))
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

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::Basis(const Matrix<4,4,T>& matrix)
    : m_orientation(CGM_XYZ::orientationMatrix(matrix))
    , m_position(CGM_XYZ::position(matrix))
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::x() const
{
    return CGM_XYZ::x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::y() const
{
    return CGM_XYZ::y(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::z() const
{
    return CGM_XYZ::z(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::up() const
{
    return CGM_XYZ::up(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::right() const
{
    return CGM_XYZ::right(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::forward() const
{
    return CGM_XYZ::forward(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::down() const
{
    return CGM_XYZ::down(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::left() const
{
    return CGM_XYZ::left(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::backward() const
{
    return CGM_XYZ::backward(m_orientation);
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
    return CGM_XYZ::orientationMatrix(m_orientation);
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
    return CGM_XYZ::packBasis(m_orientation, m_position);
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
    m_orientation = CGM_XYZ::orientationQuaternion(x,y,z);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = CGM_XYZ::orientationQuaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Matrix<4,4,T>& orientation)
{
    m_orientation = CGM_XYZ::orientationQuaternion(orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>::setOrientation(const Quaternion<T>& orientation)
{
    m_orientation = orientation;
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END
