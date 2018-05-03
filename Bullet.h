
#ifndef POKEMONVIDEOGAME_BULLET_H
#define POKEMONVIDEOGAME_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();

    void update();

    void setDirection(int direction) {
        Bullet::direction = direction;
    }

    void setMovementSpeed(float movementSpeed){
        Bullet::movementSpeed = movementSpeed;
    }
    int direction = 0;
    bool isDestroyed = false;

    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Texture attackTexture;

    virtual int loadTexture();

    int attackDamage = 3;

private:
    float movementSpeed = 40.0f;

    int counterLifeTime = 0;
    int lifeTime = 50; //"lunghezza" del tratto del proiettile
    int counterAnimation = 0;

protected:
    int adder;

};


#endif //POKEMONVIDEOGAME_BULLET_H
