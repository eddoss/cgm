#ifndef MATH3D_MATRIX_HPP
#define MATH3D_MATRIX_HPP


#include <Math3D/Core/Structs/Vectors/Vector.hpp>
#include <Math3D/Core/Structs/Matrices/Iterators/Direct.hpp>
#include <Math3D/Core/Structs/Matrices/Iterators/Indirect.hpp>
//#include <Math3D/Core/Structs/Matrices/Iterators/Column.hpp>
//#include <Math3D/Core/Structs/Matrices/Iterators/Sub.hpp>


/**
 * A column-major generic matrix.
 * @tparam M Row count. It must be > 1.
 * @tparam N Column count. It must be > 1.
 */
template<size_t M, size_t N, typename T=FLOAT>
struct Matrix
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type         = size_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;
    using transposed_type   = Matrix<N,M,T>;

/* ####################################################################################### */
public: /* Iterators typedefs */
/* ####################################################################################### */

    using iterator                      = DirectMatrixIterator<M,N,T>;
    using const_iterator                = ConstDirectMatrixIterator<M,N,T>;
    using reverse_iterator              = std::reverse_iterator<iterator>;
	using const_reverse_iterator        = std::reverse_iterator<const_iterator>;

/* --------------------------------------------------------------------------------------- */

    using IndirectIterator              = IndirectMatrixIterator<M,N,T>;
    using ConstIndirectIterator         = ConstIndirectMatrixIterator<M,N,T>;
    using ReverseIndirectIterator       = std::reverse_iterator<IndirectIterator>;
	using ConstReverseIndirectIterator  = std::reverse_iterator<ConstIndirectIterator>;

///* --------------------------------------------------------------------------------------- */
//
//    using RowIterator                   = MatrixRowIterator<M,N,T>;
//    using ConstRowIterator              = ConstIndirectMatrixIterator<M,N,T>;
//    using ReverseRowIterator            = std::reverse_iterator<RowIterator>;
//	using ConstReverseRowIterator       = std::reverse_iterator<ConstRowIterator>;
//
///* --------------------------------------------------------------------------------------- */
//
//    using ColumnIterator                = MatrixColumnIterator<M,N,T>;
//    using ConstColumnIterator           = ConstMatrixColumnIterator<M,N,T>;
//    using ReverseColumnIterator         = std::reverse_iterator<ColumnIterator>;
//	using ConstReverseColumnIterator    = std::reverse_iterator<ConstColumnIterator>;
//
///* --------------------------------------------------------------------------------------- */
//
//    using SubIterator                   = SubmatrixIterator<M,N,T>;
//    using ConstSubIterator              = ConstSubmatrixIterator<M,N,T>;
//    using ReverseSubIterator            = std::reverse_iterator<SubIterator>;
//    using ConstReverseSubIterator       = std::reverse_iterator<ConstSubIterator>;
//    using SubRect                       = typename ConstSubIterator::SubRect;

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
    rows    {M};

    /**
     * Columns count.
     */
    static constexpr const size_type
    columns {N};

    /**
     * Components count.
     */
    static constexpr const size_type
    size    {M*N};

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
    Matrix()                            = default;

    /**
     * Default copy constructor.
     */
    Matrix(const Matrix<M,N,T>&)        = default;

    /**
     * Default move constructor.
     */
    Matrix(Matrix<M,N,T>&&) noexcept    = default;

    /**
     * Default destructor.
     */
    ~Matrix()                           = default;

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Default copy assignment.
     */
    Matrix<M,N,T>&
    operator=(const Matrix<M,N,T>&)     = default;

    /**
     * Default move assignment.
     */
    Matrix<M,N,T>&
    operator=(Matrix<M,N,T>&&) noexcept = default;

    /** Assigns all components single value */
    Matrix<M,N,T>&
    operator=(T scalar);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return reference to a component.
     */
    reference
    operator()(size_t row, size_t column);

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix
     * @param column Column of matrix
     * @return const reference to a component.
     */
    const_reference
    operator()(size_t row, size_t column) const;

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */
    reference
    operator[](size_t index);

    /**
     * Gets a const reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */
    const_reference
    operator[](size_t index) const;

