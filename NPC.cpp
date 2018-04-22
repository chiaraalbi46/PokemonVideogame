//
//
//

#include "NPC.h"

void NPC::update() {
    sprite.setPosition(rect.getPosition());
}

bool NPC::getSpeak() const {
    return speak;
}

void NPC::setSpeak(bool speak) {
    NPC::speak = speak;
}

int NPC::generateRandom(int max) {
    int randomNum = rand();
    int random = (randomNum % max) + 1;
    return random;
}

void NPC::move() {
    if (direction == Character::Direction::Left && moveLeft) {
        rect.move(-speed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));

        if (rect.getPosition().x < 0) {
            moveLeft = false;

        }

    } else if (direction == Character::Direction::Right && moveRight) {
        rect.move(speed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));

        if (rect.getPosition().x > 770) {
            moveRight = false;
        }


    } else if (direction == Character::Direction::Up && moveUp) {
        rect.move(0,-speed);
        sprite.setTextureRect(sf::IntRect( counterWalking*32, 0, 32, 32));
        if (rect.getPosition().y < 0) {
            moveUp = false;
        }


    } else if (direction == Character::Direction::Down && moveDown) {
        rect.move(0, speed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
        if (rect.getPosition().y > 550) {
            moveDown = false;
        }

    }

    if(getSpeak()){
        moveDown = false;
        moveUp = false;
        moveRight = false;
        moveLeft = false;
        speed = 0;
    }


    counterWalking++;
    if (counterWalking == 3) {
        counterWalking = 0;
    }

    counter++;
    if (counter >= movementLength) {
        direction = static_cast<Direction>(generateRandom(10));
        counter = 0;
    }
}