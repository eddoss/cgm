
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
    target_include_directories(${TARGET} PRIVATE ../../include)
    target_link_libraries(${TARGET} PRIVATE GTest::GTest GTest::Main)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests LANGUAGES CXX)
find_package(GTest REQUIRED)

# ####################################################################################### #
# Tests suites sources
# ####################################################################################### #

set(VECTOR_TEST_SUITE
    run.cpp
    Vector/Arithmetic.cpp
    Vector/Assignment.cpp
    Vector/Iterator.cpp
    Vector/DotAndCross.cpp
    Vector/IncrementDecrement.cpp
    Vector/ComparisonWithOther.cpp
    Vector/ComparisonWithScalar.cpp
)

set(MATRIX_TEST_SUITE
    run.cpp
    Matrix/Accessing.cpp
    Matrix/Arithmetic.cpp
    Matrix/IncrementDecrement.cpp
    Matrix/ComparisonWithOther.cpp
    Matrix/ComparisonWithScalar.cpp
    Matrix/MatrixMultiplication.cpp
    Matrix/Iterators/Direct.cpp
    Matrix/Iterators/Indirect.cpp
    Matrix/Iterators/RowDir.cpp
    Matrix/Iterators/ColumnDir.cpp
    Matrix/Iterators/Row.cpp
)

set(ALL_TEST_SUITES
    ${VECTOR_TEST_SUITE}
    ${MATRIX_TEST_SUITE}
)

# ####################################################################################### #
# Setup tests suites
# ####################################################################################### #

math3d_add_test(AllTestSuites   "${ALL_TEST_SUITES}")
math3d_add_test(VectorTestSuite "${VECTOR_TEST_SUITE}")
math3d_add_test(MatrixTestSuite "${MATRIX_TEST_SUITE}")
