#ifndef MATH3D_VECTOR_HPP
#define MATH3D_VECTOR_HPP


#include <array>
#include <algorithm>
#include <type_traits>
#include <initializer_list>
#include <Math3D/Global.hpp>


/* ################################################################################################################## */
#define MATH3D_VECTOR_COMMON_BODY                                                                                      \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Typedefs */                                                                                                 \
/* ####################################################################################### */                          \
                                                                                                                       \
    using base_type                 = std::array<T,D>;                                                                 \
    using size_type                 = typename base_type::size_type;                                                   \
    using value_type                = typename base_type::value_type;                                                  \
    using pointer                   = typename base_type::pointer;                                                     \
    using reference                 = typename base_type::reference;                                                   \
    using const_pointer             = typename base_type::const_pointer;                                               \
    using const_reference           = typename base_type::const_reference;                                             \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Constructors */                                                                                             \
/* ####################################################################################### */                          \
                                                                                                                       \
    using iterator                  = typename base_type::iterator;                                                    \
    using const_iterator            = typename base_type::const_iterator;                                              \
    using reverse_iterator          = typename base_type::reverse_iterator;                                            \
    using const_reverse_iterator    = typename base_type::const_reverse_iterator;                                      \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Static constants */                                                                                         \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr static size_type                                                                                         \
    dimensions {D};                                                                                                    \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Constructors */                                                                                             \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr explicit                                                                                                 \
    Vector(const_reference value) : base_type()                                                                        \
    {                                                                                                                  \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                          \
        this->fill(value);                                                                                             \
    }                                                                                                                  \
                                                                                                                       \
    constexpr                                                                                                          \
    Vector(std::initializer_list<T> values)                                                                            \
    {                                                                                                                  \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                          \
        for (auto i = 0LL; i < D; ++i) this->at(i) = *(values.begin() + i);                                            \
    }                                                                                                                  \
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
public: /* Assignment operator */                                                                                      \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr Vector&                                                                                                  \
    operator=(const Vector&)        = default;                                                                         \
                                                                                                                       \
    constexpr Vector&                                                                                                  \
    operator=(Vector&&) noexcept    = default;                                                                         \
                                                                                                                       \
    constexpr Vector&                                                                                                  \
    operator=(const_reference scalar) {this->fill(scalar); return *this;}                                              \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Components accessing */                                                                                     \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr reference                                                                                                \
    operator[](size_type index) {return base_type::at(index);}                                                         \
                                                                                                                       \
    constexpr const_reference                                                                                          \
    operator[](size_type index) const {return base_type::at(index);}                                                   \
                                                                                                                       \
    constexpr reference                                                                                                \
    operator()(size_type index) {return base_type::at(index);}                                                         \
                                                                                                                       \
    constexpr const_reference                                                                                          \
    operator()(size_type index) const {return base_type::at(index);}                                                   \
                                                                                                                       \
    constexpr pointer                                                                                                  \
    data() {return base_type::data();}                                                                                 \
                                                                                                                       \
    constexpr const_pointer                                                                                            \
    data() const {return base_type::data();}                                                                           \
                                                                                                                       \
    constexpr reference                                                                                                \
    x() {return this->at(0);}                                                                                          \
                                                                                                                       \
    constexpr const_reference                                                                                          \
    x() const {return this->at(0);}                                                                                    \
                                                                                                                       \
    constexpr reference                                                                                                \
    y() {return this->at(1);}                                                                                          \
                                                                                                                       \
    constexpr const_reference                                                                                          \
    y() const {return this->at(1);}                                                                                    \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Direct iterators */                                                                                         \
