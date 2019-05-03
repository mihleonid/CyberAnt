cmake_minimum_required(VERSION 3.5)
project(CyberAnt)

set(src
	main.cpp
)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(cyberant ${src})
target_link_libraries(cyberant SDL2 SDL2_ttf pthread)

add_definitions(-std=c++11)

