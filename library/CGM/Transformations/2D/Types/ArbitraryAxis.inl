

CGM_NAMESPACE_BEGIN
CGM_XFORM2D_NAMESPACE_BEGIN

template<typename T>
constexpr
ArbitraryAxis<T>::ArbitraryAxis(const Vector<2,T>& dir, const Vector<2,T>& pos)
    : direction(dir)
    , position(pos)
{

}

CGM_XFORM2D_NAMESPACE_END
CGM_NAMESPACE_END