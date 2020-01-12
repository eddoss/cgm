#ifndef MATH3D_VECTOR_OPERATORS_HPP
#define MATH3D_VECTOR_OPERATORS_HPP


#include <Math3D/Core/Structs/Vectors/Vector.hpp>

/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of vector by 1 and returns it.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator++(Vector<D,T>& vector);

/**
 * Decrease all components of vector by 1 and returns it.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator--(Vector<D,T>& vector);

/**
 * Increase all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator++(Vector<D,T>& vector, int);

/**
 * Decrease all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator--(Vector<D,T>& vector, int);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Calculates sum of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator+(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator+(const Vector<D,T>& vector, T scalar);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator+(T scalar, const Vector<D,T>& vector);

/**
 * Add scalar to vector components.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator+=(Vector<D,T>& vector, T scalar);

/**
 * Add vector B to vector A.
 * @param A Vector to add to.
 * @param B Vector to add.
 * @return The result of adding.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator+=(Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the vector.
 * @param vector Vector to negate.
 * @return A negated copy of the vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator-(const Vector<D,T>& vector);

/**
 * Calculates difference of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator-(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Subtract scalar from each vector component and return copy.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator-(const Vector<D,T>& vector, T scalar);

/**
 * Subtract scalar from each vector component.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator-=(Vector<D,T>& vector, T scalar);

/**
 * Subtract vector B from vector A.
 * @param A Vector to subtract from.
 * @param B Vector to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator-=(Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Component wise multiplication */
/* ####################################################################################### */

/**
 * Calculates component wise multiplication of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator*(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator*(const Vector<D,T>& vector, T scalar);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator*(T scalar, const Vector<D,T>& vector);

/**
 * Multiply scalar to each vector component.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator*=(Vector<D,T>& vector, T scalar);

/**
 * Multiply component wise vector A by vector B.
 * @param A Vector to multiply to.
 * @param B Vector to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator*=(Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Calculates component wise division of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator/(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>
operator/(const Vector<D,T>& vector, T scalar);

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator/=(Vector<D,T>& vector, T scalar);

/**
 * Divide component wise vector A by vector B.
 * @param A Vector to division to.
 * @param B Vector to division.
 * @return The result of division.
 */
template<size_t D, typename T=FLOAT>
Vector<D,T>&
operator/=(Vector<D,T>& A, const Vector<D,T>& B);

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
bool
operator==(const Vector<D,T>& vector, T scalar);

/**
 * Checking the components of a vector for inequality with a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are not equal to scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator!=(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are less than a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are less than scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator<(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are greater than a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are greater than scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator>(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are less or equal to a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are less or equal to a scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator<=(const Vector<D,T>& vector, T scalar);

/**
 * Checks if all components of a vector are greater or equal to a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are greater or equal to a scalar, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
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
bool
operator==(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Check against another vector for inequality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the vectors are not equal, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator!=(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are smaller than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components less than B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator<(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are larger than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components less or equal B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator<=(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are smaller (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components greater than B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
operator>(const Vector<D,T>& A, const Vector<D,T>& B);

/**
 * Compares whether all the components of this vector are larger (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A vector components greater or equal B vector components, false otherwise.
 */
template<size_t D, typename T=FLOAT>
bool
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
template<typename TOut=FLOAT, size_t D, typename T=FLOAT>
TOut
operator|(const Vector<D,T>& A, const Vector<D,T>& B);

/* ####################################################################################### */
/* Cross product operator */
/* ####################################################################################### */

/**
 * Calculates cross product of 2D vector and 2D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product (scalar or 3D/4D vector).
 */
