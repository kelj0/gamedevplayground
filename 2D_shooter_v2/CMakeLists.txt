cmake_minimum_required(VERSION 3.17)
project(2D_shooter_v2)

set(CMAKE_CXX_STANDARD 14)


## In most cases better set in the CMake cache
set(SFML_DIR "~/github/gamedevplayground/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
file(GLOB SOURCES
        src/Player.h
        src/Player.cpp
        src/Engine.h
        src/Engine.cpp
        src/DebugEngine.h
        src/DebugEngine.cpp
        main.cpp
        )

add_executable(game
        ${SOURCES})

target_link_libraries(game sfml-graphics sfml-audio)