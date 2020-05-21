

#include <Math3D/Cartesian/2D/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::Basis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
    : m_position(position)
{
    _internal_set_basis_x(m_orientation, x);
    _internal_set_basis_y(m_orientation, y);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::Basis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
    : m_orientation(orientation)
    , m_position(position)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::x() const
{
    return _internal_get_basis_x<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::y() const
{
    return _internal_get_basis_y<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::up() const
{
    return _internal_get_basis_up<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::right() const
{
    return _internal_get_basis_right<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::down() const
{
    return _internal_get_basis_down<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::left() const
{
    return _internal_get_basis_left<T>(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<2,2,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::orientationMatrix() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::spaceMatrix() const
{
    return rawBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::setPosition(const Vector<2,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::setOrientation(const Vector<2,T>& x, const Vector<2,T>& y)
{
    _internal_get_basis_x<T>(m_orientation, x);
    _internal_get_basis_y<T>(m_orientation, y);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    m_orientation = orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation(0,0) = orientation(0,0);
    m_orientation(0,1) = orientation(0,1);
    m_orientation(1,0) = orientation(1,0);
    m_orientation(1,1) = orientation(1,1);
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::Basis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
{
    _internal_set_basis_x(m_basis, x);
    _internal_set_basis_y(m_basis, y);
    _internal_set_basis_position(m_basis, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    m_basis(2,0) = zero<T>;
    m_basis(2,1) = zero<T>;
#else
    m_basis(0,2) = zero<T>;
    m_basis(1,2) = zero<T>;
#endif

    m_basis(2,2) = number<T>(1);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::Basis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    _internal_set_orientation_matrix2x2_to_matrix3x3(m_basis, orientation);
    _internal_set_basis_position(m_basis, position);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    m_basis(2,0) = zero<T>;
    m_basis(2,1) = zero<T>;
#else
    m_basis(0,2) = zero<T>;
    m_basis(1,2) = zero<T>;
#endif

    m_basis(2,2) = number<T>(1);
}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::x() const
{
    return _internal_get_basis_x<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::y() const
{
    return _internal_get_basis_y<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::up() const
{
    return _internal_get_basis_up<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::right() const
{
    return _internal_get_basis_right<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::down() const
{
    return _internal_get_basis_down<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::left() const
{
    return _internal_get_basis_left<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::position() const
{
    return _internal_get_basis_position<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<2,2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::orientationMatrix() const
{
    return _internal_get_orientation_matrix2x2_from_matrix3x3<T>(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<3,3,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::spaceMatrix() const
{
    return m_basis;
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setPosition(const Vector<2,T>& position)
{
    _internal_set_basis_position(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Vector<2,T>& x, const Vector<2,T>& y)
{
    _internal_get_basis_x<T>(m_basis, x);
    _internal_get_basis_y<T>(m_basis, y);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    _internal_set_orientation_matrix2x2_to_matrix3x3(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_basis(0,0) = orientation(0,0);
    m_basis(0,1) = orientation(0,1);
    m_basis(1,0) = orientation(1,0);
    m_basis(1,1) = orientation(1,1);
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END
