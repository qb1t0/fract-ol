cmake_minimum_required(VERSION 3.8)
project(fractol)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES fractol.c algorithm.c includes/fractol.h onaction.c)

include_directories(include libft ${OpenGL_INCLUDE_DIR})
find_package(OpenGL REQUIRED)
add_executable(fractol  ${SOURCE_FILES})

target_link_libraries(fractol -pthread -lmlx "-framework OpenGL" "-framework AppKit" ${CMAKE_SOURCE_DIR}/libft/libft.a)