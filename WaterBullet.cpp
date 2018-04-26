

#include "WaterBullet.h"

WaterBullet::WaterBullet() {
    rect.setFillColor(sf::Color::Cyan);
    loadTexture();
    sprite.setTexture(attackTexture);
    adder = 3;

}

