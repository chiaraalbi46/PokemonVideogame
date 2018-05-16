

#ifndef POKEMONVIDEOGAME_SETTINGS_H
#define POKEMONVIDEOGAME_SETTINGS_H
#include <SFML/Graphics.hpp>
#include "GraphicPokemon.h"
#include "Graphic.h"

class Settings {
public:
    int choosePokemonBattle(sf::RenderWindow &window, int &choosen, GraphicPokemon &graphicPokemon, Player &player);
    int choosePokemon(sf::RenderWindow &window, int &choosen2, std::vector<Pokemon*> PokemonArray, GraphicPokemon &graphicPokemon,
                      Player &player);
    int menu(sf::RenderWindow &window, int &press, Player &player);
    int options(sf:: RenderWindow &window, Player &player, Graphic &graphic);
    int credits(sf:: RenderWindow &window, Player &player, Graphic &graphic);
    int start1(sf:: RenderWindow &window, Player &player, Graphic &graphic);
    int start2(sf:: RenderWindow &window, Player &player, Graphic &graphic);
    int start3(sf:: RenderWindow &window, Player &player, Graphic &graphic);
    int choosePlayer(sf:: RenderWindow &window, Player &player);
};

#endif //POKEMONVIDEOGAME_SETTINGS_H
