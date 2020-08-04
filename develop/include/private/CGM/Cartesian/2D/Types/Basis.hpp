

#include <CGM/Cartesian/2D/Types/Basis.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::Basis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
    : m_position(position)
    , m_orientation(CGM_XY::orientationMatrix(x,y))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::Basis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
    : m_orientation(orientation)
    , m_position(position)
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::Basis(const Matrix<3,3,T>& matrix)
    : m_orientation(CGM_XY::orientationMatrix(matrix))
    , m_position(CGM_XY::position(matrix))
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::x() const
{
    return CGM_XY::x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::y() const
{
    return CGM_XY::y(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::position() const
{
    return m_position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<2,2,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::orientationMatrix() const
{
    return m_orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<3,3,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::spaceMatrix() const
{
    return CGM_XY::packBasis(m_orientation, m_position);
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::setPosition(const Vector<2,T>& position)
{
    m_position = position;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::setOrientation(const Vector<2,T>& x, const Vector<2,T>& y)
{
    CGM_XY::setOrientation(m_orientation, x,y);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    m_orientation = orientation;
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    m_orientation = CGM_XY::orientationMatrix(orientation);
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
    : m_basis(CGM_XY::packBasis(x, y, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
    : m_basis(CGM_XY::packBasis(orientation, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Matrix<3,3,T>& matrix)
    : m_basis(matrix)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::x() const
{
    return CGM_XY::x(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::y() const
{
    return CGM_XY::y(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::position() const
{
    return CGM_XY::position(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<2,2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::orientationMatrix() const
{
    return CGM_XY::orientation(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE const Matrix<3,3,T>&
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::spaceMatrix() const
{
    return m_basis;
}

/* ####################################################################################### */
/* Setters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setPosition(const Vector<2,T>& position)
{
    CGM_XY::setPosition(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    CGM_XY::setOrientation(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    CGM_XY::setOrientation(m_basis, orientation);
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
