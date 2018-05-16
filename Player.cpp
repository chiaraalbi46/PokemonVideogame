
#include "Player.h"

void Player::update() {
    sprite.setPosition(rect.getPosition());
}

void Player :: move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& moveUp) {

        rect.move(0, -speed);
        direction = Character::Direction::Up;
        moveUp = true;
        moveLeft = true;
        moveRight = true;
        moveDown = true;
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3 + character * 32, 32, 32));
        //Use bicycle
        if (isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            textBicycle = false;
            rideBicycle = true;
            speed = 3;
            vel = 2;
        }
        else {
            speed=1;
            rideBicycle=false;
        }

        if (rect.getPosition().y < 0) {
            moveUp = false;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& moveDown) {
        rect.move(0, speed);
        direction = Character::Direction::Down;
        moveLeft = true;
        moveRight = true;
        moveUp = true;
        moveDown = true;
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, character * 32, 32, 32));

        //Use bicycle
        if ( isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            textBicycle = false;
            rideBicycle=true;
            speed = 3;
            vel = 2;
        }
        else {
            speed=1;
            rideBicycle=false;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveLeft) {
        rect.move(-speed,0);
        direction = Character::Direction::Left;
        moveRight = true;
        moveDown = true;
        moveUp = true;
        moveLeft = true;
        sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 + character * 32, 32, 32));
        if ( isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            textBicycle = false;
            rideBicycle=true;
            speed = 3;
            vel = 2;
        }
        else{
            speed=1;
            rideBicycle=false;
        }

        if (rect.getPosition().x < 0) {
            moveLeft = false;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveRight) {
        rect.move(speed, 0);
        direction = Character::Direction::Right;
        moveLeft = true;
        moveDown = true;
        moveUp = true;
        moveRight = true;
        sprite.setTextureRect(sf::IntRect( counterWalking * 32,32 * 2 + character * 32, 32, 32));
        //Use bicycle
        if ( isBicyclePickUp() && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            textBicycle = false;
            rideBicycle=true;
            speed = 3;
            vel = 2;
        }
        else {
            speed=1;
            rideBicycle=false;
        }
    }

    if(isEnterGym()) {
        moveLeft = false;
        moveDown = false;
        moveUp = false;
        moveRight = false;
    }
    counterWalking++;
    if(counterWalking==3){
        counterWalking=0;
    }
};

int Player::increaseScore(int medalValue) {
    score += medalValue;
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

bool Player::isCollGym() const {
    return collGym;
}
void Player::setCollGym(bool collGym) {
    Player::collGym = collGym;
}

bool Player ::isSelect() const {
    return select;
}
void Player ::setSelect(bool select) {
    Player ::select = select;
}

bool Player::isEnterGym() const {
    return enterGym;
}
void Player::setEnterGym(bool enterGym) {
    Player::enterGym = enterGym;
}

bool Player::isSelectAttack() const {
    return selectAttack;
}
void Player::setSelectAttack(bool selectAttack) {
    Player::selectAttack = selectAttack;
}

bool Player::isEnemy() const {
    return enemy;
}
void Player::setEnemy(bool enemy) {
    Player::enemy = enemy;
}

bool Player::isEnemyTurn() const {
    return enemyTurn;
}
void Player::setEnemyTurn(bool enemyTurn) {
    Player::enemyTurn = enemyTurn;
}

bool Player::isAttack() const {
    return attack;
}
void Player::setAttack(bool attack) {
    Player::attack = attack;
}

bool Player::isCambio() const {
    return cambio;
}
void Player::setCambio(bool cambio) {
    Player::cambio = cambio;
}

bool Player::isGameRestart() const {
    return gameRestart;
}
void Player::setGameRestart(bool gameRestart) {
    Player::gameRestart = gameRestart;
}

bool Player::isFight() const {
    return fight;
}
void Player::setFight(bool fight) {
    Player::fight = fight;
}

bool Player::isPrebattle() const {
    return prebattle;
}
void Player::setPrebattle(bool prebattle) {
    Player::prebattle = prebattle;
}