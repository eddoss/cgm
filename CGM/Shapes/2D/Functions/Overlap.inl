

#include "Overlap.hpp"


CGM_2D_NAMESPACE_BEGIN

template<typename T>
constexpr CGM_FORCEINLINE bool
overlapped(const Rectangle<T>& A, const Rectangle<T>& B)
{
    const auto al = A.topLeft();
    const auto ar = A.bottomRight();
    const auto bl = B.topLeft();
    const auto br = B.bottomRight();

    if (al.x >= br.x || bl.x >= ar.x)
    {
        return false;
    }

    return !(al.y <= br.y || bl.y <= ar.y);

}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Rectangle<T>
overlapped(const Rectangle<T>& A, const Rectangle<T>& B, bool& exists)
{
    // TODO Implement it
    return {};
}

CGM_2D_NAMESPACE_END