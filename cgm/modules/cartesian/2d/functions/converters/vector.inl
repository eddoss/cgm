

#include "vector.hpp"


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = orientation * vector;
    #else
        vector = vector * orientation;
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = inverse(orientation) * vector;
    #else
        vector = vector * inverse(orientation);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& space)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = multiply<Representation>(space, vector);
    #else
        vector = multiply<Representation>(vector, space);
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        vector = multiply<Representation>(inverse(space), vector);
    #else
        vector = multiply<Representation>(vector, inverse(space));
    #endif
    }
}

/* ####################################################################################### */
/* Local to local: Matrix2 */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::Global>(vector, orientationA);
    convert<ESpace::Local,Representation>(vector, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::Global>(vector, spaceA);
    convert<ESpace::Local>(vector, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
convert(Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::Global>(vector, spaceA);
    convert<ESpace::Local>(vector, spaceB);
}

/* ####################################################################################### */
/* Global to local (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientation)
{
    auto copy = vector;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& space)
{
    auto copy = vector;
    convert<Space,Representation>(copy, space);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix2 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    auto copy = vector;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    auto copy = vector;
    convert<Representation>(copy, orientationA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    auto copy = vector;
    convert<Representation>(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
converted(const Vector<2,T>& vector, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    auto copy = vector;
    convert<Representation>(copy, spaceA, spaceB);
    return copy;
}

CGM_2D_NAMESPACE_END