/* ####################################################################################### */                          \
                                                                                                                       \
    constexpr iterator                                                                                                 \
    begin() {return base_type::begin();}                                                                               \
                                                                                                                       \
    constexpr iterator                                                                                                 \
    end() {return base_type::end();}                                                                                   \
                                                                                                                       \
    constexpr const_iterator                                                                                           \
    begin() const {return base_type::begin();}                                                                         \
                                                                                                                       \
    constexpr const_iterator                                                                                           \
    end() const {return base_type::end();}                                                                             \
                                                                                                                       \
    constexpr const_iterator                                                                                           \
    cbegin() const {return base_type::cbegin();}                                                                       \
                                                                                                                       \
    constexpr const_iterator                                                                                           \
    cend() const {return base_type::cend();}                                                                           \
                                                                                                                       \
    constexpr reverse_iterator                                                                                         \
    rbegin() {return base_type::rbegin();}                                                                             \
                                                                                                                       \
    constexpr reverse_iterator                                                                                         \
    rend() {return base_type::rend();}                                                                                 \
                                                                                                                       \
    constexpr const_reverse_iterator                                                                                   \
    rbegin() const {return base_type::rbegin();}                                                                       \
                                                                                                                       \
    constexpr const_reverse_iterator                                                                                   \
    rend() const {return base_type::rend();}                                                                           \
                                                                                                                       \
    constexpr const_reverse_iterator                                                                                   \
    crbegin() const {return base_type::crbegin();}                                                                     \
                                                                                                                       \
    constexpr const_reverse_iterator                                                                                   \
    crend() const {return base_type::crend();}                                                                         \
/* ################################################################################################################## */


template<size_t D, typename T=FLOAT, typename = void>
struct Vector : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    const static Vector<D,T>& zero        (){static const Vector<D,T> vec { 0, 0 }; return vec;}
    const static Vector<D,T>& one         (){static const Vector<D,T> vec { 1, 1 }; return vec;}
    const static Vector<D,T>& left        (){static const Vector<D,T> vec {-1, 0 }; return vec;}
    const static Vector<D,T>& right       (){static const Vector<D,T> vec { 1, 0 }; return vec;}
    const static Vector<D,T>& up          (){static const Vector<D,T> vec { 0, 1 }; return vec;}
    const static Vector<D,T>& down        (){static const Vector<D,T> vec { 0,-1 }; return vec;}
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>> : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    const static Vector<D,T>& zero        (){static const Vector<D,T> vec { 0, 0, 0 }; return vec;}
    const static Vector<D,T>& one         (){static const Vector<D,T> vec { 1, 1, 1 }; return vec;}
    const static Vector<D,T>& left        (){static const Vector<D,T> vec {-1, 0, 0 }; return vec;}
    const static Vector<D,T>& right       (){static const Vector<D,T> vec { 1, 0, 0 }; return vec;}
    const static Vector<D,T>& up          (){static const Vector<D,T> vec { 0, 1, 0 }; return vec;}
    const static Vector<D,T>& down        (){static const Vector<D,T> vec { 0,-1, 0 }; return vec;}
    const static Vector<D,T>& forward     (){static const Vector<D,T> vec { 0, 0, 1 }; return vec;}
    const static Vector<D,T>& backward    (){static const Vector<D,T> vec { 0, 0,-1 }; return vec;}

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    constexpr reference
    z() {return this->at(2);}

    constexpr const_reference
    z() const {return this->at(2);}
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 3)>> : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    const static Vector<D,T>& zero        (){static const Vector<D,T> vec { 0, 0, 0, 0 }; return vec;}
    const static Vector<D,T>& one         (){static const Vector<D,T> vec { 1, 1, 1, 0 }; return vec;}
    const static Vector<D,T>& left        (){static const Vector<D,T> vec {-1, 0, 0, 0 }; return vec;}
    const static Vector<D,T>& right       (){static const Vector<D,T> vec { 1, 0, 0, 0 }; return vec;}
    const static Vector<D,T>& up          (){static const Vector<D,T> vec { 0, 1, 0, 0 }; return vec;}
    const static Vector<D,T>& down        (){static const Vector<D,T> vec { 0,-1, 0, 0 }; return vec;}
    const static Vector<D,T>& forward     (){static const Vector<D,T> vec { 0, 0, 1, 0 }; return vec;}
    const static Vector<D,T>& backward    (){static const Vector<D,T> vec { 0, 0,-1, 0 }; return vec;}

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    constexpr reference
    z() {return this->at(2);}

    constexpr const_reference
    z() const {return this->at(2);}

    constexpr reference
    w() {return this->at(3);}

    constexpr const_reference
    w() const {return this->at(3);}
};

#endif // MATH3D_VECTOR_HPP
