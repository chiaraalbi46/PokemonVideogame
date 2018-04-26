
#include "FireBullet.h"

FireBullet::FireBullet() {
    rect.setFillColor(sf::Color::Red);
    loadTexture();
    sprite.setTexture(attackTexture);
    adder = 0;

}
