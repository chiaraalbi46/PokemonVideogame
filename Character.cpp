

#include "Character.h"

using namespace std;


Character::Direction Character::getDirection() const {
    return direction;
}

void Character::setDirection(Character::Direction direction) {
    Character::direction = direction;
}
