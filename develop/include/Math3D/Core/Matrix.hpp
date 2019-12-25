#ifndef MATH3D_MATRIX_HPP
#define MATH3D_MATRIX_HPP



#include <Math3D/Core/Vector.hpp>


/**
 * A column-major generic matrix.
 * @tparam M Row count. It must be > 1.
 * @tparam N Column count. It must be > 1.
 **/
template<uint32_t M, uint32_t N, typename T=FLOAT>
struct Matrix
{
    T data[N][M];

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type         = uint32_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;

/* ####################################################################################### */
public: /* Iterator typedefs */
/* ####################################################################################### */

    using iterator          = RandomAccessIterator<T>;
    using const_iterator    = ConstRandomAccessIterator<T>;

/* ####################################################################################### */
public: /* Row and column typedefs */
/* ####################################################################################### */

    using Row       = Vector<M,T>;
    using Column    = Vector<N,T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    /**
     * Rows count.
     **/
    static constexpr const size_type
    rows {M};

    /**
     * Columns count.
     **/
    static constexpr const size_type
    columns {N};

    /**
     * Components count.
     **/
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
     **/
    Matrix();

    /**
     * Default copy constructor.
     **/
    Matrix(const Matrix<M,N,T>&) = default;

    /**
     * Default move constructor.
     **/
    Matrix(Matrix<M,N,T>&&) noexcept = default;

    /**
     * Default destructor.
     **/
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
    operator()(uint32_t row, uint32_t column);

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix
     * @param column Column of matrix
     * @return const reference to a component.
     */
    const T&
    operator()(uint32_t row, uint32_t column) const;

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @param index Index of component.
     * @return reference to a component.
     */
    T&
    operator[](uint32_t index);

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @param index Index of component.
     * @return const reference to a component.
     */
    const T&
    operator[](uint32_t index) const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get begin component iterator.
     * @return first component iterator.
     */
    iterator
    begin();

    /**
     * Get end component iterator.
     * @return last+1 component iterator.
     */
    iterator
    end();

    /**
     * Get first component const iterator.
     * @return first component const iterator.
     */
    const_iterator
    begin() const;

    /**
     * Get end component const iterator.
     * @return last+1 component const iterator.
     */
    const_iterator
    end() const;

    /**
     * Get first component const iterator.
     * @return first component const iterator.
     */
    const_iterator
    cbegin() const;

    /**
     * Get end component const iterator.
     * @return last+1 component const iterator.
     */
    const_iterator
    cend() const;
};


/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      IMPLEMENTATION      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */


/* ####################################################################################### */
/* IMPLEMENTATION | Constructors */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>::Matrix()
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>::Matrix(T scalar)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] = scalar;
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>::Matrix(std::initializer_list<T> values)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] = *(values.begin() + r * N + c);
        }
    }
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>::Matrix(const T *values)
{
    static_assert(M > 1 && N > 1, __FUNCTION__"(): rows and columns size must be greater than 1");

    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] = *(values + r * N + c);
        }
    }
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator=(T scalar)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] = scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Unary minus, increment and decrement  */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-() const
{
    Matrix<M,N,T> copy;
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] = -(data[c][r]);
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator++()
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            ++(data[c][r]);
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator--()
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            --(data[c][r]);
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator++(int)
{
    Matrix<M,N,T> copy;
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            ++(data[c][r]);
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator--(int)
{
    Matrix<M,N,T> copy;
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            --(data[c][r]);
        }
    }
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: binary minus */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] -= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator-(const Matrix<M,N,T>& matrix) const
{
    Matrix<M,N,T> copy( *this );
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] -= matrix.data[c][r];
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator-=(T scalar)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] -= scalar;
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator-=(const Matrix<M,N,T>& matrix)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] -= matrix.data[c][r];
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: binary plus */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator+(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] += scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator+(const Matrix<M,N,T>& matrix) const
{
    Matrix<M,N,T> copy( *this );
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] += matrix.data[c][r];
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator+=(T scalar)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] += scalar;
        }
    }
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator+=(const Matrix<M,N,T>& matrix)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] += matrix.data[c][r];
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: multiplication */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator*(T scalar) const
{
    Matrix<M,N,T> copy( *this );
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] *= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator*=(T scalar)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] *= scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: division */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>
Matrix<M,N,T>::operator/(T scalar) const
{
    Matrix<M,N,T> copy {*this};
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            copy.data[c][r] /= scalar;
        }
    }
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator/=(T scalar)
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            data[c][r] /= scalar;
        }
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator==(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], scalar)) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator!=(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], scalar)) return true;
        }
    }
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator<(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] >= scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator>(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] <= scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator<=(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] > scalar) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator>=(const T& scalar) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] < scalar) return false;
        }
    }
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator==(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], matrix.data[c][r])) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator!=(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (notEqual(data[c][r], matrix.data[c][r])) return true;
        }
    }
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator<(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] >= matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator>(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] <= matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator<=(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] > matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
bool
Matrix<M,N,T>::operator>=(const Matrix<M,N,T>& matrix) const
{
    for (uint32_t c = 0; c < N; ++c)
    {
        for (uint32_t r = 0; r < M; ++r)
        {
            if (data[c][r] < matrix.data[c][r]) return false;
        }
    }
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
T&
Matrix<M,N,T>::operator()(uint32_t row, uint32_t column)
{
    return data[column][row];
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
const T&
Matrix<M,N,T>::operator()(uint32_t row, uint32_t column) const
{
    return data[column][row];
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
T&
Matrix<M,N,T>::operator[](uint32_t index)
{
    return *(&data[0][0] + index);
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t M, uint32_t N, typename T>
const T&
Matrix<M,N,T>::operator[](uint32_t index) const
{
    return *(&data[0][0] + index);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::begin()
{
    return iterator {&data[0][0]};
}

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::end()
{
    return iterator {&data[0][0]+M*N};
}

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::begin() const
{
    return const_iterator {&data[0][0]};
}

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::end() const
{
    return const_iterator {&data[0][0] + M*N};
}

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cbegin() const
{
    return const_iterator {&data[0][0]};
}

template<uint32_t M, uint32_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cend() const
{
    return const_iterator {&data[0][0] + M*N};
}

#endif // MATH3D_MATRIX_HPP
