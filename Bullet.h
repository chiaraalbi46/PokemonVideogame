
#ifndef POKEMONVIDEOGAME_BULLET_H
#define POKEMONVIDEOGAME_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
    Bullet();

    void update();

    void setDirection(int direction) {
        Bullet::direction = direction;
    }

    int direction = 0;
    bool isDestroyed = false;

    sf::RectangleShape rect;
    sf::Sprite sprite;


private:
    float movementSpeed = 10.0f;
    int attackDamage = 3;
    int counterLifeTime = 0;
    int lifeTime = 50; //"lunghezza" del tratto del proiettile
    int counterAnimation = 0;

};


#endif //POKEMONVIDEOGAME_BULLET_H
