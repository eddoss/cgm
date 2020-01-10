#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <algorithm>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Vectors/Iterator.hpp>


/**
 * Generic Vector.
 * @tparam D Components count (dimensions).
 * @tparam T Components type.
 */
template<size_t D, typename T=FLOAT>
struct Vector
{
    T data[D];

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using size_type         = size_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using const_pointer     = const T*;
    using const_reference   = const T&;

/* ####################################################################################### */
public: /* Iterator typedefs */
/* ####################################################################################### */

    using iterator                  = VectorIterator<T>;
    using const_iterator            = ConstVectorIterator<T>;
    using reverse_iterator          = std::reverse_iterator<iterator>;
	using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

/* ####################################################################################### */
public: /* Statics */
/* ####################################################################################### */

    /**
     * Vector components count.
     */
    static constexpr size_type dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing all components to a single value.
     * @param value Value to set all components to.
     */
    explicit
    Vector(const T& value);

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
    operator=(const T& scalar);

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
public: /* Comparison with scalar */
/* ####################################################################################### */

    /**
     * Checking the components of a vector for equality with a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are equal to scalar, false otherwise.
     */
    bool
    operator==(const T& scalar) const;

    /**
     * Checking the components of a vector for inequality with a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are not equal to scalar, false otherwise.
     */
    bool
    operator!=(const T& scalar) const;

    /**
     * Checks if all components of a vector are less than a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are less than scalar, false otherwise.
     */
    bool
    operator<(const T& scalar) const;

    /**
     * Checks if all components of a vector are greater than a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are greater than scalar, false otherwise.
     */
    bool
    operator>(const T& scalar) const;

    /**
     * Checks if all components of a vector are less or equal to a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are less or equal to a scalar, false otherwise.
     */
    bool
    operator<=(const T& scalar) const;

    /**
     * Checks if all components of a vector are greater or equal to a scalar.
     * @param scalar Scalar value to compare with.
     * @return true if components of the vector are greater or equal to a scalar, false otherwise.
     */
    bool
    operator>=(const T& scalar) const;

/* ####################################################################################### */
public: /* Comparison with other */
/* ####################################################################################### */

    /**
     * Check against another vector for equality.
     * @param vector The vector to check against.
     * @return true if the vectors are equal, false otherwise.
     */
    bool
    operator==(const Vector<D,T>& other) const;

    /**
     * Check against another vector for inequality.
     * @param vector The vector to check against.
     * @return true if the vectors are not equal, false otherwise.
     */
    bool
    operator!=(const Vector<D,T>& other) const;

    /**
     * Compares whether all the components of this vector are smaller than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<(const Vector<D,T>& other) const;

    /**
     * Compares whether all the components of this vector are larger than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>(const Vector<D,T>& other) const;

    /**
     * Compares whether all the components of this vector are smaller (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<=(const Vector<D,T>& other) const;

    /**
     * Compares whether all the components of this vector are larger (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>=(const Vector<D,T>& other) const;

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
     * Get an iterator pointing to the first component.
     */
    iterator
    begin();

    /**
     * Get an iterator pointing to the component after the last.
     */
    iterator
    end();

    /**
     * Get an const iterator pointing to the first component.
     */
    const_iterator
    begin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    const_iterator
    end() const;

    /**
     * Get an const iterator pointing to the first component.
     */
    const_iterator
    cbegin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    const_iterator
    cend() const;

    /**
     * Get an iterator pointing to the last component.
     */
    reverse_iterator
    rbegin();

    /**
     * Get an iterator pointing to the component before the first.
     */
    reverse_iterator
    rend();

    /**
     * Get an const iterator pointing to the last component.
     */
    const_reverse_iterator
    rbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    const_reverse_iterator
    rend() const;

    /**
     * Get an const iterator pointing to the last component.
     */
    const_reverse_iterator
    crbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    const_reverse_iterator
    crend() const;
};



/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */



template<size_t D, typename T>
Vector<D,T>::Vector(const T& value)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>::Vector(std::initializer_list<T> values)
{
    static_assert(D > 1, __FUNCTION__": vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = *(values.begin() + i);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator=(const T& scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] = scalar;
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: unary minus */
/* ####################################################################################### */

template<size_t D, typename T>
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

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator++()
{
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator--()
{
    for (size_type i = 0; i < D; ++i) --(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>
Vector<D,T>::operator++(int)
{
    Vector<D,T> copy {*this};
    for (size_type i = 0; i < D; ++i) ++(data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
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

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator-=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] -= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator-=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] -= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace plus */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator+=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] += scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator+=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] += vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component multiplication */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator*=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] *= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator*=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] *= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Arithmetic operators: inplace  per-component division */
/* ####################################################################################### */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator/=(T scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] /= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
Vector<D,T>&
Vector<D,T>::operator/=(const Vector<D,T>& vector)
{
    for (size_type i = 0; i < D; ++i) data[i] /= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with scalar */
/* ####################################################################################### */

template<size_t D, typename T>
bool
Vector<D,T>::operator==(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator!=(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], scalar)) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator<(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] >= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator>(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] <= scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator<=(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] > scalar) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator>=(const T& scalar) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] < scalar) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Comparison with other */
/* ####################################################################################### */

template<size_t D, typename T>
bool
Vector<D,T>::operator==(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], other.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator!=(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (notEqual(data[i], other.data[i])) return true;
    return false;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator<(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] >= other.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator>(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] <= other.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator<=(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] > other.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
bool
Vector<D,T>::operator>=(const Vector<D,T>& other) const
{
    for (size_type i = 0; i < D; ++i) if (data[i] < other.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<size_t D, typename T>
T&
Vector<D,T>::operator[](size_type index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
const T&
Vector<D,T>::operator[](size_type index) const
{
    return data[index];
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<size_t D, typename T>
typename Vector<D,T>::iterator
Vector<D,T>::begin()
{
    return iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::iterator
Vector<D,T>::end()
{
    return iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::begin() const
{
    return const_iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::end() const
{
    return const_iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::cbegin() const
{
    return const_iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_iterator
Vector<D,T>::cend() const
{
    return const_iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::reverse_iterator
Vector<D,T>::rbegin()
{
    return reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::reverse_iterator
Vector<D,T>::rend()
{
    return reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::rbegin() const
{
    return const_reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::rend() const
{
    return const_reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::crbegin() const
{
    return const_reverse_iterator {cend()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::crend() const
{
    return const_reverse_iterator {cbegin()};
}

#endif // MATH3D_VECTOR_HPP
