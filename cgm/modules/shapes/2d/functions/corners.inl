

#include "corners.hpp"


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Ranges */
/* ####################################################################################### */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Range<T>& range)
{
    return {range.min.x, range.max.y};
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Range<T>& range)
{
    return range.max;
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Range<T>& range)
{
    return range.min;
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Range<T>& range)
{
    return {range.max.x, range.min.y};
}

/* ####################################################################################### */
/* Rectangle */
/* ####################################################################################### */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Rectangle<T>& rectangle)
{
    return
    {
        rectangle.center.x - rectangle.size.w / 2,
        rectangle.center.y + rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Rectangle<T>& rectangle)
{
    return
    {
        rectangle.center.x + rectangle.size.w / 2,
        rectangle.center.y + rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Rectangle<T>& rectangle)
{
    return
    {
        rectangle.center.x - rectangle.size.w / 2,
        rectangle.center.y - rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

template <typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Rectangle<T>& rectangle)
{
    return
    {
        rectangle.center.x + rectangle.size.w / 2,
        rectangle.center.y - rectangle.size.h / 2
    };
}

CGM_2D_NAMESPACE_END
