cmake_minimum_required(VERSION 3.13)
project(Project3)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3
        main.cpp
        hashTable.cpp hashTable.h
        grid.cpp grid.h
        heap.cpp heap.h
        matrix.cpp matrix.h
        wordList.cpp wordList.h
        cmake-build-debug/wordlist.txt)
