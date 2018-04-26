
#include "Pokemon.h"

void Pokemon::update() {
    sprite.setPosition(rect.getPosition());
}

Pokemon::~Pokemon() {}


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

int Pokemon::increaseHp() {
    hp = hp + 20 ;
}

const string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const string &name) {
    Pokemon::name = name;
}


int Pokemon::challenge(Pokemon &ComputerPlayer, vector<Bullet> &bulletArray){
    Bullet bullet = *bulletPtr;

    int shot = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shot = 3;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        shot = 4;

    }


    switch (shot) {


        case (3) :

            bullet.rect.setPosition(rect.getPosition().x + rect.getSize().x / 2 - bullet.rect.getSize().x / 2,
                                    rect.getPosition().y + rect.getSize().y / 2 - bullet.rect.getSize().y / 2);

            bullet.setDirection(3);
            bulletArray.push_back(bullet);
            break;


        case (4) :

            bullet.rect.setPosition(rect.getPosition().x + rect.getSize().x / 2 - bullet.rect.getSize().x / 2,
                                    rect.getPosition().y + rect.getSize().y / 2 - bullet.rect.getSize().y / 2);


            bullet.setDirection(4);
            bulletArray.push_back(bullet);

            break;

        default:

            break;

    }


    if(isHit){
        ComputerPlayer.subtractHp();
    }

}

