#pragma once


#include <CGM/Modules/Cartesian/2D/Functions/Converters/Matrix2x2.hpp>


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
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * orientation;
    #else
        matrix = orientation * matrix;
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = matrix * inverseForce(orientation);
    #else
        matrix = inverseForce(orientation) * matrix;
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
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = detail::multiply_matrix2x2_on_matrix3x3_res2x2(matrix, space);
    #else
        matrix = detail::multiply_matrix3x3_on_matrix2x2_res2x2(space, matrix);
    #endif
    }
    else
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = detail::multiply_matrix2x2_on_matrix3x3_res2x2(matrix, inverseOrientationForce(space));
    #else
        matrix = detail::multiply_matrix3x3_on_matrix2x2_res2x2(inverseOrientationForce(space), matrix);
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
