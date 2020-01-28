#ifndef MATH3D_MATRIX_INDIRECT_ITERATOR_HPP
#define MATH3D_MATRIX_INDIRECT_ITERATOR_HPP


#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif

/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_GET_ROW(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_GET_COLUMN(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

#else

    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_SELECTOR(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_FORWARD(current, end, message)
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_BACKWARD(current, begin, message)
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_GET_ROW(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif


/**
 * Nonlinear iterator. Iterates over the components of a simple array, taking into
 * account the step and the offset from the beginning of the array. It works with a
 * two-dimensional array T arr [n][m], where [m] can be equal to [n]. To determine
 * the current row / column, you must specify a step. If a major row is used, then
 * the step should be equal to the number of columns in the matrix. For a major
 * column, the step should equal the number of rows in the matrix.
 *
 * @tparam Step Value to calculate current row/column.
 * @tparam T Matrix components type.
 */
template<size_t M, size_t N, typename T>
class ConstMatrixIndirectIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixIndirectIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = int64_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize iterator for a specific component.
     * @tparam index If a row-major is used, it represent a row id, column id otherwise.
     * @param element If a row-major is used, it represent a column id, row id otherwise.
     */
    constexpr
    ConstMatrixIndirectIterator(pointer firstComponentPointer, size_t index)
        : m_begin(firstComponentPointer)
        , m_id(index+1)
    {
        recalculateDataAddress();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIndirectIterator()                       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIndirectIterator(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIndirectIterator(self_type&&) noexcept   = default;

/* --------------------------------------------------------------------------------------- */

    ~ConstMatrixIndirectIterator()                      = default;


/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr self_type&
    operator=(const self_type&)                         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator=(self_type&&) noexcept                     = default;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_DEREFERENCE(m_id, 1, M*N+1, "(Math3D) can't dereference out of range matrix iterator.")
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_SELECTOR(m_id, 1, M*N+1, "(Math3D) can't call selector of out of range matrix iterator.")
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_id;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_FORWARD(m_id, M*N+1, "(Math3D) can't pre-increment matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_id;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_FORWARD(m_id, M*N+1, "(Math3D) can't post-increment matrix iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        m_id += offset;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_FORWARD(m_id, M*N+1, "(Math3D) can't move matrix iterator forward after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(difference_type offset) const
    {
		return self_type {*this} += offset;
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        --m_id;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_BACKWARD(m_id, 1, "(Math3D) can't pre-decrement matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_id;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_BACKWARD(m_id, 1, "(Math3D) can't post-decrement matrix iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        m_id -= offset;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_INDIRECT_ITERATOR_BACKWARD(m_id, 1, "(Math3D) can't move matrix iterator backward before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(difference_type offset) const
    {
		return self_type {*this} -= offset;
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return static_cast<difference_type>(m_id - other.m_id);
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return m_id == other.m_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return m_id != other.m_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return m_id < other.m_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return m_id > other.m_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return m_id <= other.m_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return m_id >= other.m_id;
    }

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Get row index of the current component.
     * @return Current component row index.
     */
    constexpr size_t
    row() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_ROW(m_id, 1, M*N+1, "(Math3D) can't get row from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        return (m_data - m_begin) / N;
    #else
        return (m_data - m_begin) - M * column();
    #endif
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the current component.
     * @return Current component column index.
     */
    constexpr size_t
    column() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_COLUMN(m_id, 1, M*N+1, "(Math3D) can't get column from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        return (m_data - m_begin) - N * row();
    #else
        return (m_data - m_begin) / M;
    #endif
    }

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    pointer
    m_begin     {nullptr};

    pointer
    m_data      {nullptr};

    size_t
    m_id        {0};

/* --------------------------------------------------------------------------------------- */

    constexpr void
    recalculateDataAddress()
    {
        size_t id {m_id - 1};
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        size_t c {id / M};
        size_t r {id - M * c};
        m_data = m_begin + (r * N + c);
    #else
        size_t r {id / N};
        size_t c {id - N * r};
        m_data = m_begin + (c * M + r);
    #endif
    }
};




template<size_t M, size_t N, typename T>
class MatrixIndirectIterator : public ConstMatrixIndirectIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = MatrixIndirectIterator<M,N,T>;
    using base_type             = ConstMatrixIndirectIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    MatrixIndirectIterator(pointer firstComponentPointer, size_t index)
        : base_type(firstComponentPointer, index) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIndirectIterator()                        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIndirectIterator(const self_type&)        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIndirectIterator(self_type&&) noexcept    = default;

/* --------------------------------------------------------------------------------------- */

    ~MatrixIndirectIterator()                       = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr self_type&
    operator=(const self_type&)                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator=(self_type&&) noexcept                 = default;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        return const_cast<reference>(base_type::operator*());
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        return const_cast<pointer>(base_type::operator->());
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        base_type::operator++();
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
		self_type tmp {*this};
		base_type::operator++();
		return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
		base_type::operator+=(offset);
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(difference_type offset) const
    {
		return self_type {*this} += offset;
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        base_type::operator--();
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
		self_type tmp {*this};
		base_type::operator--();
		return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
		base_type::operator-=(offset);
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(difference_type offset) const
    {
        return self_type {*this} -= offset;
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return base_type::operator-(other);
    }
};

#endif // MATH3D_MATRIX_INDIRECT_ITERATOR_HPP
