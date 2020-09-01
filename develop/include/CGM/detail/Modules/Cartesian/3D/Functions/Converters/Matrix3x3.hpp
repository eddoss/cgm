

#include <CGM/Modules/Cartesian/3D/Functions/Converters/Matrix3x3.hpp>


CGM_NAMESPACE_BEGIN
CGM_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Global to local / local to global (inplace) */
/* ####################################################################################### */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& space)
{

}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientation)
{

}

/* ####################################################################################### */
/* Local to local: Matrix3 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<3,3,T>& orientationB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Matrix<4,4,T>& spaceB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& orientationA, const Quaternion<T>& orientationB)
{

}

/* ####################################################################################### */
/* Local to local: Matrix4 (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<3,3,T>& orientationB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Matrix<4,4,T>& spaceB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Matrix<4,4,T>& spaceA, const Quaternion<T>& orientationB)
{

}

/* ####################################################################################### */
/* Local to local: Quaternion (inplace) */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<3,3,T>& orientationB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Matrix<4,4,T>& spaceB)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
convert(Matrix<3,3,T>& matrix, const Quaternion<T>& orientationA, const Quaternion<T>& orientationB)
{

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

CGM_XYZ_NAMESPACE_END
CGM_NAMESPACE_END
