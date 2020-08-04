#pragma once


#include <type_traits>
#include <CGM/Modules/Common.hpp>
#include <CGM/Modules/Core/Types/Vector.hpp>
#include <CGM/Modules/Core/Types/Matrix.hpp>
#include <CGM/Modules/Core/Types/Quaternion.hpp>
#include <CGM/Modules/Cartesian/3D/ModuleGlobals.hpp>
#include <CGM/Modules/Cartesian/3D/Types/Enums.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Utils.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/BasisPackers.hpp>
#include <CGM/Modules/Cartesian/3D/Functions/Orientation.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

template <EBasisBase Base, typename T=FLOAT, typename = void> struct Basis;

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template <EBasisBase Base, typename T>
struct Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix3)>>
{
    CGM_RULE_OF_FIVE(Basis)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using BasedOnType = Matrix<3,3,T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    constexpr static const EBasisBase base {Base};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Creates basis manually.
     * @param x Basis X axis.
     * @param y Basis Y axis.
     * @param z Basis Z axis.
     * @param position Basis position.
     */
    constexpr
    Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

    /**
     * Creates basis from 3x3 orientation matrix and position.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis orientated by quaternion.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Quaternion<T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis from 4x4 matrix.
     * @param matrix 4x4 basis matrix.
     */
    constexpr explicit
    Basis(const Matrix<4,4,T>& matrix);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets basis X axis.
     * @return X axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    x() const;

    /**
     * Gets basis Y axis.
     * @return Y axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    y() const;

    /**
     * Gets basis Z axis.
     * @return Z axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    z() const;

    /**
     * Gets basis Up axis.
     * @return Up axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    up() const;

    /**
     * Gets basis Right axis.
     * @return Right axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    right() const;

    /**
     * Gets basis Forward axis.
     * @return Forward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    forward() const;

    /**
     * Gets basis Down axis.
     * @return Down axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    down() const;

    /**
     * Gets basis Left axis.
     * @return Left axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    left() const;

    /**
     * Gets basis Backward axis.
     * @return Backward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    backward() const;

    /**
     * Gets basis position.
     * @return Basis position value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    position() const;

    /**
     * Gets basis orientation 3x3 matrix.
     * @return Basis orientation matrix.
     */
    constexpr CGM_FORCEINLINE const Matrix<3,3,T>&
    orientationMatrix() const;

    /**
     * Gets basis orientation quaternion.
     * @return Basis orientation quaternion.
     */
    constexpr CGM_FORCEINLINE Quaternion<T>
    orientationQuaternion() const;

    /**
     * Gets 4x4 matrix is describe this basis.
     * @return 4x4 basis matrix.
     */
    constexpr CGM_FORCEINLINE Matrix<4,4,T>
    spaceMatrix() const;

/* ####################################################################################### */
public: /* Setters */
/* ####################################################################################### */

    /**
     * Sets basis position.
     * @param position New position.
     */
    constexpr CGM_FORCEINLINE void
    setPosition(const Vector<3,T>& position);

    /**
     * Sets basis orientation.
     * @param x New orientation X axis.
     * @param y New orientation Y axis.
     * @param z New orientation Z axis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by 3x3 matrix.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<3,3,T>& orientation);

    /**
     * Sets basis orientation.
     * @param orientation Extracts orientation 3x3 matrix from this matrix and apply to basis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<4,4,T>& orientation);
    
    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by quaternion.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Quaternion<T>& orientation);

/* ####################################################################################### */
private: /* Private members */
/* ####################################################################################### */

    Matrix<3,3,T>
    m_orientation;

    Vector<3,T>
    m_position;
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template <EBasisBase Base, typename T>
struct Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Matrix4)>>
{
    CGM_RULE_OF_FIVE(Basis)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using BasedOnType = Matrix<4,4,T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    constexpr static const EBasisBase base {Base};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Creates basis manually.
     * @param x Basis X axis.
     * @param y Basis Y axis.
     * @param z Basis Z axis.
     * @param position Basis position.
     */
    constexpr
    Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

    /**
     * Creates basis from 3x3 orientation matrix and position.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis orientated by quaternion.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Quaternion<T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis from 4x4 matrix.
     * @param matrix 4x4 basis matrix.
     */
    constexpr explicit
    Basis(const Matrix<4,4,T>& matrix);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets basis X axis.
     * @return X axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    x() const;

    /**
     * Gets basis Y axis.
     * @return Y axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    y() const;

    /**
     * Gets basis Z axis.
     * @return Z axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    z() const;

    /**
     * Gets basis Up axis.
     * @return Up axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    up() const;

    /**
     * Gets basis Right axis.
     * @return Right axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    right() const;

    /**
     * Gets basis Forward axis.
     * @return Forward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    forward() const;

    /**
     * Gets basis Down axis.
     * @return Down axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    down() const;

    /**
     * Gets basis Left axis.
     * @return Left axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    left() const;

    /**
     * Gets basis Backward axis.
     * @return Backward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    backward() const;

    /**
     * Gets basis position.
     * @return Basis position value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    position() const;

    /**
     * Gets basis orientation 3x3 matrix.
     * @return Basis orientation matrix.
     */
    constexpr CGM_FORCEINLINE Matrix<3,3,T>
    orientationMatrix() const;

