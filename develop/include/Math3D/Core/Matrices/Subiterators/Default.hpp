#ifndef MATH3D_SUBMATRIX_ITERATOR_HPP
#define MATH3D_SUBMATRIX_ITERATOR_HPP


#include <algorithm>
#include <Math3D/Core/Matrices/Iterators/Default.hpp>


/**
 * It iterate over all components  of internal submatrix of generic
 * matrix. You need specify top-left  and bottom-right coordinates 
 * of matrix. Also you can  setup excluded rows and columns.
 *
 * @tparam M External matrix rows count.
 * @tparam N External matrix columns count.
 * @tparam T External matrix components type..
 **/
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
    using ExcludedRows          = std::vector<size_t>;
    using ExcludedColumns       = std::vector<size_t>;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize external matrix and excluded rows and columns.
     * @param firstCompPtr External matrix first component pointer.
     * @param subRect Submatrix rectangle left-top and right-bottom coordinates.
     * @param excludedRows External matrix excluded rows numbers.
     * @param excludedColumns External matrix excluded columns numbers.
     **/
    ConstSubmatrixIterator(
        const T* firstCompPtr,
        const SubRect& subRect,
        const ExcludedRows& excludedRows,
        const ExcludedColumns& excludedColumns,
        size_t subRow,
        size_t subColumn
    )
        : base_type(firstCompPtr, 0, 0)
        , m_lt_row(subRect.first.first)
        , m_lt_col(subRect.first.second)
        , m_rb_row(subRect.second.first)
        , m_rb_col(subRect.second.second)
        , m_sub_row(subRow)
        , m_sub_col(subColumn)
    {
        validateSubRange();
        cleanupExcludedRowsColumns(excludedRows, excludedColumns);
        calculateRowsRealCount();
        calculateColumnsRealCount();
        m_sub_size = m_columns * m_rows;
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
        size_t thisId {m_sub_col * m_sub_row};
        size_t otherId {other.m_sub_col * other.m_sub_row};

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
     **/
    size_t
    subRows() const
    {
        return m_rows;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get submatrix columns count.
     * @return Submatrix columns count.
     **/
    size_t
    subColumns() const
    {
        return m_columns;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get submatrix components count.
     * @return Submatrix components count.
     **/
    size_t
    subSize() const
    {
        return m_rows*m_columns;
    }

/* --------------------------------------------------------------------------------------- */

    /**
     * Get row index of the submatrix current component.
     * To get external matrix row index use row().
     * @return Submatrix row index.
     **/
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
     **/
    size_t
    subColumn () const
    {
        return m_sub_col;
    }

/* ####################################################################################### */
protected: /* Internal fields */
/* ####################################################################################### */

    size_t
    m_rows      {0};    // real rows count

    size_t
    m_columns   {0};    // real columns count

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

    size_t
    m_sub_size  {0};    // submatrix components count

    ExcludedRows
    m_exrows;           // excluded rows (external matrix indices)

    ExcludedColumns
    m_excols;           // excluded columns (external matrix indices)

/* ####################################################################################### */
protected: /* Support for moving */
/* ####################################################################################### */

    /*
     * Move iterator forward on "offset" steps.
     */
    void
    moveForward(size_t offset)
    {
//        goToID(m_sub_col * m_rows + m_sub_row + offset);
        if (m_sub_col >= )
        setupDataPointer();
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Move iterator back on "offset" steps.
     */
    void
    moveBackward(size_t offset)
    {
        goToID(m_sub_col * m_rows + m_sub_row - offset);
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
     * Move to component by index.
     * If index is out of range, index will be clamped.
     * @param id Index to go to.
     */
    void
    goToID(size_t id)
    {
        m_sub_col = id / m_rows;
        m_sub_row = id - m_sub_col * m_rows;
    }

/* ####################################################################################### */
protected: /* Support for constructors */
/* ####################################################################################### */

    /*
     * Validate submatrix rect range.
     */
    void
    validateSubRange()
    {
        if (m_lt_row >= m_rb_row)
        {
            throw std::runtime_error("Submatrix top-left row id greater than bottom-right row id");
        }
        else if (m_lt_col >= m_rb_col)
        {
            throw std::runtime_error("Submatrix top-left column id greater than bottom-right column id");
        }
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Ignore excluded rows and columns are not in subRect range.
     */
    void
    cleanupExcludedRowsColumns(const ExcludedRows& excludedRows, const ExcludedColumns& excludedColumns)
    {
        // rows
        for (auto exrow : excludedRows)
        {
            if (exrow >= m_lt_row && exrow <= m_rb_row)
            {
                m_exrows.push_back(exrow);
            }
        }

        // columns
        for (auto excol : excludedColumns)
        {
            if (excol >= m_lt_col && excol <= m_rb_col)
            {
                m_excols.push_back(excol);
            }
        }
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Calculate real count of submatrix rows.
     */
    void
    calculateRowsRealCount()
    {
        m_rows = m_rb_row - m_lt_row + 1;

        if (m_exrows.size() == 1)
        {
            auto exvalue = m_exrows.at(0);
            for (size_t i = m_lt_row; i != m_rb_row; ++i)
            {
                if (m_rows == 0)
                {
                    throw std::runtime_error("Submatrix rows count is 0");
                }
                if (i != exvalue)
                {
                    --m_rows;
                }
            }
        }
        else if (m_exrows.size() > 1)
        {
            for (size_t i = m_lt_row; i != m_rb_row; ++i)
            {
                if (m_rows == 0)
                {
                    throw std::runtime_error("Submatrix rows count is 0");
                }
                if (std::find(m_exrows.cbegin(), m_exrows.cend(), i) != m_exrows.cend())
                {
                    --m_rows;
                }
            }
        }
        if (m_rows == 0)
        {
            throw std::runtime_error("Submatrix rows count is 0");
        }
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Calculate real count of submatrix columns.
     */
    void
    calculateColumnsRealCount()
    {
        m_columns = m_rb_col - m_lt_col + 1;

        if (m_excols.size() == 1)
        {
            auto exvalue = m_excols.at(0);
            for (size_t i = m_lt_col; i != m_rb_col; ++i)
            {
                if (m_rows == 0)
                {
                    throw std::runtime_error("Submatrix rows count is 0");
                }
                if (i != exvalue)
                {
                    --m_columns;
                }
            }
        }
        else if (m_excols.size() > 1)
        {
            for (size_t i = m_lt_col; i != m_rb_col; ++i)
            {
                if (m_rows == 0)
                {
                    throw std::runtime_error("Submatrix rows count is 0");
                }
                if (std::find(m_excols.cbegin(), m_excols.cend(), i) != m_excols.cend())
                {
                    --m_columns;
                }
            }
        }
        if (m_rows == 0)
        {
            throw std::runtime_error("Submatrix rows count is 0");
        }
    }

/* --------------------------------------------------------------------------------------- */

    /*
     * Calculate real count of submatrix columns.
     */
    void
    next()
    {
        if (m_sub_col == m_columns-1 && m_sub_row == m_rows-1) // last component
        {
            m_sub_row = 0;
            m_sub_col = m_columns;
        }
        else
        {
            m_sub_row += 1;
            if (m_sub_row == m_rows-1)
            {
                m_sub_row = 0;
                m_sub_col += 1;
            }
        }
    }
};

#endif // MATH3D_SUBMATRIX_ITERATOR_HPP
