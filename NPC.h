//
//
//

#ifndef POKEMONVIDEOGAME_NPC_H
#define POKEMONVIDEOGAME_NPC_H


#include "Character.h"


class NPC : public Character {
public:
     NPC( ): Character (){}

    ~NPC() {}

    void update();

    void move() override;

    int generateRandom(int max);


protected:
    int speed = 1;
    int movementLength = 100;
};


#endif //POKEMONVIDEOGAME_NPC_H
