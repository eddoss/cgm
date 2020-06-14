

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
    MATH3D_XY_NAMESPACE::setX(m_orientation, x);
    MATH3D_XY_NAMESPACE::setY(m_orientation, y);
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
    return MATH3D_XY_NAMESPACE::getX(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>::y() const
{
    return MATH3D_XY_NAMESPACE::getY(m_orientation);
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
    return MATH3D_XY_NAMESPACE::space(m_orientation, m_position);
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
    MATH3D_XY_NAMESPACE::getX(m_orientation, x);
    MATH3D_XY_NAMESPACE::getY(m_orientation, y);
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
    MATH3D_XY_NAMESPACE::setX(m_basis, x);
    MATH3D_XY_NAMESPACE::setY(m_basis, y);
    MATH3D_XY_NAMESPACE::setPosition(m_basis, position);

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
    MATH3D_XY_NAMESPACE::setOrientation(m_basis, orientation);
    MATH3D_XY_NAMESPACE::setPosition(m_basis, position);

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
    return MATH3D_XY_NAMESPACE::getX(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::y() const
{
    return MATH3D_XY_NAMESPACE::getY(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::position() const
{
    return MATH3D_XY_NAMESPACE::getPosition(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<2,2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::orientationMatrix() const
{
    return MATH3D_XY_NAMESPACE::getOrientation(m_basis);
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
    MATH3D_XY_NAMESPACE::setPosition(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Vector<2,T>& x, const Vector<2,T>& y)
{
    MATH3D_XY_NAMESPACE::getX(m_basis, x);
    MATH3D_XY_NAMESPACE::getY(m_basis, y);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    MATH3D_XY_NAMESPACE::setOrientation(m_basis, orientation);
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
