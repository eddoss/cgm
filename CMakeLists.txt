
cmake_minimum_required(VERSION 3.12)

# ####################################################################################### #
# Init project
# ####################################################################################### #

project(ComputerGraphixMath
    LANGUAGES CXX
    VERSION 0.0.1
)

# ####################################################################################### #
# Project C++ parameters
# ####################################################################################### #

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ####################################################################################### #
# Promoted cmake options
# ####################################################################################### #

option(CGMATH_BUILD_UNIT_TESTS "Build unit testing projects." OFF)
option(CGMATH_BUILD_EXAMPLES "Build examples projects." ON)
option(CGMATH_USE_DOUBLE_PRECISION "Use double floating point number precision." OFF)
set(CGMATH_MATRIX_LAYOUT "Column" CACHE STRING "Store matrix components by rows or columns (Row/Column).")
set(CGMATH_MATRIX_MULTIPLICATION_ORDER "Pre" CACHE STRING "If 'Pre' is used vector will be represented as row, if 'Post' - as column.")
set(CGMATH_HANDEDNESS "Right" CACHE STRING "Cartesian system handedness (Right/Left).")
set(CGMATH_UP_AXIS "Y" CACHE STRING "Label of Up axis of Cartesian system (X/Y/Z).")

# ####################################################################################### #
# Promoted cmake options constraints
# ####################################################################################### #

set_property(CACHE CGMATH_UP_AXIS PROPERTY STRINGS "X;Y;Z")
set_property(CACHE CGMATH_MATRIX_MULTIPLICATION_ORDER PROPERTY STRINGS "Pre;Post")
set_property(CACHE CGMATH_MATRIX_LAYOUT PROPERTY STRINGS "Row;Column")
set_property(CACHE CGMATH_HANDEDNESS PROPERTY STRINGS "Left;Right")

# ####################################################################################### #
# Setup subproject output dirs
# ####################################################################################### #

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# ####################################################################################### #
# Subprojects
# ####################################################################################### #

if(${CGMATH_BUILD_UNIT_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

if(${CGMATH_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()

# ####################################################################################### #
# Library target
# ####################################################################################### #

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS   "${CMAKE_CURRENT_LIST_DIR}/CGM/*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_IMPLS     "${CMAKE_CURRENT_LIST_DIR}/CGM/*.inl")

source_group("Headers" ${${PROJECT_NAME}_HEADERS})
source_group("Implementation" ${${PROJECT_NAME}_IMPLS})

# ####################################################################################### #
# Library configuration
# ####################################################################################### #

if(CGMATH_USE_DOUBLE_PRECISION)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_USE_DOUBLE_PRECISION)
endif()

# --------------------------------------------------------------------------------------- #

if(CGMATH_MATRIX_LAYOUT STREQUAL Row)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_MATRIX_LAYOUT=Row)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_ROW_WISE_MATRIX_LAYOUT)
elseif(CGMATH_MATRIX_LAYOUT STREQUAL Column)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_MATRIX_LAYOUT=Column)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_COLUMN_WISE_MATRIX_LAYOUT)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGMATH_MATRIX_LAYOUT> configuration property. It must be <Row/Column>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGMATH_HANDEDNESS STREQUAL Left)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_HANDEDNESS=Left)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_LHS)
elseif(CGMATH_HANDEDNESS STREQUAL Right)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_HANDEDNESS=Right)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_RHS)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGMATH_HANDEDNESS> configuration property. It must be <Left/Right>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGMATH_MATRIX_MULTIPLICATION_ORDER STREQUAL Pre)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_MATRIX_MULTIPLICATION_ORDER=Pre)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_MATRIX_PREMULT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_ROW_MAJOR)
elseif(CGMATH_MATRIX_MULTIPLICATION_ORDER STREQUAL Post)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_MATRIX_MULTIPLICATION_ORDER=Post)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_MATRIX_POSTMULT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_COLUMN_MAJOR)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of 'CGMATH_MATRIX_MULTIPLICATION_ORDER' configuration property. It must be <Pre/Post>.")
endif()

# --------------------------------------------------------------------------------------- #

if(CGMATH_UP_AXIS STREQUAL X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES=ZXY)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_RIGHT_IS_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_UP_IS_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_FORWARD_IS_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES_ARE_ZXY)
elseif(CGMATH_UP_AXIS STREQUAL Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES=XYZ)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_RIGHT_IS_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_UP_IS_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_FORWARD_IS_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES_ARE_XYZ)
elseif(CGMATH_UP_AXIS STREQUAL Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES=YZX)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_RIGHT_IS_Y)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_UP_IS_Z)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_FORWARD_IS_X)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_AXES_ARE_YZX)
else()
    message(FATAL_ERROR "[${PROJECT_NAME}]: invalid value of <CGMATH_UP_AXIS> configuration property. It must be <X/Y/Z>.")
endif()

# ####################################################################################### #
# Installation
# ####################################################################################### #

include(CMakePackageConfigHelpers)

set(ConfigPackageLocation "${CMAKE_INSTALL_PREFIX}/cmake")

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${ConfigPackageLocation}
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${ConfigPackageLocation}
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${ConfigPackageLocation}
)

install(
    DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/CGM"
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)
