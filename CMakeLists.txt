cmake_minimum_required(VERSION 3.9)
project(RT C)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/libft/inc)
include_directories(${CMAKE_SOURCE_DIR}/inc/)

add_executable(RT
        opencl/effects.cl
        opencl/intersections.cl
        opencl/render.cl
        src/color_vector.c
        src/ft_makelist.c
        src/handlers.c
        src/get_obj.c
        src/main.c
        src/opencl1.c
        src/opencl2.c
        src/read_help.c
        src/readf.c
        includes/rt.h
        includes/rendering.h.cl)

include_directories(${CMAKE_SOURCE_DIR}/frameworks/SDL2.framework/Headers)
target_link_libraries(RT "-F ${CMAKE_SOURCE_DIR}/frameworks -rpath ${CMAKE_SOURCE_DIR}/SDL -framework SDL2")

#include_directories(${CMAKE_SOURCE_DIR}/SDL/SDL2_image.framework/Headers)
#target_link_libraries(RT "-F ${CMAKE_SOURCE_DIR}/SDL -rpath ${CMAKE_SOURCE_DIR}/SDL -framework SDL2_image")

add_library(libft STATIC IMPORTED)
set_property(TARGET libft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(RT libft)

find_library(_openCL OpenCL)
target_link_libraries(RT ${_openCL})
