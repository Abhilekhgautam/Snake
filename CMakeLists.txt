cmake_minimum_required(VERSION 3.21)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR </usr/include/SFML>)


add_executable(Snake src/snake.cpp header/snake.h header/world.h src/world.cpp src/game.cpp header/window.h src/window.cpp src/main.cpp)

target_link_libraries (Snake sfml-graphics sfml-window sfml-system)