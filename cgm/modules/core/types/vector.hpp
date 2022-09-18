#pragma once


#include <iterator>
#include <type_traits>
#include <initializer_list>
#include <cgm/modules/core/module_globals.hpp>
#include <cgm/modules/core/types/enums.hpp>


CGM_NAMESPACE_BEGIN

template<size_t D, typename T=FLOAT, typename = void> struct Vector;

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 2D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 2)>>
{
    CGM_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x {T(0)};
    T y {T(0)};

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
    constexpr CGM_FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Access */
/* ####################################################################################### */

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E2D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E2D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;
    
    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr CGM_FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr CGM_FORCEINLINE const_pointer
    data() const;
    
/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Rearrange components inplace (at compile time).
     */
    template<E2D X, E2D Y>
    constexpr CGM_FORCEINLINE void
    shuffle();

    /**
     * Rearrange components outplace (at compile time).
     */
    template<E2D X, E2D Y>
    constexpr CGM_FORCEINLINE Vector
    shuffled() const;

    /**
     * Rearrange components inplace.
     */
    constexpr CGM_FORCEINLINE void
    shuffle(E2D X, E2D Y);

    /**
     * Rearrange components outplace.
     */
    constexpr CGM_FORCEINLINE Vector
    shuffled(E2D X, E2D Y) const;

    /**
     * Gets xy vector.
     * @return 2D Vector.
     */
    constexpr CGM_FORCEINLINE Vector
    xy() const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 3D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>>
{
    CGM_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x {T(0)};
    T y {T(0)};
    T z {T(0)};

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
    Vector(const Vector<2,T>& XY, T Z=T(0));

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assigns all components by single value.
     */
    constexpr CGM_FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Access */
/* ####################################################################################### */

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E2D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E2D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E3D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E3D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E3D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E3D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;

    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr CGM_FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr CGM_FORCEINLINE const_pointer
    data() const;

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Rearrange components inplace (at compile time).
     */
    template<E3D X, E3D Y, E3D Z>
    constexpr CGM_FORCEINLINE void
    shuffle();

    /**
     * Rearrange components outplace (at compile time).
     */
    template<E3D X, E3D Y, E3D Z>
    constexpr CGM_FORCEINLINE Vector
    shuffled() const;

    /**
     * Rearrange components inplace.
     */
    constexpr CGM_FORCEINLINE void
    shuffle(E3D X, E3D Y, E3D Z);

    /**
     * Rearrange components outplace.
     */
    constexpr CGM_FORCEINLINE Vector
    shuffled(E3D X, E3D Y, E3D Z) const;

    /**
     * Gets 2D xy vector.
     * @return 2D Vector.
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
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
    CGM_RULE_OF_FIVE(Vector)

/* ####################################################################################### */
public: /* Components */
/* ####################################################################################### */

    T x {T(0)};
    T y {T(0)};
    T z {T(0)};
    T w {T(0)};

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
    Vector(const Vector<3,T>& XYZ, T W=T(0));

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
    constexpr CGM_FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Access */
/* ####################################################################################### */

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E2D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E2D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E2D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E3D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E3D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E3D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E3D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;

    /**
     * Gets component ref (at runtime).
     * @param Reference to component.
     */
    constexpr CGM_FORCEINLINE reference
    get(E4D component);

    /**
     * Gets component const ref (at runtime).
     * @param Const reference to component.
     */
    constexpr CGM_FORCEINLINE const_reference
    get(E4D component) const;

    /**
     * Gets component ref (at compile time).
     * @param Reference to component.
     */
    template <E4D Component>
    constexpr CGM_FORCEINLINE reference
    get();

    /**
     * Gets component const ref (at compile time).
     * @param Const reference to component.
     */
    template <E4D Component>
    constexpr CGM_FORCEINLINE const_reference
    get() const;

    /**
     * Gets raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr CGM_FORCEINLINE pointer
    data();

    /**
     * Gets const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr CGM_FORCEINLINE const_pointer
    data() const;

    /**
     * Gets 2D vector (without Z and W components).
     * @return 2D Vector.
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    xy() const;

    /**
     * Gets 3D vector (without W component).
     * @return 3D Vector.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    xyz() const;

/* ####################################################################################### */
public: /* Methods */
/* ####################################################################################### */

    /**
     * Rearrange components inplace (at compile time).
     */
    template<E4D X, E4D Y, E4D Z, E4D W>
    constexpr CGM_FORCEINLINE void
    shuffle();

    /**
     * Rearrange components outplace (at compile time).
     */
    template<E4D X, E4D Y, E4D Z, E4D W>
    constexpr CGM_FORCEINLINE Vector
    shuffled() const;

    /**
     * Rearrange components inplace.
     */
    constexpr CGM_FORCEINLINE void
    shuffle(E4D X, E4D Y, E4D Z, E4D W);

    /**
     * Rearrange components outplace.
     */
    constexpr CGM_FORCEINLINE Vector
    shuffled(E4D X, E4D Y, E4D Z, E4D W) const;
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Vector 4+D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 4)>>
{
    CGM_RULE_OF_FIVE(Vector)

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
    constexpr CGM_FORCEINLINE Vector&
    operator = (value_type value);

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get component reference by index.
     * @param component reference.
     */
    constexpr CGM_FORCEINLINE reference
    operator[](size_t index);

    /**
     * Get component const reference by index.
     * @param component const reference.
     */
    constexpr CGM_FORCEINLINE const_reference
    operator[](size_t index) const;

    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr CGM_FORCEINLINE pointer
    data();

    /**
     * Get const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr CGM_FORCEINLINE const_pointer
    data() const;

    /**
     * Gets 2D vector XY.
     * @return 2D Vector.
     */
    constexpr CGM_FORCEINLINE Vector<2,T>
    xy() const;

    /**
     * Gets 3D vector XYZ.
     * @return 3D Vector.
     */
    constexpr CGM_FORCEINLINE Vector<3,T>
    xyz() const;

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    /**
     * Get an iterator pointing to the first component.
     */
    constexpr CGM_FORCEINLINE iterator
    begin();

    /**
     * Get an iterator pointing to the component after the last.
     */
    constexpr CGM_FORCEINLINE iterator
    end();

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr CGM_FORCEINLINE const_iterator
    begin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr CGM_FORCEINLINE const_iterator
    end() const;

    /**
     * Get an const iterator pointing to the first component.
     */
    constexpr CGM_FORCEINLINE const_iterator
    cbegin() const;

    /**
     * Get an const iterator pointing to the component after the last.
     */
    constexpr CGM_FORCEINLINE const_iterator
    cend() const;

    /**
     * Get an iterator pointing to the last component.
     */
    constexpr CGM_FORCEINLINE reverse_iterator
    rbegin();

    /**
     * Get an iterator pointing to the component before the first.
     */
    constexpr CGM_FORCEINLINE reverse_iterator
    rend();

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr CGM_FORCEINLINE const_reverse_iterator
    rbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr CGM_FORCEINLINE const_reverse_iterator
    rend() const;

    /**
     * Get an const iterator pointing to the last component.
     */
    constexpr CGM_FORCEINLINE const_reverse_iterator
    crbegin() const;

    /**
     * Get an const iterator pointing to the component before the first.
     */
    constexpr CGM_FORCEINLINE const_reverse_iterator
    crend() const;

/* ####################################################################################### */
protected: /* Components array */
/* ####################################################################################### */

    T m_data[D] {};
};

CGM_NAMESPACE_END


#include "vector.inl"
