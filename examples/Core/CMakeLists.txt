
project(ExamplesCore LANGUAGES CXX)

file(GLOB_RECURSE HEADERS_FILES ${CMAKE_CURRENT_LIST_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCES_FILES ${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES_FILES} ${HEADERS_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLEW::GLEW ComputerGraphixMath)
target_compile_definitions(${PROJECT_NAME} PUBLIC CGM_EXAMPLES_RESOURCES_DIR=${EXAMPLES_RESOURCES_DIR})

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_LIST_DIR} PATH)
