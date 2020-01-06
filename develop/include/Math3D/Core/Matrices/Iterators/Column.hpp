#ifndef MATH3D_MATRIX_COLUMN_ITERATOR_HPP
#define MATH3D_MATRIX_COLUMN_ITERATOR_HPP


#include <Math3D/Core/Matrices/Iterators/Default.hpp>


/**
 * Iterate over all components of specified column.
 **/
template<size_t M, size_t N, typename T>
class ConstMatrixColumnIterator : public ConstMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixColumnIterator<M,N,T>;
    using base_type             = ConstMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~ConstMatrixColumnIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixColumnIterator(pointer firstCompPtr, size_t columnIndex, size_t elementIndex=0)
        : base_type(firstCompPtr, elementIndex, columnIndex)
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstMatrixColumnIterator&
    operator=(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstMatrixColumnIterator&
    operator=(self_type&&) noexcept  = default;

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
        return *static_cast<const base_type*>(this) - other;
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
    MatrixColumnIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixColumnIterator(pointer dataPtr, size_t index, size_t element=0)
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
        return const_cast<pointer>(base_type::operator*());
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

#endif // MATH3D_MATRIX_COLUMN_ITERATOR_HPP
