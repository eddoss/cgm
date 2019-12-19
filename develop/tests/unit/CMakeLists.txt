
# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(UnitTests
    LANGUAGES CXX
)

# ####################################################################################### #
# Tests list
# ####################################################################################### #

set(TESTS_LIST
    run.cpp
    Iterators/RandomAccess.cpp)

# ####################################################################################### #
# Setup target
# ####################################################################################### #

find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME} ${TESTS_LIST})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ../../include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    debug ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG} Math3D
    optimized ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} Math3D
)

# ####################################################################################### #
# Setup tests
# ####################################################################################### #

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
