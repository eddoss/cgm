#ifndef MATH3D_UTILS_HPP
#define MATH3D_UTILS_HPP

#define MATH3D_RULE_OF_FIVE_CONSTEXPR(className) \
    ~className()                                            = default; \
    constexpr className()                                   = default; \
    constexpr className(className&&) noexcept               = default; \
    constexpr className(const className&)                   = default; \
    constexpr className& operator = (const className&)      = default; \
    constexpr className& operator = (className&&) noexcept  = default;

#define MATH3D_RULE_OF_FIVE(className) \
    ~className()                                    = default; \
    className()                                     = default; \
    className(className&&) noexcept                 = default; \
    className(const className&)                     = default; \
    className& operator = (const className&)        = default; \
    className& operator = (className&&) noexcept    = default;

#endif // MATH3D_UTILS_HPP
