//
//
//

#ifndef POKEMONVIDEOGAME_PLAYER_H
#define POKEMONVIDEOGAME_PLAYER_H

#include "Character.h"
#include "Item.h"



class Player: public Character {
public:

    Player() : Character() {
        rect.setSize(sf::Vector2f(25, 30));
        rect.setPosition(100, 100);
        rect.setFillColor(sf::Color::Transparent);
        sprite.setTextureRect(sf::IntRect(0, counterWalking1 * 30, 28, 30));
    }

    ~Player() {}


    void update();

    void move() override;

    int score = 0;
    int getScore() const;
    int increaseScore(int value);

    bool isBicyclePickUp() const;
    void setBicyclePickUp(bool bicyclePickUp);

    bool isStartBattle() const;
    void setStartBattle(bool startBattle);

    bool rideBicycle = false;

    bool startBattle = false;


protected:
    bool bicyclePickUp = false;
    int speed = 1;


};


#endif //POKEMONVIDEOGAME_PLAYER_H
