cmake_minimum_required(VERSION 3.8)
project(fractol)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES fractol.c includes/fractol.h onaction.c menu.c mandelbrot.c julia.c burningship.c)

include_directories(include libft ${OpenGL_INCLUDE_DIR})
find_package(OpenGL REQUIRED)
find_package(OpenCL REQUIRED)
add_executable(fractol  ${SOURCE_FILES} menu.c mandelbrot.c burningship.c)

target_link_libraries(fractol -lpthread -lmlx "-framework OpenGL" "-framework AppKit" ${CMAKE_SOURCE_DIR}/libft/libft.a)