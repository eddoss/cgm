

#include "Matrix2x2.hpp"


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace)
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientation)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = orientation * matrix;
    #else
        matrix = matrix * orientation;
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = inverse(orientation) * matrix;
    #else
        matrix = matrix * inverse(orientation);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& space)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<2>(space, matrix);
    #else
        matrix = multiply<2>(matrix, space);
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<2>(inverse(space), matrix);
    #else
        matrix = multiply<2>(matrix, inverse(space));
    #endif
    }
}

/* ####################################################################################### */
/* Local to local: Matrix2 (inplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace)
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& space)
{
    auto copy = matrix;
    convert<Space>(copy, space);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix2 (outplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<2,2,T>
converted(const Matrix<2,2,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, spaceA, spaceB);
    return copy;
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
