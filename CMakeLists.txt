cmake_minimum_required(VERSION 3.12)
project(Propulsion C)

set(CMAKE_C_STANDARD 11)

add_executable(Propulsion main.c structs.h trigTables.h functions.h transistors.h)