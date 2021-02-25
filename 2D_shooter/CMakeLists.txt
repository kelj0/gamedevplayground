cmake_minimum_required(VERSION 3.17)
project(2D_shooter)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "~/github/gamedevplayground/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(game main.cpp)
target_link_libraries(game sfml-graphics sfml-audio)
