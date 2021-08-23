# ####################################################################################### #
# Installation
# ####################################################################################### #

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CGM"
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/$<CONFIG>
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/$<CONFIG>
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/$<CONFIG>
    INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CGM"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CGM"
)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/CGM"
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    PATTERN "CMakeLists.txt" EXCLUDE
)