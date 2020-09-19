

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
apply(Vector<2,T>& vector, std::initializer_list<Matrix<2,2,T>> transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto matrix = identity<2,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        matrix *= *(transforms.begin() + i);
    }
    vector = matrix * vector;
#else
    for (const auto& mat : transforms)
    {
        vector *= mat;
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<2,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto matrix = identity<3,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        matrix *= *(transforms.begin() + i);
    }
    vector = detail::multiply_matrix3x3_on_vector2<Representation>(matrix, vector);
#else
    for (const auto& mat : transforms)
    {
        vector = detail::multiply_vector2_on_matrix3x3<Representation>(vector, mat);
    }
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
apply(Matrix<2,2,T>& matrix, std::initializer_list<Matrix<2,2,T>> transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto mat = identity<2,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        mat *= *(transforms.begin() + i);
    }
    matrix = mat * matrix;
#else
    for (const auto& mat : transforms)
    {
        matrix *= mat;
    }
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, std::initializer_list<Matrix<3,3,T>> transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    auto mat = identity<3,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        mat *= *(transforms.begin() + i);
    }
    matrix = mat * matrix;
#else
    for (const auto& mat : transforms)
    {
        matrix *= mat;
    }
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
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, std::initializer_list<Matrix<2,2,T>> transforms)
{
    auto copy = vector;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
applied(const Vector<2,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms)
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
constexpr CGM_FORCEINLINE Matrix<2,2,T>
applied(const Matrix<2,2,T>& matrix, std::initializer_list<Matrix<2,2,T>> transforms)
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
applied(const Matrix<3,3,T>& matrix, std::initializer_list<Matrix<3,3,T>> transforms)
{
    auto copy = matrix;
    apply(copy, transforms);
    return copy;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END