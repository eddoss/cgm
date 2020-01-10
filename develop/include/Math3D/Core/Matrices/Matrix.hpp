#ifndef MATH3D_MATRIX_HPP
#define MATH3D_MATRIX_HPP


#include <Math3D/Core/Vector.hpp>
#include <Math3D/Core/Matrices/Iterators/Default.hpp>
#include <Math3D/Core/Matrices/Iterators/Row.hpp>
#include <Math3D/Core/Matrices/Iterators/Column.hpp>
#include <Math3D/Core/Matrices/Subiterators/Default.hpp>
//#include <Math3D/Core/Matrices/Subiterators/Row.hpp>
//#include <Math3D/Core/Matrices/Subiterators/Column.hpp>


/**
 * A column-major generic matrix.
 * @tparam M Row count. It must be > 1.
 * @tparam N Column count. It must be > 1.
 */
template<size_t M, size_t N, typename T=FLOAT>
struct Matrix
{
    T data[N][M];

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type         = size_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;

/* ####################################################################################### */
public: /* Iterators typedefs */
/* ####################################################################################### */

    using iterator                      = MatrixIterator<M,N,T>;
    using const_iterator                = ConstMatrixIterator<M,N,T>;
    using reverse_iterator              = std::reverse_iterator<iterator>;
	using const_reverse_iterator        = std::reverse_iterator<const_iterator>;

/* --------------------------------------------------------------------------------------- */

    using RowIterator                   = MatrixRowIterator<M,N,T>;
    using ConstRowIterator              = ConstMatrixRowIterator<M,N,T>;
    using ReverseRowIterator            = std::reverse_iterator<RowIterator>;
	using ConstReverseRowIterator       = std::reverse_iterator<ConstRowIterator>;

/* --------------------------------------------------------------------------------------- */

    using ColumnIterator                = MatrixColumnIterator<M,N,T>;
    using ConstColumnIterator           = ConstMatrixColumnIterator<M,N,T>;
    using ReverseColumnIterator         = std::reverse_iterator<ColumnIterator>;
	using ConstReverseColumnIterator    = std::reverse_iterator<ConstColumnIterator>;

/* --------------------------------------------------------------------------------------- */

    using SubIterator                   = SubmatrixIterator<M,N,T>;
    using ConstSubIterator              = ConstSubmatrixIterator<M,N,T>;
    using ReverseSubIterator            = std::reverse_iterator<SubIterator>;
    using ConstReverseSubIterator       = std::reverse_iterator<ConstSubIterator>;
    using SubRect                       = typename ConstSubIterator::SubRect;

/* ####################################################################################### */
public: /* Row and column typedefs */
/* ####################################################################################### */

    using Row       = Vector<N,T>;
    using Column    = Vector<M,T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    /**
     * Rows count.
     */
    static constexpr const size_type
    rows {M};

    /**
     * Columns count.
     */
    static constexpr const size_type
    columns {N};

    /**
     * Components count.
     */
    static constexpr const size_type
    size {M*N};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing all components to a single value.
     * @param value Value to set all components to.
     */
    explicit
    Matrix(T scalar);

    /**
     * Constructor using initial values for each component.
     * @param values Component values.
     */
    explicit
    Matrix(const T* values);

    /**
     * Constructor initializing all components.
     * @param value Value to set all components to.
     */
    Matrix(std::initializer_list<T> values);

    /**
     * Default constructor.
     */
    Matrix();

    /**
     * Default copy constructor.
     */
    Matrix(const Matrix<M,N,T>&) = default;

    /**
     * Default move constructor.
     */
    Matrix(Matrix<M,N,T>&&) noexcept = default;

    /**
     * Default destructor.
     */
    ~Matrix() = default;

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /** Assigns all components single value */
    Matrix<M,N,T>&
    operator=(T scalar);

    /**
     * Default copy assignment.
     */
    Matrix<M,N,T>&
    operator=(const Matrix<M,N,T>&) = default;

    /**
     * Default move assignment.
     */
    Matrix<M,N,T>&
    operator=(Matrix<M,N,T>&&) noexcept = default;

/* ####################################################################################### */
public: /* Unary minus */
/* ####################################################################################### */

