

#include "matrix3x3.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientation)
{
    if constexpr (Space == ESpace::Global)
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
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& space)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<3>(space, matrix);
    #else
        matrix = multiply<3>(matrix, space);
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<3>(inverse(space), matrix);
    #else
        matrix = multiply<3>(matrix, inverse(space));
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientation)
{
    auto axes = orientationAxes(matrix);

    if constexpr (Space == ESpace::Global)
    {
        orient(axes.x, orientation);
        orient(axes.y, orientation);
        orient(axes.z, orientation);
    }
    else
    {
        auto quat = inverse(orientation);
        orient(axes.x, quat);
        orient(axes.y, quat);
        orient(axes.z, quat);
    }

    set(matrix, axes);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& space)
{
    auto copy = matrix;
    convert<Space>(copy, space);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, spaceA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

CGM_NAMESPACE_END
