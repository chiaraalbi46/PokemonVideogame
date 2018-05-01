//
// Created by Niki on 01/05/2018.
//

#ifndef POKEMONVIDEOGAME_GRAPHICPOKEMON_H
#define POKEMONVIDEOGAME_GRAPHICPOKEMON_H


#include "PokemonFactory.h"
#include "Player.h"
#include <sstream>



class GraphicPokemon {
public:
    PokemonFactory factory;

    Pokemon* infernape = factory.createPokemon(PokemonType :: PokemonFire);
    Pokemon* floatzel = factory.createPokemon(PokemonType :: PokemonWater);
    Pokemon* luxray = factory.createPokemon(PokemonType :: PokemonElectric);
    Pokemon* breloom = factory.createPokemon(PokemonType :: PokemonGrass);
    Pokemon* rapidash = factory.createPokemon(PokemonType :: PokemonFire);
    Pokemon* blastoise = factory.createPokemon(PokemonType :: PokemonWater);
    Pokemon* zapdos = factory.createPokemon(PokemonType :: PokemonElectric);
    Pokemon* bulbasaur = factory.createPokemon(PokemonType :: PokemonGrass);

    int setCheck(GraphicPokemon &graphicPokemon);
    void setPokemon();
    int loadTexturePokemon(Player &player);
    void setPokemonOpponent(sf::RenderWindow &window,vector <Pokemon*> &PokemonEnemyArray, Player &player,int &choosen4);

    sf:: Sprite sprite;
    sf:: RectangleShape rect;
    sf:: Texture textureInfernape;
    sf:: Texture textureFloatzel;
    sf:: Texture textureLuxray;
    sf:: Texture textureBreloom;
    sf:: Texture textureRapidash;
    sf:: Texture textureBlastoise;
    sf:: Texture textureZapdos;
    sf:: Texture textureBulbasaur;

    sf::Texture pokemonTexture;
    sf::Sprite spritePokemon;   // Mostra tutti i pokemon

    sf:: Texture texturecheck;
    sf:: Sprite spriteCheck;

};

#endif //GIOCO_STRATEGY_H