    /**
     * Get a copy of the matrix, the components of which were multiplied by -1.
     * @return A "negated" copy of the matrix.
     */
    Matrix<M,N,T>
    operator-() const;

/* ####################################################################################### */
public: /* Increment and decrement */
/* ####################################################################################### */

    /** Prefix increment all components of this matrix. */
    Matrix<M,N,T>&
    operator++();

    /** Prefix decrement all components of this matrix. */
    Matrix<M,N,T>&
    operator--();

    /** Postfix increment all components of this matrix. */
    Matrix<M,N,T>
    operator++(int);

    /** Postfix decrement all components of this matrix. */
    Matrix<M,N,T>
    operator--(int);

/* ####################################################################################### */
public: /* Arithmetic operators: minus */
/* ####################################################################################### */

    /**
     * Gets the result of subtracting from each component of the matrix.
     * @param scalar How much to subtract from each component.
     * @return The result of subtraction.
     */
    Matrix<M,N,T>
    operator-(T scalar) const;

    /**
     * Gets the result of component-wise subtraction of this by other matrix.
     * @param matrix The other matrix to subtract from this.
     * @return The result of matrix subtraction.
     */
    Matrix<M,N,T>
    operator-(const Matrix<M,N,T>& matrix) const;

    /**
     * Subtracts scalar from this. Uses component-wise subtraction.
     * @param scalar How much to subtract from each component.
     * @return Copy of the matrix after subtraction.
     */
    Matrix<M,N,T>&
    operator-=(T scalar);

    /**
     * Subtracts another matrix from this. Uses component-wise subtraction.
     * @param matrix The other matrix to subtract from this.
     * @return Copy of the matrix after subtraction.
     */
    Matrix<M,N,T>&
    operator-=(const Matrix<M,N,T>& matrix);

/* ####################################################################################### */
public: /* Arithmetic operators: binary plus */
/* ####################################################################################### */

    /**
     * Gets the result of adding to each component of the vector.
     * @param scalar How much add to each component.
     * @return The result of adding.
     */
    Matrix<M,N,T>
    operator+(T scalar) const;

    /**
     * Gets the result of component-wise adding of this by other vector.
     * @param vector The matrix to add to this.
     * @return The result of matrices adding.
     */
    Matrix<M,N,T>
    operator+(const Matrix<M,N,T>& matrix) const;

    /**
     * Gets the result of adding to each component of the vector.
     * @param scalar How much add to each component.
     * @return The result of adding.
     */
    Matrix<M,N,T>&
    operator+=(T scalar);

    /**
     * Gets the result of component-wise adding of this by other vector.
     * @param vector The matrix to add to this.
     * @return The result of matrices adding.
     */
    Matrix<M,N,T>&
    operator+=(const Matrix<M,N,T>& matrix);

/* ####################################################################################### */
public: /* Arithmetic operators: multiplication */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise multiplication of this matrix by scalar.
     * @param scalar The value to multiply this by.
     * @return The result of the multiplication.
     */
    Matrix<M,N,T>
    operator*(T scalar) const;

    /**
     * Gets the result of component-wise multiplication of this matrix by scalar.
     * @param scalar The value to multiply this by.
     * @return The result of the multiplication.
     */
    Matrix<M,N,T>&
    operator*=(T scalar);

/* ####################################################################################### */
public: /* Arithmetic operators: division */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise division of this matrix by scalar.
     * @param scalar The value to divide this by.
     * @return The result of the division.
     */
    Matrix<M,N,T>
    operator/(T scalar) const;

    /**
     * Gets the result of component-wise division of this matrix by scalar.
     * @param scalar The value to divide this by.
     * @return The result of the division.
     */
    Matrix<M,N,T>&
    operator/=(T scalar);

/* ####################################################################################### */
public: /* Comparison with scalar */
/* ####################################################################################### */

    /**
     * Checking the components of a matrix for equality with a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are equal to scalar, false otherwise.
     */
    bool
    operator==(const T& scalar) const;

