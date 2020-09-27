

#include <CGM/detail/Cartesian/2D/Functions/Converters/Matrix3x3.hpp>


CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace)
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = detail::multiply_matrix3x3_on_matrix2x2_res3x3(matrix, orientation);
        setPosition(matrix, position(matrix) * orientation);
    #else
        matrix = detail::multiply_matrix2x2_on_matrix3x3_res3x3(orientation, matrix);
        setPosition(matrix, orientation * position(matrix));
    #endif
    }
    else
    {
        const auto orient = inverseForce(orientation);

    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        matrix = detail::multiply_matrix3x3_on_matrix2x2_res3x3(matrix, orient);
        setPosition(matrix, position(matrix) * orient);
    #else
        matrix = detail::multiply_matrix2x2_on_matrix3x3_res3x3(orient, matrix);
        setPosition(matrix, orient * position(matrix));
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    auto axs = orientationAxes(matrix);
    auto pos = CGM_XY::position(matrix);

    if constexpr (Space == ESpace::World)
    {
        const auto invorient = inverseForce(orientation);

    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        axs.x = invorient * axs.x;
        axs.y = invorient * axs.y;
        pos = invorient * pos;
    #else
        axs.x = axs.x * invorient;
        axs.y = axs.y * invorient;
        pos = pos * invorient;
    #endif
        pos += position;
    }
    else
    {
        pos -= position;
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        axs.x = orientation * axs.x;
        axs.y = orientation * axs.y;
        pos = orientation * pos;
    #else
        axs.x = axs.x * orientation;
        axs.y = axs.y * orientation;
        pos = pos * orientation;
    #endif
    }

    set(matrix, axs, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& space)
{
    auto axs = orientationAxes(matrix);
    auto pos = CGM_XY::position(matrix);

    if constexpr (Space == ESpace::World)
    {
        const auto invorient = inverseForce(orientationMatrix(space));

    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        axs.x = invorient * axs.x;
        axs.y = invorient * axs.y;
        pos = invorient * pos;
    #else
        axs.x = axs.x * invorient;
        axs.y = axs.y * invorient;
        pos = pos * invorient;
    #endif
        pos += position(space);
    }
    else
    {
        const auto orient = orientationMatrix(space);

        pos -= position(space);
    #ifdef CGM_MATRIX_POST_MULTIPLICATION
        axs.x = orient * axs.x;
        axs.y = orient * axs.y;
        pos = orient * pos;
    #else
        axs.x = axs.x * orient;
        axs.y = axs.y * orient;
        pos = pos * orient;
    #endif
    }

    set(matrix, axs, pos);
}

/* ####################################################################################### */
/* Local to local: Matrix2 (inplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix2 with Position (inplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* ####################################################################################### */
/* Global to local / local to global (outplace)
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation)
{
    auto copy = matrix;
    convert<Space>(copy, orientation);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientation, const Vector<2,T>& position)
{
    auto copy = matrix;
    convert<Space>(copy, orientation, position);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& space)
{
    auto copy = matrix;
    convert<Space>(copy, space);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix2 (outplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Matrix<3,3,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix2 with Position (outplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<2,2,T>& orientationA, const Vector<2,T>& positionA, const Matrix<3,3,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 (outplace)
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<2,2,T>& orientationB, const Vector<2,T>& positionB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
converted(const Matrix<3,3,T>& matrix, const Matrix<3,3,T>& spaceA, const Matrix<3,3,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, spaceA, spaceB);
    return copy;
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
