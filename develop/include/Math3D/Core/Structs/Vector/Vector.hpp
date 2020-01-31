#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <algorithm>
#include <type_traits>
#include <initializer_list>
#include <Math3D/Global.hpp>
#include <Math3D/Core/Structs/Vector/Iterator.hpp>


/* ------------------------------------------------------------------------------------------------------------------ */
#define MATH3D_VECTOR_COMMON_BODY                                                                                       \
                                                                                                                        \
    T data[D];                                                                                                          \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Typedefs */                                                                                                  \
/* ####################################################################################### */                           \
                                                                                                                        \
    using self_type                 = Vector;                                                                           \
    using size_type                 = size_t;                                                                           \
    using value_type                = T;                                                                                \
    using pointer                   = T*;                                                                               \
    using reference                 = T&;                                                                               \
    using const_pointer             = const T*;                                                                         \
    using const_reference           = const T&;                                                                         \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Iterator typedefs */                                                                                         \
/* ####################################################################################### */                           \
                                                                                                                        \
    using iterator                  = VectorIterator<D,T>;                                                              \
    using const_iterator            = ConstVectorIterator<D,T>;                                                         \
    using reverse_iterator          = std::reverse_iterator<iterator>;                                                  \
	using const_reverse_iterator    = std::reverse_iterator<const_iterator>;                                            \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Statics */                                                                                                   \
/* ####################################################################################### */                           \
                                                                                                                        \
    constexpr static size_type                                                                                          \
    dimensions {D};                                                                                                     \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Constructors */                                                                                              \
/* ####################################################################################### */                           \
                                                                                                                        \
    constexpr explicit                                                                                                  \
    Vector(const T& value)                                                                                              \
    {                                                                                                                   \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                           \
        for (size_type i = 0; i < D; ++i) data[i] = value;                                                              \
    }                                                                                                                   \
                                                                                                                        \
    constexpr                                                                                                           \
    Vector(std::initializer_list<T> values)                                                                             \
    {                                                                                                                   \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                           \
        for (size_type i = 0; i < D; ++i) data[i] = *(values.begin() + i);                                              \
    }                                                                                                                   \
                                                                                                                        \
    constexpr                                                                                                           \
    Vector()                            = default;                                                                      \
                                                                                                                        \
    constexpr                                                                                                           \
    Vector(const self_type&)            = default;                                                                      \
                                                                                                                        \
    constexpr                                                                                                           \
    Vector(self_type&&) noexcept        = default;                                                                      \
                                                                                                                        \
    ~Vector()                           = default;                                                                      \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Assignment operator */                                                                                       \
/* ####################################################################################### */                           \
                                                                                                                        \
    constexpr self_type&                                                                                                \
    operator=(const self_type&)       = default;                                                                        \
                                                                                                                        \
    constexpr self_type&                                                                                                \
    operator=(self_type&&) noexcept   = default;                                                                        \
                                                                                                                        \
    constexpr self_type&                                                                                                \
    operator=(const T& scalar)                                                                                          \
    {                                                                                                                   \
        for (size_type i = 0; i < D; ++i) data[i] = scalar;                                                             \
        return *this;                                                                                                   \
    }                                                                                                                   \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Components accessing */                                                                                      \
/* ####################################################################################### */                           \
                                                                                                                        \
    constexpr reference                                                                                                 \
    operator[](size_type index) {return data[index];}                                                                   \
                                                                                                                        \
    constexpr const_reference                                                                                           \
    operator[](size_type index) const {return data[index];}                                                             \
                                                                                                                        \
    constexpr reference                                                                                                 \
    operator()(size_type index) {return data[index];}                                                                   \
                                                                                                                        \
    constexpr const_reference                                                                                           \
    operator()(size_type index) const {return data[index];}                                                             \
                                                                                                                        \
    constexpr reference                                                                                                 \
    x() {return data[0];}                                                                                               \
                                                                                                                        \
    constexpr const_reference                                                                                           \
    x() const {return data[0];}                                                                                         \
                                                                                                                        \
    constexpr reference                                                                                                 \
    y() {return data[1];}                                                                                               \
                                                                                                                        \
    constexpr const_reference                                                                                           \
    y() const {return data[1];}                                                                                         \
                                                                                                                        \
/* ####################################################################################### */                           \
public: /* Iterators */                                                                                                 \
/* ####################################################################################### */                           \
                                                                                                                        \
    constexpr iterator                                                                                                  \
    begin() {return iterator {data, 0};}                                                                                \
                                                                                                                        \
    constexpr iterator                                                                                                  \
    end() {return iterator {data, D};}                                                                                  \
                                                                                                                        \
    constexpr const_iterator                                                                                            \
    begin() const {return const_iterator {data, 0};}                                                                    \
                                                                                                                        \
    constexpr const_iterator                                                                                            \
    end() const {return const_iterator {data, D};}                                                                      \
                                                                                                                        \
    constexpr const_iterator                                                                                            \
    cbegin() const {return const_iterator {data, 0};}                                                                   \
                                                                                                                        \
    constexpr const_iterator                                                                                            \
    cend() const {return const_iterator {data, D};}                                                                     \
                                                                                                                        \
    constexpr reverse_iterator                                                                                          \
    rbegin() {return reverse_iterator {end()};}                                                                         \
                                                                                                                        \
    constexpr reverse_iterator                                                                                          \
    rend() {return reverse_iterator {begin()};}                                                                         \
                                                                                                                        \
    constexpr const_reverse_iterator                                                                                    \
    rbegin() const {return const_reverse_iterator {cend()};}                                                            \
                                                                                                                        \
    constexpr const_reverse_iterator                                                                                    \
    rend() const {return const_reverse_iterator {cbegin()};}                                                            \
                                                                                                                        \
    constexpr const_reverse_iterator                                                                                    \
    crbegin() const {return const_reverse_iterator {cend()};}                                                           \
                                                                                                                        \
    constexpr const_reverse_iterator                                                                                    \
    crend() const {return const_reverse_iterator {cbegin()};}
/* ------------------------------------------------------------------------------------------------------------------ */




/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* IMPLEMENTATION */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T=FLOAT, typename = void>
struct Vector
{
    MATH3D_VECTOR_COMMON_BODY
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>>
{
    MATH3D_VECTOR_COMMON_BODY

    constexpr reference
    z() {return data[2];}

    constexpr const_reference
    z() const {return data[2];}
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 3)>>
{
    MATH3D_VECTOR_COMMON_BODY

    constexpr reference
    w() {return data[3];}

    constexpr const_reference
    w() const {return data[3];}
};
#endif // MATH3D_VECTOR_HPP
