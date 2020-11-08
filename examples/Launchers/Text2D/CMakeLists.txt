
project(Text2D LANGUAGES CXX)

file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

find_package(harfbuzz CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ExamplesCore harfbuzz::harfbuzz)