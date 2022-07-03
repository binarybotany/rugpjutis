cmake_minimum_required(VERSION 3.22)

project(rugpjutis VERSION 0.0.0 LANGUAGES C)

add_executable(rugpjutis source/main.c)

target_link_libraries(rugpjutis PRIVATE glfw GL)