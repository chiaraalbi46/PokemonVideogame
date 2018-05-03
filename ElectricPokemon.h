

#ifndef POKEMONVIDEOGAME_ELECTRICPOKEMON_H
#define POKEMONVIDEOGAME_ELECTRICPOKEMON_H

#include "Pokemon.h"
#include "ElectricBullet.h"

class ElectricPokemon : public Pokemon{
public:
    ElectricPokemon() {
        bulletPtr = new ElectricBullet;
        isAlive = true;
        type = PokemonType ::PokemonElectric;
    }

    virtual ~ElectricPokemon() {}
};


#endif //POKEMONVIDEOGAME_ELECTRICPOKEMON_H
