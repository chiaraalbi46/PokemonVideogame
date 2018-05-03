
#include "Bullet.h"

Bullet :: Bullet(){
    rect.setSize(sf::Vector2f(48, 48));
    rect.setPosition(30, 20); //di default
    rect.setFillColor(sf::Color::Blue);
    loadTexture();
    adder = 0;
}

void Bullet::update() {

    if(direction == 1) {//Left
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(adder*32 + counterAnimation*32, 32*2, 32, 32));
    }

    if(direction == 2) {//Right
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(adder*32 + counterAnimation*32, 32*3 , 32, 32));
    }

    counterLifeTime++;
    if(counterLifeTime >= lifeTime)
        isDestroyed = true;

    counterAnimation++;
    if(counterAnimation >= 2)
        counterAnimation = 0;

    sprite.setPosition(rect.getPosition());

}

int Bullet::loadTexture() {
    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("../Risorse/attack.png"))
        return EXIT_FAILURE;
    attackTexture = bulletTexture;
}