

#ifndef POKEMONVIDEOGAME_SETTINGS_H
#define POKEMONVIDEOGAME_SETTINGS_H


#include "Player.h"
#include "GraphicPokemon.h"

class Settings {
public:
    int choosePokemonBattle(sf::RenderWindow &window, int &choosen, GraphicPokemon &graphicPokemon, Player &player);
    int chooseOptions(sf::RenderWindow &window, Player &player, int &choosen3, Pokemon &pokemon, Bullet &bullet);
    int choosePokemon(sf::RenderWindow &window, int &choosen2, std::vector<Pokemon*> PokemonArray,
                      GraphicPokemon &graphicPokemon, Player &player);
};


#endif //POKEMONVIDEOGAME_SETTINGS_H
