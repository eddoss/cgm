#ifndef MATH3D_MATRIX_HPP
#define MATH3D_MATRIX_HPP

#include <type_traits>
#include <Math3D/Global.hpp>
#include <Math3D/Platform.hpp>
#include <Math3D/Core/Structs/Matrix/Support.hpp>
#include <Math3D/Core/Structs/Matrix/Iterators/Direct.hpp>
#include <Math3D/Core/Structs/Matrix/Iterators/Indirect.hpp>
#include <Math3D/Core/Structs/Matrix/Iterators/Row.hpp>
#include <Math3D/Core/Structs/Matrix/Iterators/Column.hpp>


#ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING

    #define MATH3D_MATRIX_INTERNAL_DATA T m_data[M][N];

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_ROW_DIR_ITERATOR_ALIASES                                                                     \
    using RowDirIterator                    = MatrixDirectIterator<M,N,T>;                                             \
    using ConstRowDirIterator               = ConstMatrixDirectIterator<M,N,T>;

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_COLUMN_DIR_ITERATOR_ALIASES                                                                  \
    using ColumnDirIterator                 = MatrixIndirectIterator<M,N,T>;                                           \
    using ConstColumnDirIterator            = ConstMatrixIndirectIterator<M,N,T>;

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_CONSTRUCTOR_BODY_VALUES_PTR                                                                  \
    for (auto i = 0; i < size; ++i)                                                                                    \
    {                                                                                                                  \
        *(&m_data[0][0] + i) = *(values + i);                                                                          \
    }

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_CONSTRUCTOR_BODY_INITIALIZER_LIST                                                            \
    for (auto i = 0; i < size; ++i)                                                                                    \
    {                                                                                                                  \
        *(&m_data[0][0] + i) = *(values.begin() + i);                                                                  \
    }

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_BODY_GET_BY_ROW_COLUMN                                                                       \
    return m_data[row][column];                                                                                        \

#else

    #define MATH3D_MATRIX_INTERNAL_DATA T m_data[N][M];

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_ROW_DIR_ITERATOR_ALIASES                                                                     \
    using RowDirIterator                    = MatrixIndirectIterator<M,N,T>;                                           \
    using ConstRowDirIterator               = ConstMatrixIndirectIterator<M,N,T>;

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_COLUMN_DIR_ITERATOR_ALIASES                                                                  \
    using ColumnDirIterator                 = MatrixDirectIterator<M,N,T>;                                             \
    using ConstColumnDirIterator            = ConstMatrixDirectIterator<M,N,T>;

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_CONSTRUCTOR_BODY_VALUES_PTR                                                                  \
    for (auto c = 0; c < columns; ++c)                                                                                 \
    {                                                                                                                  \
        for (auto r = 0; r < rows; ++r)                                                                                \
        {                                                                                                              \
            m_data[c][r] = *(values + r * columns + c);                                                                \
        }                                                                                                              \
    }

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_CONSTRUCTOR_BODY_INITIALIZER_LIST                                                            \
    for (auto c = 0; c < columns; ++c)                                                                                 \
    {                                                                                                                  \
        for (auto r = 0; r < rows; ++r)                                                                                \
        {                                                                                                              \
            m_data[c][r] = *(values.begin() + r * columns + c);                                                        \
        }                                                                                                              \
    }

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_MATRIX_BODY_GET_BY_ROW_COLUMN                                                               \
    return m_data[column][row];

#endif



/* ################################################################################################################## */
#define MATH3D_MATRIX_COMMON_BODY                                                                                      \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Typedefs */                                                                                                 \
/* ####################################################################################### */                          \
                                                                                                                       \
    using size_type                         = size_t;                                                                  \
    using value_type                        = T;                                                                       \
    using pointer                           = T*;                                                                      \
    using reference                         = T&;                                                                      \
    using const_pointer                     = const T*;                                                                \
    using const_reference                   = const T&;                                                                \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Matrices typedefs */                                                                                        \
