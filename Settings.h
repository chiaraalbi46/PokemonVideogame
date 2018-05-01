//
// Created by Niki on 01/05/2018.
//

#ifndef POKEMONVIDEOGAME_SETTINGS_H
#define POKEMONVIDEOGAME_SETTINGS_H


#include "Player.h"
#include "GraphicPokemon.h"

class Settings {
public:
    int choosePokemonBattle(sf::RenderWindow &window, int &choosen, GraphicPokemon &graphicPokemon, Player &player);
};


#endif //POKEMONVIDEOGAME_SETTINGS_H
