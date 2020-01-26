#ifndef MATH3D_MATRIX_ROW_ITERATOR_HPP
#define MATH3D_MATRIX_ROW_ITERATOR_HPP


#include <Math3D/Core/Structs/Matrices/Iterators/Direct.hpp>


/**
 * Nonlinear iterator. Iterates over the components of a simple array, taking into
 * account the step and the offset from the beginning of the array. It works with a
 * two-dimensional array T arr [n][m], where [m] can be equal to [n]. To determine
 * the current row / column, you must specify a step. If a major row is used, then
 * the step should be equal to the number of columns in the matrix. For a major
 * column, the step should equal the number of rows in the matrix.
 *
 * @tparam Step Value to calculate current row/column.
 * @tparam T Matrix components type.
 */
template<size_t M, size_t N, typename T>
class ConstIndirectMatrixIterator : public ConstDirectMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstIndirectMatrixIterator<M,N,T>;
    using base_type             = ConstDirectMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize iterator for a specific component.
     * @tparam index If a row-major is used, it represent a row id, column id otherwise.
     * @param element If a row-major is used, it represent a column id, row id otherwise.
     */
    constexpr
    ConstIndirectMatrixIterator(pointer firstComponentPointer, size_t current, size_t begin, size_t end)
        : base_type(firstComponentPointer, 0, begin, end)
        , m_indirect_id(current)
    {
        recalculateDirectId();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstIndirectMatrixIterator()                       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstIndirectMatrixIterator(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstIndirectMatrixIterator(self_type&&) noexcept   = default;

/* --------------------------------------------------------------------------------------- */

    ~ConstIndirectMatrixIterator()                      = default;


/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstIndirectMatrixIterator&
    operator=(const self_type&)                         = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstIndirectMatrixIterator&
    operator=(self_type&&) noexcept                     = default;

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        ++m_indirect_id;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(this->m_direct_id, this->m_end, "(Math3D) can't pre-increment matrix indirect iterator after end.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        ++m_indirect_id;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(this->m_direct_id, this->m_end, "(Math3D) can't post-increment matrix indirect iterator after end.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        m_indirect_id += offset;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_FORWARD(this->m_direct_id, this->m_end, "(Math3D) can't move matrix indirect iterator forward after end.")
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
        --m_indirect_id;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(this->m_direct_id, this->m_begin, "(Math3D) can't pre-decrement matrix indirect iterator before begin.")
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        --m_indirect_id;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(this->m_direct_id, this->m_begin, "(Math3D) can't post-decrement matrix indirect iterator before begin.")
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        m_indirect_id -= offset;
        recalculateDirectId();
        MATH3D_VERIFY_MATRIX_ITERATOR_BACKWARD(this->m_direct_id, this->m_begin, "(Math3D) can't move matrix indirect iterator backward before begin.")
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
        return m_indirect_id - other.m_indirect_id;
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator==(const self_type& other) const
    {
        return m_indirect_id == other.m_indirect_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator!=(const self_type& other) const
    {
        return m_indirect_id != other.m_indirect_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<(const self_type& other) const
    {
        return m_indirect_id < other.m_indirect_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return m_indirect_id > other.m_indirect_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return m_indirect_id <= other.m_indirect_id;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return m_indirect_id >= other.m_indirect_id;
    }

/* ####################################################################################### */
protected: /* Internal */
/* ####################################################################################### */

    size_t
    m_indirect_id   {0};

/* --------------------------------------------------------------------------------------- */

    void
    recalculateDirectId()
    {
    #ifdef MATH3D_USE_ROW_MAJOR_MAPPING
        size_t c = m_indirect_id/M;
        size_t r = m_indirect_id - M * c;
        this->m_direct_id = r * N + c;
    #else
        size_t r = m_indirect_id/N;
        size_t c = m_indirect_id - N * r;
        this->m_direct_id = c * M + r;
    #endif
    }
};




template<size_t M, size_t N, typename T>
class IndirectMatrixIterator : public ConstIndirectMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = IndirectMatrixIterator<M,N,T>;
    using base_type             = ConstIndirectMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    constexpr
    IndirectMatrixIterator() = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    IndirectMatrixIterator(pointer firstComponentPointer, size_t current, size_t begin, size_t end)
        : base_type(firstComponentPointer, current, begin, end)
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
