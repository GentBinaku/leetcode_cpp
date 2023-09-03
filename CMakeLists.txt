cmake_minimum_required(VERSION 3.26)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 23)


# dbg-macro
include(FetchContent)

FetchContent_Declare(dbg_macro GIT_REPOSITORY https://github.com/sharkdp/dbg-macro)
FetchContent_MakeAvailable(dbg_macro)

add_executable(leetcode_cpp main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE dbg_macro) # make dbg.h available
