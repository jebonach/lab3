cmake_minimum_required(VERSION 3.10)
project(Lab3 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
    main.c
    commands.c
    list.c
    sort.c
    io.c
    parser.c
)

add_executable(program ${SOURCES})

target_include_directories(program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

