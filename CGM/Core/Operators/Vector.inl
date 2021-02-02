

#include "Vector.hpp"


/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator++(CGM::Vector<D,T>& vector)
{
    if constexpr (D == 2)
    {
        ++vector.x;
        ++vector.y;
    }
    else if constexpr (D == 3)
    {
        ++vector.x;
        ++vector.y;
        ++vector.z;
    }
    else if constexpr (D == 4)
    {
        ++vector.x;
        ++vector.y;
        ++vector.z;
        ++vector.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) ++(vector[i]);
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator--(CGM::Vector<D,T>& vector)
{
    if constexpr (D == 2)
    {
        --vector.x;
        --vector.y;
    }
    else if constexpr (D == 3)
    {
        --vector.x;
        --vector.y;
        --vector.z;
    }
    else if constexpr (D == 4)
    {
        --vector.x;
        --vector.y;
        --vector.z;
        --vector.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) --vector[i];
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator++(CGM::Vector<D,T>& vector, int)
{
    auto copy {vector};

    if constexpr (D == 2)
    {
        ++vector.x;
        ++vector.y;
    }
    else if constexpr (D == 3)
    {
        ++vector.x;
        ++vector.y;
        ++vector.z;
    }
    else if constexpr (D == 4)
    {
        ++vector.x;
        ++vector.y;
        ++vector.z;
        ++vector.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) ++(vector[i]);
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator--(CGM::Vector<D,T>& vector, int)
{
    auto copy {vector};

    if constexpr (D == 2)
    {
        --vector.x;
        --vector.y;
    }
    else if constexpr (D == 3)
    {
        --vector.x;
        --vector.y;
        --vector.z;
    }
    else if constexpr (D == 4)
    {
        --vector.x;
        --vector.y;
        --vector.z;
        --vector.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) --vector[i];
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator+=(CGM::Vector<D,T>& vector, TScalar scalar)
{
    if constexpr (D == 2)
    {
        vector.x += scalar;
        vector.y += scalar;
    }
    else if constexpr (D == 3)
    {
        vector.x += scalar;
        vector.y += scalar;
        vector.z += scalar;
    }
    else if constexpr (D == 4)
    {
        vector.x += scalar;
        vector.y += scalar;
        vector.z += scalar;
        vector.w += scalar;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) vector[i] += scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator+=(CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        A.x += B.x;
        A.y += B.y;
    }
    else if constexpr (D == 3)
    {
        A.x += B.x;
        A.y += B.y;
        A.z += B.z;
    }
    else if constexpr (D == 4)
    {
        A.x += B.x;
        A.y += B.y;
        A.z += B.z;
        A.w += B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) A[i] += B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator+(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    auto copy {A};

    if constexpr (D == 2)
    {
        copy.x += B.x;
        copy.y += B.y;
    }
    else if constexpr (D == 3)
    {
        copy.x += B.x;
        copy.y += B.y;
        copy.z += B.z;
    }
    else if constexpr (D == 4)
    {
        copy.x += B.x;
        copy.y += B.y;
        copy.z += B.z;
        copy.w += B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] += B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator+(const CGM::Vector<D,T>& vector, TScalar scalar)
{
    auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x += value;
        copy.y += value;
    }
    else if constexpr (D == 3)
    {
        copy.x += value;
        copy.y += value;
        copy.z += value;
    }
    else if constexpr (D == 4)
    {
        copy.x += value;
        copy.y += value;
        copy.z += value;
        copy.w += value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] += value;
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator+(T scalar, const CGM::Vector<D,T>& vector)
{
    auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x += value;
        copy.y += value;
    }
    else if constexpr (D == 3)
    {
        copy.x += value;
        copy.y += value;
        copy.z += value;
    }
    else if constexpr (D == 4)
    {
        copy.x += value;
        copy.y += value;
        copy.z += value;
        copy.w += value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] += value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator-(const CGM::Vector<D,T>& vector)
{
    auto copy {vector};

    if constexpr (D == 2)
    {
        copy.x = -copy.x;
        copy.y = -copy.y;
    }
    else if constexpr (D == 3)
    {
        copy.x = -copy.x;
        copy.y = -copy.y;
        copy.z = -copy.z;
    }
    else if constexpr (D == 4)
    {
        copy.x = -copy.x;
        copy.y = -copy.y;
        copy.z = -copy.z;
        copy.w = -copy.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] = -copy[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator-=(CGM::Vector<D,T>& vector, TScalar scalar)
{
    if constexpr (D == 2)
    {
        vector.x -= scalar;
        vector.y -= scalar;
    }
    else if constexpr (D == 3)
    {
        vector.x -= scalar;
        vector.y -= scalar;
        vector.z -= scalar;
    }
    else if constexpr (D == 4)
    {
        vector.x -= scalar;
        vector.y -= scalar;
        vector.z -= scalar;
        vector.w -= scalar;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) vector[i] -= scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator-=(CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        A.x -= B.x;
        A.y -= B.y;
    }
    else if constexpr (D == 3)
    {
        A.x -= B.x;
        A.y -= B.y;
        A.z -= B.z;
    }
    else if constexpr (D == 4)
    {
        A.x -= B.x;
        A.y -= B.y;
        A.z -= B.z;
        A.w -= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) A[i] -= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator-(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    auto copy {A};

    if constexpr (D == 2)
    {
        copy.x -= B.x;
        copy.y -= B.y;
    }
    else if constexpr (D == 3)
    {
        copy.x -= B.x;
        copy.y -= B.y;
        copy.z -= B.z;
    }
    else if constexpr (D == 4)
    {
        copy.x -= B.x;
        copy.y -= B.y;
        copy.z -= B.z;
        copy.w -= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] -= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator-(const CGM::Vector<D,T>& vector, TScalar scalar)
{
    auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x -= value;
        copy.y -= value;
    }
    else if constexpr (D == 3)
    {
        copy.x -= value;
        copy.y -= value;
        copy.z -= value;
    }
    else if constexpr (D == 4)
    {
        copy.x -= value;
        copy.y -= value;
        copy.z -= value;
        copy.w -= value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] -= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise multiplication */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator*=(CGM::Vector<D,T>& vector, TScalar scalar)
{
    if constexpr (D == 2)
    {
        vector.x *= scalar;
        vector.y *= scalar;
    }
    else if constexpr (D == 3)
    {
        vector.x *= scalar;
        vector.y *= scalar;
        vector.z *= scalar;
    }
    else if constexpr (D == 4)
    {
        vector.x *= scalar;
        vector.y *= scalar;
        vector.z *= scalar;
        vector.w *= scalar;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) vector[i] *= static_cast<T>(scalar);
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator*=(CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        A.x *= B.x;
        A.y *= B.y;
    }
    else if constexpr (D == 3)
    {
        A.x *= B.x;
        A.y *= B.y;
        A.z *= B.z;
    }
    else if constexpr (D == 4)
    {
        A.x *= B.x;
        A.y *= B.y;
        A.z *= B.z;
        A.w *= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) A[i] *= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator*(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    auto copy {A};

    if constexpr (D == 2)
    {
        copy.x *= B.x;
        copy.y *= B.y;
    }
    else if constexpr (D == 3)
    {
        copy.x *= B.x;
        copy.y *= B.y;
        copy.z *= B.z;
    }
    else if constexpr (D == 4)
    {
        copy.x *= B.x;
        copy.y *= B.y;
        copy.z *= B.z;
        copy.w *= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] *= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator*(const CGM::Vector<D,T>& vector, TScalar scalar)
{
    auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x *= value;
        copy.y *= value;
    }
    else if constexpr (D == 3)
    {
        copy.x *= value;
        copy.y *= value;
        copy.z *= value;
    }
    else if constexpr (D == 4)
    {
        copy.x *= value;
        copy.y *= value;
        copy.z *= value;
        copy.w *= value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] *= value;
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator*(T scalar, const CGM::Vector<D,T>& vector)
{
    auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x *= value;
        copy.y *= value;
    }
    else if constexpr (D == 3)
    {
        copy.x *= value;
        copy.y *= value;
        copy.z *= value;
    }
    else if constexpr (D == 4)
    {
        copy.x *= value;
        copy.y *= value;
        copy.z *= value;
        copy.w *= value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] *= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator/=(CGM::Vector<D,T>& vector, TScalar scalar)
{
    if constexpr (D == 2)
    {
        vector.x /= scalar;
        vector.y /= scalar;
    }
    else if constexpr (D == 3)
    {
        vector.x /= scalar;
        vector.y /= scalar;
        vector.z /= scalar;
    }
    else if constexpr (D == 4)
    {
        vector.x /= scalar;
        vector.y /= scalar;
        vector.z /= scalar;
        vector.w /= scalar;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) vector[i] /= scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>&
operator/=(CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        A.x /= B.x;
        A.y /= B.y;
    }
    else if constexpr (D == 3)
    {
        A.x /= B.x;
        A.y /= B.y;
        A.z /= B.z;
    }
    else if constexpr (D == 4)
    {
        A.x /= B.x;
        A.y /= B.y;
        A.z /= B.z;
        A.w /= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) A[i] /= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator/(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    auto copy {A};

    if constexpr (D == 2)
    {
        copy.x /= B.x;
        copy.y /= B.y;
    }
    else if constexpr (D == 3)
    {
        copy.x /= B.x;
        copy.y /= B.y;
        copy.z /= B.z;
    }
    else if constexpr (D == 4)
    {
        copy.x /= B.x;
        copy.y /= B.y;
        copy.z /= B.z;
        copy.w /= B.w;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] /= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr CGM_FORCEINLINE CGM::Vector<D,T>
operator/(const CGM::Vector<D,T>& vector, TScalar scalar)
{
   auto copy {vector};
    T value {static_cast<T>(scalar)};

    if constexpr (D == 2)
    {
        copy.x /= value;
        copy.y /= value;
    }
    else if constexpr (D == 3)
    {
        copy.x /= value;
        copy.y /= value;
        copy.z /= value;
    }
    else if constexpr (D == 4)
    {
        copy.x /= value;
        copy.y /= value;
        copy.z /= value;
        copy.w /= value;
    }
    else
    {
        for (size_t i = 0; i < D; ++i) copy[i] /= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE bool
operator==(const CGM::Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  CGM::eq(vector.x, scalar) &&
                CGM::eq(vector.y, scalar);
    }
    else if constexpr (D == 3)
    {
        return  CGM::eq(vector.x, scalar) &&
                CGM::eq(vector.y, scalar) &&
                CGM::eq(vector.z, scalar);
    }
    else if constexpr (D == 4)
    {
        return  CGM::eq(vector.x, scalar) &&
                CGM::eq(vector.y, scalar) &&
                CGM::eq(vector.z, scalar) &&
                CGM::eq(vector.w, scalar);
    }
    else
    {
        for (size_t i = 0; i < D; ++i) if (CGM::neq(vector[i], scalar)) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE bool
operator!=(const CGM::Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  CGM::neq(vector.x, scalar) ||
                CGM::neq(vector.y, scalar);
    }
    else if constexpr (D == 3)
    {
        return  CGM::neq(vector.x, scalar) ||
                CGM::neq(vector.y, scalar) ||
                CGM::neq(vector.z, scalar);
    }
    else if constexpr (D == 4)
    {
        return  CGM::neq(vector.x, scalar) ||
                CGM::neq(vector.y, scalar) ||
                CGM::neq(vector.z, scalar) ||
                CGM::neq(vector.w, scalar);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (CGM::neq(vector[i], scalar)) return true;
        return false;
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE bool
operator==(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  CGM::eq(A.x, B.x) &&
                CGM::eq(A.y, B.y);
    }
    else if constexpr (D == 3)
    {
        return  CGM::eq(A.x, B.x) &&
                CGM::eq(A.y, B.y) &&
                CGM::eq(A.z, B.z);
    }
    else if constexpr (D == 4)
    {
        return  CGM::eq(A.x, B.x) &&
                CGM::eq(A.y, B.y) &&
                CGM::eq(A.z, B.z) &&
                CGM::eq(A.w, B.w);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (CGM::neq(A[i], B[i])) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr CGM_FORCEINLINE bool
operator!=(const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  CGM::neq(A.x, B.x) ||
                CGM::neq(A.y, B.y);
    }
    else if constexpr (D == 3)
    {
        return  CGM::neq(A.x, B.x) ||
                CGM::neq(A.y, B.y) ||
                CGM::neq(A.z, B.z);
    }
    else if constexpr (D == 4)
    {
        return  CGM::neq(A.x, B.x) ||
                CGM::neq(A.y, B.y) ||
                CGM::neq(A.z, B.z) ||
                CGM::neq(A.w, B.w);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (CGM::neq(A[i], B[i])) return true;
        return false;
    }
}

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr T
operator | (const CGM::Vector<D,T>& A, const CGM::Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return A.x * B.x + A.y * B.y;
    }
    else if constexpr (D == 3)
    {
        return A.x * B.x + A.y * B.y + A.z * B.z;
    }
    else if constexpr (D == 4)
    {
        return A.x * B.x + A.y * B.y + A.z * B.z + A.w * B.w;
    }
    else
    {
        T result {CGM::val<T>(0)};
        for (auto i = 0; i < D; ++i)
        {
            result += A[i] * B[i];
        }
        return result;
    }
}

/* ####################################################################################### */
/* Cross product operator */
/* ####################################################################################### */

template<typename T>
constexpr T
operator ^ (const CGM::Vector<2,T>& A, const CGM::Vector<2,T>& B)
{
    return A.x * B.y - A.y * B.x;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE CGM::Vector<3,T>
operator ^ (const CGM::Vector<3,T>& A, const CGM::Vector<3,T>& B)
{
#ifdef CGM_CFG_LHS
    return
    {
        A.z * B.y - A.y * B.z,
        A.x * B.z - A.z * B.x,
        A.y * B.x - A.x * B.y
    };
#else
    return
    {
        A.y * B.z - A.z * B.y,
        A.z * B.x - A.x * B.z,
        A.x * B.y - A.y * B.x
    };
#endif
}