    /**
     * Checking the components of a matrix for inequality with a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are not equal to scalar, false otherwise.
     */
    bool
    operator!=(const T& scalar) const;

    /**
     * Checks if all components of a matrix are less than a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are less than scalar, false otherwise.
     */
    bool
    operator<(const T& scalar) const;

    /**
     * Checks if all components of a matrix are greater than a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are greater than scalar, false otherwise.
     */
    bool
    operator>(const T& scalar) const;

    /**
     * Checks if all components of a matrix are less or equal to a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are less or equal to a scalar, false otherwise.
     */
    bool
    operator<=(const T& scalar) const;

    /**
     * Checks if all components of a matrix are greater or equal to a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the matrix are greater or equal to a scalar, false otherwise.
     */
    bool
    operator>=(const T& scalar) const;

/* ####################################################################################### */
public: /* Comparison with other */
/* ####################################################################################### */

    /**
     * Check against another matrix for equality.
     * @param matrix The matrix to check against.
     * @return true if the matrices are equal, false otherwise.
     */
    bool
    operator==(const Matrix<M,N,T>& matrix) const;

    /**
     * Check against another matrix for inequality.
     * @param matrix The matrices to check against.
     * @return true if the matrices are not equal, false otherwise.
     */
    bool
    operator!=(const Matrix<M,N,T>& matrix) const;

    /**
     * Per component compares the matrices.
     * @param matrix The compared matrix.
     * @return true if all components of this the matrix is less, false otherwise.
     */
    bool
    operator<(const Matrix<M,N,T>& matrix) const;

    /**
     * Per component compares the matrices.
     * @param matrix The compared matrix.
     * @return true if all components of this the matrix is greater, false otherwise.
     */
    bool
    operator>(const Matrix<M,N,T>& matrix) const;

    /**
     * Per component compares the matrices.
     * @param matrix The compared matrix.
     * @return true if all components of this the matrix is less or equal, false otherwise.
     */
    bool
    operator<=(const Matrix<M,N,T>& matrix) const;

    /**
     * Per component compares the matrices.
     * @param matrix The compared matrix.
     * @return true if all components of this the matrix is greater or equal, false otherwise.
     */
    bool
    operator>=(const Matrix<M,N,T>& matrix) const;

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return reference to a component.
     */
    T&
    operator()(size_t row, size_t column);

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix
     * @param column Column of matrix
     * @return const reference to a component.
     */
    const T&
    operator()(size_t row, size_t column) const;

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @param index Index of component.
     * @return reference to a component.
     */
    T&
    operator[](size_t index);

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @param index Index of component.
     * @return const reference to a component.
     */
    const T&
    operator[](size_t index) const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component.
     */
    iterator
    begin();

    /**
     * Get an iterator pointing to the component after the last.
     */
    iterator
    end();

    /**
     * Get an const iterator pointing to the first component.
     */
    const_iterator
    begin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    const_iterator
    end() const;

    /**
     * Get an const iterator pointing to the first component.
     */
    const_iterator
    cbegin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    const_iterator
    cend() const;

    /**
     * Get an iterator pointing to the last component.
     */
    reverse_iterator
    rbegin();

    /**
     * Get an iterator pointing to the component before the first.
     */
    reverse_iterator
    rend();

    /**
     * Get an const iterator pointing to the last component.
     */
    const_reverse_iterator
    rbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    const_reverse_iterator
    rend() const;

    /**
     * Get an const iterator pointing to the last component.
     */
    const_reverse_iterator
    crbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    const_reverse_iterator
    crend() const;

/* ####################################################################################### */
public: /* Column iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component in the specified column.
     */
    ColumnIterator
    beginColumn(size_type column);

    /**
     * Get an iterator pointing to the component after the last in specified column.
     */
    ColumnIterator
    endColumn(size_type column);

    /**
     * Get an const iterator pointing to the first component in the specified column.
     */
    ConstColumnIterator
    beginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */
    ConstColumnIterator
    endColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the first component in the specified column.
     */
    ConstColumnIterator
    cbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */
    ConstColumnIterator
    cendColumn(size_type column) const;

