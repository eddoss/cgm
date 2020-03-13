#ifndef MATH3D_VECTOR_OPERATORS_HPP
#define MATH3D_VECTOR_OPERATORS_HPP


#include <Math3D/Core/Vector/Vector.hpp>


/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of vector by 1 and returns it.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator++(Vector<D,T>& vector);

/**
 * Decrease all components of vector by 1 and returns it.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator--(Vector<D,T>& vector);

/**
 * Increase all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator++(Vector<D,T>& vector, int);

/**
 * Decrease all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator--(Vector<D,T>& vector, int);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Add scalar to vector components.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>&
operator+=(Vector<D,T>& vector, TScalar scalar);

/**
 * Add vector B to vector A.
 * @param A Vector to add to.
 * @param B Vector to add.
 * @return The result of adding.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator+=(Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates sum of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator+(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator+(const Vector<D,T>& vector, TScalar scalar);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator+(TScalar scalar, const Vector<D,T>& vector);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Subtract scalar from each vector component.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>&
operator-=(Vector<D,T>& vector, TScalar scalar);

/**
 * Subtract vector B from vector A.
 * @param A Vector to subtract from.
 * @param B Vector to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator-=(Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Get a negated copy of the vector.
 * @param vector Vector to negate.
 * @return A negated copy of the vector.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator-(const Vector<D,T>& vector);

/**
 * Calculates difference of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator-(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Subtract scalar from each vector component and return copy.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator-(const Vector<D,T>& vector, TScalar scalar);

/* ####################################################################################### */
/* Component wise multiplication */
/* ####################################################################################### */

/**
 * Multiply scalar to each vector component.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>&
operator*=(Vector<D,T>& vector, TScalar scalar);

/**
 * Multiply component wise vector A by vector B.
 * @param A Vector to multiply to.
 * @param B Vector to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator*=(Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates component wise multiplication of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator*(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator*(const Vector<D,T>& vector, TScalar scalar);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator*(TScalar scalar, const Vector<D,T>& vector);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>&
operator/=(Vector<D,T>& vector, TScalar scalar);

/**
 * Divide component wise vector A by vector B.
 * @param A Vector to division to.
 * @param B Vector to division.
 * @return The result of division.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>&
operator/=(Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Calculates component wise division of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
constexpr Vector<D,T>
operator/(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT, typename TScalar=FLOAT>
constexpr Vector<D,T>
operator/(const Vector<D,T>& vector, TScalar scalar);

/* ####################################################################################### */
/* Comparison with scalar */
/* ####################################################################################### */

/**
 * Checking the components of a vector for equality with a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are equal to scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator==(const Vector<D,T>& vector, T scalar);

/**
 * Checking the components of a vector for inequality with a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are not equal to scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator!=(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are less than a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are less than scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator<(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are greater than a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are greater than scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator>(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are less or equal to a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are less or equal to a scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator<=(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are greater or equal to a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are greater or equal to a scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator>=(const Vector<D,T>& vector, T scalar);

/* ####################################################################################### */
/* Comparison with other */
/* ####################################################################################### */

/**
 * Check against another vector for equality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the vectors are equal, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator==(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Check against another vector for inequality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the vectors are not equal, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator!=(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are smaller than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components less than B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator<(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are larger than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components less or equal B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator<=(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are smaller (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components greater than B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator>(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are larger (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components greater or equal B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
constexpr bool
operator>=(const Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

/**
 * Calculates cross dot of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The dot product.
 */
