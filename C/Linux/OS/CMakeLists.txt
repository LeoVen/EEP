cmake_minimum_required(VERSION 3.10.2)
project(OS C)

set(CMAKE_C_STANDARD 11)

add_executable(OS main.c SharedMemory.c SharedMemory.h)