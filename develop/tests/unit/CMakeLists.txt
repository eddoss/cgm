
# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests
    LANGUAGES CXX
)

# ####################################################################################### #
# Tests suites
# ####################################################################################### #

set(VECTOR_TESTS_SUITES
    Vector/Arithmetic.cpp
    Vector/Assignment.cpp
    Vector/Iterator.cpp
    Vector/DotAndCross.cpp
    Vector/IncrementDecrement.cpp
    Vector/ComparisonWithOther.cpp
    Vector/ComparisonWithScalar.cpp
)

set(MATRIX_TESTS_SUITES
    Matrix/Arithmetic.cpp
    Matrix/Assignment.cpp
    Matrix/IncrementDecrement.cpp
    Matrix/ComparisonWithOther.cpp
    Matrix/ComparisonWithScalar.cpp
    Matrix/MatrixMultiplication.cpp
    Matrix/Iterators/Default.cpp
    Matrix/Iterators/Column.cpp
    Matrix/Iterators/Sub.cpp
    Matrix/Iterators/Row.cpp
)

# ####################################################################################### #
# Setup target
# ####################################################################################### #

add_executable(${PROJECT_NAME}
    run.cpp
    ${VECTOR_TESTS_SUITES}
    ${MATRIX_TESTS_SUITES}
)

find_package(GTest REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ../../include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    GTest::GTest
    GTest::Main
)

# ####################################################################################### #
# Setup tests
# ####################################################################################### #

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
