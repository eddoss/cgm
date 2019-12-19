#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <memory>
#include <algorithm>
#include <initializer_list>
#include <Math3D/Global.hpp>


template<typename T, uint32_t Size>
struct Vector
{
    T data[Size];

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /** Default constructor (no initialization). */
    Vector() = default;

    /**
     * Constructor initializing all components to a single value.
     * @param value Value to set all components to.
     */
    explicit
    Vector(T value);

    /**
     * Constructor initializing all components.
     * @param value Value to set all components to.
     */
    Vector(std::initializer_list<T> values);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components single value.
     */
    Vector<T,Size>&
    operator=(T scalar);

/* ####################################################################################### */
public: /* Arithmetic operators: unary minus */
/* ####################################################################################### */

    /**
     * Get a negated copy of the vector.
     * @return A negated copy of the vector.
     */
    Vector<T,Size>
    operator-() const;

/* ####################################################################################### */
public: /* Increment and decrement */
/* ####################################################################################### */

    /** Prefix increment all components of this vector. */
    Vector<T,Size>&
    operator++();

    /** Prefix decrement all components of this vector. */
    Vector<T,Size>&
    operator--();

    /** Postfix increment all components of this vector. */
    Vector<T,Size>
    operator++(int);

    /** Postfix decrement all components of this vector. */
    Vector<T,Size>
    operator--(int);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace minus */
/* ####################################################################################### */

    /**
     * Subtracts scalar from this. Uses component-wise subtraction.
     * @param scalar How much to subtract from each component.
     * @return The result of subtraction.
     */
    Vector<T,Size>&
    operator-=(T scalar);

    /**
     * Subtracts another vector from this. Uses component-wise subtraction.
     * @param vector The vector to subtract from this.
     * @return The result of subtraction.
     */
    Vector<T,Size>&
    operator-=(const Vector<T,Size>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace plus */
/* ####################################################################################### */

    /**
     * Gets the result of adding to each component of the vector.
     * @param scalar How much add to each component.
     * @return The result of adding.
     */
    Vector<T,Size>&
    operator+=(T scalar);

    /**
     * Gets the result of component-wise adding of this by 3D vector.
     * @param vector The vector to add to this.
     * @return The result of adding.
     */
    Vector<T,Size>&
    operator+=(const Vector<T,Size>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace  per-component multiplication */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise multiplication of this vector by scalar.
     * @param scalar The value to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<T,Size>&
    operator*=(T scalar);

    /**
     * Gets the result of component-wise multiplication of this vector by another.
     * @param vector The vector to multiply this by.
     * @return The result of the multiplication.
     */
    Vector<T,Size>&
    operator*=(const Vector<T,Size>& vector);

/* ####################################################################################### */
public: /* Arithmetic operators: inplace  per-component division */
/* ####################################################################################### */

    /**
     * Gets the result of component-wise division of this vector by scalar.
     * @param scalar The value to divide this by.
     * @return The result of the division.
     */
    Vector<T,Size>&
    operator/=(T scalar);

    /**
     * Gets the result of component-wise division of this vector by another.
     * @param vector The vector to divide this by.
     * @return The result of the division.
     */
    Vector<T,Size>&
    operator/=(const Vector<T,Size>& vector);

/* ####################################################################################### */
public: /* Comparison */
/* ####################################################################################### */

    /**
     * Check against another vector for equality.
     * @param vector The vector to check against.
     * @return true if the vectors are equal, false otherwise.
     */
    bool
    operator==(T scalar) const;

    /**
     * Check against another vector for equality.
     * @param vector The vector to check against.
     * @return true if the vectors are equal, false otherwise.
     */
    bool
    operator==(const Vector<T,Size>& vector) const;

    /**
     * Check against another vector for inequality.
     * @param vector The vector to check against.
     * @return true if the vectors are not equal, false otherwise.
     */
    bool
    operator!=(T scalar) const;

    /**
     * Check against another vector for inequality.
     * @param vector The vector to check against.
     * @return true if the vectors are not equal, false otherwise.
     */
    bool
    operator!=(const Vector<T,Size>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<(const Vector<T,Size>& vector) const;

    /**
     * Compares whether all the components of this vector are larger than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>(const Vector<T,Size>& vector) const;

    /**
     * Compares whether all the components of this vector are smaller (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is shorter, false otherwise.
     */
    bool
    operator<=(const Vector<T,Size>& vector) const;

    /**
     * Compares whether all the components of this vector are larger (or equal) than other.
     * @param vector The compared vector.
     * @return true if this the vector is longer, false otherwise.
     */
    bool
    operator>=(const Vector<T,Size>& vector) const;

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get reference to a scpecific component by index.
     * @return reference to a specific component.
     */
    T&
    operator[](uint32_t index);

    /**
     * Get reference to a scpecific component by index.
     * @return const reference to a specific component.
     */
    const T&
    operator[](uint32_t index) const;

/* ####################################################################################### */
public: /* Simple functions */
/* ####################################################################################### */

    /**
     * Get a copy of the vector as sign only.
     * Each component is set to +1 or -1.
     * @param zeroValues How to represent zero values (it can be any number).
     */
    Vector<T,Size>
    signs(T zeroValues) const;

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



template<typename T, uint32_t Size>
Vector<T,Size>::Vector(T value)
{
    static_assert(Size > 1, __FUNCTION__": vector size must be more than 1");
    for (uint32_t i = 0; i < Size; ++i) data[i] = value;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>::Vector(std::initializer_list<T> values)
{
    static_assert(Size > 1, __FUNCTION__": vector size must be more than 1");
    for (uint32_t i = 0; i < Size; ++i) data[i] = *(values.begin() + i);
}

/* ####################################################################################### */
/* Assignment operator */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator=(T scalar)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] = scalar;
    return *this;
}

/* ####################################################################################### */
/* Arithmetic operators: unary minus */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>
Vector<T,Size>::operator-() const
{
    Vector<T,Size> result
    for (uint32_t i = 0; i < Size; ++i) result.data[i] = -data[i];
    return result;
}

/* ####################################################################################### */
/* Increment and decrement */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator++()
{
    for (uint32_t i = 0; i < Size; ++i) ++(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator--()
{
    for (uint32_t i = 0; i < Size; ++i) --(data[i]);
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>
Vector<T,Size>::operator++(int)
{
    Vector<T,Size> copy {*this};
    for (uint32_t i = 0; i < Size; ++i) ++(data[i]);
    return copy;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>
Vector<T,Size>::operator--(int)
{
    Vector<T,Size> copy {*this};
    for (uint32_t i = 0; i < Size; ++i) --(data[i]);
    return copy;
}

/* ####################################################################################### */
/* Arithmetic operators: inplace minus */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator-=(T scalar)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] -= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator-=(const Vector<T,Size>& vector)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] -= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* Arithmetic operators: inplace plus */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator+=(T scalar)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] += scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator+=(const Vector<T,Size>& vector)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] += vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* Arithmetic operators: inplace  per-component multiplication */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator*=(T scalar)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] *= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator*=(const Vector<T,Size>& vector)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] *= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* Arithmetic operators: inplace  per-component division */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator/=(T scalar)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] /= scalar;
    return *this;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
