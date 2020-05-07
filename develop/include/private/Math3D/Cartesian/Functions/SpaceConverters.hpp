

#include <Math3D/Cartesian/Functions/SpaceConverters.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Local to world */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToWorld(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToWorld(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToWorld(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{

}

/* ####################################################################################### */
/* World to local */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToLocal(const Vector<2,T>& vector, const Matrix<2,2,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<2,T>
moveToLocal(const Vector<2,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Matrix<3,3,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Matrix<4,4,T>& localSpace)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation)
{

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
moveToLocal(const Vector<3,T>& vector, const Quaternion<T>& localSpaceOrientation, const Vector<3,T>& localSpacePosition)
{

}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END
