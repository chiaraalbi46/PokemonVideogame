
#include "Bullet.h"

void Bullet::update(int &typeAttack, int &adder1) {

    if(typeAttack == 1) {
        adder1 = 60;
        setName("Energy sphere");
        lifeTime = 50;
        attackDamage = 10;
        counter = 3;
        rect.setSize(sf::Vector2f(48, 48));
        if(direction == 1) {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 48, adder * 48, 48, 48));
        }
        else if (direction == 2) {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 48, adder * 48  , 48, 48));
        }
        sprite.setTexture(attack1Texture);
    }
    else if (typeAttack == 2) {
        adder1 = 0;
        setName("Laceration");
        lifeTime = 50;
        attackDamage = 13;
        counter = 6;
        rect.setSize(sf::Vector2f(192, 192));
        if (direction == 1) {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 192, adder * 192 + 4 * 192, 192, 192));
        }
        else if (direction == 2){
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 192, adder * 192 , 192, 192));
        }
        sprite.setTexture(attack2Texture);
    }
    else if (typeAttack == 3) {
        adder1 = 60;
        setName("Vortex ball");
        lifeTime = 50;
        attackDamage = 12;
        counter = 5;
        rect.setSize(sf::Vector2f(60, 67));
        if (direction == 1) {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 60, adder * 67 + 4 * 67, 60, 67));
        } else if (direction == 2) {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterAnimation * 60, adder * 67, 60, 67));
        }
        sprite.setTexture(attack3Texture);
    }

    counterLifeTime++;
    if(counterLifeTime >= lifeTime) {
        isDestroyed = true;
    }

    counterAnimation++;
    if(counterAnimation >= counter) {
        counterAnimation = 0;
    }

    sprite.setPosition(rect.getPosition());
}

int Bullet ::loadTexture() {
    sf::Texture bullet1Texture;
    sf::Texture bullet2Texture;
    sf::Texture bullet3Texture;

    if (!bullet1Texture.loadFromFile("attack1.png"))
        return EXIT_FAILURE;

    if (!bullet2Texture.loadFromFile("attack2.png"))
        return EXIT_FAILURE;

    if (!bullet3Texture.loadFromFile("attack3.png"))
        return EXIT_FAILURE;

    attack1Texture = bullet1Texture;
    attack2Texture = bullet2Texture;
    attack3Texture = bullet3Texture;

}

int Bullet ::loadEffectTexture() {
    sf::Texture bulletEffect1Texture;

    if (!bulletEffect1Texture.loadFromFile("effect1.png"))
        return EXIT_FAILURE;
    effect1Texture = bulletEffect1Texture;
}

void Bullet ::updateEffects() {
    effect1.setTextureRect(sf::IntRect(counterAnimation1 * 250, adder * 250  , 250, 250));
    effect1.setTexture(effect1Texture);

    counterAnimation1++;
    if(counterAnimation1 >= 5) {
        counterAnimation1 = 0;
    }

    effect1.setPosition(rect.getPosition());
}

const string &Bullet::getName() const {
    return name;
}
void Bullet::setName(const string &name) {
    Bullet::name = name;
}

BulletType Bullet::getType() const {
    return type;
}