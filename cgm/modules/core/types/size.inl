

#include "size.hpp"


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

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 2)>>::Size(T value)
    : w(value)
    , h(value)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr typename Size<D, T, std::enable_if_t<(D == 2)>>::pointer
Size<D, T, std::enable_if_t<(D == 2)>>::data()
{
    return &w;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Size<D, T, std::enable_if_t<(D == 2)>>::const_pointer
Size<D, T, std::enable_if_t<(D == 2)>>::data() const
{
    return &w;
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

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr
Size<D, T, std::enable_if_t<(D == 3)>>::Size(T value)
    : w(value)
    , h(value)
    , d(value)
{

}

/* ####################################################################################### */
/* Getters */
/* ####################################################################################### */

template<size_t D, typename T>
constexpr typename Size<D, T, std::enable_if_t<(D == 3)>>::pointer
Size<D, T, std::enable_if_t<(D == 3)>>::data()
{
    return &w;
}

/* --------------------------------------------------------------------------------------- */

template<size_t D, typename T>
constexpr typename Size<D, T, std::enable_if_t<(D == 3)>>::const_pointer
Size<D, T, std::enable_if_t<(D == 3)>>::data() const
{
    return &w;
}

CGM_NAMESPACE_END