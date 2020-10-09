

#include <CGM/Transformations/3D/Functions/Apply.hpp>

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    vector = transforms * vector;
#else
    vector = vector * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    vector = multiply<Representation>(transforms, vector);
#else
    vector = multiply<Representation>(vector, transforms);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    auto matrix = CGM::identity<3,T>();
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
apply(Vector<3,T>& vector, std::initializer_list<Matrix<4,4,T>> transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    auto matrix = CGM::identity<4,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        matrix *= *(transforms.begin() + i);
    }
    vector = multiply<Representation>(matrix, vector);
#else
    for (const auto& mat : transforms)
    {
        vector = multiply<Representation>(vector, mat);
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
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
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    auto mat = CGM::identity<3,T>();
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
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    matrix = transforms * matrix;
#else
    matrix = matrix * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, std::initializer_list<Matrix<4,4,T>> transforms)
{
#ifdef CGM_MATRIX_POST_MULTIPLICATION
    auto mat = CGM::identity<4,T>();
    for (auto i = static_cast<int>(transforms.size())-1; i >= 0; --i)
    {
        mat = mat * *(transforms.begin() + i);
    }
    matrix = mat * matrix;
#else
    for (const auto& mat : transforms)
    {
        matrix = matrix * mat;
    }
#endif
}

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, const Matrix<3,3,T>& transforms)
{
    auto copy = vector;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, const Matrix<4,4,T>& transforms)
{
    auto copy = vector;
    apply<Representation>(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, std::initializer_list<Matrix<3,3,T>> transforms)
{
    auto copy = vector;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
applied(const Vector<3,T>& vector, std::initializer_list<Matrix<4,4,T>> transforms)
{
    auto copy = vector;
    apply<Representation>(copy, transforms);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
applied(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms)
{
    auto copy = matrix;
    apply(copy, transforms);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
applied(const Matrix<4,4,T>& matrix, std::initializer_list<Matrix<4,4,T>> transforms)
{
    auto copy = matrix;
    apply(copy, transforms);
    return copy;
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END