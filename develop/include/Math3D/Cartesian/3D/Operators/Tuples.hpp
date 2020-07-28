#ifndef MATH3D_XYZ_OPERATORS_TUPLES_HPP
#define MATH3D_XYZ_OPERATORS_TUPLES_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Cartesian/3D/Types/Typedefs.hpp>
#include <Math3D/Cartesian/3D/Functions/Utils.hpp>


/* ####################################################################################### */
/* AxesTuple: outplace multiplication */
/* ####################################################################################### */

/**
 * Multiply orientation axes by 3D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Vector<3,T>& vector);

/**
 * Multiply orientation axes by 4D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Vector<4,T>& vector);

/**
 * Multiply orientation axes by 3x3 orientation matrix (apply orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param matrix Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix);

/**
 * Multiply orientation axes by 4x4 space matrix (apply space orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param matrix Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix);

/**
 * Multiply orientation axes by other (apply orientation to axes).
 * @param A Orientation axes to multiply.
 * @param B Orientation axes to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& A, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& B);

/**
 * Multiply orientation axes by space (apply space orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param space Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply orientation axes by 3D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>
operator * (const MATH3D_NAMESPACE::Vector<3,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation axes by 4D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>
operator * (const MATH3D_NAMESPACE::Vector<4,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation matrix by orientation axes (apply orientation to axes).
 * @param matrix Orientation matrix to multiply.
 * @param axes Orientation axes to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<3,3,T>
operator * (const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation matrix by orientation axes (apply orientation to axes).
 * @param matrix Orientation matrix to multiply.
 * @param axes Orientation axes to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<4,4,T>
operator * (const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/* ####################################################################################### */
/* AxesTuple: inplace multiplication */
/* ####################################################################################### */

/**
 * Multiply orientation axes by 3x3 orientation matrix (apply orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param matrix Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix);

/**
 * Multiply orientation axes by 4x4 space matrix (apply space orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param matrix Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix);

/**
 * Multiply orientation axes by other (apply orientation to axes).
 * @param A Orientation axes to multiply.
 * @param B Orientation axes to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& A, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& B);

/**
 * Multiply orientation axes by space (apply space orientation to axes).
 * @param axes Orientation axes to multiply.
 * @param space Matrix to multiply to.
 * @return Oriented axes.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply orientation axes by 3D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>&
operator *= (MATH3D_NAMESPACE::Vector<3,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation axes by 4D vector (apply orientation to vector).
 * @param axes Orientation axes to multiply.
 * @param vector Vector to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>&
operator *= (MATH3D_NAMESPACE::Vector<4,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation matrix by orientation axes (apply orientation to axes).
 * @param matrix Orientation matrix to multiply.
 * @param axes Orientation axes to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<3,3,T>&
operator *= (MATH3D_NAMESPACE::Matrix<3,3,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply orientation matrix by orientation axes (apply orientation to axes).
 * @param matrix Orientation matrix to multiply.
 * @param axes Orientation axes to multiply to.
 * @return Oriented vector.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<4,4,T>&
operator *= (MATH3D_NAMESPACE::Matrix<4,4,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/* ####################################################################################### */
/* SpaceTuple: outplace multiplication */
/* ####################################################################################### */

/**
 * Multiply space tuple by 3D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Vector<3,T>& vector);

/**
 * Multiply space tuple by 4D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Vector<4,T>& vector);

/**
 * Multiply space tuple by 3x3 orientation matrix.
 * @param space Space tuple to multiply.
 * @param matrix Orientation matrix to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix);

/**
 * Multiply space tuple by 4x4 space matrix.
 * @param space Space tuple to multiply.
 * @param matrix Space matrix to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix);

/**
 * Multiply space tuple by orientation axes.
 * @param space Space tuple to multiply.
 * @param axes Orientation axes to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply space tuple by space tuple.
 * @param A Space tuple to multiply.
 * @param B Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>
operator * (const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& A, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& B);

/**
 * Multiply space tuple by 3D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>
operator * (const MATH3D_NAMESPACE::Vector<3,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply space tuple by 4D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>
operator * (const MATH3D_NAMESPACE::Vector<4,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply 3x3 orientation matrix by space tuple.
 * @param matrix Orientation matrix to multiply.
 * @param space Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<3,3,T>
operator * (const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply 4x4 space matrix by space tuple.
 * @param matrix Space matrix to multiply.
 * @param space Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<4,4,T>
operator * (const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/* ####################################################################################### */
/* SpaceTuple: inplace multiplication */
/* ####################################################################################### */

/**
 * Multiply space tuple by 3x3 orientation matrix.
 * @param space Space tuple to multiply.
 * @param matrix Orientation matrix to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Matrix<3,3,T>& matrix);

/**
 * Multiply space tuple by 4x4 space matrix.
 * @param space Space tuple to multiply.
 * @param matrix Space matrix to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::Matrix<4,4,T>& matrix);

/**
 * Multiply space tuple by orientation axes.
 * @param space Space tuple to multiply.
 * @param axes Orientation axes to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::AxesTuple<T>& axes);

/**
 * Multiply space tuple by space tuple.
 * @param A Space tuple to multiply.
 * @param B Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>&
operator *= (MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& A, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& B);

/**
 * Multiply space tuple by 3D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<3,T>&
operator *= (MATH3D_NAMESPACE::Vector<3,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply space tuple by 4D vector.
 * @param space Space tuple to multiply.
 * @param vector Vector to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Vector<4,T>&
operator *= (MATH3D_NAMESPACE::Vector<4,T>& vector, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply 3x3 orientation matrix by space tuple.
 * @param matrix Orientation matrix to multiply.
 * @param space Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<3,3,T>&
operator *= (MATH3D_NAMESPACE::Matrix<3,3,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

/**
 * Multiply 4x4 space matrix by space tuple.
 * @param matrix Space matrix to multiply.
 * @param space Space tuple to multiply to.
 */
template <typename T>
MATH3D_NAMESPACE::Matrix<4,4,T>&
operator *= (MATH3D_NAMESPACE::Matrix<4,4,T>& matrix, const MATH3D_NAMESPACE::MATH3D_XYZ_NAMESPACE::SpaceTuple<T>& space);

#endif //MATH3D_XYZ_OPERATORS_TUPLES_HPP
