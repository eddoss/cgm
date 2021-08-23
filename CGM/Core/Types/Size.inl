

#include "Size.hpp"


CGM_NAMESPACE_BEGIN

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Size 2D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 2)>>::Size(T width, T height)
    : w(width)
    , h(height)
{

}

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 2)>>::Size(T value)
    : w(value)
    , h(value)
{

}

/* ####################################################################################### */
/* --------------------------------------------------------------------------------------- */
/* Size 3D */
/* --------------------------------------------------------------------------------------- */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 3)>>::Size(T width, T height, T depth)
    : w(width)
    , h(height)
    , d(depth)
{

}

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 3)>>::Size(T value)
    : w(value)
    , h(value)
    , d(value)
{

}

CGM_NAMESPACE_END