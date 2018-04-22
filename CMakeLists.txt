cmake_minimum_required(VERSION 3.7)
project(PokemonVideogame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bullet.h Character.cpp Character.h Collision.cpp Collision.h Graphic.cpp Graphic.h Item.cpp Item.h NPC.cpp NPC.h
        Player.cpp Player.h Pokemon.cpp Pokemon.h SpecialAttack.h TileMap.cpp TileMap.h)
add_executable(PokemonVideogame ${SOURCE_FILES})

add_library(core ${SOURCE_FILES} hfhx.h)
target_link_libraries(PokemonVideogame core)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PokemonVideogame ${SFML_LIBRARIES})
endif()
