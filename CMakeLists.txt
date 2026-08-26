cmake_minimum_required(VERSION 4.2)
project(pong_sdl2)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(pong_sdl2 main.cpp
        pong.cpp
        pong.h)

target_include_directories(pong_sdl2 PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(pong_sdl2 ${SDL2_LIBRARIES})
target_link_libraries(pong_sdl2 ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
