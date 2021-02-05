

#include "Size.hpp"


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Constructors */
/* ####################################################################################### */

template<typename T>
constexpr
Size<T>::Size(T width, T height)
    : w(width)
    , h(height)
{

}

template<typename T>
constexpr
Size<T>::Size(T value)
    : w(value)
    , h(value)
{

}

CGM_2D_NAMESPACE_END