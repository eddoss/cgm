

#include <Math3D/Cartesian/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* 2D */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
get2DBasisX(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(1,0)
    };
#else
    {
        basis(0,0),
        basis(0,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
get2DBasisY(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,1),
        basis(1,1)
    };
#else
    {
        basis(1,0),
        basis(1,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisX(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(1,0) = value.y;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisY(Matrix<S,S,T>& basis, const Vector<2,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,1) = value.x;
    basis(1,1) = value.y;
#else
    basis(1,0) = value.x;
    basis(1,1) = value.y;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
get2DBasisPosition(const Matrix<3,3,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(2,0),
        basis(2,1)
    };
#else
    {
        basis(0,2),
        basis(1,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
set2DBasisPosition(Matrix<3,3,T>& basis, const Vector<2,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(2,0) = position.x;
    basis(2,1) = position.y;
#else
    basis(0,2) = position.x;
    basis(1,2) = position.y;
#endif
}

/* ####################################################################################### */
/* 3D */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisX(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(1,0),
        basis(2,0),
    };
#else
    {
        basis(0,0),
        basis(0,1),
        basis(0,2),
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisY(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,1),
        basis(1,1),
        basis(2,1)
    };
#else
    {
        basis(1,0),
        basis(1,1),
        basis(1,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisZ(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,2),
        basis(1,2),
        basis(2,2)
    };
#else
    {
        basis(2,0),
        basis(2,1),
        basis(2,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisX(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,T(1),0,0) * conjugated(orientation)).xyz();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisY(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,0,T(1),0) * conjugated(orientation)).xyz();
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisZ(const Quaternion<T>& orientation)
{
    return (orientation * Quaternion<T>(0,0,0,T(1)) * conjugated(orientation)).xyz();
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(1,0) = value.y;
    basis(2,0) = value.z;
#else
    basis(0,0) = value.x;
    basis(0,1) = value.y;
    basis(0,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisY(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,1) = value.x;
    basis(1,1) = value.y;
    basis(2,1) = value.z;
#else
    basis(1,0) = value.x;
    basis(1,1) = value.y;
    basis(1,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisZ(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,2) = value.x;
    basis(1,2) = value.y;
    basis(2,2) = value.z;
#else
    basis(2,0) = value.x;
    basis(2,1) = value.y;
    basis(2,2) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisPosition(const Matrix<4,4,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,3),
        basis(1,3),
        basis(2,3)
    };
#else
    {
        basis(3,0),
        basis(3,1),
        basis(3,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
set3DBasisPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,3) = position.x;
    basis(1,3) = position.y;
    basis(2,3) = position.z;
#else
    basis(3,0) = position.x;
    basis(3,1) = position.y;
    basis(3,2) = position.z;
#endif
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END