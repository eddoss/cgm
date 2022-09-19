

#include "corners.hpp"


CGM_2D_NAMESPACE_BEGIN

/* ####################################################################################### */
/* Ranges */
/* ####################################################################################### */

constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Range<T>& range) const
{
    return {range.min.x, range.max.y};
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Range<T>& range) const
{
    return range.max;
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Range<T>& range) const
{
    return range.min;
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Range<T>& range) const
{
    return {range.max.x, range.min.y};
}

/* ####################################################################################### */
/* Rectangle */
/* ####################################################################################### */

constexpr CGM_FORCEINLINE Vector<2,T>
topLeft(const Rectangle<T>& rectangle) const
{
    return
    {
        rectangle.center.x - rectangle.size.w / 2,
        rectangle.center.y + rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
topRight(const Rectangle<T>& rectangle) const
{
    return
    {
        rectangle.center.x + rectangle.size.w / 2,
        rectangle.center.y + rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
bottomLeft(const Rectangle<T>& rectangle) const
{
    return
    {
        rectangle.center.x - rectangle.size.w / 2,
        rectangle.center.y - rectangle.size.h / 2
    };
}

/*  --------------------------------------------------------------------------------------- */

constexpr CGM_FORCEINLINE Vector<2,T>
bottomRight(const Rectangle<T>& rectangle) const
{
    return
    {
        rectangle.center.x + rectangle.size.w / 2,
        rectangle.center.y - rectangle.size.h / 2
    };
}

CGM_2D_NAMESPACE_END
