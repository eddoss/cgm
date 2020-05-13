
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

function(math3d_add_test TARGET SOURCES)
    add_executable(${TARGET} ${SOURCES})
    target_include_directories(${TARGET} PRIVATE ../include)
    target_link_libraries(${TARGET} PRIVATE GTest::GTest GTest::Main)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests LANGUAGES CXX)
find_package(GTest REQUIRED)

# ####################################################################################### #
# SUITES | Core
# ####################################################################################### #

set(TS_CORE_VECTOR
    Core/Vector/Functions.cpp
    Core/Vector/Arithmetic.cpp
    Core/Vector/ComparisonWithOther.cpp
    Core/Vector/ComparisonWithScalar.cpp
)

set(TS_CORE_MATRIX
    Core/Matrix/Functions.cpp
    Core/Matrix/Arithmetic/Plus.cpp
    Core/Matrix/Arithmetic/Minus.cpp
    Core/Matrix/Arithmetic/IncrementDecrement.cpp
    Core/Matrix/Arithmetic/DivisionByScalar.cpp
    Core/Matrix/Arithmetic/MultiplicationToScalar.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication1NxN1.cpp
    Core/Matrix/Arithmetic/MatrixMultiplication.cpp
    Core/Matrix/Arithmetic/MatrixVectorMultiplication.cpp
    Core/Matrix/Comparison/WithOther.cpp
    Core/Matrix/Comparison/WithScalar.cpp
    Core/Matrix/Iterators/Direct.cpp
    Core/Matrix/Iterators/Indirect.cpp
    Core/Matrix/Iterators/RowDir.cpp
    Core/Matrix/Iterators/ColumnDir.cpp
    Core/Matrix/Iterators/Row.cpp
    Core/Matrix/Iterators/Column.cpp
)

set(TS_CORE_QUATERNION
    Core/Quaternion/Operators.cpp
    Core/Quaternion/Functions.cpp
)

set(TS_CORE_COORDINATES
    Core/Coordinates.cpp
)

set(TS_MODULE_CORE
    "${TS_CORE_VECTOR}"
    "${TS_CORE_MATRIX}"
    "${TS_CORE_QUATERNION}"
    "${TS_CORE_COORDINATES}"
)

math3d_add_test(ModuleCoreTestSuite         "run.cpp;${MODULE_CORE_TEST_SUITE}")
math3d_add_test(Core-VectorTestSuite        "run.cpp;${CORE_VECTOR_TEST_SUITE}")
math3d_add_test(Core-MatrixTestSuite        "run.cpp;${CORE_MATRIX_TEST_SUITE}")
math3d_add_test(Core-QuaternionTestSuite    "run.cpp;${CORE_QUATERNION_TEST_SUITE}")
math3d_add_test(Core-CoordinatesTestSuite   "run.cpp;${CORE_COORDINATES_TEST_SUITE}")

# ####################################################################################### #
# SUITES | All modules
# ####################################################################################### #

set(TS_ALL_MODULES
    ${TS_MODULE_CORE}
)

math3d_add_test(AllModulesTestSuites  "${TS_ALL_MODULES}")