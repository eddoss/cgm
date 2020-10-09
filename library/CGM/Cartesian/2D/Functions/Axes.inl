

CGM_NAMESPACE_BEGIN
CGM_XY_NAMESPACE_BEGIN

/* ####################################################################################### */
/* X, Y axes */
/* ####################################################################################### */

template<EAxes Axis, typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
axis()
{
    if constexpr (Axis == EAxes::X)
    {
        return {number<T>(1), zero<T>};
    }
    else
    {
        return {zero<T>, number<T>(1)};
    }
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
x()
{
    return {number<T>(1), zero<T>};
}

/* --------------------------------------------------------------------------------------- */

template<typename T>
constexpr CGM_FORCEINLINE Vector<2,T>
y()
{
    return {zero<T>, number<T>(1)};
}

CGM_XY_NAMESPACE_END
CGM_NAMESPACE_END
