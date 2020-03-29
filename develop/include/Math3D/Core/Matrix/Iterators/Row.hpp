#ifndef MATH3D_MATRIX_ROW_ITERATOR_HPP
#define MATH3D_MATRIX_ROW_ITERATOR_HPP


#include <Math3D/Global.hpp>
#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif

MATH3D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_ROW(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_COLUMN(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

#else

    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_SELECTOR(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_FORWARD(current, end, message)
    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_BACKWARD(current, begin, message)
    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_ROW(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif


template<size_t M, size_t N, typename T>
class ConstMatrixRowIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixRowIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = int64_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    ConstMatrixRowIterator(pointer firstComponentPointer, size_t row, size_t column)
        : m_row(row)
        , m_column(column + 1)
    #ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
        , m_begin(firstComponentPointer + row * N)
    #else
        , m_begin(firstComponentPointer + row)
    #endif
    {
        recalculateDataAddress();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator()                        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator(const self_type&)        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator(self_type&&) noexcept    = default;

/* --------------------------------------------------------------------------------------- */

   ~ConstMatrixRowIterator()                        = default;

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
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_DEREFERENCE(m_column, 1, N + 1, "(Math3D) can't dereference out of range matrix iterator.")
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_SELECTOR(m_column, 1, N + 1, "(Math3D) can't call selector of out of range matrix iterator.")
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_column;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_FORWARD(m_column, N + 1, "(Math3D) can't pre-increment matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_column;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_FORWARD(m_column, N + 1, "(Math3D) can't post-increment matrix iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        m_column += offset;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_FORWARD(m_column, N + 1, "(Math3D) can't move matrix iterator forward after end.")
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
        --m_column;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_BACKWARD(m_column, 1, "(Math3D) can't pre-decrement matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_column;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_BACKWARD(m_column, 1, "(Math3D) can't post-decrement matrix iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        m_column -= offset;
        recalculateDataAddress();
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_BACKWARD(m_column, 1, "(Math3D) can't move matrix iterator backward before begin.")
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
        return static_cast<difference_type>(m_column - other.m_column);
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return m_column == other.m_column;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return m_column != other.m_column;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return m_column < other.m_column;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return m_column > other.m_column;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return m_column <= other.m_column;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return m_column >= other.m_column;
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
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_ROW(m_column, 1, N + 1, "(Math3D) can't get row from matrix iterator (out of range).")
        return m_row;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the current component.
     * @return Current component column index.
     */
    constexpr size_t
    column() const
    {
        MATH3D_VERIFY_MATRIX_ROW_ITERATOR_GET_COLUMN(m_column, 1, N + 1, "(Math3D) can't get column from matrix iterator (out of range).")
        return m_column - 1;
    }

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    size_t
    m_row       {0};

    size_t
    m_column    {0};

    pointer
    m_data      {nullptr};

    pointer
    m_begin     {nullptr};

    /* --------------------------------------------------------------------------------------- */

    constexpr void
    recalculateDataAddress()
    {
    #ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
        m_data = m_begin + (m_column - 1);
    #else
        m_data = m_begin + (M * (m_column - 1));
    #endif
    }
};





template<size_t M, size_t N, typename T>
class MatrixRowIterator : public ConstMatrixRowIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = MatrixRowIterator<M,N,T>;
    using base_type             = ConstMatrixRowIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    MatrixRowIterator(pointer firstComponentPointer, size_t row, size_t column)
        : base_type(firstComponentPointer, row, column) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixRowIterator()                         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixRowIterator(const self_type&)         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixRowIterator(self_type&&) noexcept     = default;

/* --------------------------------------------------------------------------------------- */

    ~MatrixRowIterator()                        = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr self_type&
    operator=(const self_type&)                 = default;

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator=(self_type&&) noexcept             = default;

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
        return (*static_cast<const base_type*>(this) - other);
    }
};

MATH3D_NAMESPACE_END

#endif // MATH3D_MATRIX_ROW_ITERATOR_HPP
