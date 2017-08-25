cmake_minimum_required(VERSION 3.6)
project(C___Text_File_Letter_Counter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LetterTree.cpp LetterTree.h)
add_executable(C___Text_File_Letter_Counter ${SOURCE_FILES})