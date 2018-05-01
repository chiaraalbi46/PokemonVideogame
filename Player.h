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

    bool isEnemy() const;
    void setEnemy(bool enemy);

    bool isBicyclePickUp() const;
    void setBicyclePickUp(bool bicyclePickUp);

    bool isStartBattle() const;
    void setStartBattle(bool startBattle);

    bool rideBicycle = false;
    bool startBattle = false;

    bool enemy0 = false;
    bool enemy1 = false;
    bool enemy2 = false;
    bool enemy3 = false;

    bool click0 = false;
    bool click1 = false;
    bool click2 = false;
    bool click3 = false;
    bool click4 = false;
    bool click5 = false;
    bool click6 = false;
    bool click7 = false;

protected:
    bool bicyclePickUp = false;
    int speed = 1;

    bool enemy = false;         // E' il nemico
};


#endif //POKEMONVIDEOGAME_PLAYER_H
