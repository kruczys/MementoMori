cmake_minimum_required(VERSION 3.27)
project(MementoMori C)

set(CMAKE_C_STANDARD 23)

add_executable(MementoMori src/main.c
        src/time_manage.h
        src/time_manage.c
        src/file_manage.c
        src/file_manage.h)
