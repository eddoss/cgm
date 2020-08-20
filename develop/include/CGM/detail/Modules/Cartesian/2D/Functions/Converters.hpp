

#include <CGM/Modules/Cartesian/2D/Functions/Converters.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return orientation * vector;
#else
    return vector * orientation;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * (vector - position);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return (vector - position) * orientation;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
globalToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(localSpace, vector - position(localSpace));
    }
    else
    {
        return detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(localSpace, vector);
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vector - position(localSpace), localSpace);
    }
    else
    {
        return detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vector, localSpace);
    }
#endif
}

/* ####################################################################################### */
/* Local to global */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return vector * orientation;
#else
    return orientation * vector;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return vector * orientation + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return vector * orientation;
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return orientation * vector + position;
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return orientation * vector;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr Vector<2,T>
localToGlobal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vector, localSpace) + position(localSpace);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return detail::multiply_vector2_on_matrix3x3<EVectorRepresentation::Direction>(vector, localSpace);
    }
#else
    if constexpr (Representation == EVectorRepresentation::Point)
    {
        return detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(localSpace, vector) + position(localSpace);
    }
    else if constexpr (Representation == EVectorRepresentation::Direction)
    {
        return detail::multiply_matrix3x3_on_vector2<EVectorRepresentation::Direction>(localSpace, vector);
    }
#endif
}

/* ####################################################################################### */
/* Local to local: Matrix2 */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    return globalToLocal(localToGlobal(vector, orientationA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
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
constexpr CGM_FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal(vector, orientationA), spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix2 with Position */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
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
constexpr CGM_FORCEINLINE Vector<2,T>
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
constexpr CGM_FORCEINLINE Vector<2,T>
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

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    return globalToLocal(localToGlobal<Representation>(vector, spaceA), orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
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
constexpr CGM_FORCEINLINE Vector<2,T>
localToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    return globalToLocal<Representation>(localToGlobal<Representation>(vector, spaceA), spaceB);
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END