

#ifndef POKEMONVIDEOGAME_GRAPHIC_H
#define POKEMONVIDEOGAME_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "NPC.h"
#include "Player.h"
#include "Item.h"
#include <vector>
#include <iostream>
#include <sstream>

using  namespace std;

class Graphic {
public:

    Graphic( ) : bicycle("bicycle"), berry1("cherry berry "), berry2("peach berry"),  pokeball1 ("Megaball"), pokeball2 ("Masterball"), NPC1(), NPC2(), gym("Gym")  {}


    ~Graphic(){}


    int loadTextures();


    void setText(Player &player);
    void setNPC();
    void setFont();
    void setItem();

    int setBackgroundBattle(sf::RenderWindow &window, Player &player);
    int setBattleText(sf::RenderWindow &window, Player &player);

    //Textures
    sf::Texture texturePlayer;
    sf::Texture textureNPC1;
    sf::Texture textureNPC2;
    sf::Texture textureBicycle;
    sf::Texture textureBerry1;
    sf::Texture textureBerry2;
    sf::Texture texturePokeball1;
    sf::Texture texturePokeball2;
    sf::Texture texturePlayerBike;
    sf::Texture textureGym;

    sf::Texture textureBattle;
    sf::Sprite spriteBattle;

    sf:: Text textBattle;

    //NPC
    NPC NPC1;
    NPC NPC2;


    Item bicycle;
    Item berry1;
    Item berry2;
    Item pokeball1;
    Item pokeball2;

    Item gym;

    const int levelBackground[493] =
            {
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  0,  0,  4,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  1,  0,  0,  0,  0,  0,  4,  4,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  4,  4,  4,  4,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  4,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  4,  4,  4,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,


            };

    //Texture&Front
    sf::Font font;

};

#endif //POKEMONVIDEOGAME_GRAPHIC_H
