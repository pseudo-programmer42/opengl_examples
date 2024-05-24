cmake_minimum_required(VERSION 3.28)

project(opengl_examples)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/stb_image)

add_subdirectory(001_triangle)