/* ####################################################################################### */                          \
                                                                                                                       \
    using Row                               = Matrix<1,N,T>;                                                           \
    using Column                            = Matrix<M,1,T>;                                                           \
    using Transposed                        = Matrix<N,M,T>;                                                           \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Iterators typedefs */                                                                                       \
/* ####################################################################################### */                          \
                                                                                                                       \
    using iterator                          = MatrixDirectIterator<M,N,T>;                                             \
    using const_iterator                    = ConstMatrixDirectIterator<M,N,T>;                                        \
    using reverse_iterator                  = ReverseMatrixIterator<iterator>;                                         \
	using const_reverse_iterator            = ReverseMatrixIterator<const_iterator>;                                   \
                                                                                                                       \
/* --------------------------------------------------------------------------------------- */                          \
                                                                                                                       \
    using IndirectIterator                  = MatrixIndirectIterator<M,N,T>;                                           \
    using ConstIndirectIterator             = ConstMatrixIndirectIterator<M,N,T>;                                      \
    using ReverseIndirectIterator           = ReverseMatrixIterator<IndirectIterator>;                                 \
	using ConstReverseIndirectIterator      = ReverseMatrixIterator<ConstIndirectIterator>;                            \
                                                                                                                       \
/* --------------------------------------------------------------------------------------- */                          \
                                                                                                                       \
    using RowIterator                       = MatrixRowIterator<M,N,T>;                                                \
    using ConstRowIterator                  = ConstMatrixRowIterator<M,N,T>;                                           \
    using ReverseRowIterator                = ReverseMatrixIterator<RowIterator>;                                      \
    using ConstReverseRowIterator           = ReverseMatrixIterator<ConstRowIterator>;                                 \
                                                                                                                       \
/* --------------------------------------------------------------------------------------- */                          \
                                                                                                                       \
    using ColumnIterator                    = MatrixColumnIterator<M,N,T>;                                             \
    using ConstColumnIterator               = ConstMatrixColumnIterator<M,N,T>;                                        \
    using ReverseColumnIterator             = ReverseMatrixIterator<ColumnIterator>;                                   \
    using ConstReverseColumnIterator        = ReverseMatrixIterator<ConstColumnIterator>;                              \
                                                                                                                       \
/* --------------------------------------------------------------------------------------- */                          \
                                                                                                                       \
    MATH3D_MATRIX_ROW_DIR_ITERATOR_ALIASES                                                                             \
    using ReverseRowDirIterator             = ReverseMatrixIterator<RowDirIterator>;                                   \
    using ConstReverseRowDirIterator        = ReverseMatrixIterator<ConstRowDirIterator>;                              \
                                                                                                                       \
/* --------------------------------------------------------------------------------------- */                          \
                                                                                                                       \
    MATH3D_MATRIX_COLUMN_DIR_ITERATOR_ALIASES                                                                          \
    using ReverseColumnDirIterator          = ReverseMatrixIterator<ColumnDirIterator>;                                \
    using ConstReverseColumnDirIterator     = ReverseMatrixIterator<ConstColumnDirIterator>;                           \
                                                                                                                       \
