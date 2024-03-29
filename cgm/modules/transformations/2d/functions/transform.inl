

#include "transform.hpp"


CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Inplace */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Vector<2,T>& vector, const Transforms<T>& parameters)
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

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Matrix<2,2,T>& matrix, const Transforms<T>& parameters)
{   
    if constexpr (Space == ESpace::Global)
    {
        switch (parameters.transformOrder)
        {
            case ETransformOrder::SRT:
            case ETransformOrder::STR:
            case ETransformOrder::TSR:
            {
                scale<Space>(matrix, parameters);
                rotate(matrix, parameters);
                break;
            }
            default:
            {
                rotate(matrix, parameters);
                scale<Space>(matrix, parameters);
                break;
            }
        }
    }
    else
    {
        auto parms = parameters;
        convert<ESpace::Global>(parms.pivot, matrix);
        transform<ESpace::Global>(matrix, parms);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(Matrix<3,3,T>& matrix, const Transforms<T>& parameters)
{
    if constexpr (Space == ESpace::Global)
    {
        switch (parameters.transformOrder)
        {
            case ETransformOrder::SRT:
            {
                scale<Space>(matrix, parameters);
                rotate<Space>(matrix, parameters);
                translate<Space>(matrix, parameters);
                break;
            }
            case ETransformOrder::STR:
            {
                scale<Space>(matrix, parameters);
                translate<Space>(matrix, parameters);
                rotate<Space>(matrix, parameters);
                break;
            }
            case ETransformOrder::RTS:
            {
                rotate<Space>(matrix, parameters);
                translate<Space>(matrix, parameters);
                scale<Space>(matrix, parameters);
                break;
            }
            case ETransformOrder::RST:
            {
                rotate<Space>(matrix, parameters);
                scale<Space>(matrix, parameters);
                translate<Space>(matrix, parameters);
                break;
            }
            case ETransformOrder::TSR:
            {
                translate<Space>(matrix, parameters);
                scale<Space>(matrix, parameters);
                rotate<Space>(matrix, parameters);
                break;
            }
            case ETransformOrder::TRS:
            {
                translate<Space>(matrix, parameters);
                rotate<Space>(matrix, parameters);
                scale<Space>(matrix, parameters);
                break;
            }
        }
    }
    else
    {
        auto parms = parameters;
        convert<ESpace::Global,EVectorRepresentation::Direction>(parms.pivot.axes.x, matrix);
        convert<ESpace::Global,EVectorRepresentation::Direction>(parms.pivot.axes.y, matrix);
        convert<ESpace::Global,EVectorRepresentation::Point>(parms.pivot.position, matrix);
        
        transform<ESpace::Global>(matrix, parms);
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
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
constexpr CGM_FORCEINLINE enable_if_floating<T, void>
transform(ArbitraryAxis<T>& axis, const Transforms<T>& parameters)
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
constexpr CGM_FORCEINLINE enable_if_floating<T, Vector<2,T>>
transformed(const Vector<2,T>& vector, const Transforms<T>& parameters)
{
    auto copy = vector;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<2,2,T>>
transformed(const Matrix<2,2,T>& matrix, const Transforms<T>& parameters)
{
    auto copy = matrix;
    transform<Space>(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
transformed(const Matrix<3,3,T>& matrix, const Transforms<T>& parameters)
{
    auto copy = matrix;
    transform<Space>(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Pivot<T>>
transformed(const Pivot<T>& pivot, const Transforms<T>& parameters)
{
    auto copy = pivot;
    transform(copy, parameters);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, ArbitraryAxis<T>>
transformed(const ArbitraryAxis<T>& axis, const Transforms<T>& parameters)
{
    auto copy = axis;
    transform(copy, parameters);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<typename T>
constexpr CGM_FORCEINLINE enable_if_floating<T, Matrix<3,3,T>>
transformMatrix(const Transforms<T>& parameters)
{
    auto mat = identity<3,T>();
    transform<ESpace::Global>(mat, parameters);

    transposeOrientation(mat);

    return mat;
}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END
