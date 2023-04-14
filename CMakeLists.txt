cmake_minimum_required(VERSION 3.20)
project(Algorithm CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

find_package(Catch2 3 REQUIRED)

function(add_func type func)
    add_executable(${func} ${PROJECT_SOURCE_DIR}/src/${type}/${func}.cpp)
    target_link_libraries(${func} PRIVATE Catch2::Catch2WithMain)
    add_custom_command(
      TARGET ${func}
      POST_BUILD
      COMMAND ${CMAKE_BINARY_DIR}/bin/${func}
      COMMENT "Running ${func}"
    )
endfunction(add_func)


add_func(std transform)
add_func(std lower_bound_upper_bound)

add_func(mine print)
add_func(mine dfs)
add_func(mine bfs)
add_func(mine erase_remove_idiom)

add_func(string find_first_of)
