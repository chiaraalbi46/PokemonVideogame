

#ifndef POKEMONVIDEOGAME_GRASSPOKEMON_H
#define POKEMONVIDEOGAME_GRASSPOKEMON_H

#include "Pokemon.h"
#include "GrassBullet.h"


class GrassPokemon : public Pokemon {
public:
    GrassPokemon(){
        bulletPtr = new GrassBullet;
        isAlive = true;
        type = PokemonType ::PokemonGrass;
    }

    virtual ~GrassPokemon() {}
};


#endif //POKEMONVIDEOGAME_GRASSPOKEMON_H
