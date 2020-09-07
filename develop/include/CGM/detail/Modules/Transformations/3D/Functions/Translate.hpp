

#include <CGM/Modules/Transformations/3D/Functions/Translate.hpp>


CGM_NAMESPACE_BEGIN
CGM_XFORM3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Vector (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, T value)
{
    if constexpr (Axis == EAxes::X)
    {
        vector.x += value;
    }
    else if constexpr (Axis == EAxes::Y)
    {
        vector.y += value;
    }
    else
    {
        vector.z += value;
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Vector<3,T>& value)
{
    vector += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Vector<3,T>& vector, const Transforms<T>& transforms)
{
    vector += transforms.translations;
}

/* ####################################################################################### */
/* Matrix4 (inplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, T value)
{
    Vector<3,T> axs;

    if constexpr (Axis == EAxes::X)
    {
        axs = x(matrix);
    }
    else if constexpr (Axis == EAxes::Y)
    {
        axs = y(matrix);
    }
    else
    {
        axs = z(matrix);
    }

    auto pos = position(matrix);
    pos += value * axs;

    setPosition(matrix, pos);
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, const Vector<3,T>& value)
{
    if constexpr (Space == ESpace::World)
    {
    #ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
        matrix(0,3) += value.x;
        matrix(1,3) += value.y;
        matrix(2,3) += value.z;
    #else
        matrix(3,0) += value.x;
        matrix(3,1) += value.y;
        matrix(3,2) += value.z;
    #endif
    }
    else
    {
        auto pos = position(matrix);

        pos += x(matrix) * value.x;
        pos += y(matrix) * value.y;
        pos += z(matrix) * value.z;

        setPosition(matrix, pos);
    }
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr void
translate(Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    translate<Space>(matrix, transforms.translations);
}

/* ####################################################################################### */
/* Pivot (inplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, T value)
{
    translate<Axis>(pivot.position, value);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Vector<3,T>& value)
{
    pivot.position += value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE void
translate(Pivot<T>& pivot, const Transforms<T>& transforms)
{
    pivot += transforms.translations;
}

/* ####################################################################################### */
/* Vector (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, T value)
{
    auto copy = vector;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, const Vector<3,T>& value)
{
    auto copy = vector;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<3,T>
translated(const Vector<3,T>& vector, const Transforms<T>& transforms)
{
    auto copy = vector;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Matrix4 (outplace) */
/* ####################################################################################### */

template<EAxes Axis, ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, T value)
{
    auto copy = matrix;
    translate<Axis,Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, const Vector<3,T>& value)
{
    auto copy = matrix;
    translate<Space>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<ESpace Space, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translated(const Matrix<4,4,T>& matrix, const Transforms<T>& transforms)
{
    auto copy = matrix;
    translate<Space>(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Pivot (outplace) */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, T value)
{
    auto copy = pivot;
    translate<Axis>(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Vector<3,T>& value)
{
    auto copy = pivot;
    translate(copy, value);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Pivot<T>
translated(const Pivot<T>& pivot, const Transforms<T>& transforms)
{
    auto copy = pivot;
    translate(copy, transforms);
    return copy;
}

/* ####################################################################################### */
/* Transformation makers */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(T value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    if constexpr (Axis == EAxes::X)
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), value,
            number<T>(0), number<T>(1), number<T>(0), number<T>(0),
            number<T>(1), number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };
    }
    else if constexpr (Axis == EAxes::Y)
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0), value,
            number<T>(1), number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };
    }
    else
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0), number<T>(0),
            number<T>(1), number<T>(0), number<T>(1), value,
            number<T>(0), number<T>(0), number<T>(0), number<T>(1)
        };
    }