    /**
     * Get an iterator pointing to the last component in the specified column.
     */
    ReverseColumnIterator
    rbeginColumn(size_type column);

    /**
     * Get an iterator pointing to the component before the first in the specified column.
     */
    ReverseColumnIterator
    rendColumn(size_type column);

    /**
     * Get an const iterator pointing to the last component in the specified column.
     */
    ConstReverseColumnIterator
    rbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */
    ConstReverseColumnIterator
    rendColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the last component in the specified column.
     */
    ConstReverseColumnIterator
    crbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */
    ConstReverseColumnIterator
    crendColumn(size_type column) const;

/* ####################################################################################### */
public: /* Row iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component in the specified row.
     */
    RowIterator
    beginRow(size_type row);

    /**
     * Get an iterator pointing to the component after the last in specified row.
     */
    RowIterator
    endRow(size_type row);

    /**
     * Get an const iterator pointing to the first component in the specified row.
     */
    ConstRowIterator
    beginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */
    ConstRowIterator
    endRow(size_type row) const;

    /**
     * Get an const iterator pointing to the first component in the specified row.
     */
    ConstRowIterator
    cbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */
    ConstRowIterator
    cendRow(size_type row) const;

    /**
     * Get an iterator pointing to the last component in the specified row.
     */
    ReverseRowIterator
    rbeginRow(size_type row);

    /**
     * Get an iterator pointing to the component before the first in the specified row.
     */
    ReverseRowIterator
    rendRow(size_type row);

    /**
     * Get an const iterator pointing to the last component in the specified row.
     */
    ConstReverseRowIterator
    rbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */
    ConstReverseRowIterator
    rendRow(size_type row) const;

    /**
     * Get an const iterator pointing to the last component in the specified row.
     */
    ConstReverseRowIterator
    crbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */
    ConstReverseRowIterator
    crendRow(size_type row) const;

/* ####################################################################################### */
public: /* Sub iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component in the specified submatrix.
     */
    SubIterator
    beginSub(const SubRect& subRect);

    /**
     * Get an iterator pointing to the component after the last in specified submatrix.
     */
    SubIterator
    endSub(const SubRect& subRect);

    /**
     * Get an const iterator pointing to the first component in the specified submatrix.
     */
    ConstSubIterator
    beginSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified submatrix.
     */
    ConstSubIterator
    endSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the first component in the specified submatrix.
     */
    ConstSubIterator
    cbeginSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified submatrix.
     */
    ConstSubIterator
    cendSub(const SubRect& subRect) const;

    /**
     * Get an iterator pointing to the last component in the specified submatrix.
     */
    ReverseSubIterator
    rbeginSub(const SubRect& subRect);

    /**
     * Get an iterator pointing to the component before the first in the specified submatrix.
     */
    ReverseSubIterator
    rendSub(const SubRect& subRect);

    /**
     * Get an const iterator pointing to the last component in the specified submatrix.
     */
    ConstReverseSubIterator
    rbeginSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified submatrix.
     */
    ConstReverseSubIterator
    rendSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the last component in the specified submatrix.
     */
    ConstReverseSubIterator
    crbeginSub(const SubRect& subRect) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified submatrix.
     */
    ConstReverseSubIterator
    crendSub(const SubRect& subRect) const;
};


/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      IMPLEMENTATION      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */


