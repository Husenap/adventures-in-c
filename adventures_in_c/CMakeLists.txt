set(target_name "adventures_in_c")

set(src_adventures_in_c
    "src/adventures_in_c/linked_list.c"
    "src/adventures_in_c/linked_list.h")

set(src_files
    ${src_adventures_in_c})

# Project
add_library(${target_name} STATIC ${src_files})
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings)

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

auto_group_sources(src_files ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})


# ===== Unit tests =====
add_executable(${target_name}_test
    "src/adventures_in_c/linked_list_test.cpp")
target_link_libraries(${target_name}_test gmock_main ${target_name})

gtest_discover_tests(${target_name}_test)