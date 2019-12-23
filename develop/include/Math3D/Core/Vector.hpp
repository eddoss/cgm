#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <memory>
#include <algorithm>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Iterators/RandomAccess.hpp>


template<typename T, uint32_t D>
struct Vector
{
    T data[D];

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type         = uint32_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;

/* ####################################################################################### */
public: /* Iterator typedefs */
/* ####################################################################################### */

    using iterator          = RandomAccessIterator<T>;
    using const_iterator    = ConstRandomAccessIterator<T>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    static constexpr size_type dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing all components to a single value.
     * @param value Value to set all components to.
     */
    explicit
    Vector(value_type value);

    /**
     * Constructor initializing all components.
     * @param value Value to set all components to.
     */
    Vector(std::initializer_list<T> values);

    /**
     * Default constructor (no initialization).
     */
    Vector() = default;

    /**
     * Default copy constructor.
     */
    Vector(const Vector<T,D>&) = default;

    /**
     * Default move constructor.
     */
    Vector(Vector<T,D>&&) = default;

    /**
     * Default destructor.
     */
    ~Vector() = default;

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components single value.
     */
    Vector<T,D>&
    operator=(T scalar);

    /**
     * Default copy assignment.
     */
    Vector<T,D>&
    operator=(const Vector<T,D>&) = default;

    /**
     * Default move assignment.
     */
    Vector<T,D>&
    operator=(Vector<T,D>&&) noexcept = default;

/* ####################################################################################### */
public: /* Arithmetic operators: unary minus */
/* ####################################################################################### */

    /**
     * Get a negated copy of the vector.
     * @return A negated copy of the vector.
     */
    Vector<T,D>
    operator-() const;

/* ####################################################################################### */
public: /* Increment and decrement */
/* ####################################################################################### */

    /** Prefix increment all components of this vector. */
    Vector<T,D>&
    operator++();

    /** Prefix decrement all components of this vector. */
    Vector<T,D>&
    operator--();

    /** Postfix increment all components of this vector. */
    Vector<T,D>
    operator++(int);

    /** Postfix decrement all components of this vector. */
    Vector<T,D>
    operator--(int);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace minus */
/* ####################################################################################### */

    /**
     * Subtracts scalar from this. Uses component-wise subtraction.
     * @param scalar How much to subtract from each component.
     * @return The result of subtraction.
     */
    Vector<T,D>&
    operator-=(T scalar);

