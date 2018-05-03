
#include "Pokemon.h"


void Pokemon::update() {
    sprite.setPosition(rect.getPosition());

}

void Pokemon::updateDirection(Player &player) {
    if (!player.isSelect()) {
        direction = 2;
        sprite.setTextureRect(sf::IntRect(186, 0, 185, 218));
    }
    else {
        sprite.setTextureRect(sf::IntRect( 367 , 0, 115 , 60));
    }
    if (player.isEnemy()) {
        direction = 1;
        sprite.setTextureRect(sf::IntRect(0, 0, 182, 218));
    }
};

const string &Pokemon::getName() const {
    return name;
}
void Pokemon::setName(const string &name) {
    Pokemon::name = name;
}

int Pokemon::getHp() const {
    return hp;
}

PokemonType Pokemon::getType() const {
    return type;
}



