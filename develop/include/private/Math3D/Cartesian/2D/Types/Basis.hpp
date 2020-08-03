

#include <Math3D/Cartesian/2D/Types/Basis.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::Basis(const Vector<2,T>& x, const Vector<2,T>& y, const Vector<2,T>& position)
    : m_position(position)
    , m_orientation(MATH3D_XY_NAMESPACE::orientationMatrix(x,y))
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
    : m_orientation(MATH3D_XY_NAMESPACE::orientationMatrix(matrix))
    , m_position(MATH3D_XY_NAMESPACE::position(matrix))
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::x() const
{
    return MATH3D_XY_NAMESPACE::x(m_orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2)>>::y() const
{
    return MATH3D_XY_NAMESPACE::y(m_orientation);
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
    return MATH3D_XY_NAMESPACE::packBasis(m_orientation, m_position);
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
    MATH3D_XY_NAMESPACE::setOrientation(m_orientation, x,y);
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
    m_orientation = MATH3D_XY_NAMESPACE::orientationMatrix(orientation);
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
    : m_basis(MATH3D_XY_NAMESPACE::packBasis(x, y, position))
{

}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::Basis(const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
    : m_basis(MATH3D_XY_NAMESPACE::packBasis(orientation, position))
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
    return MATH3D_XY_NAMESPACE::x(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::y() const
{
    return MATH3D_XY_NAMESPACE::y(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::position() const
{
    return MATH3D_XY_NAMESPACE::position(m_basis);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE Matrix<2,2,T>
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::orientationMatrix() const
{
    return MATH3D_XY_NAMESPACE::orientation(m_basis);
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
    MATH3D_XY_NAMESPACE::setPosition(m_basis, position);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<2,2,T>& orientation)
{
    MATH3D_XY_NAMESPACE::setOrientation(m_basis, orientation);
}

/* --------------------------------------------------------------------------------------- */

template <EBasisBase Base, typename T>
constexpr FORCEINLINE void
Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>::setOrientation(const Matrix<3,3,T>& orientation)
{
    MATH3D_XY_NAMESPACE::setOrientation(m_basis, orientation);
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END
