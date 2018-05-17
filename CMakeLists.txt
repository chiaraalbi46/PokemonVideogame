cmake_minimum_required(VERSION 3.7)
project(PokemonVideogame)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(testDirectory)

set(SFML_ROOT C:/Users/Niki/SFML)

set(SOURCE_FILES main.cpp Bullet.cpp Bullet.h Character.h Collision.cpp Collision.h Graphic.cpp Graphic.h
        Item.h NPC.cpp NPC.h Player.cpp Player.h Pokemon.cpp Pokemon.h PokemonFactory.cpp PokemonFactory.h WaterPokemon.h
        FirePokemon.h ElectricPokemon.h WaterBullet.h FireBullet.h GraphicPokemon.cpp GraphicPokemon.h GrassPokemon.h Settings.cpp
        Settings.h GrassBullet.h ElectricBullet.h Text.cpp Text.h Map.cpp Map.h)
add_executable(PokemonVideogame ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})
target_link_libraries(PokemonVideogame core)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PokemonVideogame ${SFML_LIBRARIES})
endif()
