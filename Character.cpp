//
//
//

#include "Pokemon.h"
#include "Character.h"

using namespace std;

bool Character::isMoveRight() const {
    return moveRight;
}

void Character::setMoveRight(bool moveRight) {
    Character::moveRight = moveRight;
}

bool Character::isMoveDown() const {
    return moveDown;
}

void Character::setMoveDown(bool moveDown) {
    Character::moveDown = moveDown;
}

bool Character::isMoveLeft() const {
    return moveLeft;
}

void Character::setMoveLeft(bool moveLeft) {
    Character::moveLeft = moveLeft;
}

bool Character::isMoveUp() const {
    return moveUp;
}

void Character::setMoveUp(bool moveUp) {
    Character::moveUp = moveUp;
}

void Character::setSpeed(float speed) {
    Character::speed = speed;
}

float Character::getSpeed() const {
    return speed;
}

Character::Direction Character::getDirection() const {
    return direction;
}

void Character::setDirection(Character::Direction direction) {
    Character::direction = direction;
}

const std:: string &Character:: getName() const { //come utilizzarli ??
    return name;
}

void Character::setName(const std:: string &name) {
    Character::name = name;
}

