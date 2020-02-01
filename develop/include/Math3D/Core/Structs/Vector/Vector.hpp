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
    /**
     * Vector components count.
     */                                                                                                                \
    constexpr static size_type                                                                                         \
    dimensions {D};                                                                                                    \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Constructors */                                                                                             \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Initialize all components to single value.
     */                                                                                                                \
    constexpr explicit                                                                                                 \
    Vector(const_reference value) : base_type()                                                                        \
    {                                                                                                                  \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                          \
        base_type::fill(value);                                                                                        \
    }                                                                                                                  \
                                                                                                                       \
    /**
     * Initialize all components via initializer_list.
     */                                                                                                                \
    constexpr                                                                                                          \
    Vector(std::initializer_list<T> values)                                                                            \
    {                                                                                                                  \
        static_assert(D > 1, "Math3D::Vector::constructor: vector size must be more than 1");                          \
        for (auto i = 0; i < D; ++i) base_type::at(i) = *(values.begin() + i);                                         \
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
    /**
     * Set all components to a single value.
     * @param scalar Value to set.
     */                                                                                                                \
    constexpr Vector&                                                                                                  \
    operator=(const_reference scalar) {base_type::fill(scalar); return *this;}                                         \
                                                                                                                       \
/* ####################################################################################### */                          \
public: /* Components accessing */                                                                                     \
/* ####################################################################################### */                          \
                                                                                                                       \
    /**
     * Get component reference by index.
     * @param component reference.
     */                                                                                                                \
    constexpr reference                                                                                                \
    operator[](size_type index) {return base_type::at(index);}                                                         \
                                                                                                                       \
    /**
     * Get component const reference by index.
     * @param component const reference.
     */                                                                                                                \
    constexpr const_reference                                                                                          \
    operator[](size_type index) const {return base_type::at(index);}                                                   \
                                                                                                                       \
    /**
     * Get component reference by index.
     * @param component reference.
     */                                                                                                                \
    constexpr reference                                                                                                \
    operator()(size_type index) {return base_type::at(index);}                                                         \
                                                                                                                       \
    /**
     * Get component const reference by index.
     * @param component const reference.
     */                                                                                                                \
    constexpr const_reference                                                                                          \
    operator()(size_type index) const {return base_type::at(index);}                                                   \
                                                                                                                       \
    /**
     * Get raw pointer at the first component.
     * @param first component raw pointer.
     */                                                                                                                \
    constexpr pointer                                                                                                  \
    data() {return base_type::data();}                                                                                 \
                                                                                                                       \
    /**
     * Get const raw pointer at the first component.
     * @param first component const raw pointer.
     */                                                                                                                \
    constexpr const_pointer                                                                                            \
    data() const {return base_type::data();}                                                                           \
                                                                                                                       \
    /**
     * Get X component reference.
     * @param X component reference.
     */                                                                                                                \
    constexpr reference                                                                                                \
    x() {return this->at(0);}                                                                                          \
                                                                                                                       \
    /**
     * Get X component const reference.
     * @param X component const reference.
     */                                                                                                                \
    constexpr const_reference                                                                                          \
    x() const {return this->at(0);}                                                                                    \
                                                                                                                       \
    /**
     * Get Y component reference.
     * @param Y component reference.
     */                                                                                                                \
    constexpr reference                                                                                                \
    y() {return this->at(1);}                                                                                          \
                                                                                                                       \
    /**
     * Get Y component const reference.
     * @param X component const reference.
     */                                                                                                                \
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

    /** 2D zero vector. */
    const static Vector<D,T>& zero()    {static const Vector<D,T> vec { 0, 0 }; return vec;}

    /** 2D one vector. */
    const static Vector<D,T>& one()     {static const Vector<D,T> vec { 1, 1 }; return vec;}

    /** 2D -X axis. */
    const static Vector<D,T>& left()    {static const Vector<D,T> vec {-1, 0 }; return vec;}

    /** 2D +X axis. */
    const static Vector<D,T>& right()   {static const Vector<D,T> vec { 1, 0 }; return vec;}

    /** 2D +Y axis. */
    const static Vector<D,T>& up()      {static const Vector<D,T> vec { 0, 1 }; return vec;}

    /** 2D -Y axis. */
    const static Vector<D,T>& down()    {static const Vector<D,T> vec { 0,-1 }; return vec;}
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D == 3)>> : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Static constants */
/* ####################################################################################### */

    /** 3D zero vector. */
    const static Vector<D,T>& zero()        {static const Vector<D,T> vec { 0, 0, 0 }; return vec;}

    /** 3D one vector. */
    const static Vector<D,T>& one()         {static const Vector<D,T> vec { 1, 1, 1 }; return vec;}

    /** 3D -X axis. */
    const static Vector<D,T>& left()        {static const Vector<D,T> vec {-1, 0, 0 }; return vec;}

    /** 3D +X axis. */
    const static Vector<D,T>& right()       {static const Vector<D,T> vec { 1, 0, 0 }; return vec;}

    /** 3D +Y axis. */
    const static Vector<D,T>& up()          {static const Vector<D,T> vec { 0, 1, 0 }; return vec;}

    /** 3D -Y axis. */
    const static Vector<D,T>& down()        {static const Vector<D,T> vec { 0,-1, 0 }; return vec;}

    /** 3D +Z axis. */
    const static Vector<D,T>& forward()     {static const Vector<D,T> vec { 0, 0, 1 }; return vec;}

    /** 3D -Z axis. */
    const static Vector<D,T>& backward()    {static const Vector<D,T> vec { 0, 0,-1 }; return vec;}

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get Z component reference.
     * @param Z component reference.
     */
    constexpr reference
    z() {return base_type::at(2);}

    /**
     * Get Z component const reference.
     * @param Z component const reference.
     */
    constexpr const_reference
    z() const {return base_type::at(2);}
};

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
struct Vector <D, T, std::enable_if_t<(D > 3)>> : private std::array<T,D>
{
    MATH3D_VECTOR_COMMON_BODY

/* ####################################################################################### */
public: /* Components accessing */
/* ####################################################################################### */

    /**
     * Get Z component reference.
     * @param Z component reference.
     */
    constexpr reference
    z() {return base_type::at(2);}

    /**
     * Get Z component const reference.
     * @param Z component const reference.
     */
    constexpr const_reference
    z() const {return base_type::at(2);}

    /**
     * Get W component reference.
     * @param W component reference.
     */
    constexpr reference
    w() {return base_type::at(3);}

    /**
     * Get W component const reference.
     * @param W component const reference.
     */
    constexpr const_reference
    w() const {return base_type::at(3);}
};

#endif // MATH3D_VECTOR_HPP
