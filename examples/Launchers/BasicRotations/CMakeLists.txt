project(BasicRotations LANGUAGES CXX)

file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_LIST_DIR}/*.hpp)

add_executable(${PROJECT_NAME}
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
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ExamplesCore
)