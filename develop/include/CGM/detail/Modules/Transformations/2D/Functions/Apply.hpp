

#include <CGM/Modules/Transformations/2D/Functions/Apply.hpp>

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<2,2,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    vector = transforms * vector;
#else
    vector = vector * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    vector = detail::multiply_matrix3x3_on_vector2<Representation>(transforms, vector);
#else
    vector = detail::multiply_vector2_on_matrix3x3<Representation>(vector, transforms);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    matrix = transforms * matrix;
#else
    matrix = matrix * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    matrix = transforms * matrix;
#else
    matrix = matrix * transforms;
#endif
}

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, const Matrix<2,2,T>& transforms)
{
    auto copy = vector;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, const Matrix<3,3,T>& transforms)
{
    auto copy = vector;
    apply<Representation>(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
applied(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& transforms)
{
    auto copy = matrix;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
applied(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms)
{
    auto copy = matrix;
    apply(copy, transforms);
    return copy;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END