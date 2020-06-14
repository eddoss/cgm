

#include <Math3D/Cartesian/2D/Functions/Converters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return inverseForce(orientation) * vector;
#else
    return vector * inverseForce(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return inverseForce(orientation) * vector + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return inverseForce(orientation) * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return vector * inverseForce(orientation) + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * inverseForce(orientation);
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix3x3_on_vector2<Representation>(inverseForce(localSpace), vector);
#else
    return _internal_multiply_vector2_on_matrix3x3<Representation>(vector, inverseForce(localSpace));
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix2)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return globalToLocal<Representation>(vector, localSpace.orientationMatrix(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return globalToLocal(vector, localSpace.orientationMatrix());
        }
    }
    else if constexpr (Base == EBasisBase::Matrix3)
    {
        return globalToLocal<Representation>(vector, localSpace.spaceMatrix());
    }
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector;
#else
    return vector * orientation;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * vector + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return vector * orientation + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return _internal_multiply_matrix3x3_on_vector2<Representation>(localSpace, vector);
#else
    return _internal_multiply_vector2_on_matrix3x3<Representation>(vector, localSpace);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Basis<Base,T>& localSpace)
{
    if constexpr (Base == EBasisBase::Matrix2)
    {
        if constexpr (Representation == EVectorRepresentation::Point)
        {
            return localToGlobal(vector, localSpace.orientationMatrix(), localSpace.position());
        }
        else if constexpr (Representation == EVectorRepresentation::Direction)
        {
            return localToGlobal(vector, localSpace.orientationMatrix());
        }
    }
    else if constexpr (Base == EBasisBase::Matrix3)
    {
        return localToGlobal<Representation>(vector, localSpace.spaceMatrix());
    }
}

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
       return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Basis<Base,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal(localToGlobal<Representation>(vector, orientationA, positionA), orientationB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal(vector, orientationA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), spaceB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Basis<Base,T>& spaceB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, orientationA, positionA), spaceB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
    }
}

/* ####################################################################################### */
/* Local to local: Matrix4 */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Basis<Base,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Basis */
/* ####################################################################################### */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), orientationB, positionB);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
    }
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase Base, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<Base,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, EBasisBase BaseA, EBasisBase BaseB, typename T>
constexpr FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Basis<BaseA,T>& spaceA, const Basis<BaseB,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

MATH3D_XY_NAMESPACE_END
MATH3D_NAMESPACE_END