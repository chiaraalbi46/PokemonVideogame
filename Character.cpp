

#include "Character.h"

using namespace std;


Character::Direction Character::getDirection() const {
    return direction;
}

void Character::setDirection(Character::Direction direction) {
    Character::direction = direction;
}

const std:: string &Character:: getName() const {
    return name;
}

void Character::setName(const std:: string &name) {
    Character::name = name;
}