template<size_t D, typename T=FLOAT>
constexpr T
operator|(const Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Cross product operator */
/* ####################################################################################### */

/**
 * Calculates cross product of 2D vector and 2D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr T
operator^(const Vector<2,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 2D vector and 3D vectors.
 * Represent 2D as 3D with Z=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<3,T>
operator^(const Vector<2,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 2D vector and 4D vectors.
 * Represent 2D as 4D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<4,T>
operator^(const Vector<2,T>& A, const Vector<4,T>& B);

/**
 * Calculates cross product of 3D vector and 2D vectors.
 * Represent 2D as 3D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 3D vector and 3D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 3D vector and 4D vectors.
 * Represent 3D as 4D with W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<4,T>& B);

/**
 * Calculates cross product of 4D vector and 2D vectors.
 * Represent 2D as 4D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 4D vector and 3D vectors.
 * Represent 3D as 4D with W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 4D vector and 4D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
constexpr Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<4,T>& B);





/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */





/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator++(Vector<D,T>& vector)
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
        for (auto i = 0; i < D; ++i) ++(vector[i]);
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator--(Vector<D,T>& vector)
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
        for (auto i = 0; i < D; ++i) --vector[i];
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator++(Vector<D,T>& vector, int)
{
    Vector<D,T> copy {vector};

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
        for (auto i = 0; i < D; ++i) ++(vector[i]);
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator--(Vector<D,T>& vector, int)
{
    Vector<D,T> copy {vector};

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
        for (auto i = 0; i < D; ++i) --vector[i];
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>&
operator+=(Vector<D,T>& vector, TScalar scalar)
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
        for (auto i = 0; i < D; ++i) vector[i] += scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator+=(Vector<D,T>& A, const Vector<D,T>& B)
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
        for (auto i = 0; i < D; ++i) A[i] += B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator+(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};

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
        for (auto i = 0; i < D; ++i) copy[i] += B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>
operator+(const Vector<D,T>& vector, TScalar scalar)
{
    Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] += value;
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator+(T scalar, const Vector<D,T>& vector)
{
    Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] += value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator-(Vector<D,T>& vector)
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
        for (auto i = 0; i < D; ++i) copy[i] = -copy[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>&
operator-=(Vector<D,T>& vector, TScalar scalar)
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
        for (auto i = 0; i < D; ++i) vector[i] -= scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator-=(Vector<D,T>& A, const Vector<D,T>& B)
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
        for (auto i = 0; i < D; ++i) A[i] -= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator-(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};

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
        for (auto i = 0; i < D; ++i) copy[i] -= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>
operator-(const Vector<D,T>& vector, TScalar scalar)
{
    Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] -= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise multiplication */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>&
operator*=(Vector<D,T>& vector, TScalar scalar)
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
        for (auto i = 0; i < D; ++i) vector[i] *= static_cast<T>(scalar);
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator*=(Vector<D,T>& A, const Vector<D,T>& B)
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
        for (auto i = 0; i < D; ++i) A[i] *= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator*(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};

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
        for (auto i = 0; i < D; ++i) copy[i] *= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>
operator*(const Vector<D,T>& vector, TScalar scalar)
{
    Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] *= value;
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator*(T scalar, const Vector<D,T>& vector)
{
        Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] *= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>&
operator/=(Vector<D,T>& vector, TScalar scalar)
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
        for (auto i = 0; i < D; ++i) vector[i] /= scalar;
    }

    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>&
operator/=(Vector<D,T>& A, const Vector<D,T>& B)
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
        for (auto i = 0; i < D; ++i) A[i] /= B[i];
    }

    return A;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE Vector<D,T>
operator/(const Vector<D,T>& A, const Vector<D,T>& B)
{
        Vector<D,T> copy {A};

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
        for (auto i = 0; i < D; ++i) copy[i] /= B[i];
    }

    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T, typename TScalar>
constexpr FORCEINLINE Vector<D,T>
operator/(const Vector<D,T>& vector, TScalar scalar)
{
    Vector<D,T> copy {vector};
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
        for (auto i = 0; i < D; ++i) copy[i] /= value;
    }

    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator==(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  equal(vector.x, scalar) &&
                equal(vector.y, scalar);
    }
    else if constexpr (D == 3)
    {
        return  equal(vector.x, scalar) &&
                equal(vector.y, scalar) &&
                equal(vector.z, scalar);
    }
    else if constexpr (D == 4)
    {
        return  equal(vector.x, scalar) &&
                equal(vector.y, scalar) &&
                equal(vector.z, scalar) &&
                equal(vector.w, scalar);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (notEqual(vector[i], scalar)) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator!=(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  notEqual(vector.x, scalar) &&
                notEqual(vector.y, scalar);
    }
    else if constexpr (D == 3)
    {
        return  notEqual(vector.x, scalar) &&
                notEqual(vector.y, scalar) &&
                notEqual(vector.z, scalar);
    }
    else if constexpr (D == 4)
    {
        return  notEqual(vector.x, scalar) &&
                notEqual(vector.y, scalar) &&
                notEqual(vector.z, scalar) &&
                notEqual(vector.w, scalar);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (notEqual(vector[i], scalar)) return true;
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator<(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  vector.x < scalar &&
                vector.y < scalar;
    }
    else if constexpr (D == 3)
    {
        return  vector.x < scalar &&
                vector.y < scalar &&
                vector.z < scalar;
    }
    else if constexpr (D == 4)
    {
        return  vector.x < scalar &&
                vector.y < scalar &&
                vector.z < scalar &&
                vector.w < scalar;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (vector[i] >= scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator>(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  vector.x > scalar &&
                vector.y > scalar;
    }
    else if constexpr (D == 3)
    {
        return  vector.x > scalar &&
                vector.y > scalar &&
                vector.z > scalar;
    }
    else if constexpr (D == 4)
    {
        return  vector.x > scalar &&
                vector.y > scalar &&
                vector.z > scalar &&
                vector.w > scalar;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (vector[i] <= scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator<=(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  vector.x <= scalar &&
                vector.y <= scalar;
    }
    else if constexpr (D == 3)
    {
        return  vector.x <= scalar &&
                vector.y <= scalar &&
                vector.z <= scalar;
    }
    else if constexpr (D == 4)
    {
        return  vector.x <= scalar &&
                vector.y <= scalar &&
                vector.z <= scalar &&
                vector.w <= scalar;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (vector[i] > scalar) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator>=(const Vector<D,T>& vector, T scalar)
{
    if constexpr (D == 2)
    {
        return  vector.x >= scalar &&
                vector.y >= scalar;
    }
    else if constexpr (D == 3)
    {
        return  vector.x >= scalar &&
                vector.y >= scalar &&
                vector.z >= scalar;
    }
    else if constexpr (D == 4)
    {
        return  vector.x >= scalar &&
                vector.y >= scalar &&
                vector.z >= scalar &&
                vector.w >= scalar;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (vector[i] < scalar) return false;
        return true;
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator==(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  equal(A.x, B.x) &&
                equal(A.y, B.y);
    }
    else if constexpr (D == 3)
    {
        return  equal(A.x, B.x) &&
                equal(A.y, B.y) &&
                equal(A.z, B.z);
    }
    else if constexpr (D == 4)
    {
        return  equal(A.x, B.x) &&
                equal(A.y, B.y) &&
                equal(A.z, B.z) &&
                equal(A.w, B.w);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (notEqual(A[i], B[i])) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator!=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  notEqual(A.x, B.x) &&
                notEqual(A.y, B.y);
    }
    else if constexpr (D == 3)
    {
        return  notEqual(A.x, B.x) &&
                notEqual(A.y, B.y) &&
                notEqual(A.z, B.z);
    }
    else if constexpr (D == 4)
    {
        return  notEqual(A.x, B.x) &&
                notEqual(A.y, B.y) &&
                notEqual(A.z, B.z) &&
                notEqual(A.w, B.w);
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (notEqual(A[i], B[i])) return true;
        return false;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator<(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  A.x < B.x &&
                A.y < B.y;
    }
    else if constexpr (D == 3)
    {
        return  A.x < B.x &&
                A.y < B.y &&
                A.z < B.z;
    }
    else if constexpr (D == 4)
    {
        return  A.x < B.x &&
                A.y < B.y &&
                A.z < B.z &&
                A.w < B.w;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (A[i] >= B[i]) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator>(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  A.x > B.x &&
                A.y > B.y;
    }
    else if constexpr (D == 3)
    {
        return  A.x > B.x &&
                A.y > B.y &&
                A.z > B.z;
    }
    else if constexpr (D == 4)
    {
        return  A.x > B.x &&
                A.y > B.y &&
                A.z > B.z &&
                A.w > B.w;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (A[i] <= B[i]) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator<=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  A.x <= B.x &&
                A.y <= B.y;
    }
    else if constexpr (D == 3)
    {
        return  A.x <= B.x &&
                A.y <= B.y &&
                A.z <= B.z;
    }
    else if constexpr (D == 4)
    {
        return  A.x <= B.x &&
                A.y <= B.y &&
                A.z <= B.z &&
                A.w <= B.w;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (A[i] > B[i]) return false;
        return true;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE bool
operator>=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return  A.x >= B.x &&
                A.y >= B.y;
    }
    else if constexpr (D == 3)
    {
        return  A.x >= B.x &&
                A.y >= B.y &&
                A.z >= B.z;
    }
    else if constexpr (D == 4)
    {
        return  A.x >= B.x &&
                A.y >= B.y &&
                A.z >= B.z &&
                A.w >= B.w;
    }
    else
    {
        for (auto i = 0; i < D; ++i) if (A[i] < B[i]) return false;
        return true;
    }
}

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr T
operator|(const Vector<D,T>& A, const Vector<D,T>& B)
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
        T result {zero<T>()};
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
operator^(const Vector<2,T>& A, const Vector<2,T>& B)
{
    return A.x * B.y - A.y * B.x;
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
operator^(const Vector<2,T>& A, const Vector<3,T>& B)
{
    return Vector<3,T>
    {
        A.y * B.z,
       -A.x * B.z,
        A.x * B.y - A.y * B.x
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<4,T>
operator^(const Vector<2,T>& A, const Vector<4,T>& B)
{
    return Vector<4,T>
    {
        A.y * B.z,
       -A.x * B.z,
        A.x * B.y - A.y * B.x,
        zero<T>()
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<2,T>& B)
{
    return Vector<3,T>
    {
       -A.z * B.y,
        A.z * B.x,
        A.x * B.y - A.y * B.x
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<3,T>& B)
{
    return Vector<3,T>
    {
        A.y * B.z - A.z * B.y,
        A.z * B.x - A.x * B.z,
        A.x * B.y - A.y * B.x
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<4,T>& B)
{
    return Vector<3,T>
    {
        A.y * B.z - A.z * B.y,
        A.z * B.x - A.x * B.z,
        A.x * B.y - A.y * B.x
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<2,T>& B)
{
    return Vector<4,T>
    {
       -A.z * B.y,
        A.z * B.x,
        A.x * B.y - A.y * B.x,
        zero<T>()
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<3,T>& B)
{
    return Vector<4,T>
    {
        A.y * B.z - A.z * B.y,
        A.z * B.x - A.x * B.z,
        A.x * B.y - A.y * B.x,
        zero<T>()
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr FORCEINLINE Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<4,T>& B)
{
    return Vector<4,T>
    {
        A.y * B.z - A.z * B.y,
        A.z * B.x - A.x * B.z,
        A.x * B.y - A.y * B.x,
        zero<T>()
    };
}

#endif // MATH3D_VECTOR_OPERATORS_HPP