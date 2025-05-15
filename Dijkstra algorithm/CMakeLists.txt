cmake_minimum_required(VERSION 3.10)

project(Dijkstra)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(googletest)


add_library(
    FileReaderWriter
    src/FileReaderWriter.cpp
    src/FileReaderWriter.hpp
)

add_library(
    Dijkstra
    src/Dijkstra.cpp
    src/Dijkstra.hpp
)

add_executable(
    DijkstraTest
    test/DijkstraTests.cpp
)

target_include_directories(
    Dijkstra PRIVATE
    FileReaderWriter PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_include_directories(
    DijkstraTest PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    DijkstraTest PRIVATE
    gtest
    gtest_main
    Dijkstra
    FileReaderWriter
)