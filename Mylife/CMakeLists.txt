cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_library(untitled1 Mylife_CPP/Sort.cpp Mylife_H/Sort.h library.h Mylife_CPP/SortOthers.cpp Mylife_H/SortOthers.h Mylife_CPP/MyStack.cpp Mylife_H/MyStack.h Mylife_CPP/StackOthers.cpp Mylife_H/StackOthers.h Mylife_CPP/DogAndCat.cpp Mylife_H/DogAndCat.h Mylife_H/table.h Mylife_CPP/TableOthers.cpp Mylife_H/TableOthers.h)