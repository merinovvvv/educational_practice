cmake_minimum_required(VERSION 3.28)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cpp_labs main.cpp
        labs.h
        labs.cpp
)

include_directories(lib/spdlog/include)
include_directories(lib/nlohmann_json)

#
#target_link_libraries(
#        cpp_labs
#        GTest::gtest_main
#)