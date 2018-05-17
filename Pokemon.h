
#ifndef POKEMONVIDEOGAME_POKEMON_H
#define POKEMONVIDEOGAME_POKEMON_H

#include <iostream>
#include "Text.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include "FireBullet.h"


enum class PokemonType {PokemonWater, PokemonFire, PokemonElectric, PokemonGrass};
using namespace std;

class Pokemon {
public:

    Pokemon() {
        rect.setSize(sf::Vector2f(200, 218));
        sprite.setTextureRect(sf::IntRect(186, 0, 185, 218));
        rect.setPosition(70, 180);
        bulletPtr = new FireBullet();
        isAlive = true;
        hp = 400;
        type = PokemonType ::PokemonFire;
    }

    virtual ~Pokemon(){}
    void update();

    PokemonType getType() const;

    const string &getName() const;
    void setName(const string &name);

    void updateDirection(Player &player);
    bool isAlive;
    int hp;

    int getHp() const;

    int direction;

    Bullet *bulletPtr;
    sf::RectangleShape rect;
    sf::Sprite sprite;
    PokemonType type;

protected:
    string name;
};

#endif //GIOCO0_POKEMON_H