/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix()
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix(T scalar)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] = scalar;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix(std::initializer_list<T> values)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] = *(values.begin() + r * N + c);
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix(const T *values)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] = *(values + r * N + c);
        }
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator=(T scalar)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] = scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Unary minus, increment and decrement  */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-() const
{
    Matrix<M,N,T> copy;
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] = -(data[c][r]);
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator++()
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            ++(data[c][r]);
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator--()
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            --(data[c][r]);
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator++(int)
{
    Matrix<M,N,T> copy;
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            ++(data[c][r]);
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator--(int)
{
    Matrix<M,N,T> copy;
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            --(data[c][r]);
        }
    }
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: binary minus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] -= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-(const Matrix<M,N,T>& matrix) const
{
    Matrix<M,N,T> copy( *this );
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] -= matrix.data[c][r];
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator-=(T scalar)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] -= scalar;
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator-=(const Matrix<M,N,T>& matrix)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] -= matrix.data[c][r];
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: binary plus */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator+(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] += scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator+(const Matrix<M,N,T>& matrix) const
{
    Matrix<M,N,T> copy( *this );
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] += matrix.data[c][r];
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator+=(T scalar)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] += scalar;
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator+=(const Matrix<M,N,T>& matrix)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] += matrix.data[c][r];
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: multiplication */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator*(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] *= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator*=(T scalar)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] *= scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: division */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator/(T scalar) const
{
    Matrix<M,N,T> copy {*this};
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            copy.data[c][r] /= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator/=(T scalar)
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            data[c][r] /= scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator==(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], scalar)) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator!=(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], scalar)) return true;
        }
    }
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator<(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] >= scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator>(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] <= scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator<=(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] > scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator>=(const T& scalar) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] < scalar) return false;
        }
    }
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator==(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], matrix.data[c][r])) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator!=(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], matrix.data[c][r])) return true;
        }
    }
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator<(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] >= matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator>(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] <= matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator<=(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] > matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
bool
Matrix<M,N,T>::operator>=(const Matrix<M,N,T>& matrix) const
{
    for (size_t c = 0; c < N; ++c)
    {
        for (size_t r = 0; r < M; ++r)
        {
            if (data[c][r] < matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
T&
Matrix<M,N,T>::operator()(size_t row, size_t column)
{
    return data[column][row];
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
const T&
Matrix<M,N,T>::operator()(size_t row, size_t column) const
{
    return data[column][row];
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
T&
Matrix<M,N,T>::operator[](size_t index)
{
    return *(&data[0][0] + index);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
const T&
Matrix<M,N,T>::operator[](size_t index) const
{
    return *(&data[0][0] + index);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::begin()
{
    return iterator {&data[0][0], 0, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::end()
{
    return iterator {&data[0][0], M, N-1};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::begin() const
{
    return const_iterator {&data[0][0], 0, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::end() const
{
    return const_iterator {&data[0][0], M, N-1};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cbegin() const
{
    return const_iterator {&data[0][0], 0, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cend() const
{
    return const_iterator {&data[0][0], M, N-1};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::reverse_iterator
Matrix<M,N,T>::rbegin()
{
    return reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::reverse_iterator
Matrix<M,N,T>::rend()
{
    return reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::rbegin() const
{
    return const_reverse_iterator {cend()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::rend() const
{
    return const_reverse_iterator {cbegin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::crbegin() const
{
    return const_reverse_iterator {cend()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::crend() const
{
    return const_reverse_iterator {cbegin()};
}

/* ####################################################################################### */
/* Column iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ColumnIterator
Matrix<M,N,T>::beginColumn(size_type column)
{
    return ColumnIterator(&data[0][0], column, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ColumnIterator
Matrix<M,N,T>::endColumn(size_type column)
{
    return ColumnIterator(&data[0][0], column, M);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::beginColumn(size_type column) const
{
    return ConstColumnIterator(&data[0][0], column, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::endColumn(size_type column) const
{
    return ConstColumnIterator(&data[0][0], column, M);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::cbeginColumn(size_type column) const
{
    return ConstColumnIterator(&data[0][0], column, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::cendColumn(size_type column) const
{
    return ConstColumnIterator(&data[0][0], column, M);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseColumnIterator
Matrix<M,N,T>::rbeginColumn(size_type column)
{
    return ReverseColumnIterator(endColumn(column));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseColumnIterator
Matrix<M,N,T>::rendColumn(size_type column)
{
    return ReverseColumnIterator(beginColumn(column));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::rbeginColumn(size_type column) const
{
    return ConstReverseColumnIterator(endColumn(column));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::rendColumn(size_type column) const
{
    return ConstReverseColumnIterator(beginColumn(column));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::crbeginColumn(size_type column) const
{
    return ConstReverseColumnIterator(cendColumn(column));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::crendColumn(size_type column) const
{
    return ConstReverseColumnIterator(cbeginColumn(column));
}

/* ####################################################################################### */
/* Row iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::RowIterator
Matrix<M,N,T>::beginRow(size_type row)
{
    return RowIterator(&data[0][0], row, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::RowIterator
Matrix<M,N,T>::endRow(size_type row)
{
    return RowIterator(&data[0][0], row, N);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::beginRow(size_type row) const
{
    return ConstRowIterator(&data[0][0], row, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::endRow(size_type row) const
{
    return ConstRowIterator(&data[0][0], row, N);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::cbeginRow(size_type row) const
{
    return ConstRowIterator(&data[0][0], row, 0);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::cendRow(size_type row) const
{
    return ConstRowIterator(&data[0][0], row, N);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseRowIterator
Matrix<M,N,T>::rbeginRow(size_type row)
{
    return ReverseRowIterator(endRow(row));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseRowIterator
Matrix<M,N,T>::rendRow(size_type row)
{
    return ReverseRowIterator(beginRow(row));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::rbeginRow(size_type row) const
{
    return ConstReverseRowIterator(endRow(row));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::rendRow(size_type row) const
{
    return ConstReverseRowIterator(beginRow(row));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::crbeginRow(size_type row) const
{
    return ConstReverseRowIterator(cendRow(row));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::crendRow(size_type row) const
{
    return ConstReverseRowIterator(cbeginRow(row));
}

/* ####################################################################################### */
/* Sub iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::SubIterator
Matrix<M,N,T>::beginSub(const Matrix::SubRect& subRect)
{
    return SubIterator
    {
        &data[0][0],
        subRect,
        0,
        0
    };
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::SubIterator
Matrix<M,N,T>::endSub(const Matrix::SubRect& subRect)
{
    return ++SubIterator
    {
        &data[0][0],
        subRect,
        subRect.second.first - subRect.first.first,
        subRect.second.second - subRect.first.second
    };
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstSubIterator
Matrix<M,N,T>::beginSub(const Matrix::SubRect& subRect) const
{
    return ConstSubIterator
    {
        &data[0][0],
        subRect,
        0,
        0
    };
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstSubIterator
Matrix<M,N,T>::endSub(const Matrix::SubRect& subRect) const
{
    return ++ConstSubIterator
    {
        &data[0][0],
        subRect,
        subRect.second.first - subRect.first.first,
        subRect.second.second - subRect.first.second
    };
}


/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstSubIterator
Matrix<M,N,T>::cbeginSub(const Matrix::SubRect& subRect) const
{
    return ConstSubIterator
            {
                    &data[0][0],
                    subRect,
                    0,
                    0
            };
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstSubIterator
Matrix<M,N,T>::cendSub(const Matrix::SubRect& subRect) const
{
    return ++ConstSubIterator
    {
        &data[0][0],
        subRect,
        subRect.second.first - subRect.first.first,
        subRect.second.second - subRect.first.second
    };
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseSubIterator
Matrix<M,N,T>::rbeginSub(const SubRect& subRect)
{
    return ReverseSubIterator(endSub(subRect));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseSubIterator
Matrix<M,N,T>::rendSub(const SubRect& subRect)
{
    return ReverseSubIterator(beginSub(subRect));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseSubIterator
Matrix<M,N,T>::rbeginSub(const SubRect& subRect) const
{
    return ConstReverseSubIterator(endSub(subRect));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseSubIterator
Matrix<M,N,T>::rendSub(const SubRect& subRect) const
{
    return ConstReverseSubIterator(beginSub(subRect));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseSubIterator
Matrix<M,N,T>::crbeginSub(const SubRect& subRect) const
{
    return ConstReverseSubIterator(endSub(subRect));
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseSubIterator
Matrix<M,N,T>::crendSub(const SubRect& subRect) const
{
    return ConstReverseSubIterator(beginSub(subRect));
}

#endif // MATH3D_MATRIX_HPP
