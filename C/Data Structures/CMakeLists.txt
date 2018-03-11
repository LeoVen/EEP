cmake_minimum_required(VERSION 3.9)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

#Set Paths of my project
set(STRUCTURES ./structures)
set(HEADERS ./headers)
set(UTIL ./util)

#Include them
include_directories(STRUCTURES)
include_directories(HEADERS)
include_directories(UTIL)

add_executable(DataStructures main.c headers/SinglyLinkedList.h structures/SinglyLinkedList.c util/raise.c util/utility.c headers/utility.h headers/StaticArray.h structures/StaticArray.c)