    /**
     * Gets basis orientation quaternion.
     * @return Basis orientation quaternion.
     */
    constexpr CGM_FORCEINLINE Quaternion<T>
    orientationQuaternion() const;

    /**
     * Gets 4x4 matrix is describe this basis.
     * @return 4x4 basis matrix.
     */
    constexpr CGM_FORCEINLINE const Matrix<4,4,T>&
    spaceMatrix() const;

/* ####################################################################################### */
public: /* Setters */
/* ####################################################################################### */

    /**
     * Sets basis position.
     * @param position New position.
     */
    constexpr CGM_FORCEINLINE void
    setPosition(const Vector<3,T>& position);

    /**
     * Sets basis orientation.
     * @param x New orientation X axis.
     * @param y New orientation Y axis.
     * @param z New orientation Z axis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by 3x3 matrix.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<3,3,T>& orientation);

    /**
     * Sets basis orientation.
     * @param orientation Extracts orientation 3x3 matrix from this matrix and apply to basis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<4,4,T>& orientation);
    
    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by quaternion.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Quaternion<T>& orientation);

/* ####################################################################################### */
private: /* Private members */
/* ####################################################################################### */

    Matrix<4,4,T>
    m_basis;
};

/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////////////// */

template <EBasisBase Base, typename T>
struct Basis <Base, T, std::enable_if_t<(Base == EBasisBase::Quaternion)>>
{
    CGM_RULE_OF_FIVE(Basis)

/* ####################################################################################### */
public: /* Aliases */
/* ####################################################################################### */

    using BasedOnType = Quaternion<T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    constexpr static const EBasisBase base {Base};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Creates basis manually.
     * @param x Basis X axis.
     * @param y Basis Y axis.
     * @param z Basis Z axis.
     * @param position Basis position.
     */
    constexpr
    Basis(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position);

    /**
     * Creates basis from 3x3 orientation matrix and position.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Matrix<3,3,T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis orientated by quaternion.
     * @param orientation Basis orientation.
     * @param position Basis position.
     */
    constexpr
    Basis(const Quaternion<T>& orientation, const Vector<3,T>& position);

    /**
     * Creates basis from 4x4 matrix.
     * @param matrix 4x4 basis matrix.
     */
    constexpr explicit
    Basis(const Matrix<4,4,T>& matrix);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets basis X axis.
     * @return X axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    x() const;

    /**
     * Gets basis Y axis.
     * @return Y axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    y() const;

    /**
     * Gets basis Z axis.
     * @return Z axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    z() const;

    /**
     * Gets basis Up axis.
     * @return Up axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    up() const;

    /**
     * Gets basis Right axis.
     * @return Right axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    right() const;

    /**
     * Gets basis Forward axis.
     * @return Forward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    forward() const;

    /**
     * Gets basis Down axis.
     * @return Down axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    down() const;

    /**
     * Gets basis Left axis.
     * @return Left axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    left() const;

    /**
     * Gets basis Backward axis.
     * @return Backward axis value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    backward() const;

    /**
     * Gets basis position.
     * @return Basis position value.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    position() const;

    /**
     * Gets basis orientation 3x3 matrix.
     * @return Basis orientation matrix.
     */
    constexpr CGM_FORCEINLINE Matrix<3,3,T>
    orientationMatrix() const;

    /**
     * Gets basis orientation quaternion.
     * @return Basis orientation quaternion.
     */
    constexpr CGM_FORCEINLINE const Quaternion<T>&
    orientationQuaternion() const;

    /**
     * Gets 4x4 matrix is describe this basis.
     * @return 4x4 basis matrix.
     */
    constexpr CGM_FORCEINLINE Matrix<4,4,T>
    spaceMatrix() const;

/* ####################################################################################### */
public: /* Setters */
/* ####################################################################################### */

    /**
     * Sets basis position.
     * @param position New position.
     */
    constexpr CGM_FORCEINLINE void
    setPosition(const Vector<3,T>& position);

    /**
     * Sets basis orientation.
     * @param x New orientation X axis.
     * @param y New orientation Y axis.
     * @param z New orientation Z axis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z);

    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by 3x3 matrix.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<3,3,T>& orientation);

    /**
     * Sets basis orientation.
     * @param orientation Extracts orientation 3x3 matrix from this matrix and apply to basis.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Matrix<4,4,T>& orientation);
    
    /**
     * Sets basis orientation.
     * @param orientation New orientation represented by quaternion.
     */
    constexpr CGM_FORCEINLINE void
    setOrientation(const Quaternion<T>& orientation);

/* ####################################################################################### */
private: /* Private members */
/* ####################################################################################### */

    Quaternion<T>
    m_orientation;

    Vector<3,T>
    m_position;
};

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END


#include <CGM/detail/Modules/Cartesian/3D/Types/Basis.hpp>