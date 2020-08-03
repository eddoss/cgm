#pragma once


#include <iterator>
#include <type_traits>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Common.hpp>


MATH3D_NAMESPACE_BEGIN

template<size_t D, typename T=FLOAT, typename = void> struct Vector;

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 2D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 2)>>
{
    MATH3D_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x;
    T y;

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    /**
     * Vector components count.
     */
    constexpr static size_t
    dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T value);

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components by single value.
     */
    constexpr FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Raw data */
/* ####################################################################################### */

    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr FORCEINLINE const_pointer
    data() const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 3D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>>
{
    MATH3D_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x;
    T y;
    T z;

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    /**
     * Vector components count.
     */
    constexpr static size_t
    dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T value);

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y, T Z);

    /**
     * Initialize X and Y components from 2D vector.
     */
    constexpr explicit
    Vector(const Vector<2,T>& XY, T Z=zero<T>);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components by single value.
     */
    constexpr FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr FORCEINLINE const_pointer
    data() const;

    /**
     * Gets 2D vector (without Z component).
     * @return 2D Vector.
     */
    constexpr FORCEINLINE Vector<2,T>
    xy() const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 4D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 4)>>
{
    MATH3D_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x;
    T y;
    T z;
    T w;

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    /**
     * Vector components count.
     */
    constexpr static size_t
    dimensions {D};

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T value);

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y, T Z, T W);

    /**
     * Initialize X, Y, Z components from 3D vector.
     */
    constexpr explicit
    Vector(const Vector<3,T>& XYZ, T W=zero<T>);

    /**
     * Initialize components from two 2D vectors.
     */
    constexpr
    Vector(const Vector<2,T>& XY, const Vector<2,T>& ZW);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components by single value.
     */
    constexpr FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr FORCEINLINE const_pointer
    data() const;

    /**
     * Gets 2D vector (without Z and W components).
     * @return 2D Vector.
     */
    constexpr FORCEINLINE Vector<2,T>
    xy() const;

    /**
     * Gets 3D vector (without W component).
     * @return 3D Vector.
     */
    constexpr FORCEINLINE Vector<3,T>
    xyz() const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 4+D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 4)>>
{
    MATH3D_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Iterator typedefs */
/* ####################################################################################### */

    using iterator                  = pointer;
    using const_iterator            = const_pointer;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components via initializer_list.
     */
    constexpr
    Vector(std::initializer_list<T> values);

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T value);

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assign all components by single value.
     */
    constexpr FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get component reference by index.
     * @param component reference.
     */
    constexpr FORCEINLINE reference
    operator[](size_t index);

    /**
     * Get component const reference by index.
     * @param component const reference.
     */
    constexpr FORCEINLINE const_reference
    operator[](size_t index) const;

    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr FORCEINLINE pointer
    data();

    /**
     * Get const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr FORCEINLINE const_pointer
    data() const;

    /**
     * Gets 2D vector XY.
     * @return 2D Vector.
     */
    constexpr FORCEINLINE Vector<2,T>
    xy() const;

    /**
     * Gets 3D vector XYZ.
     * @return 3D Vector.
     */
    constexpr FORCEINLINE Vector<3,T>
    xyz() const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component.
     */
    constexpr FORCEINLINE iterator
    begin();

    /**
     * Get an iterator pointing to the component after the last.
     */
    constexpr FORCEINLINE iterator
    end();

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr FORCEINLINE const_iterator
    begin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr FORCEINLINE const_iterator
    end() const;

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr FORCEINLINE const_iterator
    cbegin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr FORCEINLINE const_iterator
    cend() const;

    /**
     * Get an iterator pointing to the last component.
     */
    constexpr FORCEINLINE reverse_iterator
    rbegin();

    /**
     * Get an iterator pointing to the component before the first.
     */
    constexpr FORCEINLINE reverse_iterator
    rend();

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr FORCEINLINE const_reverse_iterator
    rbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr FORCEINLINE const_reverse_iterator
    rend() const;

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr FORCEINLINE const_reverse_iterator
    crbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr FORCEINLINE const_reverse_iterator
    crend() const;

/* ####################################################################################### */
protected: /* Components array */
/* ####################################################################################### */

    T m_data[D];
};

MATH3D_NAMESPACE_END


#include <private/Math3D/Core/Vector.hpp>
