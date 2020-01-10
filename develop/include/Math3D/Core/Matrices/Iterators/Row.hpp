#ifndef MATH3D_MATRIX_ROW_ITERATOR_HPP
#define MATH3D_MATRIX_ROW_ITERATOR_HPP


#include <Math3D/Core/Matrices/Iterators/Default.hpp>


/**
 * Iterate over all components of specified row.
 */
template<size_t M, size_t N, typename T>
class ConstMatrixRowIterator : public ConstMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixRowIterator<M,N,T>;
    using base_type             = ConstMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~ConstMatrixRowIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixRowIterator(pointer firstCompPtr, size_t rowIndex, size_t elementIndex=0)
        : base_type(firstCompPtr, rowIndex, elementIndex)
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstMatrixRowIterator&
    operator=(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstMatrixRowIterator&
    operator=(self_type&&) noexcept  = default;

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        *(static_cast<base_type*>(this)) += M;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp {*this};
        *(static_cast<base_type*>(this)) += M;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        *(static_cast<base_type*>(this)) += M * offset;
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
        *(static_cast<base_type*>(this)) -= M;
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp {*this};
        *(static_cast<base_type*>(this)) -= M;
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        *(static_cast<base_type*>(this)) -= M * offset;
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
        size_t beforeLeft = this->m_row * N + this->m_col;
        size_t beforeRight = other.m_row * N + other.m_col;

        if (beforeLeft > beforeRight)
        {
            return beforeLeft - beforeRight;
        }
        else
        {
            return beforeRight - beforeLeft;
        }
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
    MatrixRowIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixRowIterator(pointer dataPtr, size_t index, size_t element=0)
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

#endif // MATH3D_MATRIX_ROW_ITERATOR_HPP
