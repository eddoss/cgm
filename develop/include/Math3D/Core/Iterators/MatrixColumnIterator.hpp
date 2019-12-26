#ifndef MATH3D_ITERATORS_MATRIX_COLUMN_ACCESS_HPP
#define MATH3D_ITERATORS_MATRIX_COLUMN_ACCESS_HPP


#include <iterator>

/**
 *
 **/
template<uint32_t M, uint32_t N, typename T>
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
    using difference_type       = ptrdiff_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    ConstMatrixColumnIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(pointer dataPtr, uint32_t index, uint32_t element=0)
        : ptr(dataPtr + index*M + element)
    {

    }

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        return *ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        return ptr;
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++ptr;
        return (*this);
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++ptr;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        ptr += offset;
        return (*this);
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(size_t offset) const
    {
        self_type tmp = (*this);
        tmp.ptr += offset;
        return tmp;
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        --ptr;
        return (*this);
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --ptr;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        ptr -= offset;
        return (*this);
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(size_t offset) const
    {
        self_type tmp = (*this);
        tmp.ptr -= offset;
        return tmp;
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return ptr-other.ptr;
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return ptr == other.ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return ptr != other.ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return ptr < other.ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return ptr > other.ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return ptr <= other.ptr;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return ptr >= other.ptr;
    }

/* ####################################################################################### */
private: /* Internal */
/* ####################################################################################### */

    pointer ptr {nullptr};
};




template<uint32_t M, uint32_t N, typename T>
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
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = ptrdiff_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    MatrixColumnIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixColumnIterator(pointer dataPtr, uint32_t index, uint32_t element=0)
        : base_type(dataPtr, index, element)
    {

    }

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

#endif // MATH3D_ITERATORS_MATRIX_COLUMN_ACCESS_HPP
