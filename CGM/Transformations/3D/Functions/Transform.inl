

#include "Transform.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE void
transform(Vector<3,T>& vector, const Transforms<T>& parameters)
{
    switch (parameters.transformOrder)
    {
        case ETransformOrder::SRT:
        {
            scale(vector, parameters);
            rotate(vector, parameters);
            translate(vector, parameters);
            break;
        }
        case ETransformOrder::STR:
        {
            scale(vector, parameters);
            translate(vector, parameters);
            rotate(vector, parameters);
            break;
        }
        case ETransformOrder::RTS:
        {
            rotate(vector, parameters);
            translate(vector, parameters);
            scale(vector, parameters);
            break;
        }
        case ETransformOrder::RST:
        {
            rotate(vector, parameters);
            scale(vector, parameters);
            translate(vector, parameters);
            break;
        }
        case ETransformOrder::TSR:
        {
            translate(vector, parameters);
            scale(vector, parameters);
            rotate(vector, parameters);
            break;
        }
        case ETransformOrder::TRS:
        {
            translate(vector, parameters);
            rotate(vector, parameters);
            scale(vector, parameters);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
transform(Matrix<3,3,T>& matrix, const Transforms<T>& parameters)
{   
    switch (parameters.transformOrder)
    {
        case ETransformOrder::SRT:
        case ETransformOrder::STR:
        case ETransformOrder::TSR:
        {
            scale(matrix, parameters);
            rotate(matrix, parameters);
            break;
        }
        default:
        {
            rotate(matrix, parameters);
            scale(matrix, parameters);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
transform(Matrix<4,4,T>& matrix, const Transforms<T>& parameters)
{
    switch (parameters.transformOrder)
    {
        case ETransformOrder::SRT:
        {
            scale(matrix, parameters);
            rotate(matrix, parameters);
            translate(matrix, parameters);
            break;
        }
        case ETransformOrder::STR:
        {
            scale(matrix, parameters);
            translate(matrix, parameters);
            rotate(matrix, parameters);
            break;
        }
        case ETransformOrder::RTS:
        {
            rotate(matrix, parameters);
            translate(matrix, parameters);
            scale(matrix, parameters);
            break;
        }
        case ETransformOrder::RST:
        {
            rotate(matrix, parameters);
            scale(matrix, parameters);
            translate(matrix, parameters);
            break;
        }
        case ETransformOrder::TSR:
        {
            translate(matrix, parameters);
            scale(matrix, parameters);
            rotate(matrix, parameters);
            break;
        }
        case ETransformOrder::TRS:
        {
            translate(matrix, parameters);
            rotate(matrix, parameters);
            scale(matrix, parameters);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
transform(Pivot<T>& pivot, const Transforms<T>& parameters)
{
    switch (parameters.transformOrder)
    {
        case ETransformOrder::SRT:
        {
            scale(pivot, parameters);
            rotate(pivot, parameters);
            translate(pivot, parameters);
            break;
        }
        case ETransformOrder::STR:
        {
            scale(pivot, parameters);
            translate(pivot, parameters);
            rotate(pivot, parameters);
            break;
        }
        case ETransformOrder::RTS:
        {
            rotate(pivot, parameters);
            translate(pivot, parameters);
            scale(pivot, parameters);
            break;
        }
        case ETransformOrder::RST:
        {
            rotate(pivot, parameters);
            scale(pivot, parameters);
            translate(pivot, parameters);
            break;
        }
        case ETransformOrder::TSR:
        {
            translate(pivot, parameters);
            scale(pivot, parameters);
            rotate(pivot, parameters);
            break;
        }
        case ETransformOrder::TRS:
        {
            translate(pivot, parameters);
            rotate(pivot, parameters);
            scale(pivot, parameters);
            break;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
transform(Ray<T>& axis, const Transforms<T>& parameters)
{
    switch (parameters.transformOrder)
    {
        case ETransformOrder::SRT:
        {
            scale(axis, parameters);
            rotate(axis, parameters);
            translate(axis, parameters);
            break;
        }
        case ETransformOrder::STR:
        {
            scale(axis, parameters);
            translate(axis, parameters);
            rotate(axis, parameters);
            break;
        }
        case ETransformOrder::RTS:
        {
            rotate(axis, parameters);
            translate(axis, parameters);
            scale(axis, parameters);
            break;
        }
        case ETransformOrder::RST:
        {
            rotate(axis, parameters);
            scale(axis, parameters);
            translate(axis, parameters);
            break;
        }
        case ETransformOrder::TSR:
        {
            translate(axis, parameters);
            scale(axis, parameters);
            rotate(axis, parameters);
            break;
        }
        case ETransformOrder::TRS:
        {
            translate(axis, parameters);
            rotate(axis, parameters);
            scale(axis, parameters);
            break;
        }
    }
}

/* ####################################################################################### */
/* Outplace */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
transformed(const Vector<3,T>& vector, const Transforms<T>& parameters)
{
    auto copy = vector;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<3,3,T>
transformed(const Matrix<3,3,T>& matrix, const Transforms<T>& parameters)
{
    auto copy = matrix;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
transformed(const Matrix<4,4,T>& matrix, const Transforms<T>& parameters)
{
    auto copy = matrix;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
transformed(const Pivot<T>& pivot, const Transforms<T>& parameters)
{
    auto copy = pivot;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Ray<T>
transformed(const Ray<T>& axis, const Transforms<T>& parameters)
{
    auto copy = axis;
    transform(copy, parameters);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
transformMatrix(const Transforms<T>& parameters)
{
    auto mat = CGM::identity<4,T>();
    transform(mat, parameters);

    transposeOrientation(mat);

    return mat;
}

CGM_NAMESPACE_END
