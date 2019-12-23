#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <memory>
#include <algorithm>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Iterators/RandomAccess.hpp>

/**
 * Generic Vector.
 * @tparam D Components count (dimensions).
 * @tparam T Components type.
 **/
template<uint32_t D, typename T=FLOAT>
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
    Vector(const Vector<D,T>&) = default;

    /**
     * Default move constructor.
     */
    Vector(Vector<D,T>&&) = default;

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
    Vector<D,T>&
    operator=(T scalar);

    /**
     * Default copy assignment.
     */
    Vector<D,T>&
    operator=(const Vector<D,T>&) = default;

    /**
     * Default move assignment.
     */
    Vector<D,T>&
    operator=(Vector<D,T>&&) noexcept = default;

/* ####################################################################################### */
public: /* Arithmetic operators: unary minus */
/* ####################################################################################### */

    /**
     * Get a negated copy of the vector.
     * @return A negated copy of the vector.
     */
    Vector<D,T>
    operator-() const;

/* ####################################################################################### */
public: /* Increment and decrement */
/* ####################################################################################### */

    /** Prefix increment all components of this vector. */
    Vector<D,T>&
    operator++();

    /** Prefix decrement all components of this vector. */
    Vector<D,T>&
    operator--();

    /** Postfix increment all components of this vector. */
    Vector<D,T>
    operator++(int);

    /** Postfix decrement all components of this vector. */
    Vector<D,T>
    operator--(int);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace minus */
/* ####################################################################################### */

    /**
     * Subtracts scalar from this. Uses component-wise subtraction.
     * @param scalar How much to subtract from each component.
     * @return The result of subtraction.
     */
    Vector<D,T>&
    operator-=(T scalar);

    /**
     * Subtracts another vector from this. Uses component-wise subtraction.
     * @param vector The vector to subtract from this.
     * @return The result of subtraction.
     */
    Vector<D,T>&
    operator-=(const Vector<D,T>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace plus */
/* ####################################################################################### */

    /**
     * Gets the result of adding to each component of the vector.
     * @param scalar How much add to each component.
     * @return The result of adding.
     */
    Vector<D,T>&
    operator+=(T scalar);

    /**
     * Gets the result of component-wise adding of this by 3D vector.
     * @param vector The vector to add to this.
     * @return The result of adding.
     */
    Vector<D,T>&
    operator+=(const Vector<D,T>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace per-component multiplication */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise multiplication of this vector by scalar.
     * @param scalar The value to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<D,T>&
    operator*=(T scalar);

    /**
     * Gets the result of component-wise multiplication of this vector by another.
     * @param vector The vector to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<D,T>&
    operator*=(const Vector<D,T>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace per-component division */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise division of this vector by scalar.
     * @param scalar The value to divide this by.
     * @return The result of the division.
     */
    Vector<D,T>&
    operator/=(T scalar);

    /**
     * Gets the result of component-wise division of this vector by another.
     * @param vector The vector to divide this by.
     * @return The result of the division.
     */
    Vector<D,T>&
    operator/=(const Vector<D,T>& vector);

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
    operator==(const Vector<D,T>& vector) const;

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
    operator!=(const Vector<D,T>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<(const Vector<D,T>& vector) const;

    /**
     * Compares whether all the components of this vector are larger than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>(const Vector<D,T>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<=(const Vector<D,T>& vector) const;

    /**
     * Compares whether all the components of this vector are larger (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>=(const Vector<D,T>& vector) const;

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
    Vector<D,T>
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



template<uint32_t D, typename T>
Vector<D,T>::Vector(T value)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = value;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>::Vector(std::initializer_list<T> values)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = *(values.begin() + i);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] = scalar;
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: unary minus */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>
Vector<D,T>::operator-() const
{
    Vector<D,T> result;
    for (size_type i = 0; i < D; ++i) result.data[i] = -data[i];
    return result;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Increment and decrement */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator++()
{
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator--()
{
    for (size_type i = 0; i < D; ++i) --(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>
Vector<D,T>::operator++(int)
{
    Vector<D,T> copy {*this};
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>
Vector<D,T>::operator--(int)
{
    Vector<D,T> copy {*this};
    for (size_type i = 0; i < D; ++i) --(data[i]);
    return copy;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace minus */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator-=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] -= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator-=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] -= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace plus */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator+=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] += scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator+=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] += vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component multiplication */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator*=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] *= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator*=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] *= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component division */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator/=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] /= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator/=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] /= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison */
/* ####################################################################################### */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator==(T scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator==(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], vector.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator!=(T scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator!=(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], vector.data[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator<(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] >= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator>(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] <= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator<=(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] > vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::operator>=(const Vector<D,T>& vector) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] < vector.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<uint32_t D, typename T>
T&
Vector<D,T>::operator[](size_type index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
const T&
Vector<D,T>::operator[](size_type index) const
{
    return data[index];
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<uint32_t D, typename T>
typename Vector<D,T>::iterator
Vector<D,T>::begin()
{
    return iterator {data};
}

template<uint32_t D, typename T>
typename Vector<D,T>::iterator
Vector<D,T>::end()
{
    return iterator {data+D};
}

template<uint32_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::begin() const
{
    return const_iterator {data};
}

template<uint32_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::end() const
{
    return const_iterator {data+D};
}

template<uint32_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::cbegin() const
{
    return const_iterator {data};
}

template<uint32_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::cend() const
{
    return const_iterator {data+D};
}

/* ####################################################################################### */
/* IMPLEMENTATION | Simple functions */
/* ####################################################################################### */

template<uint32_t D, typename T>
Vector<D,T>
Vector<D,T>::signs(T zeroValues) const
{
    Vector<D,T> result;
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

template<uint32_t D, typename T>
void
Vector<D,T>::makePositive()
{
    for (size_type i = 1; i < D; ++i) data[i] = std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
void
Vector<D,T>::makeNegative()
{
    for (size_type i = 1; i < D; ++i) data[i] = -std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<uint32_t D, typename T>
bool
Vector<D,T>::containsNaN() const
{
    for (size_type i = 1; i < D; ++i) if (std::isnan(data[i])) return true;
    return false;
}

#endif // MATH3D_VECTOR_HPP
