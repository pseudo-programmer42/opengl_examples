cmake_minimum_required(VERSION 3.28)

project(triangle)

add_executable(triangle
	main.cpp
)

target_link_libraries(triangle PUBLIC glfw)
target_include_directories(triangle PUBLIC "${CMAKE_SOURCE_DIR}/external/glfw/include")

target_link_libraries(triangle PUBLIC glad)
target_include_directories(triangle PUBLIC "${CMAKE_SOURCE_DIR}/external/glad/include")

target_include_directories(triangle PUBLIC "${CMAKE_SOURCE_DIR}/external/glm")