/* ####################################################################################### */                          \
private: /* Data */                                                                                                    \
/* ####################################################################################### */                          \
                                                                                                                       \
    MATH3D_MATRIX_INTERNAL_DATA                                                                                        \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Statics */                                                                                                  \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Rows count.
     */                                                                                                                \
    constexpr static const size_type                                                                                   \
    rows    {M};                                                                                                       \
                                                                                                                       \
    /**
     * Columns count.
     */                                                                                                                \
    constexpr static const size_type                                                                                   \
    columns {N};                                                                                                       \
                                                                                                                       \
    /**
     * Components count.
     */                                                                                                                \
    constexpr static const size_type                                                                                   \
    size    {M*N};                                                                                                     \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Constructors */                                                                                             \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Constructor initializing all components to a single value.
     * @param scalar Value to set all components to.
     */                                                                                                                \
    constexpr explicit                                                                                                 \
    Matrix(T scalar)                                                                                                   \
    {                                                                                                                  \
        for (auto i = 0; i < size; ++i)                                                                                \
        {                                                                                                              \
            *(&m_data[0][0] + i) = scalar;                                                                             \
        }                                                                                                              \
    }                                                                                                                  \
                                                                                                                       \
    /**
     * Constructor using initial values for each component (row-wise init).
     * @param values Component values.
     */                                                                                                                \
    constexpr explicit                                                                                                 \
    Matrix(const T* values)                                                                                            \
    {                                                                                                                  \
        MATH3D_MATRIX_CONSTRUCTOR_BODY_VALUES_PTR                                                                      \
    }                                                                                                                  \
                                                                                                                       \
    /**
     * Constructor initializing all components (row-wise init).
     * @param values Values to set all components to.
     */                                                                                                                \
    constexpr                                                                                                          \
    Matrix(std::initializer_list<T> values)                                                                            \
    {                                                                                                                  \
        MATH3D_MATRIX_CONSTRUCTOR_BODY_INITIALIZER_LIST                                                                \
    }                                                                                                                  \
                                                                                                                       \
    constexpr                                                                                                          \
    Matrix()                        = default;                                                                         \
                                                                                                                       \
    constexpr                                                                                                          \
    Matrix(const Matrix&)           = default;                                                                         \
                                                                                                                       \
    constexpr                                                                                                          \
    Matrix(Matrix&&) noexcept       = default;                                                                         \
                                                                                                                       \
    ~Matrix()                       = default;                                                                         \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Assignment operator */                                                                                      \
