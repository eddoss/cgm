

#include "matrix4x4.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientation)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<4>(orientation,matrix);
    #else
        matrix = multiply<4>(matrix, orientation);
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = multiply<4>(inverse(orientation), matrix);
    #else
        matrix = multiply<4>(matrix, inverse(orientation));
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& space)
{
    if constexpr (Space == ESpace::Global)
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = space * matrix;
    #else
        matrix = matrix * space;
    #endif
    }
    else
    {
    #ifdef CGM_CFG_MATRIX_POSTMULT
        matrix = inverse(space) * matrix;
    #else
        matrix = matrix * inverse(space);
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientation)
{
    auto axs = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::Global)
    {
        orient(axs.x, orientation);
        orient(axs.y, orientation);
        orient(axs.z, orientation);
        orient(pos, orientation);
    }
    else
    {
        const auto quat = inverse(orientation);

        orient(axs.x, quat);
        orient(axs.y, quat);
        orient(axs.z, quat);
        orient(pos, quat);
    }

    set(matrix, axs, pos);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::Global>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& space)
{
    auto copy = matrix;
    convert<Space>(copy, space);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix4 (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, spaceA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

CGM_NAMESPACE_END
