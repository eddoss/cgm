project(Text LANGUAGES CXX)

file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_LIST_DIR}/*.hpp)

add_executable(${PROJECT_NAME}
    ${SOURCES_FILES}
    ${HEADERS_FILES}
)

find_package(Freetype REQUIRED)
find_package(harfbuzz CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ExamplesCore
        harfbuzz::harfbuzz
        Freetype::Freetype
)