/* ####################################################################################### */                          \
                                                                                                                       \
    Matrix&                                                                                                            \
    operator=(const Matrix&)        = default;                                                                         \
                                                                                                                       \
    Matrix&                                                                                                            \
    operator=(Matrix&&) noexcept    = default;                                                                         \
                                                                                                                       \
    /**
     * Assigns all components single value.
     */                                                                                                                \
    constexpr Matrix&                                                                                                  \
    operator=(T scalar)                                                                                                \
    {                                                                                                                  \
        for (auto i = 0; i < size; ++i)                                                                                \
        {                                                                                                              \
            *(&m_data[0][0] + i) = scalar;                                                                             \
        }                                                                                                              \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Components accessing */                                                                                     \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */                                                                                                                \
    constexpr pointer                                                                                                  \
    data() {return &m_data[0][0];}                                                                                     \
                                                                                                                       \
    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return reference to a component.
     */                                                                                                                \
    constexpr reference                                                                                                \
    operator()(size_t row, size_t column)                                                                              \
    {                                                                                                                  \
        MATH3D_MATRIX_BODY_GET_BY_ROW_COLUMN                                                                           \
    }                                                                                                                  \
                                                                                                                       \
    /**
     * Gets a reference to a specific component of the matrix by row and column.
     * @param row Row of matrix.
     * @param column Column of matrix.
     * @return const reference to a component.
     */                                                                                                                \
    constexpr const_reference                                                                                          \
    operator()(size_t row, size_t column) const                                                                        \
    {                                                                                                                  \
        MATH3D_MATRIX_BODY_GET_BY_ROW_COLUMN                                                                           \
    }                                                                                                                  \
                                                                                                                       \
    /**
     * Gets a reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major.
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */                                                                                                                \
    constexpr reference                                                                                                \
    operator[](size_t index) {return *(&m_data[0][0] + index);}                                                        \
                                                                                                                       \
    /**
     * Gets a const reference to a specific component of the matrix by index of bulk data.
     * @warning Mapping based operator! For row-major indexed per rows, For column-major.
     * indexed per columns.
     * @param index Index of component.
     * @return reference to a component.
     */                                                                                                                \
    constexpr const_reference                                                                                          \
    operator[](size_t index) const {return *(&m_data[0][0] + index);}                                                  \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Direct iterators */                                                                                         \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an direct iterator pointing to the first component.
     */                                                                                                                \
    constexpr iterator                                                                                                 \
    begin() {return iterator {&m_data[0][0], 0};}                                                                      \
                                                                                                                       \
    /**
     * Get an direct iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr iterator                                                                                                 \
    end() {return iterator {&m_data[0][0], M*N};}                                                                      \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the first component.
     */                                                                                                                \
    constexpr const_iterator                                                                                           \
    begin() const {return const_iterator {&m_data[0][0], 0};}                                                          \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr const_iterator                                                                                           \
    end() const {return const_iterator {&m_data[0][0], M*N};}                                                          \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the first component.
     */                                                                                                                \
    constexpr const_iterator                                                                                           \
    cbegin() const {return const_iterator {&m_data[0][0], 0};}                                                         \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr const_iterator                                                                                           \
    cend() const {return const_iterator {&m_data[0][0], M*N};}                                                         \
                                                                                                                       \
    /**
     * Get an direct iterator pointing to the last component.
     */                                                                                                                \
    constexpr reverse_iterator                                                                                         \
    rbegin() {return reverse_iterator {end()};}                                                                        \
                                                                                                                       \
    /**
     * Get an direct iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr reverse_iterator                                                                                         \
    rend() {return reverse_iterator {begin()};}                                                                        \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the last component.
     */                                                                                                                \
    constexpr const_reverse_iterator                                                                                   \
    rbegin() const {return const_reverse_iterator {end()};}                                                            \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr const_reverse_iterator                                                                                   \
    rend() const {return const_reverse_iterator {begin()};}                                                            \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the last component.
     */                                                                                                                \
    constexpr const_reverse_iterator                                                                                   \
    crbegin() const {return const_reverse_iterator {cend()};}                                                          \
                                                                                                                       \
    /**
     * Get an const direct iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr const_reverse_iterator                                                                                   \
    crend() const {return const_reverse_iterator {cbegin()};}                                                          \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Indirect iterators */                                                                                       \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an indirect iterator pointing to the first component.
     */                                                                                                                \
    constexpr IndirectIterator                                                                                         \
    beginIndirect() {return IndirectIterator {&m_data[0][0], 0};}                                                      \
                                                                                                                       \
    /**
     * Get an indirect iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr IndirectIterator                                                                                         \
    endIndirect() {return IndirectIterator {&m_data[0][0], M*N};}                                                      \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstIndirectIterator                                                                                    \
    beginIndirect() const {return ConstIndirectIterator {&m_data[0][0], 0};}                                           \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstIndirectIterator                                                                                    \
    endIndirect() const {return ConstIndirectIterator {&m_data[0][0], M*N};}                                           \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstIndirectIterator                                                                                    \
    cbeginIndirect() const {return ConstIndirectIterator {&m_data[0][0], 0};}                                          \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstIndirectIterator                                                                                    \
    cendIndirect() const {return ConstIndirectIterator {&m_data[0][0], M*N};}                                          \
                                                                                                                       \
    /**
     * Get an indirect iterator pointing to the last component.
     */                                                                                                                \
    constexpr ReverseIndirectIterator                                                                                  \
    rbeginIndirect() {return ReverseIndirectIterator {endIndirect()};}                                                 \
                                                                                                                       \
    /**
     * Get an indirect iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ReverseIndirectIterator                                                                                  \
    rendIndirect() {return ReverseIndirectIterator {beginIndirect()};}                                                 \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseIndirectIterator                                                                             \
    rbeginIndirect() const {return ConstReverseIndirectIterator {cendIndirect()};}                                     \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseIndirectIterator                                                                             \
    rendIndirect() const {return ConstReverseIndirectIterator {cbeginIndirect()};}                                     \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseIndirectIterator                                                                             \
    crbeginIndirect() const {return ConstReverseIndirectIterator {cendIndirect()};}                                    \
                                                                                                                       \
    /**
     * Get an const indirect iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseIndirectIterator                                                                             \
    crendIndirect() const {return ConstReverseIndirectIterator {cbeginIndirect()};}                                    \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Row-dir iterators */                                                                                        \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an row-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr RowDirIterator                                                                                           \
    beginRowDir() {return RowDirIterator {&m_data[0][0], 0};}                                                          \
                                                                                                                       \
    /**
     * Get an row-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr RowDirIterator                                                                                           \
    endRowDir() {return RowDirIterator {&m_data[0][0], M*N};}                                                          \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstRowDirIterator                                                                                      \
    beginRowDir() const {return ConstRowDirIterator {&m_data[0][0], 0};}                                               \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstRowDirIterator                                                                                      \
    endRowDir() const {return ConstRowDirIterator {&m_data[0][0], M*N};}                                               \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstRowDirIterator                                                                                      \
    cbeginRowDir() const {return ConstRowDirIterator {&m_data[0][0], 0};}                                              \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstRowDirIterator                                                                                      \
    cendRowDir() const {return ConstRowDirIterator {&m_data[0][0], M*N};}                                              \
                                                                                                                       \
    /**
     * Get an row-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ReverseRowDirIterator                                                                                    \
    rbeginRowDir() {return ReverseRowDirIterator {endRowDir()};}                                                       \
                                                                                                                       \
    /**
     * Get an row-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ReverseRowDirIterator                                                                                    \
    rendRowDir() {return ReverseRowDirIterator {beginRowDir()};}                                                       \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseRowDirIterator                                                                               \
    rbeginRowDir() const {return ConstReverseRowDirIterator {cendRowDir()};}                                           \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseRowDirIterator                                                                               \
    rendRowDir() const {return ConstReverseRowDirIterator {cbeginRowDir()};}                                           \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseRowDirIterator                                                                               \
    crbeginRowDir() const {return ConstReverseRowDirIterator {cendRowDir()};}                                          \
                                                                                                                       \
    /**
     * Get an const row-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseRowDirIterator                                                                               \
    crendRowDir() const {return ConstReverseRowDirIterator {cbeginRowDir()};}                                          \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Column-dir iterators */                                                                                     \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an column-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr ColumnDirIterator                                                                                        \
    beginColumnDir() {return ColumnDirIterator {&m_data[0][0], 0};}                                                    \
                                                                                                                       \
    /**
     * Get an column-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ColumnDirIterator                                                                                        \
    endColumnDir() {return ColumnDirIterator {&m_data[0][0], M*N};}                                                    \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstColumnDirIterator                                                                                   \
    beginColumnDir() const {return ConstColumnDirIterator {&m_data[0][0], 0};}                                         \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstColumnDirIterator                                                                                   \
    endColumnDir() const {return ConstColumnDirIterator {&m_data[0][0], M*N};}                                         \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the first component.
     */                                                                                                                \
    constexpr ConstColumnDirIterator                                                                                   \
    cbeginColumnDir() const {return ConstColumnDirIterator {&m_data[0][0], 0};}                                        \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the component after the last.
     */                                                                                                                \
    constexpr ConstColumnDirIterator                                                                                   \
    cendColumnDir() const {return ConstColumnDirIterator {&m_data[0][0], M*N};}                                        \
                                                                                                                       \
    /**
     * Get an column-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ReverseColumnDirIterator                                                                                 \
    rbeginColumnDir() {return ReverseColumnDirIterator {endColumnDir()};}                                              \
                                                                                                                       \
    /**
     * Get an column-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ReverseColumnDirIterator                                                                                 \
    rendColumnDir() {return ReverseColumnDirIterator {beginColumnDir()};}                                              \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseColumnDirIterator                                                                            \
    rbeginColumnDir() const {return ConstReverseColumnDirIterator {cendColumnDir()};}                                  \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseColumnDirIterator                                                                            \
    rendColumnDir() const {return ConstReverseColumnDirIterator {cbeginColumnDir()};}                                  \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the last component.
     */                                                                                                                \
    constexpr ConstReverseColumnDirIterator                                                                            \
    crbeginColumnDir() const {return ConstReverseColumnDirIterator {cendColumnDir()};}                                 \
                                                                                                                       \
    /**
     * Get an const column-dir iterator pointing to the component before the first.
     */                                                                                                                \
    constexpr ConstReverseColumnDirIterator                                                                            \
    crendColumnDir() const {return ConstReverseColumnDirIterator {cbeginColumnDir()};}                                 \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Row iterators */                                                                                            \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an iterator pointing to the first component in the specified row.
     */                                                                                                                \
    constexpr RowIterator                                                                                              \
    beginRow(size_type row) {return RowIterator {&m_data[0][0], row, 0};}                                              \
                                                                                                                       \
    /**
     * Get an iterator pointing to the component after the last in specified row.
     */                                                                                                                \
    constexpr RowIterator                                                                                              \
    endRow(size_type row) {return RowIterator {&m_data[0][0], row, N};}                                                \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the first component in the specified row.
     */                                                                                                                \
    constexpr ConstRowIterator                                                                                         \
    beginRow(size_type row) const {return ConstRowIterator {&m_data[0][0], row, 0};}                                   \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */                                                                                                                \
    constexpr ConstRowIterator                                                                                         \
    endRow(size_type row) const {return ConstRowIterator {&m_data[0][0], row, N};}                                     \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the first component in the specified row.
     */                                                                                                                \
    constexpr ConstRowIterator                                                                                         \
    cbeginRow(size_type row) const {return ConstRowIterator {&m_data[0][0], row, 0};}                                  \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component after the last in the specified row.
     */                                                                                                                \
    constexpr ConstRowIterator                                                                                         \
    cendRow(size_type row) const {return ConstRowIterator {&m_data[0][0], row, N};}                                    \
                                                                                                                       \
    /**
     * Get an iterator pointing to the last component in the specified row.
     */                                                                                                                \
    constexpr ReverseRowIterator                                                                                       \
    rbeginRow(size_type row) {return ReverseRowIterator {endRow(row)};}                                                \
                                                                                                                       \
    /**
     * Get an iterator pointing to the component before the first in the specified row.
     */                                                                                                                \
    constexpr ReverseRowIterator                                                                                       \
    rendRow(size_type row) {return ReverseRowIterator {beginRow(row)};}                                                \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the last component in the specified row.
     */                                                                                                                \
    constexpr ConstReverseRowIterator                                                                                  \
    rbeginRow(size_type row) const {return ConstReverseRowIterator {endRow(row)};}                                     \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */                                                                                                                \
    constexpr ConstReverseRowIterator                                                                                  \
    rendRow(size_type row) const {return ConstReverseRowIterator {beginRow(row)};}                                     \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the last component in the specified row.
     */                                                                                                                \
    constexpr ConstReverseRowIterator                                                                                  \
    crbeginRow(size_type row) const {return ConstReverseRowIterator {cendRow(row)};}                                   \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component before the first in the specified row.
     */                                                                                                                \
    constexpr ConstReverseRowIterator                                                                                  \
    crendRow(size_type row) const {return ConstReverseRowIterator {cbeginRow(row)};}                                   \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Column iterators */                                                                                         \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get an iterator pointing to the first component in the specified column.
     */                                                                                                                \
    constexpr ColumnIterator                                                                                           \
    beginColumn(size_type column) {return ColumnIterator {&m_data[0][0], column, 0};}                                  \
                                                                                                                       \
    /**
     * Get an iterator pointing to the component after the last in specified column.
     */                                                                                                                \
    constexpr ColumnIterator                                                                                           \
    endColumn(size_type column) {return ColumnIterator {&m_data[0][0], column, M};}                                    \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the first component in the specified column.
     */                                                                                                                \
    constexpr ConstColumnIterator                                                                                      \
    beginColumn(size_type column) const {return ConstColumnIterator {&m_data[0][0], column, 0};}                       \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */                                                                                                                \
    constexpr ConstColumnIterator                                                                                      \
    endColumn(size_type column) const {return ConstColumnIterator {&m_data[0][0], column, M};}                         \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the first component in the specified column.
     */                                                                                                                \
    constexpr ConstColumnIterator                                                                                      \
    cbeginColumn(size_type column) const {return ConstColumnIterator {&m_data[0][0], column, 0};}                      \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component after the last in the specified column.
     */                                                                                                                \
    constexpr ConstColumnIterator                                                                                      \
    cendColumn(size_type column) const {return ConstColumnIterator {&m_data[0][0], column, M};}                        \
                                                                                                                       \
    /**
     * Get an iterator pointing to the last component in the specified column.
     */                                                                                                                \
    constexpr ReverseColumnIterator                                                                                    \
    rbeginColumn(size_type column) {return ReverseColumnIterator {endColumn(column)};}                                 \
                                                                                                                       \
    /**
     * Get an iterator pointing to the component before the first in the specified column.
     */                                                                                                                \
    constexpr ReverseColumnIterator                                                                                    \
    rendColumn(size_type column) {return ReverseColumnIterator {beginColumn(column)};}                                 \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the last component in the specified column.
     */                                                                                                                \
    constexpr ConstReverseColumnIterator                                                                               \
    rbeginColumn(size_type column) const {return ConstReverseColumnIterator {endColumn(column)};}                      \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */                                                                                                                \
    constexpr ConstReverseColumnIterator                                                                               \
    rendColumn(size_type column) const {return ConstReverseColumnIterator {beginColumn(column)};}                      \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the last component in the specified column.
     */                                                                                                                \
    constexpr ConstReverseColumnIterator                                                                               \
    crbeginColumn(size_type column) const {return ConstReverseColumnIterator {cendColumn(column)};}                    \
                                                                                                                       \
    /**
     * Get an const iterator pointing to the component before the first in the specified column.
     */                                                                                                                \
    constexpr ConstReverseColumnIterator                                                                               \
    crendColumn(size_type column) const {return ConstReverseColumnIterator {cbeginColumn(column)};}
/* ################################################################################################################## */


template<size_t M, size_t N, typename T=FLOAT, typename = void>
struct Matrix
{
    MATH3D_MATRIX_COMMON_BODY
};

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
struct Matrix <M, N, T, std::enable_if_t<(M == N)>>
{
    MATH3D_MATRIX_COMMON_BODY

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    /**
     * Get reference to identity matrix.
     * @return const reference to identity matrix.
     */
    const static Matrix<M,M,T>&
    identity()
    {
        static const Matrix<M,M,T> mat { makeIdentity() }; return mat;
    }

    /**
     * Create identity matrix.
     * @return copy of identity matrix.
     */
    constexpr static Matrix<M,M,T>
    makeIdentity()
    {
        if constexpr (M==2)
        {
            return Matrix<M,M,T>
            {
                1, 0,
                0, 1
            };
        }
        else if constexpr (M==3)
        {
            return Matrix<M,M,T>
            {
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
            };
        }
        else if constexpr (M==4)
        {
            return Matrix<M,M,T>
            {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            };
        }
        else
        {
            Matrix<M, M, T> matrix(static_cast<T>(0));
            for (auto i = 0; i < M; ++i) matrix(i,i) = static_cast<T>(1);
            return matrix;
        }
    }
};

#endif // MATH3D_MATRIX_HPP
