cmake_minimum_required(VERSION 3.16)

project("adventures_in_c" C CXX)

include("cmake/prevent_in_source_builds.cmake")
include("cmake/standard_project_setup.cmake")

include("cmake/compiler_features.cmake")
include("cmake/compiler_warnings.cmake")

include("cmake/auto_group_sources.cmake")

set(${PROJECT_NAME}_FOLDER
    ${PROJECT_NAME}
    CACHE STRING "The folder that ${PROJECT_NAME} projects will be placed in.")

enable_testing()
include(GoogleTest)
include("thirdparty/googletest.cmake")

add_subdirectory("adventures_in_c")