cmake_minimum_required(VERSION 3.0.0)
set(This ExampleTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(Sources
    ExamTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This}
    gtest 
    gmock
    gtest_main
    #CPP_PRJ
    #libraryTargetOfCodeBeingTested
    #${GTEST_LIBRARY}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)