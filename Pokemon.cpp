//
//
//
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



