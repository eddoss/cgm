

#include <CGM/Modules/Transformations/3D/Functions/Apply.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    vector = transforms * vector;
#else
    vector = vector * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Vector<3,T>& vector, const Matrix<4,4,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    vector = detail::multiply_vector3_on_matrix4x4<Representation>(vector, transforms);
#else
    vector = detail::multiply_matrix4x4_on_vector3<Representation>(transforms, vector);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<3,3,T>& matrix, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    matrix = transforms * matrix;
#else
    matrix = matrix * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    matrix = spaceMatrix(transforms, {zero<T>, zero<T>, zero<T>}) * matrix;
#else
    detail::multiply_matrix4x4_on_matrix3x3(matrix, transforms);
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Matrix<4,4,T>& matrix, const Matrix<4,4,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    matrix = transforms * matrix;
#else
    matrix = matrix * transforms;
#endif
}

template<typename T>
constexpr CGM_FORCEINLINE void
apply(Axes<T>& axes, const Matrix<3,3,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    axes.x = transforms * axes.x;
    axes.y = transforms * axes.y;
    axes.z = transforms * axes.z;
#else
    axes.x = axes.x * transforms;
    axes.y = axes.y * transforms;
    axes.z = axes.z * transforms;
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EVectorRepresentation Representation, typename T>
constexpr CGM_FORCEINLINE void
apply(Axes<T>& axes, const Matrix<4,4,T>& transforms)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    axes.x = detail::multiply_matrix4x4_on_vector3<Representation>(transforms, axes.x);
    axes.y = detail::multiply_matrix4x4_on_vector3<Representation>(transforms, axes.y);
    axes.z = detail::multiply_matrix4x4_on_vector3<Representation>(transforms, axes.z);
#else
    axes.x = detail::multiply_vector3_on_matrix4x4<Representation>(axes.x, transforms);
    axes.y = detail::multiply_vector3_on_matrix4x4<Representation>(axes.y, transforms);
    axes.z = detail::multiply_vector3_on_matrix4x4<Representation>(axes.z, transforms);
#endif
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END