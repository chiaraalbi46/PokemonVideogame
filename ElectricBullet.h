

#ifndef POKEMONVIDEOGAME_ELECTRICBULLET_H
#define POKEMONVIDEOGAME_ELECTRICBULLET_H

#include "Bullet.h"

class ElectricBullet : public Bullet {
public:
    ElectricBullet(){
        rect.setFillColor(sf::Color::Yellow);
        rect.setSize(sf::Vector2f(48, 48));
        loadTexture();
        loadEffectTexture();
        adder = 0;
        type = BulletType ::BulletElectric;
    }
};


#endif //POKEMONVIDEOGAME_ELECTRICBULLET_H
