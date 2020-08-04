#pragma once


#include <CGM/Global.hpp>
#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_ROW(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_COLUMN(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

#else

    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_SELECTOR(current, begin, end, message)
    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_FORWARD(current, end, message)
    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_BACKWARD(current, begin, message)
    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_ROW(current, begin, end, message)
    #define CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif



template<size_t M, size_t N, typename T>
class ConstMatrixColumnIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixColumnIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = int64_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    ConstMatrixColumnIterator(pointer firstComponentPointer, size_t column, size_t row)
        : m_row(row+1)
        , m_column(column)
    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        , m_begin(firstComponentPointer + column)
    #else
        , m_begin(firstComponentPointer + column * M)
    #endif
    {
        recalculateDataAddress();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator()                         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(const self_type&)         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(self_type&&) noexcept     = default;

/* --------------------------------------------------------------------------------------- */

   ~ConstMatrixColumnIterator()                         = default;

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
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_DEREFERENCE(m_row, 1, M + 1, "(CGM) can't dereference out of range matrix iterator.")
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_SELECTOR(m_row, 1, M + 1, "(CGM) can't call selector of out of range matrix iterator.")
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_row;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_FORWARD(m_row, M + 1, "(CGM) can't pre-increment matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_row;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_FORWARD(m_row, M + 1, "(CGM) can't post-increment matrix iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        m_row += offset;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_FORWARD(m_row, M + 1, "(CGM) can't move matrix iterator forward after end.")
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
        --m_row;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_BACKWARD(m_row, 1, "(CGM) can't pre-decrement matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_row;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_BACKWARD(m_row, 1, "(CGM) can't post-decrement matrix iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        m_row -= offset;
        recalculateDataAddress();
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_BACKWARD(m_row, 1, "(CGM) can't move matrix iterator backward before begin.")
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
        return static_cast<difference_type>(m_row - other.m_row);
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return m_row == other.m_row;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return m_row != other.m_row;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return m_row < other.m_row;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return m_row > other.m_row;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return m_row <= other.m_row;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return m_row >= other.m_row;
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
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_ROW(m_row, 1, M + 1, "(CGM) can't get row from matrix iterator (out of range).")
        return m_row - 1;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the current component.
     * @return Current component column index.
     */
    constexpr size_t
    column() const
    {
        CGM_VERIFY_MATRIX_COLUMN_ITERATOR_GET_COLUMN(m_row, 1, M + 1, "(CGM) can't get column from matrix iterator (out of range).")
        return m_column;
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
    #ifdef CGM_USE_ROW_WISE_MATRIX_STORING
        m_data = m_begin + (N * (m_row - 1));
    #else
        m_data = m_begin + (m_row - 1);
    #endif
    }
};





template<size_t M, size_t N, typename T>
class MatrixColumnIterator : public ConstMatrixColumnIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = MatrixColumnIterator<M,N,T>;
    using base_type             = ConstMatrixColumnIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    MatrixColumnIterator(pointer firstComponentPointer, size_t column, size_t row)
        : base_type(firstComponentPointer, column, row) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixColumnIterator()                      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixColumnIterator(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixColumnIterator(self_type&&) noexcept  = default;

/* --------------------------------------------------------------------------------------- */

    ~MatrixColumnIterator()                     = default;

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

CGM_NAMESPACE_END