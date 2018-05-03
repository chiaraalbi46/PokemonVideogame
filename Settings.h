

#ifndef POKEMONVIDEOGAME_SETTINGS_H
#define POKEMONVIDEOGAME_SETTINGS_H

#include <SFML/Graphics.hpp>
#include "GraphicPokemon.h"

class Settings {
public:
    int choosePokemonBattle(sf::RenderWindow &window, int &choosen, GraphicPokemon &graphicPokemon, Player &player);
    int choosePokemon(sf::RenderWindow &window, int &choosen2, std::vector<Pokemon*> PokemonArray, GraphicPokemon &graphicPokemon, Player &player);
};

#endif //POKEMONVIDEOGAME_SETTINGS_H
