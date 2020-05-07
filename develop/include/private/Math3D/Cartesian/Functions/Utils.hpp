

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

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), Vector<2,T>>
get2DBasisY(const Matrix<S,S,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisX(const Matrix<S,S,T>& basis, const Vector<2,T>& value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 2 || S == 3), void>
set2DBasisY(const Matrix<S,S,T>& basis, const Vector<2,T>& value)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
get2DBasisPosition(const Matrix<3,3,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
set2DBasisPosition(const Matrix<3,3,T>& basis, const Vector<2,T>& position)
{

}

/* ####################################################################################### */
/* 3D */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisX(const Matrix<S,S,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisY(const Matrix<S,S,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
get3DBasisZ(const Matrix<S,S,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisX(const Quaternion<T>& orientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisY(const Quaternion<T>& orientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisZ(const Quaternion<T>& orientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisX(const Matrix<S,S,T>& basis, const Vector<3,T>& value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisY(const Matrix<S,S,T>& basis, const Vector<3,T>& value)
{

}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
set3DBasisZ(const Matrix<S,S,T>& basis, const Vector<3,T>& value)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
get3DBasisPosition(const Matrix<4,4,T>& basis)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE void
set3DBasisPosition(const Matrix<4,4,T>& basis, const Vector<3,T>& position)
{

}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END