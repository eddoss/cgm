

#include <CGM/detail/Core/Types/Matrix.hpp>


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr
Matrix<M,N,T>::Matrix(T scalar)
{
    for (size_t i = 0; i < size; ++i)
    {
        *(&m_data[0][0] + i) = scalar;
    }
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr
Matrix<M,N,T>::Matrix(const T* values)
{
#ifdef CGM_ROW_WISE_MATRIX_LAYOUT
    for (size_t i = 0; i < size; ++i)
    {
        *(&m_data[0][0] + i) = *(values + i);
    }
#else
    for (size_t c = 0; c < columns; ++c)
    {
        for (size_t r = 0; r < rows; ++r)
        {
            m_data[c][r] = *(values + r * columns + c);
        }
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr
Matrix<M,N,T>::Matrix(std::initializer_list<T> values)
{
#ifdef CGM_ROW_WISE_MATRIX_LAYOUT
    for (size_t i = 0; i < size; ++i)
    {
        *(&m_data[0][0] + i) = *(values.begin() + i);
    }
#else
    for (size_t c = 0; c < columns; ++c)
    {
        for (size_t r = 0; r < rows; ++r)
        {
            m_data[c][r] = *(values.begin() + r * columns + c);
        }
    }
#endif
}

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr Matrix<M,N,T>&
Matrix<M,N,T>::operator = (T scalar)
{
    for (size_t i = 0; i < size; ++i)
    {
        *(&m_data[0][0] + i) = scalar;
    }
    return *this;
}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::pointer
Matrix<M,N,T>::data()
{
    return &m_data[0][0];
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::const_pointer
Matrix<M,N,T>::data() const
{
    return &m_data[0][0];
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::reference
Matrix<M,N,T>::operator () (size_t row, size_t column)
{
#ifdef CGM_ROW_WISE_MATRIX_LAYOUT
    return m_data[row][column];
#else
    return m_data[column][row];
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::const_reference
Matrix<M,N,T>::operator () (size_t row, size_t column) const
{
#ifdef CGM_ROW_WISE_MATRIX_LAYOUT
    return m_data[row][column];
#else
    return m_data[column][row];
#endif
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::reference
Matrix<M,N,T>::operator [] (size_t index)
{
    return *(&**m_data + index);
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr CGM_FORCEINLINE typename Matrix<M,N,T>::const_reference
Matrix<M,N,T>::operator [] (size_t index) const
{
    return *(&**m_data + index);
}

/* ####################################################################################### */
/* Direct iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::begin()
{
    return iterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::iterator
Matrix<M,N,T>::end()
{
    return iterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::begin() const
{
    return const_iterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::end() const
{
    return const_iterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cbegin() const
{
    return const_iterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_iterator
Matrix<M,N,T>::cend() const
{
    return const_iterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::reverse_iterator
Matrix<M,N,T>::rbegin()
{
    return reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::reverse_iterator
Matrix<M,N,T>::rend()
{
    return reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::rbegin() const
{
    return const_reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::rend() const
{
    return const_reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::crbegin() const
{
    return const_reverse_iterator {cend()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::const_reverse_iterator
Matrix<M,N,T>::crend() const
{
    return const_reverse_iterator {cbegin()};
}

/* ####################################################################################### */
/* Indirect iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::IndirectIterator
Matrix<M,N,T>::beginIndirect()
{
    return IndirectIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::IndirectIterator
Matrix<M,N,T>::endIndirect()
{
    return IndirectIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::beginIndirect() const
{
    return ConstIndirectIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::endIndirect() const
{
    return ConstIndirectIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::cbeginIndirect() const
{
    return ConstIndirectIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstIndirectIterator
Matrix<M,N,T>::cendIndirect() const
{
    return ConstIndirectIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseIndirectIterator
Matrix<M,N,T>::rbeginIndirect()
{
    return ReverseIndirectIterator {endIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseIndirectIterator
Matrix<M,N,T>::rendIndirect()
{
    return ReverseIndirectIterator {beginIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::rbeginIndirect() const
{
    return ConstReverseIndirectIterator {cendIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::rendIndirect() const
{
    return ConstReverseIndirectIterator {cbeginIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::crbeginIndirect() const
{
    return ConstReverseIndirectIterator {cendIndirect()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseIndirectIterator
Matrix<M,N,T>::crendIndirect() const
{
    return ConstReverseIndirectIterator {cbeginIndirect()};
}

/* ####################################################################################### */
/* Row-dir iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::RowDirIterator
Matrix<M,N,T>::beginRowDir()
{
    return RowDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::RowDirIterator
Matrix<M,N,T>::endRowDir()
{
    return RowDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowDirIterator
Matrix<M,N,T>::beginRowDir() const
{
    return ConstRowDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowDirIterator
Matrix<M,N,T>::endRowDir() const
{
    return ConstRowDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowDirIterator
Matrix<M,N,T>::cbeginRowDir() const
{
    return ConstRowDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowDirIterator
Matrix<M,N,T>::cendRowDir() const
{
    return ConstRowDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseRowDirIterator
Matrix<M,N,T>::rbeginRowDir()
{
    return ReverseRowDirIterator {endRowDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseRowDirIterator
Matrix<M,N,T>::rendRowDir()
{
    return ReverseRowDirIterator {beginRowDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowDirIterator
Matrix<M,N,T>::rbeginRowDir() const
{
    return ConstReverseRowDirIterator {cendRowDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowDirIterator
Matrix<M,N,T>::rendRowDir() const
{
    return ConstReverseRowDirIterator {cbeginRowDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowDirIterator
Matrix<M,N,T>::crbeginRowDir() const
{
    return ConstReverseRowDirIterator {cendRowDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowDirIterator
Matrix<M,N,T>::crendRowDir() const
{
    return ConstReverseRowDirIterator {cbeginRowDir()};
}

/* ####################################################################################### */
/* Column-dir iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ColumnDirIterator
Matrix<M,N,T>::beginColumnDir()
{
    return ColumnDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ColumnDirIterator
Matrix<M,N,T>::endColumnDir()
{
    return ColumnDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnDirIterator
Matrix<M,N,T>::beginColumnDir() const
{
    return ConstColumnDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnDirIterator
Matrix<M,N,T>::endColumnDir() const
{
    return ConstColumnDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnDirIterator
Matrix<M,N,T>::cbeginColumnDir() const
{
    return ConstColumnDirIterator {&**m_data, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnDirIterator
Matrix<M,N,T>::cendColumnDir() const
{
    return ConstColumnDirIterator {&**m_data, M*N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseColumnDirIterator
Matrix<M,N,T>::rbeginColumnDir()
{
    return ReverseColumnDirIterator {endColumnDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseColumnDirIterator
Matrix<M,N,T>::rendColumnDir()
{
    return ReverseColumnDirIterator {beginColumnDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnDirIterator
Matrix<M,N,T>::rbeginColumnDir() const
{
    return ConstReverseColumnDirIterator {cendColumnDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnDirIterator
Matrix<M,N,T>::rendColumnDir() const
{
    return ConstReverseColumnDirIterator {cbeginColumnDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnDirIterator
Matrix<M,N,T>::crbeginColumnDir() const
{
    return ConstReverseColumnDirIterator {cendColumnDir()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnDirIterator
Matrix<M,N,T>::crendColumnDir() const
{
    return ConstReverseColumnDirIterator {cbeginColumnDir()};
}

/* ####################################################################################### */
/* Row iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::RowIterator
Matrix<M,N,T>::beginRow(size_type row)
{
    return RowIterator {&**m_data, row, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::RowIterator
Matrix<M,N,T>::endRow(size_type row)
{
    return RowIterator {&**m_data, row, N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::beginRow(size_type row) const
{
    return ConstRowIterator {&**m_data, row, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::endRow(size_type row) const
{
    return ConstRowIterator {&**m_data, row, N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::cbeginRow(size_type row) const
{
    return ConstRowIterator {&**m_data, row, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstRowIterator
Matrix<M,N,T>::cendRow(size_type row) const
{
    return ConstRowIterator {&**m_data, row, N};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseRowIterator
Matrix<M,N,T>::rbeginRow(size_type row)
{
    return ReverseRowIterator {endRow(row)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseRowIterator
Matrix<M,N,T>::rendRow(size_type row)
{
    return ReverseRowIterator {beginRow(row)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::rbeginRow(size_type row) const
{
    return ConstReverseRowIterator {endRow(row)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::rendRow(size_type row) const
{
    return ConstReverseRowIterator {beginRow(row)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::crbeginRow(size_type row) const
{
    return ConstReverseRowIterator {cendRow(row)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseRowIterator
Matrix<M,N,T>::crendRow(size_type row) const
{
    return ConstReverseRowIterator {cbeginRow(row)};
}

/* ####################################################################################### */
/* Column iterators */
/* ####################################################################################### */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ColumnIterator
Matrix<M,N,T>::beginColumn(size_type column)
{
    return ColumnIterator {&**m_data, column, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ColumnIterator
Matrix<M,N,T>::endColumn(size_type column)
{
    return ColumnIterator {&**m_data, column, M};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::beginColumn(size_type column) const
{
    return ConstColumnIterator {&**m_data, column, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::endColumn(size_type column) const
{
    return ConstColumnIterator {&**m_data, column, M};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::cbeginColumn(size_type column) const
{
    return ConstColumnIterator {&**m_data, column, 0};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstColumnIterator
Matrix<M,N,T>::cendColumn(size_type column) const
{
    return ConstColumnIterator {&**m_data, column, M};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseColumnIterator
Matrix<M,N,T>::rbeginColumn(size_type column)
{
    return ReverseColumnIterator {endColumn(column)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ReverseColumnIterator
Matrix<M,N,T>::rendColumn(size_type column)
{
    return ReverseColumnIterator {beginColumn(column)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::rbeginColumn(size_type column) const
{
    return ConstReverseColumnIterator {endColumn(column)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::rendColumn(size_type column) const
{
    return ConstReverseColumnIterator {beginColumn(column)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::crbeginColumn(size_type column) const
{
    return ConstReverseColumnIterator {cendColumn(column)};
}

/* --------------------------------------------------------------------------------------- */

template<size_t M, size_t N, typename T>
constexpr typename Matrix<M,N,T>::ConstReverseColumnIterator
Matrix<M,N,T>::crendColumn(size_type column) const
{
    return ConstReverseColumnIterator {cbeginColumn(column)};
}


CGM_NAMESPACE_END
