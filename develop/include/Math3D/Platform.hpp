#ifndef MATH3D_PLATFORM_HPP
#define MATH3D_PLATFORM_HPP

/* --------------------------------------------------------------------------------------- */

#ifdef __GNUC__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#endif

/* --------------------------------------------------------------------------------------- */

#ifdef __clang__
    #define FORCEINLINE     inline __attribute__((always_inline))
    #define FORCENOINLINE   __attribute__((noinline))
#endif

/* --------------------------------------------------------------------------------------- */

#ifdef _MSC_VER
    #define FORCEINLINE     __forceinline
    #define FORCENOINLINE   __declspec(noinline)
#endif

/* --------------------------------------------------------------------------------------- */

#endif //MATH3D_PLATFORM_HPP
