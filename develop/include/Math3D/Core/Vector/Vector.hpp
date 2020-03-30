#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <array>
#include <algorithm>
#include <type_traits>
#include <initializer_list>
#include <Math3D/Global.hpp>


MATH3D_NAMESPACE_BEGIN

/* ################################################################################################################## */
#define MATH3D_VECTOR_DATA_GETTERS                                                                                     \
    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */                                                                                                                \
    constexpr pointer                                                                                                  \
    data() {return &x;}                                                                                                \
                                                                                                                       \
    /**
     * Get const raw pointer at the first component.
     * @param first component const raw pointer.
     */                                                                                                                \
    constexpr const_pointer                                                                                            \
    data() const {return &x;}                                                                                          \
/* ################################################################################################################## */

/* ################################################################################################################## */
#define MATH3D_VECTOR_COMMON_BODY                                                                                      \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Typedefs */                                                                                                 \
/* ####################################################################################### */                          \
                                                                                                                       \
    using value_type                = T;                                                                               \
    using pointer                   = T*;                                                                              \
    using reference                 = T&;                                                                              \
    using const_pointer             = const T*;                                                                        \
    using const_reference           = const T&;                                                                        \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Static constants */                                                                                         \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Vector components count.
     */                                                                                                                \
    constexpr static size_t                                                                                            \
    dimensions {D};                                                                                                    \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Default constructors */                                                                                     \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr                                                                                                          \
    Vector()                        = default;                                                                         \
                                                                                                                       \
    constexpr                                                                                                          \
    Vector(const Vector&)           = default;                                                                         \
                                                                                                                       \
    constexpr                                                                                                          \
    Vector(Vector&&) noexcept       = default;                                                                         \
                                                                                                                       \
    ~Vector()                       = default;                                                                         \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Default assignment operators */                                                                             \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr Vector&                                                                                                  \
    operator=(const Vector&)        = default;                                                                         \
                                                                                                                       \
    constexpr Vector&                                                                                                  \
    operator=(Vector&&) noexcept    = default;                                                                         \
                                                                                                                       \
/* ################################################################################################################## */

template<size_t D, typename T=FLOAT, typename = void> struct Vector;

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 2)>>
{
    T x;
    T y;

    MATH3D_VECTOR_COMMON_BODY
    MATH3D_VECTOR_DATA_GETTERS

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components via initializer_list.
     */
    constexpr
    Vector(std::initializer_list<T> values)
        : x(*(values.begin()))
        , y(*(values.begin() + 1)) {};

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T singleValue)
        : x(singleValue)
        , y(singleValue) {};

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y)
        : x(X)
        , y(Y) {};

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assign all components by single value.
     */
    constexpr Vector&
    operator = (value_type value)
    {
        x = value;
        y = value;
    }
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>>
{
    T x;
    T y;
    T z;

    MATH3D_VECTOR_COMMON_BODY
    MATH3D_VECTOR_DATA_GETTERS

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components via initializer_list.
     */
    constexpr
    Vector(std::initializer_list<T> values)
        : x(*(values.begin()))
        , y(*(values.begin() + 1))
        , z(*(values.begin() + 2)) {};

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T singleValue)
        : x(singleValue)
        , y(singleValue)
        , z(singleValue) {};

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y, T Z)
        : x(X)
        , y(Y)
        , z(Z){};

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assign all components by single value.
     */
    constexpr Vector&
    operator = (value_type value)
    {
        x = value;
        y = value;
        z = value;
    }
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 4)>>
{
    T x;
    T y;
    T z;
    T w;

    MATH3D_VECTOR_COMMON_BODY
    MATH3D_VECTOR_DATA_GETTERS

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components via initializer_list.
     */
    constexpr
    Vector(std::initializer_list<T> values)
        : x(*(values.begin()))
        , y(*(values.begin() + 1))
        , z(*(values.begin() + 2))
        , w(*(values.begin() + 3)) {};

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T singleValue)
        : x(singleValue)
        , y(singleValue)
        , z(singleValue)
        , w(singleValue) {};

    /**
     * Initialize all components directly.
     */
    constexpr
    Vector(T X, T Y, T Z, T W)
        : x(X)
        , y(Y)
        , z(Z)
        , w(W) {};

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assign all components by single value.
     */
    constexpr Vector&
    operator = (value_type value)
    {
        x = value;
        y = value;
        z = value;
        w = value;
    }
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 4)>> : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using base_type                 = std::array<T,D>;
    using size_type                 = typename base_type::size_type;

/* ####################################################################################### */
public: /* Iterator typedefs */
/* ####################################################################################### */

    using iterator                  = typename base_type::iterator;
    using const_iterator            = typename base_type::const_iterator;
    using reverse_iterator          = typename base_type::reverse_iterator;
    using const_reverse_iterator    = typename base_type::const_reverse_iterator;

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize all components via initializer_list.
     */
    constexpr
    Vector(std::initializer_list<T> values)
    {
        for (auto i = 0; i < D; ++i) base_type::at(i) = *(values.begin() + i);
    }

    /**
     * Initialize all components by single value.
     */
    constexpr explicit
    Vector(T singleValue)
    {
        for (auto i = 0; i < D; ++i) base_type::at(i) = singleValue;
    }

/* ####################################################################################### */
public: /* Assignment operator */
/* ####################################################################################### */

    /**
     * Assign all components by single value.
     */
    constexpr Vector&
    operator = (value_type value)
    {
        for (auto i = 0; i < D; ++i) base_type::at(i) = value;
    }

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get component reference by index.
     * @param component reference.
     */
    constexpr reference
    operator[](size_type index) {return base_type::at(index);}

    /**
     * Get component const reference by index.
     * @param component const reference.
     */
    constexpr const_reference
    operator[](size_type index) const {return base_type::at(index);}

    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */
    constexpr pointer
    data() {return base_type::data();}

    /**
     * Get const raw pointer at the first component.
     * @param first component const raw pointer.
     */
    constexpr const_pointer
    data() const {return base_type::data();}

/* ####################################################################################### */
public: /* Iterators */
/* ####################################################################################### */

    constexpr iterator
    begin() {return base_type::begin();}

    constexpr iterator
    end() {return base_type::end();}

    constexpr const_iterator
    begin() const {return base_type::begin();}

    constexpr const_iterator
    end() const {return base_type::end();}

    constexpr const_iterator
    cbegin() const {return base_type::cbegin();}

    constexpr const_iterator
    cend() const {return base_type::cend();}

    constexpr reverse_iterator
    rbegin() {return base_type::rbegin();}

    constexpr reverse_iterator
    rend() {return base_type::rend();}

    constexpr const_reverse_iterator
    rbegin() const {return base_type::rbegin();}

    constexpr const_reverse_iterator
    rend() const {return base_type::rend();}

    constexpr const_reverse_iterator
    crbegin() const {return base_type::crbegin();}

    constexpr const_reverse_iterator
    crend() const {return base_type::crend();}
};

MATH3D_NAMESPACE_END

#endif // MATH3D_VECTOR_HPP