Vector<T,Size>&
Vector<T,Size>::operator/=(const Vector<T,Size>& vector)
{
    for (uint32_t i = 0; i < Size; ++i) data[i] /= vector.data[i];
    return *this;
}

/* ####################################################################################### */
/* Comparison */
/* ####################################################################################### */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator==(T scalar) const
{
    for (uint32_t i = 0; i < Size; ++i) if (notEqual(data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator==(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (notEqual(data[i], vector.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator!=(T scalar) const
{
    for (uint32_t i = 0; i < Size; ++i) if (equal(data[i], scalar)) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator!=(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (equal(data[i], vector.data[i])) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator<(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (data[i] >= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator>(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (data[i] <= vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator<=(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (data[i] > vector.data[i]) return false;
    return true;
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::operator>=(const Vector<T,Size>& vector) const
{
    for (uint32_t i = 0; i < Size; ++i) if (data[i] < vector.data[i]) return false;
    return true;
}

/* ####################################################################################### */
/* Components accessing */
/* ####################################################################################### */

template<typename T, uint32_t Size>
T&
Vector<T,Size>::operator[](uint32_t index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
const T&
Vector<T,Size>::operator[](uint32_t index) const
{
    return data[index];
}

/* ####################################################################################### */
/* Simple functions */
/* ####################################################################################### */

template<typename T, uint32_t Size>
Vector<T,Size>
Vector<T,Size>::signs(T zeroValues) const
{
    Vector<T,Size> result;
    for (uint32_t i = 0; i < Size; ++i)
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

template<typename T, uint32_t Size>
void
Vector<T,Size>::makePositive()
{
    for (uint32_t i = 1; i < Size; ++i) data[i] = std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
void
Vector<T,Size>::makeNegative()
{
    for (uint32_t i = 1; i < Size; ++i) data[i] = -std::abs(data[i]);
}

/* --------------------------------------------------------------------------------------- */

template<typename T, uint32_t Size>
bool
Vector<T,Size>::containsNaN() const
{
    for (uint32_t i = 1; i < Size; ++i) std::isnan(data[i]) ? return true;
    return false;
}

#endif // MATH3D_VECTOR_HPP
