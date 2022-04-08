cmake_minimum_required(VERSION 3.0.0)
#project(example VERSION 0.1.0)

set(This CPP_PRJ)
project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_CXX_CLANG_TIDY
#    clang-tidy;
#    -header-filter=.;
#    -checks=*;)

#include(CTest)
include_directories("${gtest_SOURCE_DIR}/include"
                      "${gmock_SOURCE_DIR}/include")
enable_testing()

add_subdirectory(External/googletest)
add_subdirectory(Tests)

set(Headers
    inc/Exam.h
)
set(Sources
    src/Exam.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

set (SRC_LIST main.cpp)

add_executable(mainTest ${SRC_LIST})

#add_executable(mainTest main.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
