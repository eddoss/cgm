

#include <CGM/Modules/Transformations/3D/Functions/Rotate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle)
{
    const auto src = vector;
    const T cos = std::cos(angle);
    const T sin = std::sin(angle);

    if constexpr (Axis == EAxes::X)
    {
        const auto y = Vector<3,T>{ zero<T>, cos, sin };
        const auto z = Vector<3,T>{ zero<T>, -sin, cos };

        vector = y * src.y;
        vector += z * src.z;
        vector.x = src.x;
    }
    else if constexpr (Axis == EAxes::Y)
    {
        const auto x = Vector<3,T>(cos, zero<T>, -sin);
        const auto z = Vector<3,T>(sin, zero<T>, cos);

        vector = x * src.x;
        vector += z * src.z;
        vector.y = src.y;
    }
    else
    {
        const auto x = Vector<3,T>(cos, sin, zero<T>);
        const auto y = Vector<3,T>(-sin, cos, zero<T>);

        vector = x * src.x;
        vector += y * src.y;
        vector.z = src.z;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* Matrix3 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<3,3,T>& matrix, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* Matrix4 */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* Pivot */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
rotate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* AxesTuple */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(AxesTuple<T>& axes, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(AxesTuple<T>& axes, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(AxesTuple<T>& axes, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(AxesTuple<T>& axes, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(AxesTuple<T>& axes, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* AxesTuple */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(SpaceTuple<T>& space, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(SpaceTuple<T>& space, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(SpaceTuple<T>& space, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(SpaceTuple<T>& space, const Quaternion<T>& quaternion)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(SpaceTuple<T>& space, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* Quaternion */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Quaternion<T>& quat)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE void
rotate(Quaternion<T>& quaternion, const Transforms<T>& transforms)
{
    
}

/* ####################################################################################### */
/* Basis struct */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
rotate(Basis<Base,T>& basis, T angle)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
rotate(Basis<Base,T>& basis, T angle, const Axis<T>& axis)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
rotate(Basis<Base,T>& basis, const Vector<3,T>& angles, const Pivot<T>& pivotPoint, ERotationOrder rotationOrder)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
rotate(Basis<Base,T>& basis, const Quaternion<T>& quat)
{
    
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, EBasisBase Base, typename T>
constexpr CGM_FORCEINLINE void
rotate(Basis<Base,T>& basis, const Transforms<T>& transforms)
{
    
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END