//
//
//

#ifndef POKEMONVIDEOGAME_PLAYER_H
#define POKEMONVIDEOGAME_PLAYER_H

#include "Character.h"
#include "Item.h"
#include "Graphic.h"



class Player: public Character {
public:

    Player() : Character() {
        rect.setSize(sf::Vector2f(25, 30));
        rect.setPosition(100, 100);
        rect.setFillColor(sf::Color::Transparent);
        sprite.setTextureRect(sf::IntRect(0, counter * 30, 28, 30));
    }

    ~Player() {}


    void update();

    void move() override;


    int getScore() const;
    int increaseScore(int value);

    void setRideBicycle(bool rideBicycle);



    sf::Texture myTexture;
    sf::Texture textureExchange;


protected:
    bool rideBicycle = false;

    int score = 0;


};


#endif //POKEMONVIDEOGAME_PLAYER_H
