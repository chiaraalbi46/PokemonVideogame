//
//
//

#ifndef POKEMONVIDEOGAME_GRAPHIC_H
#define POKEMONVIDEOGAME_GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "NPC.h"
#include "Player.h"
#include "Item.h"
#include <vector>
#include <string>


class Graphic {
public:

    Graphic(std:: string b = "bicycle", std:: string ba = "bacca", std:: string p = "pokeball"  ) :
            bicycle("bicycle"), bacca("bacca"), pokeball ("pokeball"), NPC1(), NPC2(), text1(), text2()  {}

    ~Graphic(){}


    int loadTextures();


    void setNPC();
    void setFont();
    void setItem();

    //Textures
    sf::Texture texturePlayer;
    sf::Texture textureNPC1;
    sf::Texture textureNPC2;
    sf::Texture textureBicycle;
    sf::Texture textureBacca;
    sf::Texture texturePokeball;
    sf::Texture texturetext1;
    sf::Texture texturetext2;
    sf::Texture texturePlayerBike;



    //NPC
    NPC NPC1;
    NPC NPC2;

    NPC text1;
    NPC text2;

    Item bicycle;
    Item bacca;
    Item pokeball;

    const int levelBackground[336] =
            {
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                    4,  4,  4,  0,  0,  0,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  4,  4,  4,  4,  4,  0,  0,  4,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                    0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,
                    0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  4,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  4,  4,  4,  4,  1,  1,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  4,  1,  1,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  4,  4,  4,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,


            };

    //Texture&Front
    sf::Font font;




};


#endif //POKEMONVIDEOGAME_GRAPHIC_H
