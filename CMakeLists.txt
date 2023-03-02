cmake_minimum_required(VERSION 3.10)

project(ProjectE VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(ProjectEConfig.h.in ProjectEConfig.h)

add_executable(ProjectE projecte.c ./questions/questions.c ./questions/useful.c)

target_include_directories(ProjectE PUBLIC ${PROJECT_BINARY_DIR} PUBLIC ./questions/)

target_link_libraries(ProjectE PRIVATE m)

