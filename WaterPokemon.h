
#ifndef POKEMONVIDEOGAME_WATERPOKEMON_H
#define POKEMONVIDEOGAME_WATERPOKEMON_H

#include "Pokemon.h"
#include "WaterBullet.h"

class WaterPokemon : public Pokemon {
public:
    WaterPokemon(){
        bulletPtr = new WaterBullet;
        isAlive = true;
        type = PokemonType ::PokemonWater;
    }

    virtual ~WaterPokemon() {}

};


#endif //POKEMONVIDEOGAME_WATERPOKEMON_H
