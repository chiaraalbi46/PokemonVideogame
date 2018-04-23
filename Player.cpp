

#include "Player.h"


void Player::update() {
    sprite.setPosition(rect.getPosition());
}


void Player :: move() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& moveUp) {
        rect.move(0, -speed);
        direction = Character::Direction::Up;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;

        //Use bicycle
        if(isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            rideBicycle = true;
            sprite.setTextureRect(sf::IntRect(30 * 2, counterWalking * 30, 30, 30));
            speed = 3;

        }
        else{
            rideBicycle = false;
            sprite.setTextureRect(sf::IntRect(28 * 2, counterWalking1* 30 , 28, 30));
            speed = 1;
        }


        if (rect.getPosition().y < 0) {
            moveUp = false;
        }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& moveDown) {
        rect.move(0, speed);
        direction = Character::Direction::Down;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;

        if(isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            rideBicycle = true;
            sprite.setTextureRect(sf::IntRect(0, counterWalking * 30, 30, 30));
            speed = 3;

        }
        else{
            rideBicycle = false;
            sprite.setTextureRect(sf::IntRect(0 , counterWalking1* 30 , 30, 30));
            speed = 1;
        }

        if (rect.getPosition().y > 475) {
            moveDown = false;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveLeft) {
        rect.move(-speed,0);
        direction = Character::Direction::Left;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;

        if(isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            rideBicycle = true;
            sprite.setTextureRect(sf::IntRect(28, counterWalking * 30, 28, 30));
            speed = 3;

        }
        else{
            rideBicycle = false;
            sprite.setTextureRect(sf::IntRect(28 , counterWalking1* 30 , 30, 30));
            speed = 1;
        }


        if (rect.getPosition().x < 0) {
            moveLeft = false;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveRight) {
        rect.move(speed, 0);
        direction = Character::Direction::Right;
        moveUp = true;
        moveDown = true;
        moveLeft = true;
        moveRight = true;

        if(isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            rideBicycle = true;
            sprite.setTextureRect(sf::IntRect(30 * 3, counterWalking * 30, 30, 30));
            speed = 3;
        }
        else{
            rideBicycle = false;
            sprite.setTextureRect(sf::IntRect(28 * 3, counterWalking1* 30 , 28, 30));
            speed = 1;
        }


        if (rect.getPosition().x > 770) {
            moveRight = false;
        }
    }


    counterWalking1++; //per il giocatore senza bici
    if( counterWalking1 == 6){
        counterWalking1 = 0;
    }
    counterWalking++; //per il giocatore con la bici
    if(counterWalking == 3){
        counterWalking = 0;
    }

};


int Player::increaseScore(int value) {
    score += value;
}
int Player::getScore() const {
    return score;
}


bool Player::isBicyclePickUp() const {
    return bicyclePickUp;
}

void Player::setBicyclePickUp(bool bicyclePickUp) {
    Player::bicyclePickUp = bicyclePickUp;
}

bool Player::isStartBattle() const {
    return startBattle;
}

void Player::setStartBattle(bool startBattle) {
    Player::startBattle = startBattle;
}

