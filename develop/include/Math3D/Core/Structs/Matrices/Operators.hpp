#ifndef MATH3D_MATRIX_OPERATORS_HPP
#define MATH3D_MATRIX_OPERATORS_HPP


#include <Math3D/Core/Structs/Vectors/Matrix.hpp>

/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator++(Matrix<M,N,T>& matrix);

/**
 * Decrease all components of matrix by 1 and returns it.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator--(Matrix<M,N,T>& matrix);

/**
 * Increase all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator++(Matrix<M,N,T>& matrix, int);

/**
 * Decrease all components of matrix by 1 and returns unchanged copy of it.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator--(Matrix<M,N,T>& matrix, int);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Calculates sum of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator+(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Add scalar to matrix and return copy.
 * @param matrix Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator+(T scalar, const Matrix<M,N,T>& matrix);

/**
 * Add scalar to matrix components.
 * @param matrix Vector to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Add matrix B to matrix A.
 * @param A Vector to add to.
 * @param B Vector to add.
 * @return The result of adding.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Get a negated copy of the matrix.
 * @param matrix Vector to negate.
 * @return A negated copy of the matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix);

/**
 * Calculates difference of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Subtract scalar from each matrix component and return copy.
 * @param matrix Vector to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Subtract scalar from each matrix component.
 * @param matrix Vector to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Subtract matrix B from matrix A.
 * @param A Vector to subtract from.
 * @param B Vector to subtract.
 * @return The result of subtraction.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Component wise multiplication */
/* ####################################################################################### */

/**
 * Calculates component wise multiplication of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator*(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Multiply scalar to each matrix component and return copy.
 * @param matrix Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator*(T scalar, const Matrix<M,N,T>& matrix);

/**
 * Multiply scalar to each matrix component.
 * @param matrix Vector to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Multiply component wise matrix A by matrix B.
 * @param A Vector to multiply to.
 * @param B Vector to multiply.
 * @return The result of multiplication.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Calculates component wise division of two matrix.
 * @param A Left matrix.
 * @param B Right matrix.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator/(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Vector to division to.
 * @param scalar Value to division.
 * @return New copy of the result matrix.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Divide each matrix component by a scalar and return copy.
 * @param matrix Vector to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, T scalar);

/**
 * Divide component wise matrix A by matrix B.
 * @param A Vector to division to.
 * @param B Vector to division.
 * @return The result of division.
 */
template<size_t M, size_t N, typename T=FLOAT>
Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Comparison with scalar */
/* ####################################################################################### */

/**
 * Checking the components of a matrix for equality with a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are equal to scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator==(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checking the components of a matrix for inequality with a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are not equal to scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator!=(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are less than a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are less than scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator<(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are greater than a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are greater than scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator>(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are less or equal to a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are less or equal to a scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator<=(const Matrix<M,N,T>& matrix, T scalar);

/**
 * Checks if all components of a matrix are greater or equal to a scalar.
 * @param matrix Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the matrix are greater or equal to a scalar, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator>=(const Matrix<M,N,T>& matrix, T scalar);

/* ####################################################################################### */
/* Comparison with other */
/* ####################################################################################### */

/**
 * Check against another matrix for equality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the matrix are equal, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator==(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Check against another matrix for inequality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the matrices are not equal, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator!=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are smaller than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A matrix components less than B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator<(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are larger than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A matrix components less or equal B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator<=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are smaller (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A matrix components greater than B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator>(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/**
 * Compares whether all the components of this matrix are larger (or equal) than other.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if A matrix components greater or equal B matrix components, false otherwise.
 */
template<size_t M, size_t N, typename T=FLOAT>
bool
operator>=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B);

/* ####################################################################################### */
/* Stream output */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const Matrix<M,N,T>& vec);





/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */





/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator++(Matrix<M,N,T>& matrix)
{
    for (auto i = 0; i < D; ++i) ++(matrix.data[i]);
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator--(Matrix<M,N,T>& matrix)
{
    for (auto i = 0; i < D; ++i) --(matrix.data[i]);
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator++(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) ++(matrix.data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator--(Matrix<M,N,T>& matrix, int)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) --(matrix.data[i]);
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Plus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator+(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] += B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator+(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator+(T scalar, const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] += scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) matrix.data[i] += scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator+=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] += B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Minus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] = -copy.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] -= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator-(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] -= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) matrix.data[i] -= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator-=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] -= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise multiplication */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator*(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] *= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator*(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator*(T scalar, const Matrix<M,N,T>& matrix)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] *= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) matrix.data[i] *= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator*=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] *= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Component wise division */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator/(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    Matrix<M,N,T> copy {A};
    for (auto i = 0; i < D; ++i) copy.data[i] /= B.data[i];
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
operator/(const Matrix<M,N,T>& matrix, T scalar)
{
    Matrix<M,N,T> copy {matrix};
    for (auto i = 0; i < D; ++i) copy.data[i] /= scalar;
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) matrix.data[i] /= scalar;
    return matrix;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
operator/=(Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) A.data[i] /= B.data[i];
    return A;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
bool
operator==(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (notEqual(matrix.data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator!=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (notEqual(matrix.data[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator<(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (matrix.data[i] >= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator>(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (matrix.data[i] <= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator<=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (matrix.data[i] > scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator>=(const Matrix<M,N,T>& matrix, T scalar)
{
    for (auto i = 0; i < D; ++i) if (matrix.data[i] < scalar) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
bool
operator==(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (notEqual(A.data[i], B.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator!=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (notEqual(A.data[i], B.data[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator<(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] >= B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator>(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] <= B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator<=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] > B.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
operator>=(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
{
    for (auto i = 0; i < D; ++i) if (A.data[i] < B.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

template<typename TOut, size_t D, typename T>
TOut
operator|(const Matrix<M,N,T>& A, const Matrix<M,N,T>& B)
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

template<size_t M, size_t N, typename T>
std::ostream&
operator << (std::ostream& stream, const Matrix<M,N,T>& vec)
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

#endif // MATH3D_MATRIX_OPERATORS_HPP
