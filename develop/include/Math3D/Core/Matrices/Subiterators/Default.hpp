#ifndef MATH3D_SUBMATRIX_ITERATOR_HPP
#define MATH3D_SUBMATRIX_ITERATOR_HPP


#include <algorithm>
#include <Math3D/Core/Matrices/Iterators/Default.hpp>


/**
 * Iterate over all components  of internal sub matrix of generic
 * matrix. You need specify top-left and bottom-right coordinates
 * of external matrix.
 *
 * @tparam M External matrix rows count.
 * @tparam N External matrix columns count.
 * @tparam T External matrix components type.
 */
template<size_t M, size_t N, typename T>
class ConstSubmatrixIterator : public ConstMatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ConstSubmatrixIterator<M,N,T>;
    using base_type             = ConstMatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = const T&;
    using pointer               = const T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;
    using SubRect               = std::pair<std::pair<size_t,size_t>, std::pair<size_t,size_t>>;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    ConstSubmatrixIterator(pointer firstCompPtr, const SubRect& subRect, size_t subRow, size_t subColumn)
        : base_type(firstCompPtr, subRect.first.first, subRect.first.second)
        , m_lt_row(subRect.first.first)
        , m_lt_col(subRect.first.second)
        , m_rb_row(subRect.second.first)
        , m_rb_col(subRect.second.second)
        , m_sub_row(subRow)
        , m_sub_col(subColumn)
    {
        if (m_lt_row > m_rb_row)
        {
            throw std::runtime_error("Submatrix top-left row id greater than bottom-right row id");
        }
        else if (m_lt_col > m_rb_col)
        {
            throw std::runtime_error("Submatrix top-left column id greater than bottom-right column id");
        }

        setupDataPointer();
    }

/* --------------------------------------------------------------------------------------- */

   ~ConstSubmatrixIterator()                     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstSubmatrixIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    ConstSubmatrixIterator(self_type&&) noexcept = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr ConstSubmatrixIterator&
    operator=(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr ConstSubmatrixIterator&
    operator=(self_type&&) noexcept   = default;

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        moveForward(1);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        moveForward(1);
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        moveForward(offset);
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
        moveBackward(1);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        moveBackward(1);
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        moveBackward(offset);
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
        if (m_lt_row != other.m_lt_row ||
            m_lt_col != other.m_lt_col ||
            m_rb_row != other.m_rb_row ||
            m_rb_col != other.m_rb_col)
        {
            throw std::runtime_error("Incompatible iterator. It must have the same sub rect.");
        }

        size_t rows {subRows()};
        size_t thisId {m_sub_col * rows + m_sub_row};
        size_t otherId {other.m_sub_col * rows + other.m_sub_row};

        if (thisId > otherId)
        {
            return thisId - otherId;
        }
        else
        {
            return otherId - thisId;
        }
    }

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Get submatrix rows count.
     * @return Submatrix rows count.
     */
    size_t
    subRows() const
    {
        return m_rb_row - m_lt_row + 1;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get submatrix columns count.
     * @return Submatrix columns count.
     */
    size_t
    subColumns() const
    {
        return m_rb_col - m_lt_col + 1;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get submatrix components count.
     * @return Submatrix components count.
     */
    size_t
    subSize() const
    {
        return subRows() * subColumns();
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get row index of the submatrix current component.
     * To get external matrix row index use row().
     * @return Submatrix row index.
     */
    size_t
    subRow() const
    {
        return m_sub_row;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get column index of the submatrix current component.
     * To get external matrix column index use column().
     * @return Submatrix column index.
     */
    size_t
    subColumn () const
    {
        return m_sub_col;
    }

/* ####################################################################################### */
protected: /* Internal fields */
/* ####################################################################################### */

    size_t
    m_lt_row    {0};    // submatrix left-top point row id

    size_t
    m_lt_col    {0};    // submatrix left-top point column id

    size_t
    m_rb_row    {0};    // submatrix right-bottom point row id

    size_t
    m_rb_col    {0};    // submatrix right-bottom point column id

    size_t
    m_sub_row   {0};    // id of submatrix current component row

    size_t
    m_sub_col   {0};    // id of submatrix current component column

/* ####################################################################################### */
protected: /* Support */
/* ####################################################################################### */

    /*
     * Move iterator forward on "offset" steps.
     */
    void
    moveForward(size_t offset)
    {
        goToID(m_sub_col * subRows() + m_sub_row + offset);
        setupDataPointer();
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Move iterator back on "offset" steps.
     */
    void
    moveBackward(size_t offset)
    {
        goToID(m_sub_col * subRows() + m_sub_row - offset);
        setupDataPointer();
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Setup internal data pointer. Call this method
     * when you change sub row or sub column.
     */
    void
    setupDataPointer()
    {
        size_t r = m_lt_row + m_sub_row;
        size_t c = m_lt_col + m_sub_col;
        size_t id = c * M + r;

        this->m_data = this->m_first + id;
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Move to component by index (inside submatrix).
     * @param id Index to go to.
     */
    void
    goToID(size_t id)
    {
        size_t rows = subRows();
        m_sub_col = id / rows;
        m_sub_row = id - m_sub_col * rows;
        this->m_row = m_lt_row + m_sub_row;
        this->m_col = m_lt_col + m_sub_col;
    }
};




/**
 * Non-const version of "ConstSubmatrixIterator".
 */
template<size_t M, size_t N, typename T>
class SubmatrixIterator : public ConstSubmatrixIterator<M,N,T>
{

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = SubmatrixIterator<M,N,T>;
    using base_type             = ConstSubmatrixIterator<M,N,T>;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using iterator_category     = typename base_type::iterator_category;
    using difference_type       = typename base_type::difference_type;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    SubmatrixIterator(pointer firstCompPtr, const typename base_type::SubRect& subRect, size_t subRow, size_t subColumn)
        : base_type(firstCompPtr, subRect, subRow, subColumn)
    {

    }

/* --------------------------------------------------------------------------------------- */

    ~SubmatrixIterator()                    = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    SubmatrixIterator(const self_type&)     = default;

/* --------------------------------------------------------------------------------------- */

    constexpr
    SubmatrixIterator(self_type&&) noexcept = default;

/* ####################################################################################### */
public: /* Default assignment */
/* ####################################################################################### */

    constexpr SubmatrixIterator&
    operator=(const self_type&)       = default;

/* --------------------------------------------------------------------------------------- */

    constexpr SubmatrixIterator&
    operator=(self_type&&) noexcept   = default;

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
        base_type::moveForward(1);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp = *this;
        base_type::moveForward(1);
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(size_t offset)
    {
        base_type::moveForward(offset);
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
        base_type::moveBackward(1);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp = *this;
        base_type::moveBackward(1);
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(size_t offset)
    {
        base_type::moveBackward(offset);
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

#endif // MATH3D_SUBMATRIX_ITERATOR_HPP
