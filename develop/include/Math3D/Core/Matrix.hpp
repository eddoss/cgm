#pragma once


#include <type_traits>
#include <Math3D/Global.hpp>
#include <private/Math3D/Core/Support/Matrix/ReverseMatrixIterator.hpp>
#include <private/Math3D/Core/Support/Matrix/Iterators/Direct.hpp>
#include <private/Math3D/Core/Support/Matrix/Iterators/Indirect.hpp>
#include <private/Math3D/Core/Support/Matrix/Iterators/Row.hpp>
#include <private/Math3D/Core/Support/Matrix/Iterators/Column.hpp>


MATH3D_NAMESPACE_BEGIN

template<size_t M, size_t N, typename T=FLOAT>
struct Matrix
{
    MATH3D_RULE_OF_FIVE(Matrix)

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type                         = size_t;
    using value_type                        = T;
    using pointer                           = T*;
    using reference                         = T&;
    using const_pointer                     = const T*;
    using const_reference                   = const T&;

/* ####################################################################################### */
public: /* Matrices typedefs */
/* ####################################################################################### */

    using Row                               = Matrix<1,N,T>;
    using Column                            = Matrix<M,1,T>;
    using Transposed                        = Matrix<N,M,T>;

/* ####################################################################################### */
public: /* Iterators typedefs */
/* ####################################################################################### */

    using iterator                          = MatrixDirectIterator<M,N,T>;
    using const_iterator                    = ConstMatrixDirectIterator<M,N,T>;
    using reverse_iterator                  = ReverseMatrixIterator<iterator>;
	using const_reverse_iterator            = ReverseMatrixIterator<const_iterator>;

/* --------------------------------------------------------------------------------------- */

    using IndirectIterator                  = MatrixIndirectIterator<M,N,T>;
    using ConstIndirectIterator             = ConstMatrixIndirectIterator<M,N,T>;
    using ReverseIndirectIterator           = ReverseMatrixIterator<IndirectIterator>;
	using ConstReverseIndirectIterator      = ReverseMatrixIterator<ConstIndirectIterator>;

/* --------------------------------------------------------------------------------------- */

    using RowIterator                       = MatrixRowIterator<M,N,T>;
    using ConstRowIterator                  = ConstMatrixRowIterator<M,N,T>;
    using ReverseRowIterator                = ReverseMatrixIterator<RowIterator>;
    using ConstReverseRowIterator           = ReverseMatrixIterator<ConstRowIterator>;

/* --------------------------------------------------------------------------------------- */

    using ColumnIterator                    = MatrixColumnIterator<M,N,T>;
    using ConstColumnIterator               = ConstMatrixColumnIterator<M,N,T>;
    using ReverseColumnIterator             = ReverseMatrixIterator<ColumnIterator>;
    using ConstReverseColumnIterator        = ReverseMatrixIterator<ConstColumnIterator>;

/* --------------------------------------------------------------------------------------- */

#ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
    using RowDirIterator                    = MatrixDirectIterator<M,N,T>;
    using ConstRowDirIterator               = ConstMatrixDirectIterator<M,N,T>;
#else
    using RowDirIterator                    = MatrixIndirectIterator<M,N,T>;
    using ConstRowDirIterator               = ConstMatrixIndirectIterator<M,N,T>;
#endif
    using ReverseRowDirIterator             = ReverseMatrixIterator<RowDirIterator>;
    using ConstReverseRowDirIterator        = ReverseMatrixIterator<ConstRowDirIterator>;

/* --------------------------------------------------------------------------------------- */

#ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
    using ColumnDirIterator                 = MatrixIndirectIterator<M,N,T>;
    using ConstColumnDirIterator            = ConstMatrixIndirectIterator<M,N,T>;
#else
    using ColumnDirIterator                 = MatrixDirectIterator<M,N,T>;
    using ConstColumnDirIterator            = ConstMatrixDirectIterator<M,N,T>;
#endif
    using ReverseColumnDirIterator          = ReverseMatrixIterator<ColumnDirIterator>;
    using ConstReverseColumnDirIterator     = ReverseMatrixIterator<ConstColumnDirIterator>;

/* ####################################################################################### */
private: /* Data */
/* ####################################################################################### */

#ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
    T m_data[M][N];
#else
    T m_data[N][M];
#endif

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    /**
     * Rows count.
     */
    constexpr static const size_type
    rows    {M};

    /**
     * Columns count.
     */
    constexpr static const size_type
    columns {N};

    /**
     * Components count.
     */
    constexpr static const size_type
    size    {M*N};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing all components to a single value.
     * @param scalar Value to set all components to.
     */
    constexpr explicit
    Matrix(T scalar);

    /**
     * Constructor using initial values for each component (row-wise init).
     * @param values Component values.
     */
    constexpr explicit
    Matrix(const T* values);