/* ####################################################################################### */
public: /* Direct iterators */
/* ####################################################################################### */

    /**
     * Get an direct iterator pointing to the first component.
     */
    iterator
    begin();

    /**
     * Get an direct iterator pointing to the component after the last.
     */
    iterator
    end();

    /**
     * Get an const direct iterator pointing to the first component.
     */
    const_iterator
    begin() const;

    /**
     * Get an const direct iterator pointing to the component after the last.
     */
    const_iterator
    end() const;

    /**
     * Get an const direct iterator pointing to the first component.
     */
    const_iterator
    cbegin() const;

    /**
     * Get an const direct iterator pointing to the component after the last.
     */
    const_iterator
    cend() const;

    /**
     * Get an direct iterator pointing to the last component.
     */
    reverse_iterator
    rbegin();

    /**
     * Get an direct iterator pointing to the component before the first.
     */
    reverse_iterator
    rend();

    /**
     * Get an const direct iterator pointing to the last component.
     */
    const_reverse_iterator
    rbegin() const;

    /**
     * Get an const direct iterator pointing to the component before the first.
     */
    const_reverse_iterator
    rend() const;

    /**
     * Get an const direct iterator pointing to the last component.
     */
    const_reverse_iterator
    crbegin() const;

    /**
     * Get an const direct iterator pointing to the component before the first.
     */
    const_reverse_iterator
    crend() const;

/* ####################################################################################### */
public: /* Indirect iterators */
/* ####################################################################################### */

    /**
     * Get an indirect iterator pointing to the first component.
     */
    IndirectIterator
    beginIndirect();

    /**
     * Get an indirect iterator pointing to the component after the last.
     */
    IndirectIterator
    endIndirect();

    /**
     * Get an const indirect iterator pointing to the first component.
     */
    ConstIndirectIterator
    beginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component after the last.
     */
    ConstIndirectIterator
    endIndirect() const;

    /**
     * Get an const indirect iterator pointing to the first component.
     */
    ConstIndirectIterator
    cbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component after the last.
     */
    ConstIndirectIterator
    cendIndirect() const;

    /**
     * Get an indirect iterator pointing to the last component.
     */
    ReverseIndirectIterator
    rbeginIndirect();

    /**
     * Get an indirect iterator pointing to the component before the first.
     */
    ReverseIndirectIterator
    rendIndirect();

    /**
     * Get an const indirect iterator pointing to the last component.
     */
    ConstReverseIndirectIterator
    rbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component before the first.
     */
    ConstReverseIndirectIterator
    rendIndirect() const;

    /**
     * Get an const indirect iterator pointing to the last component.
     */
    ConstReverseIndirectIterator
    crbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component before the first.
     */
    ConstReverseIndirectIterator
    crendIndirect() const;

/* ####################################################################################### */
public: /* Column iterators */
/* ####################################################################################### */

