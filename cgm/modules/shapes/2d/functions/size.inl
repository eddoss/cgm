

#include "size.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE Size<2,T>
size(const Range<T>& range)
{
    return
    {
        std::fabs(range.max.x - range.min.x),
        std::fabs(range.max.y - range.min.y)
    }
}

/*  --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Size<2,T>
size(const Rectangle<T>& rectangle)
{
    return rectangle.size;
}

CGM_2D_NAMESPACE_END


#include "size.inl"
