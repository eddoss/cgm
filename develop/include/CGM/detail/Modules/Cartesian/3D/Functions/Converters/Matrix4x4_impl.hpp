

#include <CGM/detail/Modules/Cartesian/3D/Functions/Converters/Matrix4x4.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientation)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = detail::multiply_matrix4x4_on_matrix3x3_res4x4(matrix, orientation);
        setPosition(matrix, position(matrix) * orientation);
    #else
        matrix = detail::multiply_matrix3x3_on_matrix4x4_res4x4(orientation, matrix);
        setPosition(matrix, orientation * position(matrix));
    #endif
    }
    else
    {
        const auto orient = inverseForce(orientation);

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix = detail::multiply_matrix4x4_on_matrix3x3_res4x4(matrix, orient);
        setPosition(matrix, position(matrix) * orient);
    #else
        matrix = detail::multiply_matrix3x3_on_matrix4x4_res4x4(orient, matrix);
        setPosition(matrix, orient * position(matrix));
    #endif
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    auto axs = orientationAxes(matrix);
    auto pos = CGM_XYZ::position(matrix);

    if constexpr (Space == ESpace::World)
    {
        const auto invorient = inverseForce(orientation);

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        axs.x = invorient * axs.x;
        axs.y = invorient * axs.y;
        axs.z = invorient * axs.z;
        pos = invorient * pos;
    #else
        axs.x = axs.x * invorient;
        axs.y = axs.y * invorient;
        axs.z = axs.z * invorient;
        pos = pos * invorient;
    #endif
        pos += position;
    }
    else
    {
        pos -= position;
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        axs.x = orientation * axs.x;
        axs.y = orientation * axs.y;
        axs.z = orientation * axs.z;
        pos = orientation * pos;
    #else
        axs.x = axs.x * orientation;
        axs.y = axs.y * orientation;
        axs.z = axs.z * orientation;
        pos = pos * orientation;
    #endif
    }

    set(matrix, axs, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& space)
{
    auto axs = orientationAxes(matrix);
    auto pos = CGM_XYZ::position(matrix);

    if constexpr (Space == ESpace::World)
    {
        const auto invorient = inverseForce(orientationMatrix(space));

    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        axs.x = invorient * axs.x;
        axs.y = invorient * axs.y;
        axs.z = invorient * axs.z;
        pos = invorient * pos;
    #else
        axs.x = axs.x * invorient;
        axs.y = axs.y * invorient;
        axs.z = axs.z * invorient;
        pos = pos * invorient;
    #endif
        pos += position(space);
    }
    else
    {
        const auto orient = orientationMatrix(space);

        pos -= position(space);
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        axs.x = orient * axs.x;
        axs.y = orient * axs.y;
        axs.z = orient * axs.z;
        pos = orient * pos;
    #else
        axs.x = axs.x * orient;
        axs.y = axs.y * orient;
        axs.z = axs.z * orient;
        pos = pos * orient;
    #endif
    }

    set(matrix, axs, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientation)
{
    auto axs = orientationAxes(matrix);
    auto pos = position(matrix);

    if constexpr (Space == ESpace::World)
    {
        orient(axs.x, orientation);
        orient(axs.y, orientation);
        orient(axs.z, orientation);
        orient(pos, orientation);
    }
    else
    {
        const auto quat = inverseForce(orientation);

        orient(axs.x, quat);
        orient(axs.y, quat);
        orient(axs.z, quat);
        orient(pos, quat);
    }

    set(matrix, axs, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    auto axs = orientationAxes(matrix);
    auto pos = CGM_XYZ::position(matrix);

    if constexpr (Space == ESpace::World)
    {
        orient(axs.x, orientation);
        orient(axs.y, orientation);
        orient(axs.z, orientation);
        orient(pos, orientation);
        pos += position;
    }
    else
    {
        const auto quat = inverseForce(orientation);

        pos -= position;
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
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, spaceA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* ####################################################################################### */
/* Local to local: Quaternion with Position (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, spaceB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    convert<ESpace::World>(matrix, orientationA, positionA);
    convert<ESpace::Local>(matrix, orientationB, positionB);
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
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    auto copy = matrix;
    convert<Space>(copy, orientation, position);
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

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    auto copy = matrix;
    convert<Space>(copy, orientation, position);
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
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB, positionB);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB, positionB);
    return copy;
}

/* ####################################################################################### */
/* Local to local: Matrix3 with Position (outplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Matrix<4,4,T>& spaceB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, spaceB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<3,3,T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB, positionB);
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
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB, positionB);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, spaceA, orientationB, positionB);
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
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB, positionB);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, orientationB, positionB);
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
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Matrix<3,3,T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB, positionB);
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

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
converted(const Matrix<4,4,T>& matrix, const Quaternion<T>& orientationA, const Vector<3,T>& positionA, const Quaternion<T>& orientationB, const Vector<3,T>& positionB)
{
    auto copy = matrix;
    convert(copy, orientationA, positionA, orientationB, positionB);
    return copy;
}

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END