    /**
     * Subtracts another vector from this. Uses component-wise subtraction.
     * @param vector The vector to subtract from this.
     * @return The result of subtraction.
     */
    Vector<T,D>&
    operator-=(const Vector<T,D>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace plus */
/* ####################################################################################### */

    /**
     * Gets the result of adding to each component of the vector.
     * @param scalar How much add to each component.
     * @return The result of adding.
     */
    Vector<T,D>&
    operator+=(T scalar);

    /**
     * Gets the result of component-wise adding of this by 3D vector.
     * @param vector The vector to add to this.
     * @return The result of adding.
     */
    Vector<T,D>&
    operator+=(const Vector<T,D>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace per-component multiplication */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise multiplication of this vector by scalar.
     * @param scalar The value to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<T,D>&
    operator*=(T scalar);

    /**
     * Gets the result of component-wise multiplication of this vector by another.
     * @param vector The vector to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<T,D>&
    operator*=(const Vector<T,D>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace per-component division */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise division of this vector by scalar.
     * @param scalar The value to divide this by.
     * @return The result of the division.
     */
    Vector<T,D>&
    operator/=(T scalar);

    /**
     * Gets the result of component-wise division of this vector by another.
     * @param vector The vector to divide this by.
     * @return The result of the division.
     */
    Vector<T,D>&
    operator/=(const Vector<T,D>& vector);

/* ####################################################################################### */
public: /* Comparison */
/* ####################################################################################### */

    /**
     * Check against another vector for equality.
     * @param vector The vector to check against.
     * @return true if the vectors are equal, false otherwise.
     */
    bool
    operator==(value_type scalar) const;

    /**
     * Check against another vector for equality.
     * @param vector The vector to check against.
     * @return true if the vectors are equal, false otherwise.
     */
    bool
    operator==(const Vector<T,D>& vector) const;

    /**
     * Check against another vector for inequality.
     * @param vector The vector to check against.
     * @return true if the vectors are not equal, false otherwise.
     */
    bool
    operator!=(value_type scalar) const;

    /**
     * Check against another vector for inequality.
     * @param vector The vector to check against.
     * @return true if the vectors are not equal, false otherwise.
     */
    bool
    operator!=(const Vector<T,D>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<(const Vector<T,D>& vector) const;

    /**
     * Compares whether all the components of this vector are larger than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>(const Vector<T,D>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<=(const Vector<T,D>& vector) const;

    /**
     * Compares whether all the components of this vector are larger (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>=(const Vector<T,D>& vector) const;

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get reference to a scpecific component by index.
     * @return reference to a specific component.
     */
    reference
    operator[](size_type index);

    /**
     * Get reference to a scpecific component by index.
     * @return const reference to a specific component.
     */
    const_reference
    operator[](size_type index) const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get begin component iterator.
     * @return first component iterator.
     */
    iterator
    begin();

    /**
     * Get end component iterator.
     * @return last+1 component iterator.
     */
    iterator
    end();

    /**
     * Get first component const iterator.
     * @return first component const iterator.
     */
    const_iterator
    begin() const;

    /**
     * Get end component const iterator.
     * @return last+1 component const iterator.
     */
    const_iterator
    end() const;

    /**
     * Get first component const iterator.
     * @return first component const iterator.
     */
    const_iterator
    cbegin() const;

    /**
     * Get end component const iterator.
     * @return last+1 component const iterator.
     */
    const_iterator
    cend() const;

/* ####################################################################################### */
public: /* Simple functions */
/* ####################################################################################### */

    /**
     * Get a copy of the vector as sign only.
     * Each component is set to +1 or -1.
     * @param zeroValues How to represent zero values (it can be any number).
     */
    Vector<T,D>
    signs(value_type zeroValues) const;

    /**
     * Make all components values positive.
     */
    void
    makePositive();

    /**
     * Make all components values negative.
     */
    void
    makeNegative();

    /**
     * Utility to check if there are any non-finite values (NaN or Inf).
     * @return true if there are any non-finite values, false otherwise.
     */
    bool
    containsNaN() const;
};



/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */



template<typename T, uint32_t D>
Vector<T,D>::Vector(T value)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>::Vector(std::initializer_list<T> values)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = *(values.begin() + i);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] = scalar;
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: unary minus */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>
Vector<T,D>::operator-() const
{
    Vector<T,D> result;
    for (size_type i = 0; i < D; ++i) result.data[i] = -data[i];
    return result;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator++()
{
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator--()
{
    for (size_type i = 0; i < D; ++i) --(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>
Vector<T,D>::operator++(int)
{
    Vector<T,D> copy {*this};
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>
Vector<T,D>::operator--(int)
{
    Vector<T,D> copy {*this};
    for (size_type i = 0; i < D; ++i) --(data[i]);
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace minus */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator-=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] -= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator-=(const Vector<T,D>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] -= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace plus */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator+=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] += scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator+=(const Vector<T,D>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] += vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component multiplication */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator*=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] *= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator*=(const Vector<T,D>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] *= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component division */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator/=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] /= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
Vector<T,D>&
Vector<T,D>::operator/=(const Vector<T,D>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] /= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison */
/* ####################################################################################### */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator==(T scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator==(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], vector.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator!=(T scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator!=(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], vector.data[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator<(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] >= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator>(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] <= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator<=(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] > vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::operator>=(const Vector<T,D>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] < vector.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<typename T, uint32_t D>
T&
Vector<T,D>::operator[](size_type index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
const T&
Vector<T,D>::operator[](size_type index) const
{
    return data[index];
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<typename T, uint32_t D>
typename Vector<T,D>::iterator
Vector<T,D>::begin()
{
    return iterator {data};
}

template<typename T, uint32_t D>
typename Vector<T,D>::iterator
Vector<T,D>::end()
{
    return iterator {data+D};
}

template<typename T, uint32_t D>
typename Vector<T,D>::const_iterator
Vector<T,D>::begin() const
{
    return const_iterator {data};
}

template<typename T, uint32_t D>
typename Vector<T,D>::const_iterator
Vector<T,D>::end() const
{
    return const_iterator {data+D};
}

template<typename T, uint32_t D>
typename Vector<T,D>::const_iterator
Vector<T,D>::cbegin() const
{
    return const_iterator {data};
}

template<typename T, uint32_t D>
typename Vector<T,D>::const_iterator
Vector<T,D>::cend() const
{
    return const_iterator {data+D};
}

/* ####################################################################################### */
/* IMPLEMENTATION | Simple functions */
/* ####################################################################################### */

template<typename T, uint32_t D>
Vector<T,D>
Vector<T,D>::signs(T zeroValues) const
{
    Vector<T,D> result;
    for (size_type i = 0; i < D; ++i)
    {
        if (data[i] > 0)
            result.data[i] = 1;
        else if (data[i] < 0)
            result.data[i] = -1;
        else
            result.data[i] = zeroValues;
    }
    return result;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
void
Vector<T,D>::makePositive()
{
    for (size_type i = 1; i < D; ++i) data[i] = std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
void
Vector<T,D>::makeNegative()
{
    for (size_type i = 1; i < D; ++i) data[i] = -std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t D>
bool
Vector<T,D>::containsNaN() const
{
    for (size_type i = 1; i < D; ++i) if (std::isnan(data[i])) return true;
    return false;
}

#endif // MATH3D_VECTOR_HPP