    /**
     * Constructor initializing all components (row-wise init).
     * @param values Values to set all components to.
     */
    constexpr
    Matrix(std::initializer_list<T> values);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components single value.
     */
    constexpr Matrix&
    operator=(T scalar);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr FORCEINLINE pointer
    data();

    /**
     * Get const raw pointer at the first component.
     * @param first component raw const pointer.
     */
    constexpr FORCEINLINE const_pointer
    data() const;

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return reference to a component.
     */
    constexpr FORCEINLINE reference
    operator()(size_t row, size_t column);

    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return const reference to a component.
     */
    constexpr FORCEINLINE const_reference
    operator()(size_t row, size_t column) const;

    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major.
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */
    constexpr FORCEINLINE reference
    operator[](size_t index);

    /**
     * Gets a const reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major.
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */
    constexpr FORCEINLINE const_reference
    operator[](size_t index) const;

/* ####################################################################################### */
public: /* Direct iterators */
/* ####################################################################################### */

    /**
     * Get an direct iterator pointing to the first component.
     */
    constexpr iterator
    begin();

    /**
     * Get an direct iterator pointing to the component after the last.
     */
    constexpr iterator
    end();

    /**
     * Get an const direct iterator pointing to the first component.
     */
    constexpr const_iterator
    begin() const;

    /**
     * Get an const direct iterator pointing to the component after the last.
     */
    constexpr const_iterator
    end() const;

    /**
     * Get an const direct iterator pointing to the first component.
     */
    constexpr const_iterator
    cbegin() const;

    /**
     * Get an const direct iterator pointing to the component after the last.
     */
    constexpr const_iterator
    cend() const;

    /**
     * Get an direct iterator pointing to the last component.
     */
    constexpr reverse_iterator
    rbegin();

    /**
     * Get an direct iterator pointing to the component before the first.
     */
    constexpr reverse_iterator
    rend();

    /**
     * Get an const direct iterator pointing to the last component.
     */
    constexpr const_reverse_iterator
    rbegin() const;

    /**
     * Get an const direct iterator pointing to the component before the first.
     */
    constexpr const_reverse_iterator
    rend() const;

    /**
     * Get an const direct iterator pointing to the last component.
     */
    constexpr const_reverse_iterator
    crbegin() const;

    /**
     * Get an const direct iterator pointing to the component before the first.
     */
    constexpr const_reverse_iterator
    crend() const;

/* ####################################################################################### */
public: /* Indirect iterators */
/* ####################################################################################### */

    /**
     * Get an indirect iterator pointing to the first component.
     */
    constexpr IndirectIterator
    beginIndirect();

    /**
     * Get an indirect iterator pointing to the component after the last.
     */
    constexpr IndirectIterator
    endIndirect();

    /**
     * Get an const indirect iterator pointing to the first component.
     */
    constexpr ConstIndirectIterator
    beginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component after the last.
     */
    constexpr ConstIndirectIterator
    endIndirect() const;

    /**
     * Get an const indirect iterator pointing to the first component.
     */
    constexpr ConstIndirectIterator
    cbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component after the last.
     */
    constexpr ConstIndirectIterator
    cendIndirect() const;

    /**
     * Get an indirect iterator pointing to the last component.
     */
    constexpr ReverseIndirectIterator
    rbeginIndirect();

    /**
     * Get an indirect iterator pointing to the component before the first.
     */
    constexpr ReverseIndirectIterator
    rendIndirect();

    /**
     * Get an const indirect iterator pointing to the last component.
     */
    constexpr ConstReverseIndirectIterator
    rbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component before the first.
     */
    constexpr ConstReverseIndirectIterator
    rendIndirect() const;

    /**
     * Get an const indirect iterator pointing to the last component.
     */
    constexpr ConstReverseIndirectIterator
    crbeginIndirect() const;

    /**
     * Get an const indirect iterator pointing to the component before the first.
     */
    constexpr ConstReverseIndirectIterator
    crendIndirect() const;

/* ####################################################################################### */
public: /* Row-dir iterators */
/* ####################################################################################### */

    /**
     * Get an row-dir iterator pointing to the first component.
     */
    constexpr RowDirIterator
    beginRowDir();

    /**
     * Get an row-dir iterator pointing to the component after the last.
     */
    constexpr RowDirIterator
    endRowDir();

    /**
     * Get an const row-dir iterator pointing to the first component.
     */
    constexpr ConstRowDirIterator
    beginRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the component after the last.
     */
    constexpr ConstRowDirIterator
    endRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the first component.
     */
    constexpr ConstRowDirIterator
    cbeginRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the component after the last.
     */
    constexpr ConstRowDirIterator
    cendRowDir() const;

    /**
     * Get an row-dir iterator pointing to the last component.
     */
    constexpr ReverseRowDirIterator
    rbeginRowDir();

    /**
     * Get an row-dir iterator pointing to the component before the first.
     */
    constexpr ReverseRowDirIterator
    rendRowDir();

