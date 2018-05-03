

#ifndef POKEMONVIDEOGAME_WATERBULLET_H
#define POKEMONVIDEOGAME_WATERBULLET_H


#include "Bullet.h"

class WaterBullet: public Bullet{
public:
    WaterBullet(){
        rect.setSize(sf::Vector2f(48, 48));
        rect.setFillColor(sf::Color::Cyan);
        loadTexture();
        adder = 2;
    }
};



#endif //POKEMONVIDEOGAME_WATERBULLET_H
