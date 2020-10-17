

#include "Input.hpp"
#include <CGM/Transformations/2D/Functions/Transform.hpp>


using namespace std;
using namespace CGM;

TEST(Transformations2D_Transform, Vector)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

#ifdef CGM_CFG_LHS
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::SRT));
        const auto expect = Vector<2,double>{+2.18460, +2.89412};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::STR));
        const auto expect = Vector<2,double>{+1.72947, +2.55545};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::RST));
        const auto expect = Vector<2,double>{+1.83102, +2.46839};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::RTS));
        const auto expect = Vector<2,double>{+3.52992, +0.29565};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::TSR));
        const auto expect = Vector<2,double>{+2.49074, -0.09550};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::TRS));
        const auto expect = Vector<2,double>{+2.67713, -0.44202};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
#else
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::SRT));
        const auto expect = Vector<2,double>{-0.92234, +2.19305};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::STR));
        const auto expect = Vector<2,double>{-0.62722, +2.67756};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::RST));
        const auto expect = Vector<2,double>{-0.56876, +2.61879};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::RTS));
        const auto expect = Vector<2,double>{+1.13014, +0.44605};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::TSR));
        const auto expect = Vector<2,double>{+1.76189, +1.29945};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformed(cgm_test::vector, cgm_test::get(ETransformOrder::TRS));
        const auto expect = Vector<2,double>{+1.57550, +1.64597};
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
#endif
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Transform, Matrix2)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::SRT));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::STR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::RST));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::RTS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::TSR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::orientation, cgm_test::get(ETransformOrder::TRS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154}
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::SRT));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::STR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::RST));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::RTS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::TSR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::orientation, cgm_test::get(ETransformOrder::TRS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 }
            );
        #else
            const auto expect = CGM_XY::orientationMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Transform, Matrix3)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

    {
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::SRT));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389},
                Vector<2,double>{+2.18460, +2.89412}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980},
                Vector<2,double>{-0.92234, +2.19305}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::STR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389},
                Vector<2,double>{+1.72947, +2.55545}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980},
                Vector<2,double>{-0.62722, +2.67756}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::RST));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154},
                Vector<2,double>{+1.83102, +2.46839}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215},
                Vector<2,double>{-0.56876, +2.61879}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::RTS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154},
                Vector<2,double>{+3.52992, +0.29565}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215},
                Vector<2,double>{+1.13014, +0.44605}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::TSR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.94926, +0.20488},
                Vector<2,double>{-0.30731, +2.92389},
                Vector<2,double>{+2.49074, -0.09550}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.25986, +1.50145},
                Vector<2,double>{-2.25217, +1.88980},
                Vector<2,double>{+1.76189, +1.29945}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_WORLD>(cgm_test::space, cgm_test::get(ETransformOrder::TRS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+2.12161, -0.11927},
                Vector<2,double>{-0.63146, +2.75154},
                Vector<2,double>{+2.67713, -0.44202}
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{+1.08751, +1.82559},
                Vector<2,double>{-1.92803, +2.06215},
                Vector<2,double>{+1.57550, +1.64597}
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
    {
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::SRT));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 },
                Vector<2,double>{ +1.095035, +1.625152 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 },
                Vector<2,double>{ +0.795964, +0.624163 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::STR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 },
                Vector<2,double>{ +0.852172, +1.112449 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 },
                Vector<2,double>{ +0.829081, +1.190512 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::RST));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 },
                Vector<2,double>{ +0.937481, +1.530972 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 },
                Vector<2,double>{ +0.953518, +0.718343 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::RTS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 },
                Vector<2,double>{ +3.457554, +0.410129 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 },
                Vector<2,double>{ +3.473591, -0.402499 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::TSR));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.206538, -0.176554 },
                Vector<2,double>{ -0.688732, +2.666627 },
                Vector<2,double>{ +2.768868, -0.870815 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.709895, +1.405788 },
                Vector<2,double>{ -2.347827, +1.439778 },
                Vector<2,double>{ +3.585527, +1.095321 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
        {
            const auto result = CGM_XFORM2D::transformed<CGM_LOCAL>(cgm_test::space, cgm_test::get(ETransformOrder::TRS));
        #ifdef CGM_CFG_LHS
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +2.571642, -0.214931 },
                Vector<2,double>{ -0.727109, +2.301524 },
                Vector<2,double>{ +3.050895, -0.641548 }
            );
        #else
            const auto expect = CGM_XY::spaceMatrix
            (
                Vector<2,double>{ +1.344792, +1.444164 },
                Vector<2,double>{ -2.309451, +1.804881 },
                Vector<2,double>{ +3.303500, +0.866055 }
            );
        #endif
            ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
        }
    }
}

/* --------------------------------------------------------------------------------------- */

TEST(Transformations2D_Transform, XFormMatrix)
{
    namespace cgm_test = cgm_xy_xform_tests_data;

#ifdef CGM_CFG_LHS
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::SRT));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, +0.64378},
            Vector<2,double>{-1.19179, +2.67783},
            Vector<2,double>{+0.94572, -0.02133}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::STR));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, +0.64378},
            Vector<2,double>{-1.19179, +2.67783},
            Vector<2,double>{+0.49059, -0.36000}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::RST));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, +0.43849},
            Vector<2,double>{-1.39708, +2.37348},
            Vector<2,double>{+0.76239, -0.03052}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::RTS));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, +0.43849},
            Vector<2,double>{-1.39708, +2.37348},
            Vector<2,double>{+2.46129, -2.20326}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::TSR));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, +0.64378},
            Vector<2,double>{-1.19179, +2.67783},
            Vector<2,double>{+1.25186, -3.01095}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::TRS));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, +0.43849},
            Vector<2,double>{-1.39708, +2.37348},
            Vector<2,double>{+1.60850, -2.94092}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
#else
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::SRT));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, -1.39708},
            Vector<2,double>{+0.43849, +2.37348},
            Vector<2,double>{+0.21172, -0.76475}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::STR));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, -1.39708},
            Vector<2,double>{+0.43849, +2.37348},
            Vector<2,double>{+0.50684, -0.28023}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::RST));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, -1.19179},
            Vector<2,double>{+0.64378, +2.67783},
            Vector<2,double>{+0.39505, -0.75555}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::RTS));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, -1.19179},
            Vector<2,double>{+0.64378, +2.67783},
            Vector<2,double>{+2.09395, -2.92829}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::TSR));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+2.16972, -1.39708},
            Vector<2,double>{+0.43849, +2.37348},
            Vector<2,double>{+2.89596, -1.65834}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
    {
        const auto result = CGM_XFORM2D::transformMatrix(cgm_test::get(ETransformOrder::TRS));
        const auto expect = CGM_XY::spaceMatrix
        (
            Vector<2,double>{+1.86537, -1.19179},
            Vector<2,double>{+0.64378, +2.67783},
            Vector<2,double>{+2.53931, -1.72837}
        );
        ASSERT_TRUE(CGM::eq(result, expect, 0.0001));
    }
#endif
}