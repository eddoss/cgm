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

function(cgm_add_test TARGET_NAME SOURCES_DIR)
    set(name "cgm-tests-${TARGET_NAME}")
    file(GLOB_RECURSE ${name}_SOURCES  "${CMAKE_CURRENT_LIST_DIR}/suites/${SOURCES_DIR}/*.cpp")
    add_executable(${name} "${${name}_SOURCES};runner.cpp")
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
            cgm
    )
    add_test(NAME ${name} COMMAND ${name})
    gtest_discover_tests(${name})
endfunction()

enable_testing()

# ####################################################################################### #
# Init test project
# ####################################################################################### #

project(CGM_Tests LANGUAGES CXX)

find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

# ####################################################################################### #
# SUITES | Core
# ####################################################################################### #

cgm_add_test(core         core)
cgm_add_test(core-vector  core/vector)
cgm_add_test(core-matrix  core/matrix)

# ####################################################################################### #
# SUITES | Coordinates
# ####################################################################################### #

cgm_add_test(coordinates coordinates)

# ####################################################################################### #
# SUITES | Cartesian
# ####################################################################################### #

cgm_add_test(cartesian      cartesian)
cgm_add_test(cartesian-2d   cartesian/2d)
cgm_add_test(cartesian-3d   cartesian/3d)

# ####################################################################################### #
# SUITES | Transformations
# ####################################################################################### #

cgm_add_test(transformations      transformations)
cgm_add_test(transformations-2d   transformations/2d)
cgm_add_test(transformations-3d   transformations/3d)

# ####################################################################################### #
# SUITES | Interpolations
# ####################################################################################### #

cgm_add_test(interpolations interpolations)

# ####################################################################################### #
# SUITES | All modules
# ####################################################################################### #

cgm_add_test(all "")