//    /**
//     * Get an iterator pointing to the first component in the specified column.
//     */
//    ColumnIterator
//    beginColumn(size_type column);
//
//    /**
//     * Get an iterator pointing to the component after the last in specified column.
//     */
//    ColumnIterator
//    endColumn(size_type column);
//
//    /**
//     * Get an const iterator pointing to the first component in the specified column.
//     */
//    ConstColumnIterator
//    beginColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified column.
//     */
//    ConstColumnIterator
//    endColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the first component in the specified column.
//     */
//    ConstColumnIterator
//    cbeginColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified column.
//     */
//    ConstColumnIterator
//    cendColumn(size_type column) const;
//
//    /**
//     * Get an iterator pointing to the last component in the specified column.
//     */
//    ReverseColumnIterator
//    rbeginColumn(size_type column);
//
//    /**
//     * Get an iterator pointing to the component before the first in the specified column.
//     */
//    ReverseColumnIterator
//    rendColumn(size_type column);
//
//    /**
//     * Get an const iterator pointing to the last component in the specified column.
//     */
//    ConstReverseColumnIterator
//    rbeginColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified column.
//     */
//    ConstReverseColumnIterator
//    rendColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the last component in the specified column.
//     */
//    ConstReverseColumnIterator
//    crbeginColumn(size_type column) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified column.
//     */
//    ConstReverseColumnIterator
//    crendColumn(size_type column) const;
//
///* ####################################################################################### */
//public: /* Row iterators */
///* ####################################################################################### */
//
//    /**
//     * Get an iterator pointing to the first component in the specified row.
//     */
//    RowIterator
//    beginRow(size_type row);
//
//    /**
//     * Get an iterator pointing to the component after the last in specified row.
//     */
//    RowIterator
//    endRow(size_type row);
//
//    /**
//     * Get an const iterator pointing to the first component in the specified row.
//     */
//    ConstRowIterator
//    beginRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified row.
//     */
//    ConstRowIterator
//    endRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the first component in the specified row.
//     */
//    ConstRowIterator
//    cbeginRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified row.
//     */
//    ConstRowIterator
//    cendRow(size_type row) const;
//
//    /**
//     * Get an iterator pointing to the last component in the specified row.
//     */
//    ReverseRowIterator
//    rbeginRow(size_type row);
//
//    /**
//     * Get an iterator pointing to the component before the first in the specified row.
//     */
//    ReverseRowIterator
//    rendRow(size_type row);
//
//    /**
//     * Get an const iterator pointing to the last component in the specified row.
//     */
//    ConstReverseRowIterator
//    rbeginRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified row.
//     */
//    ConstReverseRowIterator
//    rendRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the last component in the specified row.
//     */
//    ConstReverseRowIterator
//    crbeginRow(size_type row) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified row.
//     */
//    ConstReverseRowIterator
//    crendRow(size_type row) const;
//
///* ####################################################################################### */
//public: /* Sub iterators */
///* ####################################################################################### */
//
//    /**
//     * Get an iterator pointing to the first component in the specified submatrix.
//     */
//    SubIterator
//    beginSub(const SubRect& subRect);
//
//    /**
//     * Get an iterator pointing to the component after the last in specified submatrix.
//     */
//    SubIterator
//    endSub(const SubRect& subRect);
//
//    /**
//     * Get an const iterator pointing to the first component in the specified submatrix.
//     */
//    ConstSubIterator
//    beginSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified submatrix.
//     */
//    ConstSubIterator
//    endSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the first component in the specified submatrix.
//     */
//    ConstSubIterator
//    cbeginSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the component after the last in the specified submatrix.
//     */
//    ConstSubIterator
//    cendSub(const SubRect& subRect) const;
//
//    /**
//     * Get an iterator pointing to the last component in the specified submatrix.
//     */
//    ReverseSubIterator
//    rbeginSub(const SubRect& subRect);
//
//    /**
//     * Get an iterator pointing to the component before the first in the specified submatrix.
//     */
//    ReverseSubIterator
//    rendSub(const SubRect& subRect);
//
//    /**
//     * Get an const iterator pointing to the last component in the specified submatrix.
//     */
//    ConstReverseSubIterator
//    rbeginSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified submatrix.
//     */
//    ConstReverseSubIterator
//    rendSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the last component in the specified submatrix.
//     */
//    ConstReverseSubIterator
//    crbeginSub(const SubRect& subRect) const;
//
//    /**
//     * Get an const iterator pointing to the component before the first in the specified submatrix.
//     */
//    ConstReverseSubIterator
//    crendSub(const SubRect& subRect) const;

/* ####################################################################################### */
public: /* Data */
/* ####################################################################################### */

#ifdef MATH3D_USE_ROW_MAJOR_MAPPING
    T data[M][N];
#else
    T data[N][M];