#else
    if constexpr (Axis == EAxes::X)
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0), number<T>(0),
            number<T>(1), number<T>(0), number<T>(1), number<T>(0),
            value, number<T>(0), number<T>(0), number<T>(1)
        };
    }
    else if constexpr (Axis == EAxes::Y)
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0), number<T>(0),
            number<T>(1), number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), value, number<T>(0), number<T>(1)
        };
    }
    else
    {
        return
        {
            number<T>(1), number<T>(0), number<T>(0), number<T>(0),
            number<T>(0), number<T>(1), number<T>(0), number<T>(0),
            number<T>(1), number<T>(0), number<T>(1), number<T>(0),
            number<T>(0), number<T>(0), value, number<T>(1)
        };
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EAxes Axis, typename T>
constexpr Matrix<4,4,T>
translationMatrix(T value, const Matrix<3,3,T>& localOrientation)
{
    Vector<3,T> pos;

    if constexpr (Axis == EAxes::X)
    {
        pos = converted<ESpace::World>({value, number<T>(0), number<T>(0)}, localOrientation);
    }
    else if constexpr (Axis == EAxes::Y)
    {
        pos = converted<ESpace::World>({number<T>(0), value, number<T>(0)}, localOrientation);
    }
    else
    {
        pos = converted<ESpace::World>({number<T>(0), number<T>(0), value}, localOrientation);
    }

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), number<T>(0), pos.x,
        number<T>(0), number<T>(1), number<T>(0), pos.y,
        number<T>(1), number<T>(0), number<T>(1), pos.z,
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0), number<T>(0),
        number<T>(1), number<T>(0), number<T>(1), number<T>(0),
        pos.x, pos.y, pos.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<EAxes Axis, typename T>
constexpr Matrix<4,4,T>
translationMatrix(T value, const Matrix<4,4,T>& localSpace)
{
    Vector<3,T> pos;

    if constexpr (Axis == EAxes::X)
    {
        pos = converted<ESpace::World>({value, number<T>(0), number<T>(0)}, localSpace);
    }
    else if constexpr (Axis == EAxes::Y)
    {
        pos = converted<ESpace::World>({number<T>(0), value, number<T>(0)}, localSpace);
    }
    else
    {
        pos = converted<ESpace::World>({number<T>(0), number<T>(0), value}, localSpace);
    }

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), number<T>(0), pos.x,
        number<T>(0), number<T>(1), number<T>(0), pos.y,
        number<T>(1), number<T>(0), number<T>(1), pos.z,
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0), number<T>(0),
        number<T>(1), number<T>(0), number<T>(1), number<T>(0),
        pos.x, pos.y, pos.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Vector<3,T>& value)
{
#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), number<T>(0), value.x,
        number<T>(0), number<T>(1), number<T>(0), value.y,
        number<T>(1), number<T>(0), number<T>(1), value.z,
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0), number<T>(0),
        number<T>(1), number<T>(0), number<T>(1), number<T>(0),
        value.x, value.y, value.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Vector<3,T>& value, const Matrix<3,3,T>& localOrientation)
{
    auto pos = converted<ESpace::World>(value, localOrientation);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), number<T>(0), pos.x,
        number<T>(0), number<T>(1), number<T>(0), pos.y,
        number<T>(1), number<T>(0), number<T>(1), pos.z,
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0), number<T>(0),
        number<T>(1), number<T>(0), number<T>(1), number<T>(0),
        pos.x, pos.y, pos.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Vector<3,T>& value, const Matrix<4,4,T>& localSpace)
{
    auto pos = converted<ESpace::World>(value, localSpace);

#ifdef CGM_USE_COLUMN_MAJOR_VECTOR_REPRESENTATION
    return
    {
        number<T>(1), number<T>(0), number<T>(0), pos.x,
        number<T>(0), number<T>(1), number<T>(0), pos.y,
        number<T>(1), number<T>(0), number<T>(1), pos.z,
        number<T>(0), number<T>(0), number<T>(0), number<T>(1)
    };
#else
    return
    {
        number<T>(1), number<T>(0), number<T>(0), number<T>(0),
        number<T>(0), number<T>(1), number<T>(0), number<T>(0),
        number<T>(1), number<T>(0), number<T>(1), number<T>(0),
        pos.x, pos.y, pos.z, number<T>(1)
    };
#endif
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Transforms<T>& transforms)
{
    return translationMatrix(transforms.translations);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Transforms<T>& transforms, const Matrix<3,3,T>& localOrientation)
{
    return translationMatrix(transforms.translations, localOrientation);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Matrix<4,4,T>
translationMatrix(const Transforms<T>& transforms, const Matrix<4,4,T>& localSpace)
{
    return translationMatrix(transforms.translations, localSpace);
}

CGM_XFORM3D_NAMESPACE_END
CGM_NAMESPACE_END
