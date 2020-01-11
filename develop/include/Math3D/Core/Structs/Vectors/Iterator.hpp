#ifndef MATH3D_VECTOR_ITERATOR_HPP
#define MATH3D_VECTOR_ITERATOR_HPP


#include <iterator>


/**
 * Iterate over vector components.
 */
template<typename T>
class ConstVectorIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstVectorIterator<T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = size_t;

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
    ConstVectorIterator(pointer dataPtr, size_t offset=0)
        : m_data(dataPtr + offset)
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
        return *m_data;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        return m_data;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_data;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_data;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        m_data += offset;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(size_t offset) const
    {
        self_type tmp = *this;
        tmp.m_data += offset;
        return tmp;
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        --m_data;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_data;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        m_data -= offset;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(size_t offset) const
    {
        self_type tmp = *this;
        tmp.m_data -= offset;
        return tmp;
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return m_data - other.m_data;
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

    pointer m_data {nullptr};
};



template<typename T>
class VectorIterator : public ConstVectorIterator<T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = VectorIterator<T>;
    using base_type             = ConstVectorIterator<T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~VectorIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    VectorIterator(pointer dataPtr, size_t offset=0)
        : base_type(dataPtr, offset)
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr VectorIterator&
    operator=(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr VectorIterator&
    operator=(self_type&&) noexcept = default;

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
        ++*static_cast<base_type*>(this);
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
		self_type tmp = *this;
		++*this;
		return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
		*static_cast<base_type*>(this) += offset;
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(size_t offset) const
    {
		self_type tmp = *this;
		return tmp += offset;
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        --*static_cast<base_type*>(this);
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
		self_type tmp = *this;
		--*this;
		return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
		*static_cast<base_type*>(this) -= offset;
		return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(size_t offset) const
    {
		self_type tmp = *this;
		return tmp -= offset;
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
