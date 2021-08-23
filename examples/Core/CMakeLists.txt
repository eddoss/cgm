project(ExamplesCore LANGUAGES CXX)

file(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_LIST_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_library(${PROJECT_NAME} STATIC
    ${SOURCES_FILES}
    ${HEADERS_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD                17
    CXX_STANDARD_REQUIRED       ON
    CXX_EXTENSIONS              OFF
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    GLEW::GLEW
    CGM
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    CGM_EXAMPLES_RESOURCES_DIR=${EXAMPLES_RESOURCES_DIR}
)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_LIST_DIR} PATH)
