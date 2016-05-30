cmake_minimum_required(VERSION 2.8)
project(cpp_arcade)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -g")

set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/")
find_package(OGRE REQUIRED)
include_directories (${OGRE_INCLUDE_DIRS})
find_package(OIS REQUIRED)

set(SOURCE_FILES sfml/main.cpp
                 src/AEngine.cpp
                 src/AEvents.cpp
                 src/Sprites.cpp
                 src/Map.cpp
                 src/DL.cpp
                 src/Entity.cpp
                 src/SfmlWrapperGui.cpp
                 src/SnakeEngine.cpp
                 src/MovableEntity.cpp
                 src/DrawableEntity.cpp
                 src/Snake.cpp
                 src/GhostBuster.cpp
                 src/Ghost.cpp
                 src/DLLoader.cpp
                 src/Pacman.cpp
                 src/OgreWrapper.cpp)

set(SPRITES_FILES src/sprites/pomme.c
                  src/sprites/snakeGround.c
                  src/sprites/snakeWall.c
                  src/sprites/pacman.c
                  src/sprites/ghost.c
                  src/sprites/snakeBody.c
                  src/sprites/snakeHead.c
                  src/sprites/pacmanDot.c
                  src/sprites/pacmanGround.c
                  src/sprites/pacmanWall.c
                  src/sprites/pacmanPowerUp.c)

include_directories(include interfaces templates lib/tardis/include)
add_executable(cpp_arcade ${SOURCE_FILES} ${SPRITES_FILES})
target_link_libraries(cpp_arcade ${CMAKE_SOURCE_DIR}/lib/tardis/libtardis.a dl sfml-graphics sfml-window sfml-system caca OgreOverlay OgreMain ${OIS_LIBRARY} boost_system)