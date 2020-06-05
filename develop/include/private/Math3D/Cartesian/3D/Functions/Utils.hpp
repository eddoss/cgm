

#include <Math3D/Cartesian/3D/Functions/Utils.hpp>


MATH3D_NAMESPACE_BEGIN
MATH3D_XYZ_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y, Z axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getX(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(0,0),
        basis(0,1),
        basis(0,2),
    };
#else
    {
        basis(0,0),
        basis(1,0),
        basis(2,0),
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getX(const Quaternion<T>& orientation)
{
    return _internal_rotated_vector3_by_quaternion({T(1),T(0),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getY(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(1,0),
        basis(1,1),
        basis(1,2)
    };
#else
    {
        basis(0,1),
        basis(1,1),
        basis(2,1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getY(const Quaternion<T>& orientation)
{
    return _internal_rotated_vector3_by_quaternion({T(0),T(1),T(0)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getZ(const Matrix<S,S,T>& basis)
{
    return
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    {
        basis(2,0),
        basis(2,1),
        basis(2,2)
    };
#else
    {
        basis(0,2),
        basis(1,2),
        basis(2,2)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getZ(const Quaternion<T>& orientation)
{
    return _internal_rotated_vector3_by_quaternion({T(0),T(0),T(1)}, orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setX(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(0,0) = value.x;
    basis(0,1) = value.y;
    basis(0,2) = value.z;
#else
    basis(0,0) = value.x;
    basis(1,0) = value.y;
    basis(2,0) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setY(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(1,0) = value.x;
    basis(1,1) = value.y;
    basis(1,2) = value.z;
#else
    basis(0,1) = value.x;
    basis(1,1) = value.y;
    basis(2,1) = value.z;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setZ(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    basis(2,0) = value.x;
    basis(2,1) = value.y;
    basis(2,2) = value.z;
#else
    basis(0,2) = value.x;
    basis(1,2) = value.y;
    basis(2,2) = value.z;
#endif
}

/* ####################################################################################### */
/* Uo, Right, Forward axes */
/* ####################################################################################### */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getUp(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return getX(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return getY(basis);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return getZ(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getUp(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return getX(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return getY(orientation);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return getZ(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getRight(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return getX(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return getY(basis);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return getZ(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getRight(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return getX(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return getY(orientation);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return getZ(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getForward(const Matrix<S,S,T>& basis)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return getX(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return getY(basis);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return getZ(basis);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getForward(const Quaternion<T>& orientation)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return getX(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return getY(orientation);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return getZ(orientation);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getDown(const Matrix<S,S,T>& basis)
{
    return -getUp(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getDown(const Quaternion<T>& orientation)
{
    return -getUp(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getLeft(const Matrix<S,S,T>& basis)
{
    return -getRight(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getLeft(const Quaternion<T>& orientation)
{
    return -getRight(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), Vector<3,T>>
getBackward(const Matrix<S,S,T>& basis)
{
    return -getForward(basis);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getBackward(const Quaternion<T>& orientation)
{
    return -getForward(orientation);
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setUp(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_UP_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_UP_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setRight(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_RIGHT_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_RIGHT_Z
    return setZ(basis, value);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t S, typename T>
constexpr FORCEINLINE std::enable_if_t<(S == 3 || S == 4), void>
setForward(Matrix<S,S,T>& basis, const Vector<3,T>& value)
{
#ifdef MATH3D_CARTESIAN_FORWARD_X
    return setX(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Y
    return setY(basis, value);
#endif
#ifdef MATH3D_CARTESIAN_FORWARD_Z
    return setZ(basis, value);
#endif
}

/* ####################################################################################### */
/* Basis position */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
getPosition(const Matrix<4,4,T>& basis)
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
setPosition(Matrix<4,4,T>& basis, const Vector<3,T>& position)
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

/* ####################################################################################### */
/* Orientation */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<3,3,T>
getOrientation(const Matrix<4,4,T>& basis)
{
    return
    {
        basis(0,0), basis(0,1), basis(0,2),
        basis(1,0), basis(1,1), basis(1,2),
        basis(2,0), basis(2,1), basis(2,2)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<3,3,T>& orientation, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    setX(orientation, x);
    setY(orientation, y);
    setZ(orientation, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    setX(basis, x);
    setY(basis, y);
    setZ(basis, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<3,3,T>& orientation)
{
    basis(0,0) = orientation(0,0);
    basis(0,1) = orientation(0,1);
    basis(0,2) = orientation(0,2);
    basis(1,0) = orientation(1,0);
    basis(1,1) = orientation(1,1);
    basis(1,2) = orientation(1,2);
    basis(2,0) = orientation(2,0);
    basis(2,1) = orientation(2,1);
    basis(2,2) = orientation(2,2);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Quaternion<T>& orientation)
{
    auto [x,y,z] {orientationAxes(orientation)};
    setOrientation(basis, x, y, z);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr void
setOrientation(Matrix<4,4,T>& basis, const Matrix<4,4,T>& other)
{
    basis(0,0) = other(0,0);
    basis(0,1) = other(0,1);
    basis(0,2) = other(0,2);
    basis(1,0) = other(1,0);
    basis(1,1) = other(1,1);
    basis(1,2) = other(1,2);
    basis(2,0) = other(2,0);
    basis(2,1) = other(2,1);
    basis(2,2) = other(2,2);
}

/* ####################################################################################### */
/* Orientation to axes */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<3,3,T>& orientation)
{
    return std::make_tuple(getX(orientation), getY(orientation), getZ(orientation));
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Quaternion<T>& orientation)
{
    return std::make_tuple
    (
        _internal_rotated_vector3_by_quaternion({T(1),0,0}, orientation),
        _internal_rotated_vector3_by_quaternion({0,T(1),0}, orientation),
        _internal_rotated_vector3_by_quaternion({0,0,T(1)}, orientation)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>>
orientationAxes(const Matrix<4,4,T>& space)
{
    return std::make_tuple(getX(space), getY(space), getZ(space));
}

/* ####################################################################################### */
/* Orientation converters */
/* ####################################################################################### */

template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Quaternion<T>& orientation)
{
    Matrix<3,3,T> mat;

    setX(mat, _internal_rotated_vector3_by_quaternion({T(1),T(0),T(0)}, orientation));
    setY(mat, _internal_rotated_vector3_by_quaternion({T(0),T(1),T(0)}, orientation));
    setZ(mat, _internal_rotated_vector3_by_quaternion({T(0),T(0),T(1)}, orientation));

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<3,3,T>
orientationMatrix(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z)
{
    Matrix<3,3,T> mat;

    setX(mat, x);
    setY(mat, y);
    setZ(mat, z);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<3,3,T>& matrix)
{
    return orientationQuaternion
    (
        getX(matrix),
        getY(matrix),
        getZ(matrix)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Quaternion<T>
orientationQuaternion(const Matrix<4,4,T>& matrix)
{
    return orientationQuaternion
    (
        getX(matrix),
        getY(matrix),
        getZ(matrix)
    );
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Quaternion<T>
orientationQuaternion(const Vector<3,T>& X, const Vector<3,T>& Y, const Vector<3,T>& Z)
{
    Quaternion<T> q; T t;

    if (Z.z < 0)
    {
        if (X.x > Y.y)
        {
            t = 1 + X.x - Y.y - Z.z;
            q = {Y.z - Z.y, t, X.y + Y.x, Z.x + X.z};
        }
        else
        {
            t = 1 - X.x + Y.y - Z.z;
            q = {Z.x - X.z, X.y + Y.x, t, Y.z + Z.y};
        }
    }
    else
    {
        if (X.x < -Y.y)
        {
            t = 1 - X.x - Y.y + Z.z;
            q = {X.y - Y.x, Z.x + X.z, Y.z + Z.y, t};
        }
        else
        {
            t = 1 + X.x + Y.y + Z.z;
            q = {t, Y.z - Z.y, Z.x - X.z, X.y - Y.x};
        }
    }

    return q *= 0.5 / std::sqrt(t);
}

/* ####################################################################################### */
/* Space creators */
/* ####################################################################################### */

template<typename T>
constexpr FORCEINLINE Matrix<4,4,T>
space(const Vector<3,T>& x, const Vector<3,T>& y, const Vector<3,T>& z, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    setX(mat,x);
    setY(mat,y);
    setZ(mat,z);

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
space(const Matrix<3,3,T>& orientation, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif

    setOrientation(mat, orientation);
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr Matrix<4,4,T>
space(const Quaternion<T>& orientation, const Vector<3,T>& position)
{
    Matrix<4,4,T> mat;

    mat(3,3) = number<T>(1);

#ifdef MATH3D_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    mat(3,0) = zero<T>;
    mat(3,1) = zero<T>;
    mat(3,2) = zero<T>;
#else
    mat(0,3) = zero<T>;
    mat(1,3) = zero<T>;
    mat(2,3) = zero<T>;
#endif

    setOrientation(mat, orientation);
    setPosition(mat, position);

    return mat;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE std::tuple<Vector<3,T>, Vector<3,T>, Vector<3,T>, Vector<3,T>>
unpackSpace(const Matrix<4,4,T>& matrix)
{
    return std::make_tuple(getX(matrix), getY(matrix), getZ(matrix), getPosition(matrix));
}

MATH3D_XYZ_NAMESPACE_END
MATH3D_NAMESPACE_END