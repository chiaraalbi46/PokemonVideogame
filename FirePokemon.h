

#ifndef POKEMONVIDEOGAME_FIREPOKEMON_H
#define POKEMONVIDEOGAME_FIREPOKEMON_H

#include "Pokemon.h"

class FirePokemon : public Pokemon{
public:
    FirePokemon() {
        bulletPtr = new FireBullet;
        isAlive = true;
    }

    virtual ~FirePokemon() {}
};

#endif //POKEMONVIDEOGAME_FIREPOKEMON_H
