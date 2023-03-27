cmake_minimum_required(VERSION 3.20)
project(Algorithm CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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

function(add_std_func func)
    add_executable(std-${func} ${PROJECT_SOURCE_DIR}/src/std/${func}.cpp)
    target_link_libraries(std-${func} PRIVATE Catch2::Catch2WithMain)
endfunction(add_std_func)

function(add_mine_func func)
    add_executable(${func} ${PROJECT_SOURCE_DIR}/src/mine/${func}.cpp)
    target_link_libraries(mine-${func} PRIVATE Catch2::Catch2WithMain)
endfunction(add_mine_func)

add_std_func(transform)
