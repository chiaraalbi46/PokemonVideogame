
#ifndef POKEMONVIDEOGAME_FIREBULLET_H
#define POKEMONVIDEOGAME_FIREBULLET_H

#include "Bullet.h"

class FireBullet : public  Bullet  {
public:
    FireBullet(){
        rect.setFillColor(sf::Color::Red);
        rect.setSize(sf::Vector2f(48, 48));
        loadTexture();
        loadEffectTexture();
        adder = 3;
        type = BulletType :: BulletFire;
    }
};

#endif //POKEMONVIDEOGAME_FIREBULLET_H
