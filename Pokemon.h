
#ifndef POKEMONVIDEOGAME_POKEMON_H
#define POKEMONVIDEOGAME_POKEMON_H


#include "SpecialAttack.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Pokemon {
public:
    Pokemon() {}

    virtual ~Pokemon();

    void update();
    void updateDirection();

    int attack(Pokemon& ComputerPlayer);

    int getHp() const{
        return hp;
    }

    int increaseHp();

    int subtractHp();

    bool isDead();

    SpecialAttack* specialAttack;

    const string &getName() const;
    void setName(const string &name);


    sf::RectangleShape rect;
    sf::Sprite sprite;

protected:
    int direction = 0;
    int hp = 30;
    std::string name;

    bool isHit;

};

#endif //GIOCO0_POKEMON_H
