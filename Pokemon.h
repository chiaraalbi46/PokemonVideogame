
#ifndef POKEMONVIDEOGAME_POKEMON_H
#define POKEMONVIDEOGAME_POKEMON_H

#include "Bullet.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "FireBullet.h"

using namespace std;

class Pokemon {
public:
    Pokemon() {
        rect.setSize(sf::Vector2f(200, 218));
        sprite.setTextureRect(sf::IntRect(186, 0, 185, 218));
        rect.setPosition(70, 180);
        hp = 400;
    }

    virtual ~Pokemon();

    void update();
    void updateDirection(Player &player);

    int getHp() const{
        return hp;
    }

    int increaseHp();

    int subtractHp();

    const string &getName() const;
    void setName(const string &name);

    Bullet *bulletPtr;
    int direction = 0;

    sf::RectangleShape rect;
    sf::Sprite sprite;

protected:
    std::string name;
    int hp = 30;
    bool isHit;

};

#endif //GIOCO0_POKEMON_H
