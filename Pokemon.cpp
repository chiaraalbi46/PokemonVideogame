
#include "Pokemon.h"

void Pokemon::update() {
    sprite.setPosition(rect.getPosition());
}

Pokemon::~Pokemon() {}

int Pokemon::attack(Pokemon &ComputerPlayer) {
    specialAttack->useAttack();
    if(isHit){
        ComputerPlayer.subtractHp();
    }
}

void Pokemon::updateDirection() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = 3;
        sprite.setTextureRect(sf::IntRect(28, 0, 28, 30));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 4;
        sprite.setTextureRect(sf::IntRect(28 * 3, 0, 28, 30));
    }

}

int Pokemon::subtractHp() {
    hp -= 20;
    return hp;
}

bool Pokemon::isDead() {
    if(hp == 0)
        return true;
}

int Pokemon::increaseHp() {
    hp = hp + 20 ;
}

const string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const string &name) {
    Pokemon::name = name;
}



