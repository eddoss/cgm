#ifndef MATH3D_MATRIX_ITERATOR_HPP
#define MATH3D_MATRIX_ITERATOR_HPP


#include <iterator>


/**
 * Pointer based random access matrix const iterator.
 **/
template<size_t M, size_t N, typename T>
class ConstMatrixIterator
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = size_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~ConstMatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstMatrixIterator(pointer firstCompPtr, size_t row, size_t column)
        : m_data(firstCompPtr + column * M + row)
        , m_first(firstCompPtr)
        , m_row(row)
        , m_column(column)
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstMatrixIterator&
    operator=(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstMatrixIterator&
    operator=(self_type&&) noexcept   = default;

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
        calcRowColumn();
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_data;
        calcRowColumn();
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        m_data += offset;
        calcRowColumn();
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
        calcRowColumn();
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_data;
        calcRowColumn();
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        m_data -= offset;
        calcRowColumn();
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
        if (m_data > other.m_data)
        {
            return m_data - other.m_data;
        }
        else
        {
            return other.m_data - m_data;
        }
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
     **/
    size_t
    row() const {return m_row;}

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the current component.
     * @return Current component column index.
     **/
    size_t
    column() const {return m_column;}

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    pointer
    m_data      {nullptr};

    pointer
    m_first     {nullptr};

    size_t
    m_row       {0};

    size_t
    m_column    {0};

    void
    calcRowColumn()
    {

        difference_type offset {static_cast<difference_type>(m_data - m_first)};
        m_row = offset % M;
        m_column = (offset-m_row) / M;
    }
};




/**
 * Pointer based random access matrix iterator.
 **/
template<size_t M, size_t N, typename T>
class MatrixIterator : public ConstMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = MatrixIterator<M,N,T>;
    using base_type             = ConstMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = std::random_access_iterator_tag;
    using difference_type       = size_t;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

   ~MatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIterator(self_type&&) noexcept = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    MatrixIterator(pointer firstCompPtr, size_t row, size_t column)
        : base_type(firstCompPtr, row, column)
    {

    }

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr MatrixIterator&
    operator=(const self_type&)      = default;

/* --------------------------------------------------------------------------------------- */

    constexpr MatrixIterator&
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
