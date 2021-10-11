#pragma once


#include <CGM/Modules/Core/ModuleGlobals.hpp>
#include <CGM/Modules/Primitives/Types/Number.hpp>


CGM_NAMESPACE_BEGIN

template<size_t D, typename T=FLOAT, typename = void> struct Size;

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Size 2D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Size <D, T, std::enable_if_t<(D == 2)>>
{
    CGM_RULE_OF_FIVE(Size)

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    Length<T> w {T(0)};    ///< Width
    Length<T> h {T(0)};    ///< Height

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize width and height.
     * @param width Width value.
     * @param height Height value.
     */
    constexpr
    Size(T width, T height);

    /**
     * Initialize width and height by the same value.
     */
    constexpr explicit
    Size(T value);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

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
};

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Size 3D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
struct Size <D, T, std::enable_if_t<(D == 3)>>
{
    CGM_RULE_OF_FIVE(Size)

/* ####################################################################################### */
public: /* Typedefs */
/* ####################################################################################### */

    using value_type                = T;
    using pointer                   = T*;
    using reference                 = T&;
    using const_pointer             = const T*;
    using const_reference           = const T&;

/* ####################################################################################### */
public: /* Attributes */
/* ####################################################################################### */

    Length<T> w;    ///< Width
    Length<T> h;    ///< Height
    Length<T> d;    ///< Depth

/* ####################################################################################### */
public: /* Constructors */
/* ####################################################################################### */

    /**
     * Initialize width, height and depth.
     * @param width Width value.
     * @param height Height value.
     * @param depth Depth value.
     */
    constexpr
    Size(T width, T height, T depth);

    /**
     * Initialize width, height and depth by the same value.
     * @param value Width, height and depth value.
     */
    constexpr explicit
    Size(T value);

/* ####################################################################################### */
public: /* Getters */
/* ####################################################################################### */

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
};

CGM_NAMESPACE_END


#include "Size.inl"