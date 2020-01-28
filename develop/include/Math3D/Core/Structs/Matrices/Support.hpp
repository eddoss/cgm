#ifndef MATH3D_SUPPORT_HPP
#define MATH3D_SUPPORT_HPP

template <typename Iterator>
class ReverseMatrixIterator : public Iterator
{
/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using self_type             = ReverseMatrixIterator<Iterator>;
    using base_type             = Iterator;
    using value_type            = typename Iterator::value_type;
    using reference             = typename Iterator::reference;
    using pointer               = typename Iterator::pointer;
    using iterator_category     = typename Iterator::iterator_category;
    using difference_type       = typename Iterator::difference_type;

/* ####################################################################################### */
public: /* Data accessing */
/* ####################################################################################### */

    constexpr reference
    operator*() const
    {
        return (--static_cast<base_type>(self_type{*this})).operator*();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr pointer
    operator->() const
    {
        return static_cast<base_type>(self_type{*this}).operator->();
    }

/* ####################################################################################### */
public: /* Move forward */
/* ####################################################################################### */

    constexpr self_type&
    operator++()
    {
        base_type::operator--();
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator++(int)
    {
        self_type tmp {*this};
        base_type::operator--();
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator+=(difference_type offset)
    {
        base_type::operator-=(offset);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator+(difference_type offset) const
    {
        return self_type {base_type::operator-(offset)};
    }

/* ####################################################################################### */
public: /* Move backward */
/* ####################################################################################### */

    constexpr self_type&
    operator--()
    {
        base_type::operator++();
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator--(int)
    {
        self_type tmp {*this};
        base_type::operator++();
        return tmp;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type&
    operator-=(difference_type offset)
    {
        base_type::operator+=(offset);
        return *this;
    }

/* --------------------------------------------------------------------------------------- */

    constexpr self_type
    operator-(difference_type offset) const
    {
		return self_type {base_type::operator+(offset)};
    }

/* ####################################################################################### */
public: /* Difference */
/* ####################################################################################### */

    constexpr difference_type
    operator-(const self_type& other) const
    {
        return static_cast<const base_type&>(other) - *this;
    }

/* ####################################################################################### */
public: /* Compares */
/* ####################################################################################### */

    constexpr bool
    operator<(const self_type& other) const
    {
        return ! base_type::operator<(static_cast<const base_type&>(other));
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>(const self_type& other) const
    {
        return ! base_type::operator>(static_cast<const base_type&>(other));
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator<=(const self_type& other) const
    {
        return ! base_type::operator<=(static_cast<const base_type&>(other));
    }

/* --------------------------------------------------------------------------------------- */

    constexpr bool
    operator>=(const self_type& other) const
    {
        return ! base_type::operator>=(static_cast<const base_type&>(other));
    }

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    constexpr size_t
    row() const
    {
        return (--static_cast<base_type>(self_type{*this})).row();
    }

/* --------------------------------------------------------------------------------------- */

    constexpr size_t
    column() const
    {
        return (--static_cast<base_type>(self_type{*this})).column();
    }
};

#endif //MATH3D_SUPPORT_HPP
