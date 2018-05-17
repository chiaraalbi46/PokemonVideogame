

#ifndef POKEMONVIDEOGAME_NPC_H
#define POKEMONVIDEOGAME_NPC_H


#include "Character.h"


class NPC : public Character {
public:
     NPC( ): Character (){
         sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32, 32, 32));
     }

    ~NPC() {}

    void update();

    void move();

    int generateRandom(int max);

protected:
    int speed = 1;
    int movementLength = 100;
};


#endif //POKEMONVIDEOGAME_NPC_H
