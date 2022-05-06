cmake_minimum_required(VERSION 3.21)
project(raycaster)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(raycaster "src/Main.cpp" src/Engine/Engine.cpp src/Engine/Engine.h src/Graphics/Grid.cpp src/Graphics/Grid.h "src/Constants.h" "src/Graphics/Player.cpp" "src/Graphics/Player.h" "src/Graphics/Line.cpp" "src/Graphics/Line.h" src/Physics/Vector2f.cpp src/Physics/Vector2f.h src/Graphics/Raycaster.cpp src/Graphics/Raycaster.h)
target_link_libraries(raycaster PRIVATE SDL2::SDL2 SDL2::SDL2main)