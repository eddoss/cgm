# ####################################################################################### #
# Target declaration
# ####################################################################################### #

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS   "${CMAKE_CURRENT_LIST_DIR}/CGM/*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_INLINES   "${CMAKE_CURRENT_LIST_DIR}/CGM/*.inl")

source_group("Headers" ${${PROJECT_NAME}_HEADERS})
source_group("Implementation" ${${PROJECT_NAME}_INLINES})

# ####################################################################################### #
# Target configuration
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
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_MATRIX_MULTIPLICATION_ORDER=Pre)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_MATRIX_PREMULT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGM_CFG_ROW_MAJOR)
elseif(CGMATH_MATRIX_MULTIPLICATION_ORDER STREQUAL Post)
    target_compile_definitions(${PROJECT_NAME} INTERFACE CGMATH_MATRIX_MULTIPLICATION_ORDER=Post)
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