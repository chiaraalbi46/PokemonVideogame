//
//
//

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

        if(rideBicycle){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                sprite.setTexture(textureExchange);
                sprite.setTextureRect(sf::IntRect(30 * 2, counterWalking* 30 , 30, 30));
                speed = 3;
            }

            else{
                sprite.setTexture(myTexture);
                sprite.setTextureRect(sf::IntRect(28 * 2, counter* 30 , 28, 30));
                speed = 1;
            }

        }
        else{
            sprite.setTexture(myTexture);
            sprite.setTextureRect(sf::IntRect(28 * 2, counter* 30 , 28, 30));
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

        if(rideBicycle){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                sprite.setTexture(textureExchange);
                sprite.setTextureRect(sf::IntRect(0, counterWalking* 30 , 30, 30));
                speed = 3;
            }

            else{
                sprite.setTexture(myTexture);
                sprite.setTextureRect(sf::IntRect(0 , counter* 30 , 28, 30));
                speed = 1;
            }

        }
        else{ //movimento giocatore senza bici
            sprite.setTexture(myTexture);
            sprite.setTextureRect(sf::IntRect(0 , counter* 30 , 28, 30));
            speed = 1;
        }

        if (rect.getPosition().y > 550) {
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

        if(rideBicycle){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                sprite.setTexture(textureExchange);
                sprite.setTextureRect(sf::IntRect(30 , counterWalking* 30 , 30, 30));
                speed = 3;
            }
            else {
                sprite.setTexture(myTexture);
                sprite.setTextureRect(sf::IntRect(28 , counter* 30 , 28, 30));
                speed = 1;
            }
        }
        else{
            sprite.setTexture(myTexture);
            sprite.setTextureRect(sf::IntRect(28 , counter* 30 , 28, 30));
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

        if(rideBicycle){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                sprite.setTexture(textureExchange);
                sprite.setTextureRect(sf::IntRect(30 * 3, counterWalking * 30, 30, 30));
                speed = 3;
            }
            else{
                sprite.setTexture(myTexture);
                sprite.setTextureRect(sf::IntRect(28 * 3, counter* 30 , 28, 30));
                speed = 1;
            }
        }
        else{
            sprite.setTexture(myTexture);
            sprite.setTextureRect(sf::IntRect(28 * 3, counter* 30 , 28, 30));
            speed = 1;
        }


        if (rect.getPosition().x > 770) {
            moveRight = false;
        }
    }


    counter++; //per il giocatore senza bici
    if( counter == 6){
        counter = 0;
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

void Player::setRideBicycle(bool rideBicycle) {
    Player::rideBicycle = rideBicycle;
}


