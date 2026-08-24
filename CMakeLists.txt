cmake_minimum_required(VERSION 4.2)
project(sdl2_sandbox)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(sdl2_sandbox main.cpp
        pong.cpp
        pong.h)

target_include_directories(sdl2_sandbox PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(sdl2_sandbox ${SDL2_LIBRARIES})
target_link_libraries(sdl2_sandbox ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
