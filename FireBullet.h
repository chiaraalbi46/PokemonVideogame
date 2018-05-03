
#ifndef POKEMONVIDEOGAME_FIREBULLET_H
#define POKEMONVIDEOGAME_FIREBULLET_H

#include "Bullet.h"

class ElectricBullet : public Bullet {
public:
    ElectricBullet(){
        rect.setFillColor(sf::Color::Yellow);
        rect.setSize(sf::Vector2f(48, 48));
        loadTexture();
        adder = 0;
    }
};

#endif //POKEMONVIDEOGAME_FIREBULLET_H