#endif
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
Matrix<M,N,T>::Matrix(T scalar)
{
    for (auto i = 0; i < size; ++i)
    {
        *(&data[0][0] + i) = scalar;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix(std::initializer_list<T> values)
{
#ifdef MATH3D_USE_ROW_MAJOR_MAPPING
    for (auto i = 0; i < size; ++i)
    {
        *(&data[0][0] + i) = *(values.begin() + i);
    }
#else
    for (auto c = 0; c < columns; ++c)
    {
        for (auto r = 0; r < rows; ++r)
        {
            data[c][r] = *(values.begin() + r * columns + c);
        }
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>::Matrix(const T *values)
{
#ifdef MATH3D_USE_ROW_MAJOR_MAPPING
    for (auto i = 0; i < size; ++i)
    {
        *(&data[0][0] + i) = *(values + i);
    }
#else
    for (auto c = 0; c < columns; ++c)
    {
        for (auto r = 0; r < rows; ++r)
        {
            data[c][r] = *(values + r * columns + c);
        }
    }
#endif
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
Matrix<M,N,T>&
Matrix<M,N,T>::operator=(T scalar)
{
    for (auto i = 0; i < size; ++i)
    {
        *(&data[0][0] + i) = scalar;
    }
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
FORCEINLINE T&
Matrix<M,N,T>::operator()(size_t row, size_t column)
{
#ifdef MATH3D_USE_ROW_MAJOR_MAPPING
    return data[row][column];
#else
    return data[column][row];
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
FORCEINLINE const T&
Matrix<M,N,T>::operator()(size_t row, size_t column) const
{
#ifdef MATH3D_USE_ROW_MAJOR_MAPPING
    return data[row][column];
#else
    return data[column][row];
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
FORCEINLINE T&
Matrix<M,N,T>::operator[](size_t index)
{
    return *(&data[0][0] + index);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
FORCEINLINE const T&
Matrix<M,N,T>::operator[](size_t index) const
{
    return *(&data[0][0] + index);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Direct iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::begin()
{
    return iterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::end()
{
    return iterator {&data[0][0], M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::begin() const
{
    return const_iterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::end() const
{
    return const_iterator {&data[0][0], M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cbegin() const
{
    return const_iterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cend() const
{
    return const_iterator {&data[0][0], M*N};
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
/* IMPLEMENTATION | Indirect iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::IndirectIterator
Matrix<M,N,T>::beginIndirect()
{
    return IndirectIterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::IndirectIterator
Matrix<M,N,T>::endIndirect()
{
    return IndirectIterator {&data[0][0], M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::beginIndirect() const
{
    return ConstIndirectIterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::endIndirect() const
{
    return ConstIndirectIterator {&data[0][0], M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::cbeginIndirect() const
{
    return ConstIndirectIterator {&data[0][0], 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::cendIndirect() const
{
    return ConstIndirectIterator {&data[0][0], M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseIndirectIterator
Matrix<M,N,T>::rbeginIndirect()
{
    return ReverseIndirectIterator {endIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ReverseIndirectIterator
Matrix<M,N,T>::rendIndirect()
{
    return ReverseIndirectIterator {beginIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::rbeginIndirect() const
{
    return ConstReverseIndirectIterator {cendIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::rendIndirect() const
{
    return ConstReverseIndirectIterator {cbeginIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::crbeginIndirect() const
{
    return ConstReverseIndirectIterator {cendIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::crendIndirect() const
{
    return ConstReverseIndirectIterator {cbeginIndirect()};
}

/* ####################################################################################### */
/* Column iterators */
/* ####################################################################################### */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ColumnIterator
//Matrix<M,N,T>::beginColumn(size_type column)
//{
//    return ColumnIterator(&data[0][0], column, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ColumnIterator
//Matrix<M,N,T>::endColumn(size_type column)
//{
//    return ColumnIterator(&data[0][0], column, M);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstColumnIterator
//Matrix<M,N,T>::beginColumn(size_type column) const
//{
//    return ConstColumnIterator(&data[0][0], column, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstColumnIterator
//Matrix<M,N,T>::endColumn(size_type column) const
//{
//    return ConstColumnIterator(&data[0][0], column, M);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstColumnIterator
//Matrix<M,N,T>::cbeginColumn(size_type column) const
//{
//    return ConstColumnIterator(&data[0][0], column, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstColumnIterator
//Matrix<M,N,T>::cendColumn(size_type column) const
//{
//    return ConstColumnIterator(&data[0][0], column, M);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseColumnIterator
//Matrix<M,N,T>::rbeginColumn(size_type column)
//{
//    return ReverseColumnIterator(endColumn(column));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseColumnIterator
//Matrix<M,N,T>::rendColumn(size_type column)
//{
//    return ReverseColumnIterator(beginColumn(column));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseColumnIterator
//Matrix<M,N,T>::rbeginColumn(size_type column) const
//{
//    return ConstReverseColumnIterator(endColumn(column));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseColumnIterator
//Matrix<M,N,T>::rendColumn(size_type column) const
//{
//    return ConstReverseColumnIterator(beginColumn(column));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseColumnIterator
//Matrix<M,N,T>::crbeginColumn(size_type column) const
//{
//    return ConstReverseColumnIterator(cendColumn(column));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseColumnIterator
//Matrix<M,N,T>::crendColumn(size_type column) const
//{
//    return ConstReverseColumnIterator(cbeginColumn(column));
//}
//
///* ####################################################################################### */
///* Row iterators */
///* ####################################################################################### */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::RowIterator
//Matrix<M,N,T>::beginRow(size_type row)
//{
//    return RowIterator(&data[0][0], row, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::RowIterator
//Matrix<M,N,T>::endRow(size_type row)
//{
//    return RowIterator(&data[0][0], row, N);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstRowIterator
//Matrix<M,N,T>::beginRow(size_type row) const
//{
//    return ConstRowIterator(&data[0][0], row, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstRowIterator
//Matrix<M,N,T>::endRow(size_type row) const
//{
//    return ConstRowIterator(&data[0][0], row, N);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstRowIterator
//Matrix<M,N,T>::cbeginRow(size_type row) const
//{
//    return ConstRowIterator(&data[0][0], row, 0);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstRowIterator
//Matrix<M,N,T>::cendRow(size_type row) const
//{
//    return ConstRowIterator(&data[0][0], row, N);
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseRowIterator
//Matrix<M,N,T>::rbeginRow(size_type row)
//{
//    return ReverseRowIterator(endRow(row));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseRowIterator
//Matrix<M,N,T>::rendRow(size_type row)
//{
//    return ReverseRowIterator(beginRow(row));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseRowIterator
//Matrix<M,N,T>::rbeginRow(size_type row) const
//{
//    return ConstReverseRowIterator(endRow(row));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseRowIterator
//Matrix<M,N,T>::rendRow(size_type row) const
//{
//    return ConstReverseRowIterator(beginRow(row));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseRowIterator
//Matrix<M,N,T>::crbeginRow(size_type row) const
//{
//    return ConstReverseRowIterator(cendRow(row));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseRowIterator
//Matrix<M,N,T>::crendRow(size_type row) const
//{
//    return ConstReverseRowIterator(cbeginRow(row));
//}
//
///* ####################################################################################### */
///* Sub iterators */
///* ####################################################################################### */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::SubIterator
//Matrix<M,N,T>::beginSub(const Matrix::SubRect& subRect)
//{
//    return SubIterator
//    {
//        &data[0][0],
//        subRect,
//        0,
//        0
//    };
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::SubIterator
//Matrix<M,N,T>::endSub(const Matrix::SubRect& subRect)
//{
//    return ++SubIterator
//    {
//        &data[0][0],
//        subRect,
//        subRect.second.first - subRect.first.first,
//        subRect.second.second - subRect.first.second
//    };
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstSubIterator
//Matrix<M,N,T>::beginSub(const Matrix::SubRect& subRect) const
//{
//    return ConstSubIterator
//    {
//        &data[0][0],
//        subRect,
//        0,
//        0
//    };
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstSubIterator
//Matrix<M,N,T>::endSub(const Matrix::SubRect& subRect) const
//{
//    return ++ConstSubIterator
//    {
//        &data[0][0],
//        subRect,
//        subRect.second.first - subRect.first.first,
//        subRect.second.second - subRect.first.second
//    };
//}
//
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstSubIterator
//Matrix<M,N,T>::cbeginSub(const Matrix::SubRect& subRect) const
//{
//    return ConstSubIterator
//            {
//                    &data[0][0],
//                    subRect,
//                    0,
//                    0
//            };
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstSubIterator
//Matrix<M,N,T>::cendSub(const Matrix::SubRect& subRect) const
//{
//    return ++ConstSubIterator
//    {
//        &data[0][0],
//        subRect,
//        subRect.second.first - subRect.first.first,
//        subRect.second.second - subRect.first.second
//    };
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseSubIterator
//Matrix<M,N,T>::rbeginSub(const SubRect& subRect)
//{
//    return ReverseSubIterator(endSub(subRect));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ReverseSubIterator
//Matrix<M,N,T>::rendSub(const SubRect& subRect)
//{
//    return ReverseSubIterator(beginSub(subRect));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseSubIterator
//Matrix<M,N,T>::rbeginSub(const SubRect& subRect) const
//{
//    return ConstReverseSubIterator(endSub(subRect));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseSubIterator
//Matrix<M,N,T>::rendSub(const SubRect& subRect) const
//{
//    return ConstReverseSubIterator(beginSub(subRect));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseSubIterator
//Matrix<M,N,T>::crbeginSub(const SubRect& subRect) const
//{
//    return ConstReverseSubIterator(endSub(subRect));
//}
//
///* --------------------------------------------------------------------------------------- */
//
//template<size_t M, size_t N, typename T>
//typename Matrix<M,N,T>::ConstReverseSubIterator
//Matrix<M,N,T>::crendSub(const SubRect& subRect) const
//{
//    return ConstReverseSubIterator(beginSub(subRect));
//}

#endif // MATH3D_MATRIX_HPP
