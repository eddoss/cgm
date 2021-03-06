if(NOT ${CGM_BUILD_UNIT_TESTS})
    return()
endif()

# ##################################################################################### #
# This function help you add tests based on GoogleTest framework.
# You need find GTest package before to call this function.
# It create executable target and setup it with GTest libraries
# and include directories.
#
# TARGET    - name of the created target
# RUNNER    - .cpp file running tests
# SOURCES   - tests list
# ##################################################################################### #

function(cgm_add_test TARGET_NAME SOURCES)
    set(name "CGM_TESTS_${TARGET_NAME}")
    add_executable(${name} ${SOURCES})
    set_target_properties(${name} PROPERTIES
        CXX_STANDARD                17
        CXX_STANDARD_REQUIRED       ON
        CXX_EXTENSIONS              OFF
        MSVC_RUNTIME_LIBRARY        "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
        ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    )
    target_link_libraries(${name}
        PRIVATE
            GTest::gtest
            GTest::gtest_main
        PUBLIC
            CGM
    )
    add_test(NAME ${name} COMMAND ${name})
    gtest_discover_tests(${name})
endfunction()

enable_testing()

# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(CGM_Tests LANGUAGES CXX)

find_package(GTest REQUIRED)

include(GoogleTest)

# ####################################################################################### #
# SUITES | Core
# ####################################################################################### #

set(TESTS_FILES_CORE_VECTOR
    Core/Vector/Getters.cpp
    Core/Vector/Functions.cpp
    Core/Vector/Arithmetic.cpp
    Core/Vector/ComparisonWithOther.cpp
    Core/Vector/ComparisonWithScalar.cpp
)

set(TESTS_FILES_CORE_MATRIX
    Core/Matrix/Access.cpp
    Core/Matrix/Functions.cpp
    Core/Matrix/Arithmetic/Plus.cpp
    Core/Matrix/Arithmetic/Minus.cpp
    Core/Matrix/Arithmetic/IncrementDecrement.cpp
    Core/Matrix/Arithmetic/DivisionByScalar.cpp
    Core/Matrix/Arithmetic/MultiplicationToScalar.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication1NxN1.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication.cpp
    Core/MatrixVectorMultiplication.cpp
    Core/Matrix/Comparison/WithOther.cpp
    Core/Matrix/Comparison/WithScalar.cpp
    Core/Matrix/Iterators/Direct.cpp
    Core/Matrix/Iterators/Indirect.cpp
    Core/Matrix/Iterators/RowDir.cpp
    Core/Matrix/Iterators/ColumnDir.cpp
    Core/Matrix/Iterators/Row.cpp
    Core/Matrix/Iterators/Column.cpp
)

set(TESTS_FILES_CORE
    "${TESTS_FILES_CORE_VECTOR}"
    "${TESTS_FILES_CORE_MATRIX}"
)

cgm_add_test(Core         "run.cpp;${TESTS_FILES_CORE}")
cgm_add_test(Core-Vector  "run.cpp;${TESTS_FILES_CORE_VECTOR}")
cgm_add_test(Core-Matrix  "run.cpp;${TESTS_FILES_CORE_MATRIX}")

# ####################################################################################### #
# SUITES | Coordinates
# ####################################################################################### #

set(TESTS_FILES_COORDINATES
    Coordinates.cpp
)

cgm_add_test(Coordinates "run.cpp;${TESTS_FILES_COORDINATES}")

# ####################################################################################### #
# SUITES | Cartesian
# ####################################################################################### #

set(TESTS_FILES_CARTESIAN_2D
    Cartesian/2D/Functions/Axes.cpp
    Cartesian/2D/Functions/Utils.cpp
    Cartesian/2D/Functions/Orientation.cpp
    Cartesian/2D/Functions/Converters/Vector/GlobalToLocal.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToGlobal.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Vector/LocalToLocal/Matrix2.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/GlobalToLocal.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToGlobal.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Matrix2x2/LocalToLocal/Matrix2.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/GlobalToLocal.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToGlobal.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix3.cpp
    Cartesian/2D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix2.cpp
)

