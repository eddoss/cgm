#ifndef MATH3D_MATRIX_ITERATOR_HPP
#define MATH3D_MATRIX_ITERATOR_HPP


#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif


/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define MATH3D_VERIFY_MATRIX_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ITERATOR_GET_ROW(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_ITERATOR_GET_COLUMN(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

#else

    #define MATH3D_VERIFY_MATRIX_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ITERATOR_SELECTOR(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(current, end, message)
    #define MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(current, begin, message)
    #define MATH3D_VERIFY_MATRIX_ITERATOR_GET_ROW(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif


/**
 * Linear iterator. Iterates over the components of a simple array one by one.
 * It works with a two-dimensional array T arr [n][m], where [m] can be equal to [n].
 * To determine the current row/column, you must specify a step. If a row-major
 * is used, then the step should be equal to the number of columns in the matrix.
 * For a column-major the step should equal the number of rows in the matrix.
 *
 * @tparam Step Value to calculate current row/column.
 * @tparam T Matrix components type.
 */
template<size_t M, size_t N, typename T>
class ConstDirectMatrixIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstDirectMatrixIterator<M,N,T>;
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
     * @param index If a row-major is used, it represent a row id, column id otherwise.
     * @param element If a row-major is used, it represent a column id, row id otherwise.
     */
    constexpr
    ConstDirectMatrixIterator(pointer firstCompPtr, size_t index)
        : m_begin(firstCompPtr)
        , m_end(firstCompPtr + M*N + 1)
        , m_id(index)
    {

    }

/* --------------------------------------------------------------------------------------- */

   ~ConstDirectMatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstDirectMatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstDirectMatrixIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstDirectMatrixIterator(self_type&&) noexcept = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstDirectMatrixIterator&
    operator=(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstDirectMatrixIterator&
    operator=(self_type&&) noexcept   = default;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        MATH3D_VERIFY_MATRIX_ITERATOR_DEREFERENCE(m_begin + m_id, m_begin, m_end, "(Math3D) can't dereference out of range matrix iterator.")
        return *(m_begin + m_id);
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        MATH3D_VERIFY_MATRIX_ITERATOR_SELECTOR(m_begin + m_id, m_begin, m_end, "(Math3D) can't call selector of out of range matrix iterator.")
        return m_begin + m_id;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_id;
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(m_begin + m_id, m_end, "(Math3D) can't pre-increment matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_id;
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(m_begin + m_id, m_end, "(Math3D) can't post-increment matrix iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        m_id += offset;
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(m_begin + m_id, m_end, "(Math3D) can't seek matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(size_t offset) const
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
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(m_begin + m_id, m_begin, "(Math3D) can't pre-decrement matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_id;
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(m_begin + m_id, m_begin, "(Math3D) can't post-decrement matrix iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        m_id -= offset;
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(m_begin + m_id, m_begin, "(Math3D) can't seek matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(size_t offset) const
    {
		return self_type {*this} -= offset;
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return static_cast<difference_type>(m_id-other.m_id);
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
    size_t
    row() const
    {
        MATH3D_VERIFY_MATRIX_ITERATOR_GET_ROW(m_begin+m_id, m_begin, m_end, "(Math3D) can't get row from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        return m_id % N;
    #else
        return m_id % M;
    #endif
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the current component.
     * @return Current component column index.
     */
    size_t
    column() const
    {
        MATH3D_VERIFY_MATRIX_ITERATOR_GET_COLUMN(m_begin+m_id, m_begin, m_end, "(Math3D) can't get column from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        return (m_id - m_id % N) / N;
    #else
        return (m_id - m_id % M) / M;
    #endif
    }

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    pointer
    m_begin     {nullptr};

    pointer
    m_end       {nullptr};

    size_t
    m_id        {0};
};





template<size_t M, size_t N, typename T>
class DirectMatrixIterator : public ConstDirectMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = DirectMatrixIterator<M,N,T>;
    using base_type             = ConstDirectMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    DirectMatrixIterator(pointer firstCompPtr, size_t index)
        : base_type(firstCompPtr, index) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    DirectMatrixIterator()                      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    DirectMatrixIterator(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    DirectMatrixIterator(self_type&&) noexcept  = default;

/* --------------------------------------------------------------------------------------- */

    ~DirectMatrixIterator()                     = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr DirectMatrixIterator&
    operator=(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr DirectMatrixIterator&
    operator=(self_type&&) noexcept  = default;

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
    operator+=(size_t offset)
    {
        base_type::operator+=(offset);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(size_t offset) const
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
    operator-=(size_t offset)
    {
        base_type::operator-=(offset);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(size_t offset) const
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

#endif // MATH3D_MATRIX_ITERATOR_HPP