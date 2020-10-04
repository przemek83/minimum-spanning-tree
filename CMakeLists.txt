cmake_minimum_required(VERSION 3.8)

project(minimum-spanning-tree
    LANGUAGES CXX 
    VERSION 1.0.0 
    DESCRIPTION "Find minimum spanning tree in given social web with weights."
    HOMEPAGE_URL "https://github.com/przemek83/minimum-spanning-tree")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Gtest / Gmock
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src 
    ${CMAKE_BINARY_DIR}/googletest-build)

configure_file(${CMAKE_SOURCE_DIR}/testFile.txt 
    ${CMAKE_BINARY_DIR}/testFile.txt COPYONLY)

set(${PROJECT_NAME}_SOURCES
    main.cpp
    SocialNetwork.cpp
    SocialNetwork.h
    )

add_executable(${CMAKE_PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

enable_testing()
add_subdirectory(test)
