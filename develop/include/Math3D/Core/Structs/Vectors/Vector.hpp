#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <algorithm>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Structs/Vectors/Iterator.hpp>


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
    constexpr static size_type
    dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Constructor initializing all components to a single value.
     * @param value Value to set all components to.
     */
    constexpr explicit
    Vector(const T& value);

    /**
     * Constructor initializing all components.
     * @param value Value to set all components to.
     */
    constexpr
    Vector(std::initializer_list<T> values);

    /**
     * Default constructor (no initialization).
     */
    Vector()                            = default;

    /**
     * Default copy constructor.
     */
    Vector(const Vector<D,T>&)          = default;

    /**
     * Default move constructor.
     */
    Vector(Vector<D,T>&&) noexcept      = default;

    /**
     * Default destructor.
     */
    ~Vector()                           = default;

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Default copy assignment.
     */
    Vector<D,T>&
    operator=(const Vector<D,T>&)       = default;

    /**
     * Default move assignment.
     */
    Vector<D,T>&
    operator=(Vector<D,T>&&) noexcept   = default;

    /**
     * Assigns all components single value.
     */
    constexpr Vector<D,T>&
    operator=(const T& scalar);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get reference to a scpecific component by index.
     * @return reference to a specific component.
     */
    constexpr reference
    operator[](size_type index);

    /**
     * Get reference to a scpecific component by index.
     * @return const reference to a specific component.
     */
    constexpr const_reference
    operator[](size_type index) const;

    /**
     * Get reference to a scpecific component by index.
     * @return reference to a specific component.
     */
    constexpr reference
    operator()(size_type index);

    /**
     * Get reference to a scpecific component by index.
     * @return const reference to a specific component.
     */
    constexpr const_reference
    operator()(size_type index) const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component.
     */
    constexpr iterator
    begin();

    /**
     * Get an iterator pointing to the component after the last.
     */
    constexpr iterator
    end();

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr const_iterator
    begin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr const_iterator
    end() const;

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr const_iterator
    cbegin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr const_iterator
    cend() const;

    /**
     * Get an iterator pointing to the last component.
     */
    constexpr reverse_iterator
    rbegin();

    /**
     * Get an iterator pointing to the component before the first.
     */
    constexpr reverse_iterator
    rend();

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr const_reverse_iterator
    rbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr const_reverse_iterator
    rend() const;

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr const_reverse_iterator
    crbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr const_reverse_iterator
    crend() const;
};

/* ####################################################################################### */
/* X, Y, Z, W accessors */
/* ####################################################################################### */

/**
 * Get X component reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::reference
x(Vector<D,T>& vector);

/**
 * Get Y component reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::reference
y(Vector<D,T>& vector);

/**
 * Get Z component reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::reference
z(Vector<D,T>& vector);

/**
 * Get W component reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::reference
w(Vector<D,T>& vector);

/**
 * Get X component const reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reference
x(Vector<D,T>& vector);

/**
 * Get Y component const reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reference
y(Vector<D,T>& vector);

/**
 * Get Z component const reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reference
z(Vector<D,T>& vector);

/**
 * Get W component const reference.
 */
template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reference
w(Vector<D,T>& vector);





/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */




/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Vector<D,T>::Vector(const T& value)
{
    static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = value;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Vector<D,T>::Vector(std::initializer_list<T> values)
{
    static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");
    for (size_type i = 0; i < D; ++i) data[i] = *(values.begin() + i);
}

/* ####################################################################################### */
/* IMPLEMENTATION | Assignment operator */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr Vector<D,T>&
Vector<D,T>::operator=(const T& scalar)
{
    for (size_type i = 0; i < D; ++i) data[i] = scalar;
    return *this;
}

/* ####################################################################################### */
/* IMPLEMENTATION | Components accessing */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE T&
Vector<D,T>::operator[](size_type index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE const T&
Vector<D,T>::operator[](size_type index) const
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE T&
Vector<D,T>::operator()(size_type index)
{
    return data[index];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE const T&
Vector<D,T>::operator()(size_type index) const
{
    return data[index];
}

/* ####################################################################################### */
/* IMPLEMENTATION | Iterators */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr typename Vector<D,T>::iterator
Vector<D,T>::begin()
{
    return iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::iterator
Vector<D,T>::end()
{
    return iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_iterator
Vector<D,T>::begin() const
{
    return const_iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_iterator
Vector<D,T>::end() const
{
    return const_iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_iterator
Vector<D,T>::cbegin() const
{
    return const_iterator {data};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_iterator
Vector<D,T>::cend() const
{
    return const_iterator {data+D};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::reverse_iterator
Vector<D,T>::rbegin()
{
    return reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::reverse_iterator
Vector<D,T>::rend()
{
    return reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::rbegin() const
{
    return const_reverse_iterator {end()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::rend() const
{
    return const_reverse_iterator {begin()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::crbegin() const
{
    return const_reverse_iterator {cend()};
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Vector<D,T>::const_reverse_iterator
Vector<D,T>::crend() const
{
    return const_reverse_iterator {cbegin()};
}

/* ####################################################################################### */
/* X,Y,Z,W accessors */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::reference
x(Vector<D,T>& vector)
{
    return vector.data[0];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::reference
y(Vector<D,T>& vector)
{
    static_assert(D > 1, "Math3D::y(): vector size must be more than 1");
    return vector.data[1];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::reference
z(Vector<D,T>& vector)
{
    static_assert(D > 2, "Math3D::z(): vector size must be more than 2");
    return vector.data[2];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::reference
w(Vector<D,T>& vector)
{
    static_assert(D > 3, "Math3D::w(): vector size must be more than 3");
    return vector.data[3];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::const_reference
x(const Vector<D,T>& vector)
{
    return vector.data[0];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::const_reference
y(const Vector<D,T>& vector)
{
    static_assert(D > 1, "Math3D::y(): vector size must be more than 1");
    return vector.data[1];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::const_reference
z(const Vector<D,T>& vector)
{
    static_assert(D > 2, "Math3D::z(): vector size must be more than 2");
    return vector.data[2];
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr FORCEINLINE typename Vector<D,T>::const_reference
w(const Vector<D,T>& vector)
{
    static_assert(D > 3, "Math3D::w(): vector size must be more than 3");
    return vector.data[3];
}

#endif // MATH3D_VECTOR_HPP
