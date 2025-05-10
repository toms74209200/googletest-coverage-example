cmake_minimum_required(VERSION 3.20)

project(GoogleTest)
set(CMAKE_CXX_STANDARD 23)
find_package(GTest)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE TESTS test/*_test.cpp)
add_executable(GoogleTest ${SOURCES} ${TESTS})
target_link_libraries(
    GoogleTest
    ${GTEST_BOTH_LIBRARIES}
    gmock
    pthread
    GTest::Main)
target_include_directories(
    GoogleTest
    PRIVATE
    ${GTEST_INCLUDE_DIRS})
target_include_directories(
    GoogleTest
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/test)