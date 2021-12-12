cmake_minimum_required(VERSION 3.14)
project(space_shooter)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Headers/GameEngine.h
        Sources/GameEngine.cpp
        Headers/Player.h
        Sources/Player.cpp
        Headers/Bullet.h
        Sources/Bullet.cpp
        Sprites/ship.png)

add_executable(SpaceShooter ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SpaceShooter sfml-system sfml-window sfml-graphics sfml-audio sfml-network)