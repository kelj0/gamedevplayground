cmake_minimum_required(VERSION 3.17)
project(2D_shooter)

set(CMAKE_CXX_STANDARD 14)


## In most cases better set in the CMake cache
set(SFML_DIR "~/github/gamedevplayground/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
file(GLOB SOURCES
        *.h
        *.cpp)

add_executable(game
        ${SOURCES})

target_link_libraries(game sfml-graphics sfml-audio)