template<typename T=FLOAT>
T
operator^(const Vector<2,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 2D vector and 3D vectors.
 * Represent 2D as 3D with Z=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<3,T>
operator^(const Vector<2,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 2D vector and 4D vectors.
 * Represent 2D as 4D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<4,T>
operator^(const Vector<2,T>& A, const Vector<4,T>& B);

/**
 * Calculates cross product of 3D vector and 2D vectors.
 * Represent 2D as 3D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 3D vector and 3D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 3D vector and 4D vectors.
 * Represent 3D as 4D with W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<4,T>& B);

/**
 * Calculates cross product of 4D vector and 2D vectors.
 * Represent 2D as 4D with Z=0, W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<2,T>& B);

/**
 * Calculates cross product of 4D vector and 3D vectors.
 * Represent 3D as 4D with W=0.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<3,T>& B);

/**
 * Calculates cross product of 4D vector and 4D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T=FLOAT>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<4,T>& B);

/* ####################################################################################### */
/* Stream output */
/* ####################################################################################### */

template<size_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const Vector<D,T>& vec);





/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */





/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>&
operator++(Vector<D,T>& vector)
{
    for (auto i = 0; i < D; ++i) ++(vector.data[i]);
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator--(Vector<D,T>& vector)
{
    for (auto i = 0; i < D; ++i) --(vector.data[i]);
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator++(Vector<D,T>& vector, int)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) ++(vector.data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator--(Vector<D,T>& vector, int)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) --(vector.data[i]);
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>
operator+(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] += B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator+(const Vector<D,T>& vector, T scalar)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator+(T scalar, const Vector<D,T>& vector)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator+=(Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) vector.data[i] += scalar;
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator+=(Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] += B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>
operator-(const Vector<D,T>& vector)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] = -copy.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator-(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] -= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator-(const Vector<D,T>& vector, T scalar)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] -= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator-=(Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) vector.data[i] -= scalar;
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator-=(Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] -= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise multiplication */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>
operator*(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] *= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator*(const Vector<D,T>& vector, T scalar)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator*(T scalar, const Vector<D,T>& vector)
{
    Vector<D,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator*=(Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) vector.data[i] *= scalar;
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator*=(Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] *= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>
operator/(const Vector<D,T>& A, const Vector<D,T>& B)
{
    Vector<D,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] /= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
operator/(const Vector<D,T>& vector, T scalar)
{
    Vector<D,T> copy {vector};
    for (auto i = 0; i < D; ++i) copy.data[i] /= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator/=(Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) vector.data[i] /= scalar;
    return vector;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
operator/=(Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] /= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t D, typename T>
bool
operator==(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (notEqual(vector.data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator!=(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (notEqual(vector.data[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator<(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (vector.data[i] >= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator>(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (vector.data[i] <= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator<=(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (vector.data[i] > scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator>=(const Vector<D,T>& vector, T scalar)
{
    for (auto i = 0; i < D; ++i) if (vector.data[i] < scalar) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t D, typename T>
bool
operator==(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (notEqual(A.data[i], B.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator!=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (notEqual(A.data[i], B.data[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator<(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] >= B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator>(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] <= B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator<=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] > B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
operator>=(const Vector<D,T>& A, const Vector<D,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] < B.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

template<typename TOut, size_t D, typename T>
TOut
operator|(const Vector<D,T>& A, const Vector<D,T>& B)
{
    if constexpr (D == 2)
    {
        return static_cast<TOut>(A(0)*B(0)+A(1)*B(1));
    }
    else if constexpr (D == 3)
    {
        return static_cast<TOut>(x(A)*x(B)+y(A)*y(B)+z(A)*z(B));
    }
    else if constexpr (D == 4)
    {
        return static_cast<TOut>(x(A)*x(B)+y(A)*y(B)+z(A)*z(B)+w(A)*w(B));
    }
    else
    {
        TOut result {0};
        for (size_t i = 0; i < D; ++i)
        {
            result += A(i)*B(i);
        }
        return result;
    }
}

/* ####################################################################################### */
/* Cross product operator */
/* ####################################################################################### */

template<typename T>
T
operator^(const Vector<2,T>& A, const Vector<2,T>& B)
{
    return x(A) * y(B) - y(A) * x(B);
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
operator^(const Vector<2,T>& A, const Vector<3,T>& B)
{
    return Vector<3,T>
    {
        y(A) * z(B),
       -x(A) * z(B),
        x(A) * y(B) - y(A) * x(B)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<4,T>
operator^(const Vector<2,T>& A, const Vector<4,T>& B)
{
    return Vector<4,T>
    {
        y(A) * z(B),
       -x(A) * z(B),
        x(A) * y(B) - y(A) * x(B),
        static_cast<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<2,T>& B)
{
    return Vector<3,T>
    {
       -z(A) * y(B),
        z(A) * x(B),
        x(A) * y(B) - y(A) * x(B)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<3,T>& B)
{
    return Vector<3,T>
    {
        y(A) * z(B) - z(A) * y(B),
        z(A) * x(B) - x(A) * z(B),
        x(A) * y(B) - y(A) * x(B)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<3,T>
operator^(const Vector<3,T>& A, const Vector<4,T>& B)
{
    return Vector<3,T>
    {
        y(A) * z(B) - z(A) * y(B),
        z(A) * x(B) - x(A) * z(B),
        x(A) * y(B) - y(A) * x(B)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<2,T>& B)
{
    return Vector<4,T>
    {
       -z(A) * y(B),
        z(A) * x(B),
        x(A) * y(B) - y(A) * x(B),
        static_cast<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<3,T>& B)
{
    return Vector<4,T>
    {
        y(A) * z(B) - z(A) * y(B),
        z(A) * x(B) - x(A) * z(B),
        x(A) * y(B) - y(A) * x(B),
        static_cast<T>(0)
    };
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
Vector<4,T>
operator^(const Vector<4,T>& A, const Vector<4,T>& B)
{
    return Vector<4,T>
    {
        y(A) * z(B) - z(A) * y(B),
        z(A) * x(B) - x(A) * z(B),
        x(A) * y(B) - y(A) * x(B),
        static_cast<T>(0)
    };
}

/* ####################################################################################### */
/* Stream output */
/* ####################################################################################### */

template<size_t D, typename T>
std::ostream&
operator << (std::ostream& stream, const Vector<D,T>& vec)
{
    stream.setf(std::ios::showpos);
    stream << typeid(vec).name() << "\n{";
    stream << std::fixed;
    for (size_t i = 0; i < D; ++i)
    {
        stream  << "\n    "
                << std::setw(10)
                << std::left
                << std::setprecision(6)
                << vec[i];
    }
    stream << "\n}\n";
    return stream;
}

#endif // MATH3D_VECTOR_OPERATORS_HPP
