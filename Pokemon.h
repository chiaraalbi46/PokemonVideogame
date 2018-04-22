//
//
//

#ifndef POKEMONVIDEOGAME_POKEMON_H
#define POKEMONVIDEOGAME_POKEMON_H


#include "SpecialAttack.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Pokemon {
public:
    Pokemon() {
        rect.setSize(sf::Vector2f(64, 64));
        rect.setPosition(200, 200);
    }
    ~Pokemon();

    void update();

    int attack(Pokemon& ComputerPlayer);

    int getHp() const{
        return hp;
    }

    int increaseHp();

    int subtractHp();

    bool isDead();

    SpecialAttack* specialAttack;


    sf::RectangleShape rect;
    sf::Sprite sprite;

protected:
    int hp;
    std::string name;
    vector <Bullet*> bulletVec;
    bool isHit;
   // bool isDead = true;
    // int damage;
};

#endif //GIOCO0_POKEMON_H
