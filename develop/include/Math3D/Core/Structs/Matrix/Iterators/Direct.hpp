#ifndef MATH3D_MATRIX_DIRECT_ITERATOR_HPP
#define MATH3D_MATRIX_DIRECT_ITERATOR_HPP


#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif


/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_ROW(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_COLUMN(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

#else

    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_SELECTOR(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_FORWARD(current, end, message)
    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_BACKWARD(current, begin, message)
    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_ROW(current, begin, end, message)
    #define MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif



template<size_t M, size_t N, typename T>
class ConstMatrixDirectIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixDirectIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = int64_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    ConstMatrixDirectIterator(pointer firstComponentPointer, size_t index)
        : m_begin(firstComponentPointer)
        , m_data(firstComponentPointer + index)
    {

    }

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixDirectIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixDirectIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixDirectIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

   ~ConstMatrixDirectIterator()                     = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstMatrixDirectIterator&
    operator=(const self_type&)                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstMatrixDirectIterator&
    operator=(self_type&&) noexcept                 = default;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_DEREFERENCE(m_data, m_begin, m_begin + M*N, "(Math3D) can't dereference out of range matrix iterator.")
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_SELECTOR(m_data, m_begin, m_begin + M*N, "(Math3D) can't call selector of out of range matrix iterator.")
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_data;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_FORWARD(m_data, m_begin + M*N, "(Math3D) can't pre-increment matrix iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_data;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_FORWARD(m_data, m_begin + M*N, "(Math3D) can't post-increment matrix iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        m_data += offset;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_FORWARD(m_data, m_begin + M*N, "(Math3D) can't move matrix iterator forward after end.")
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
        --m_data;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't pre-decrement matrix iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_data;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't post-decrement matrix iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        m_data -= offset;
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't move matrix iterator backward before begin.")
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
        return static_cast<difference_type>(m_data - other.m_data);
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return m_data == other.m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return m_data != other.m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return m_data < other.m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return m_data > other.m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return m_data <= other.m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return m_data >= other.m_data;
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
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_ROW(m_data, m_begin, m_begin + M*N, "(Math3D) can't get row from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
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
        MATH3D_VERIFY_MATRIX_DIRECT_ITERATOR_GET_COLUMN(m_data, m_begin, m_begin + M*N, "(Math3D) can't get column from matrix iterator (out of range).")
    #ifdef MATH3D_USE_ROW_WISE_MATRIX_STORING
        return (m_data - m_begin) - N * row();
    #else
        return (m_data - m_begin) / M;
    #endif
    }

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    pointer
    m_begin {nullptr};

    pointer
    m_data  {nullptr};
};





template<size_t M, size_t N, typename T>
class MatrixDirectIterator : public ConstMatrixDirectIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = MatrixDirectIterator<M,N,T>;
    using base_type             = ConstMatrixDirectIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    MatrixDirectIterator(pointer firstComponentPointer, size_t index)
        : base_type(firstComponentPointer, index) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixDirectIterator()                      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixDirectIterator(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixDirectIterator(self_type&&) noexcept  = default;

/* --------------------------------------------------------------------------------------- */

    ~MatrixDirectIterator()                     = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr MatrixDirectIterator&
    operator=(const self_type&)                 = default;

/* --------------------------------------------------------------------------------------- */

    constexpr MatrixDirectIterator&
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

#endif // MATH3D_MATRIX_DIRECT_ITERATOR_HPP