    /**
     * Get an const row-dir iterator pointing to the last component.
     */
    constexpr ConstReverseRowDirIterator
    rbeginRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the component before the first.
     */
    constexpr ConstReverseRowDirIterator
    rendRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the last component.
     */
    constexpr ConstReverseRowDirIterator
    crbeginRowDir() const;

    /**
     * Get an const row-dir iterator pointing to the component before the first.
     */
    constexpr ConstReverseRowDirIterator
    crendRowDir() const;

/* ####################################################################################### */
public: /* Column-dir iterators */
/* ####################################################################################### */

    /**
     * Get an column-dir iterator pointing to the first component.
     */
    constexpr ColumnDirIterator
    beginColumnDir();

    /**
     * Get an column-dir iterator pointing to the component after the last.
     */
    constexpr ColumnDirIterator
    endColumnDir();

    /**
     * Get an const column-dir iterator pointing to the first component.
     */
    constexpr ConstColumnDirIterator
    beginColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the component after the last.
     */
    constexpr ConstColumnDirIterator
    endColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the first component.
     */
    constexpr ConstColumnDirIterator
    cbeginColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the component after the last.
     */
    constexpr ConstColumnDirIterator
    cendColumnDir() const;

    /**
     * Get an column-dir iterator pointing to the last component.
     */
    constexpr ReverseColumnDirIterator
    rbeginColumnDir();

    /**
     * Get an column-dir iterator pointing to the component before the first.
     */
    constexpr ReverseColumnDirIterator
    rendColumnDir();

    /**
     * Get an const column-dir iterator pointing to the last component.
     */
    constexpr ConstReverseColumnDirIterator
    rbeginColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the component before the first.
     */
    constexpr ConstReverseColumnDirIterator
    rendColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the last component.
     */
    constexpr ConstReverseColumnDirIterator
    crbeginColumnDir() const;

    /**
     * Get an const column-dir iterator pointing to the component before the first.
     */
    constexpr ConstReverseColumnDirIterator
    crendColumnDir() const;

/* ####################################################################################### */
public: /* Row iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component in the specified row.
     */
    constexpr RowIterator
    beginRow(size_type row);

    /**
     * Get an iterator pointing to the component after the last in specified row.
     */
    constexpr RowIterator
    endRow(size_type row);

    /**
     * Get an const iterator pointing to the first component in the specified row.
     */
    constexpr ConstRowIterator
    beginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */
    constexpr ConstRowIterator
    endRow(size_type row) const;

    /**
     * Get an const iterator pointing to the first component in the specified row.
     */
    constexpr ConstRowIterator
    cbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */
    constexpr ConstRowIterator
    cendRow(size_type row) const;

    /**
     * Get an iterator pointing to the last component in the specified row.
     */
    constexpr ReverseRowIterator
    rbeginRow(size_type row);

    /**
     * Get an iterator pointing to the component before the first in the specified row.
     */
    constexpr ReverseRowIterator
    rendRow(size_type row);

    /**
     * Get an const iterator pointing to the last component in the specified row.
     */
    constexpr ConstReverseRowIterator
    rbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */
    constexpr ConstReverseRowIterator
    rendRow(size_type row) const;

    /**
     * Get an const iterator pointing to the last component in the specified row.
     */
    constexpr ConstReverseRowIterator
    crbeginRow(size_type row) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */
    constexpr ConstReverseRowIterator
    crendRow(size_type row) const;

/* ####################################################################################### */
public: /* Column iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component in the specified column.
     */
    constexpr ColumnIterator
    beginColumn(size_type column);

    /**
     * Get an iterator pointing to the component after the last in specified column.
     */
    constexpr ColumnIterator
    endColumn(size_type column);

    /**
     * Get an const iterator pointing to the first component in the specified column.
     */
    constexpr ConstColumnIterator
    beginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */
    constexpr ConstColumnIterator
    endColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the first component in the specified column.
     */
    constexpr ConstColumnIterator
    cbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */
    constexpr ConstColumnIterator
    cendColumn(size_type column) const;

    /**
     * Get an iterator pointing to the last component in the specified column.
     */
    constexpr ReverseColumnIterator
    rbeginColumn(size_type column);

    /**
     * Get an iterator pointing to the component before the first in the specified column.
     */
    constexpr ReverseColumnIterator
    rendColumn(size_type column);

    /**
     * Get an const iterator pointing to the last component in the specified column.
     */
    constexpr ConstReverseColumnIterator
    rbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */
    constexpr ConstReverseColumnIterator
    rendColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the last component in the specified column.
     */
    constexpr ConstReverseColumnIterator
    crbeginColumn(size_type column) const;

    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */
    constexpr ConstReverseColumnIterator
    crendColumn(size_type column) const;
};

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Matrix.hpp>