set(TESTS_FILES_CARTESIAN_3D
    Cartesian/3D/Operators.cpp
    Cartesian/3D/Functions/Axes.cpp
    Cartesian/3D/Functions/Utils.cpp
    Cartesian/3D/Functions/Quaternion.cpp
    Cartesian/3D/Functions/Orientation.cpp
    Cartesian/3D/Functions/Converters/Vector/GlobalToLocal.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToGlobal.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Vector/LocalToLocal/Quaternion.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/GlobalToLocal.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToGlobal.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Matrix3x3/LocalToLocal/Quaternion.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/GlobalToLocal.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToGlobal.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Matrix3.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Matrix4.cpp
    Cartesian/3D/Functions/Converters/Matrix4x4/LocalToLocal/Quaternion.cpp
)

set(TESTS_FILES_CARTESIAN
    ${TESTS_FILES_CARTESIAN_2D}
    ${TESTS_FILES_CARTESIAN_3D}
)

cgm_add_test(Cartesian    "run.cpp;${TESTS_FILES_CARTESIAN}")
cgm_add_test(Cartesian-2D "run.cpp;${TESTS_FILES_CARTESIAN_2D}")
cgm_add_test(Cartesian-3D "run.cpp;${TESTS_FILES_CARTESIAN_3D}")

# ####################################################################################### #
# SUITES | Transformations
# ####################################################################################### #

set(TESTS_FILES_TRANSFORMATIONS_2D
    Transformations/2D/Apply.cpp
    Transformations/2D/Translation.cpp
    Transformations/2D/Scale.cpp
    Transformations/2D/Rotate.cpp
    Transformations/2D/Reflect.cpp
    Transformations/2D/Refract.cpp
    Transformations/2D/Transform.cpp
)

set(TESTS_FILES_TRANSFORMATIONS_3D
    Transformations/3D/Apply.cpp
    Transformations/3D/Translation.cpp
    Transformations/3D/Scale.cpp
    Transformations/3D/Rotate.cpp
    Transformations/3D/Reflect.cpp
    Transformations/3D/Refract.cpp
    Transformations/3D/Transform.cpp
)

set(TESTS_FILES_TRANSFORMATIONS
    ${TESTS_FILES_TRANSFORMATIONS_2D}
    ${TESTS_FILES_TRANSFORMATIONS_3D}
)

cgm_add_test(Transformations      "run.cpp;${TESTS_FILES_TRANSFORMATIONS}")
cgm_add_test(Transformations-2D   "run.cpp;${TESTS_FILES_TRANSFORMATIONS_2D}")
cgm_add_test(Transformations-3D   "run.cpp;${TESTS_FILES_TRANSFORMATIONS_3D}")

# ####################################################################################### #
# SUITES | Interpolations
# ####################################################################################### #

set(TESTS_FILES_INTERPOLATIONS
    Interpolations/Clamp.cpp
    Interpolations/Fit.cpp
    Interpolations/Fit01.cpp
    Interpolations/Fit10.cpp
    Interpolations/Fit11.cpp
    Interpolations/FitUnclamped.cpp
    Interpolations/Fit01Unclamped.cpp
    Interpolations/Fit10Unclamped.cpp
    Interpolations/Fit11Unclamped.cpp
    Interpolations/Interps.cpp
)

cgm_add_test(Interpolations "run.cpp;${TESTS_FILES_INTERPOLATIONS}")

# ####################################################################################### #
# SUITES | All modules
# ####################################################################################### #

set(TESTS_ALL_MODULES
    ${TESTS_FILES_CORE}
    ${TESTS_FILES_COORDINATES}
    ${TESTS_FILES_CARTESIAN}
    ${TESTS_FILES_TRANSFORMATIONS}
    ${TESTS_FILES_INTERPOLATIONS}
)

cgm_add_test(All "${TESTS_ALL_MODULES}")