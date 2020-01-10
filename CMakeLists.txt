
cmake_minimum_required(VERSION 3.12)

# ####################################################################################### #
# Init project
# ####################################################################################### #

project(Math3D
    LANGUAGES CXX
    VERSION 0.0.1
)

set(PROJECT_INSTALL_PREFIX ${PROJECT_NAME}/${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build parameters
# ####################################################################################### #
option(BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(BUILD_VISUAL_TESTS "Build visual testing projects." OFF)
option(USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
# ####################################################################################### #

# ####################################################################################### #
# Setup shared and static libraries output dir
# ####################################################################################### #

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# Public headers and private sources
# ####################################################################################### #

set(Math3D_PUBLIC_HEADERS
    develop/include/Math3D/IO.hpp
    develop/include/Math3D/Global.hpp
        develop/include/Math3D/Core/Vectors/Vector.hpp
        develop/include/Math3D/Core/Vectors/Iterators.hpp
    develop/include/Math3D/Core/Matrices/Matrix.hpp
    develop/include/Math3D/Core/Matrices/Iterators/Default.hpp
    develop/include/Math3D/Core/Matrices/Iterators/Row.hpp
    develop/include/Math3D/Core/Matrices/Iterators/Column.hpp
    develop/include/Math3D/Core/Matrices/Subiterators/Default.hpp
    develop/include/Math3D/Core/Matrices/Subiterators/Row.hpp
    develop/include/Math3D/Core/Matrices/Subiterators/Column.hpp
)

# ####################################################################################### #
# Setup main target
# ####################################################################################### #

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/develop/include")

if(USE_DOUBLE_PRECISION)
    target_compile_definitions(${PROJECT_NAME} INTERFACE USE_DOUBLE_PRECISION=true)
else()
    target_compile_definitions(${PROJECT_NAME} INTERFACE USE_DOUBLE_PRECISION=false)
endif()

# ####################################################################################### #
# Installation 
# ####################################################################################### #

install( 
    FILES ${Math3D_PUBLIC_HEADERS}
    DESTINATION "${PROJECT_INSTALL_PREFIX}/include/Math3D"
    DESTINATION "${PROJECT_INSTALL_PREFIX}/include/Math3D"
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${PROJECT_INSTALL_PREFIX}/bin/$<CONFIG>"
    LIBRARY DESTINATION "${PROJECT_INSTALL_PREFIX}/lib/$<CONFIG>"
    ARCHIVE DESTINATION "${PROJECT_INSTALL_PREFIX}/lib/$<CONFIG>"
)

# ####################################################################################### #
# Testing
# ####################################################################################### #

if(${BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(develop/tests)
endif()
