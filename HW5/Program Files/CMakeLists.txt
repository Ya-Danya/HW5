# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(homework5 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
    book.h
    rnd.h
    bookshelf.h
    row.h
    library.h

    # Sources
    book.cpp
    main.cpp
    bookshelf.cpp
    row.cpp
    library.cpp
)

add_executable(homework ${SOURCE_FILES})

find_package(Threads)

target_link_libraries (homework ${CMAKE_THREAD_LIBS_INIT})