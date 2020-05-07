#ifndef MATH3D_VECTOR_OPERATORS_HPP
#define MATH3D_VECTOR_OPERATORS_HPP


#include <type_traits>
#include <Math3D/Common.hpp>
#include <Math3D/Core/Vector/Vector.hpp>
#include <Math3D/Core/Matrix/Matrix.hpp>


/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

/**
 * Increase all components of vector by 1 and returns it.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator++(MATH3D_NAMESPACE::Vector<D,T>& vector);

/**
 * Decrease all components of vector by 1 and returns it.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator--(MATH3D_NAMESPACE::Vector<D,T>& vector);

/**
 * Increase all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T=FLOAT>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator++(MATH3D_NAMESPACE::Vector<D,T>& vector, int);

/**
 * Decrease all components of vector by 1 and returns unchanged copy of it.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator--(MATH3D_NAMESPACE::Vector<D,T>& vector, int);

/* ####################################################################################### */
/* Plus */
/* ####################################################################################### */

/**
 * Add scalar to vector components.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return The result of adding.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator+=(MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Add vector B to vector A.
 * @param A Vector to add to.
 * @param B Vector to add.
 * @return The result of adding.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator+=(MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Calculates sum of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T=FLOAT>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator+(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator+(const MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Add scalar to vector and return copy.
 * @param vector Vector to add to.
 * @param scalar Value to add.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator+(TScalar scalar, const MATH3D_NAMESPACE::Vector<D,T>& vector);

/* ####################################################################################### */
/* Minus */
/* ####################################################################################### */

/**
 * Subtract scalar from each vector component.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator-=(MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Subtract vector B from vector A.
 * @param A Vector to subtract from.
 * @param B Vector to subtract.
 * @return The result of subtraction.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator-=(MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Get a negated copy of the vector.
 * @param vector Vector to negate.
 * @return A negated copy of the vector.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator-(const MATH3D_NAMESPACE::Vector<D,T>& vector);

/**
 * Calculates difference of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator-(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Subtract scalar from each vector component and return copy.
 * @param vector Vector to subtract from.
 * @param scalar Value to subtract.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator-(const MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/* ####################################################################################### */
/* Multiplication on matrix */
/* ####################################################################################### */

/**
 * Generic multiplication vector A by matrix B.
 * @tparam D Vector dimensions.
 * @tparam N Matrix rows count.
 * @return If N == 1 return scalar, otherwise return Vector<N>.
 */
template<size_t D, size_t N, typename T>
constexpr std::conditional_t<(N == 1), T, MATH3D_NAMESPACE::Vector<N,T>>
operator * (const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Matrix<D,N,T>& B);

/* ####################################################################################### */
/* Component wise multiplication */
/* ####################################################################################### */

/**
 * Multiply scalar to each vector component.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator*=(MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Multiply component wise vector A by vector B.
 * @param A Vector to multiply to.
 * @param B Vector to multiply.
 * @return The result of multiplication.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator*=(MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Calculates component wise multiplication of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator*(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator*(const MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Multiply scalar to each vector component and return copy.
 * @param vector Vector to multiply to.
 * @param scalar Value to multiply.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator*(TScalar scalar, const MATH3D_NAMESPACE::Vector<D,T>& vector);

/* ####################################################################################### */
/* Component wise division */
/* ####################################################################################### */

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return The result of division.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator/=(MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/**
 * Divide component wise vector A by vector B.
 * @param A Vector to division to.
 * @param B Vector to division.
 * @return The result of division.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>&
operator/=(MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Calculates component wise division of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return New copy of the result vector.
 */
template<size_t D, typename T>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator/(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Divide each vector component by a scalar and return copy.
 * @param vector Vector to division to.
 * @param scalar Value to division.
 * @return New copy of the result vector.
 */
template<size_t D, typename T, typename TScalar>
constexpr MATH3D_NAMESPACE::Vector<D,T>
operator/(const MATH3D_NAMESPACE::Vector<D,T>& vector, TScalar scalar);

/* ####################################################################################### */
/* Comparison with scalar */
/* ####################################################################################### */

/**
 * Checking the components of a vector for equality with a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are equal to scalar, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator==(const MATH3D_NAMESPACE::Vector<D,T>& vector, T scalar);

/**
 * Checking the components of a vector for inequality with a scalar.
 * @param vector Vector to compare.
 * @param scalar Scalar value to compare with.
 * @return true if components of the vector are not equal to scalar, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator!=(const MATH3D_NAMESPACE::Vector<D,T>& vector, T scalar);

/* ####################################################################################### */
/* Comparison with other */
/* ####################################################################################### */

/**
 * Check against another vector for equality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the vectors are equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator==(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/**
 * Check against another vector for inequality.
 * @param A Vector to compare.
 * @param B Vector to compare with.
 * @return true if the vectors are not equal, false otherwise.
 */
template<size_t D, typename T>
constexpr bool
operator!=(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/* ####################################################################################### */
/* Dot product operator */
/* ####################################################################################### */

/**
 * Calculates cross dot of two vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The dot product.
 */
template<size_t D, typename T>
constexpr T
operator|(const MATH3D_NAMESPACE::Vector<D,T>& A, const MATH3D_NAMESPACE::Vector<D,T>& B);

/* ####################################################################################### */
/* Cross product operator */
/* ####################################################################################### */

/**
 * Calculates cross product of 2D vector and 2D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T>
constexpr T
operator^(const MATH3D_NAMESPACE::Vector<2,T>& A, const MATH3D_NAMESPACE::Vector<2,T>& B);

/**
 * Calculates cross product of 3D vector and 3D vectors.
 * @param A Left vector.
 * @param B Right vector.
 * @return The cross product.
 */
template<typename T>
constexpr MATH3D_NAMESPACE::Vector<3,T>
operator^(const MATH3D_NAMESPACE::Vector<3,T>& A, const MATH3D_NAMESPACE::Vector<3,T>& B);


#include <private/Math3D/Core/Vector/Operators.hpp>


#endif // MATH3D_VECTOR_OPERATORS_HPP
