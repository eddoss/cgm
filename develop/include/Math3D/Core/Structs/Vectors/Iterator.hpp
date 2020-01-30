#ifndef MATH3D_VECTOR_ITERATOR_HPP
#define MATH3D_VECTOR_ITERATOR_HPP


#include <iterator>
#ifdef NDEBUG
    #include <stdexcept>
#endif


/* ####################################################################################### */
/* Debug verifiers */
/* ####################################################################################### */

#ifndef NDEBUG

    #define MATH3D_VERIFY_VECTOR_ITERATOR_DEREFERENCE(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_VECTOR_ITERATOR_SELECTOR(current, begin, end, message) \
    if (current >= end || current < begin) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_VECTOR_ITERATOR_FORWARD(current, end, message) \
    if (current > end) {throw std::range_error(message);}

/* --------------------------------------------------------------------------------------- */

    #define MATH3D_VERIFY_VECTOR_ITERATOR_BACKWARD(current, begin, message) \
    if (current < begin) {throw std::range_error(message);}

#else

    #define MATH3D_VERIFY_VECTOR_ITERATOR_DEREFERENCE(current, begin, end, message)
    #define MATH3D_VERIFY_VECTOR_ITERATOR_SELECTOR(current, begin, end, message)
    #define MATH3D_VERIFY_VECTOR_ITERATOR_FORWARD(current, end, message)
    #define MATH3D_VERIFY_VECTOR_ITERATOR_BACKWARD(current, begin, message)
    #define MATH3D_VERIFY_VECTOR_ITERATOR_GET_ROW(current, begin, end, message)
    #define MATH3D_VERIFY_VECTOR_ITERATOR_GET_COLUMN(current, begin, end, message)

#endif


template<size_t D, typename T>
class ConstVectorIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstVectorIterator<D,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = int64_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~ConstVectorIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstVectorIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstVectorIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstVectorIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstVectorIterator(pointer firstComponentPointer, size_t index)
        : m_data(firstComponentPointer + index)
    #ifndef NDEBUG
        , m_begin(firstComponentPointer)
    #endif
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstVectorIterator&
    operator=(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstVectorIterator&
    operator=(self_type&&) noexcept = default;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        MATH3D_VERIFY_VECTOR_ITERATOR_DEREFERENCE(m_data, m_begin, m_begin + D, "(Math3D) can't dereference out of range vector iterator.")
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        MATH3D_VERIFY_VECTOR_ITERATOR_SELECTOR(m_data, m_begin, m_begin + D, "(Math3D) can't call selector of out of range vector iterator.")
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        MATH3D_VERIFY_VECTOR_ITERATOR_FORWARD(m_data, m_begin + D, "(Math3D) can't pre-increment vector iterator after end.")
        ++m_data;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        MATH3D_VERIFY_VECTOR_ITERATOR_FORWARD(m_data, m_begin + D, "(Math3D) can't post-increment vector iterator after end.")
        self_type tmp {*this};
        ++m_data;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        MATH3D_VERIFY_VECTOR_ITERATOR_FORWARD(m_data, m_begin + D, "(Math3D) can't move vector iterator forward after end.")
        m_data += offset;
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
        --m_data;
        MATH3D_VERIFY_VECTOR_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't pre-decrement vector iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_data;
        MATH3D_VERIFY_VECTOR_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't post-decrement vector iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        m_data -= offset;
        MATH3D_VERIFY_VECTOR_ITERATOR_BACKWARD(m_data, m_begin, "(Math3D) can't move vector iterator backward before begin.")
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
        return static_cast<difference_type>(m_data-other.m_data);
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
protected: /* Internal */
/* ####################################################################################### */

    pointer
    m_data  {nullptr};

#ifndef NDEBUG
    pointer
    m_begin {nullptr};
#endif
};



template<size_t D, typename T>
class VectorIterator : public ConstVectorIterator<D,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = VectorIterator<D,T>;
    using base_type             = ConstVectorIterator<D,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    VectorIterator(pointer dataPtr, size_t offset=0)
        : base_type(dataPtr, offset) {}

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator()                        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator(const self_type&)        = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator(self_type&&) noexcept    = default;

/* --------------------------------------------------------------------------------------- */

    ~VectorIterator()                       = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr VectorIterator&
    operator=(const self_type&)             = default;

/* --------------------------------------------------------------------------------------- */

    constexpr VectorIterator&
    operator=(self_type&&) noexcept         = default;

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

#endif // MATH3D_VECTOR_ITERATOR_HPP
