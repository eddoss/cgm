#ifndef MATH3D_XY_BASIS_HPP
#define MATH3D_XY_BASIS_HPP


#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrix.hpp>
#include <Math3D/Core/Quaternion.hpp>
#include <Math3D/Cartesian/Enums.hpp>
#include <private/Math3D/Cartesian/2D/InternalUtils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

template <EBasisBase Base, typename T, typename = void> struct Basis;

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template <EBasisBase Base, typename T>
struct Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix2),void>>
{
    MATH3D_RULE_OF_FIVE(Basis)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using BaseOnType = Matrix<2,2,T>;

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets basis X axis.
     * @return X axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    x() const;

    /**
     * Gets basis Y axis.
     * @return Y axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    y() const;

    /**
     * Gets basis Up axis.
     * @return Up axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    up() const;

    /**
     * Gets basis Right axis.
     * @return Right axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    right() const;

    /**
     * Gets basis Down axis.
     * @return Down axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    down() const;

    /**
     * Gets basis Left axis.
     * @return Left axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    left() const;

    /**
     * Gets basis position.
     * @return Basis position value.
     */
    constexpr FORCEINLINE Vector<2,T>
    position() const;

    /**
     * Gets basis orientation 2x2 matrix.
     * @return Basis orientation matrix.
     */
    constexpr FORCEINLINE const Matrix<2,2,T>&
    orientationMatrix() const;

    /**
     * Gets 3x3 matrix is describe this basis.
     * @return 3x3 basis matrix.
     */
    constexpr FORCEINLINE Matrix<3,3,T>
    spaceMatrix() const;

/* ####################################################################################### */
public: /* Setters */
/* ####################################################################################### */

    /**
     * Sets basis position.
     * @param position New position.
     */
    constexpr FORCEINLINE void
    setPosition(const Vector<2,T>& position);

    /**
     * Sets basis orientation.
     * @param x New orientation X axis.
     * @param y New orientation Y axis.
     */
    constexpr FORCEINLINE void
    setOrientation(const Vector<2,T>& x, const Vector<2,T>& y);

    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by 2x2 matrix.
     */
    constexpr FORCEINLINE void
    setOrientation(const Matrix<2,2,T>& orientation);

    /**
     * Sets basis orientation.
     * @param orientation Extracts orientation 3x3 matrix from this matrix and apply to basis.
     */
    constexpr FORCEINLINE void
    setOrientation(const Matrix<3,3,T>& orientation);

/* ####################################################################################### */
private: /* Private members */
/* ####################################################################################### */

    Matrix<2,2,T>
    m_orientation;

    Vector<2,T>
    m_position;
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template <EBasisBase Base, typename T>
struct Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3),void>>
{
    MATH3D_RULE_OF_FIVE(Basis)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using BaseOnType = Matrix<3,3,T>;

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets basis X axis.
     * @return X axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    x() const;

    /**
     * Gets basis Y axis.
     * @return Y axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    y() const;

    /**
     * Gets basis Up axis.
     * @return Up axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    up() const;

    /**
     * Gets basis Right axis.
     * @return Right axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    right() const;

    /**
     * Gets basis Down axis.
     * @return Down axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    down() const;

    /**
     * Gets basis Left axis.
     * @return Left axis value.
     */
    constexpr FORCEINLINE Vector<2,T>
    left() const;

    /**
     * Gets basis position.
     * @return Basis position value.
     */
    constexpr FORCEINLINE Vector<2,T>
    position() const;

    /**
     * Gets basis orientation 2x2 matrix.
     * @return Basis orientation matrix.
     */
    constexpr FORCEINLINE Matrix<2,2,T>
    orientationMatrix() const;

    /**
     * Gets 3x3 matrix is describe this basis.
     * @return 3x3 basis matrix.
     */
    constexpr FORCEINLINE const Matrix<3,3,T>&
    spaceMatrix() const;

/* ####################################################################################### */
public: /* Setters */
/* ####################################################################################### */

    /**
     * Sets basis position.
     * @param position New position.
     */
    constexpr FORCEINLINE void
    setPosition(const Vector<2,T>& position);

    /**
     * Sets basis orientation.
     * @param x New orientation X axis.
     * @param y New orientation Y axis.
     */
    constexpr FORCEINLINE void
    setOrientation(const Vector<2,T>& x, const Vector<2,T>& y);

    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by 2x2 matrix.
     */
    constexpr FORCEINLINE void
    setOrientation(const Matrix<2,2,T>& orientation);

    /**
     * Sets basis orientation.
     * @param orientation Extracts orientation 3x3 matrix from this matrix and apply to basis.
     */
    constexpr FORCEINLINE void
    setOrientation(const Matrix<3,3,T>& orientation);

/* ####################################################################################### */
private: /* Private members */
/* ####################################################################################### */

    Matrix<3,3,T>
    m_basis;
};

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END


#include <private/Math3D/Cartesian/2D/Basis.hpp>


#endif // MATH3D_XY_BASIS_HPP
