cmake_minimum_required(VERSION 3.8)

project(minimum-spanning-tree
    LANGUAGES CXX 
    VERSION 1.0.0 
    DESCRIPTION "Find minimum spanning tree in given social web with weights."
    HOMEPAGE_URL "https://github.com/przemek83/minimum-spanning-tree")

configure_file(${CMAKE_SOURCE_DIR}/testFile.txt 
    ${CMAKE_BINARY_DIR}/testFile.txt COPYONLY)

set(${PROJECT_NAME}_SOURCES
    main.cpp
    )

add_executable(${CMAKE_PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
