//
// Created by Niki on 03/05/2018.
//

#ifndef POKEMONVIDEOGAME_GRASSBULLET_H
#define POKEMONVIDEOGAME_GRASSBULLET_H

#include "Bullet.h"
class GrassBullet : public  Bullet  {
public:
    GrassBullet(){
        rect.setFillColor(sf::Color:: Green);
        rect.setSize(sf::Vector2f(48, 48));
        loadTexture();
        adder = 1;
    }
};

#endif //POKEMONVIDEOGAME_GRASSBULLET_H
