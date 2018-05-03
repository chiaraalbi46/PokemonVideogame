

#ifndef POKEMONVIDEOGAME_FACTORYPOKEMON_H
#define POKEMONVIDEOGAME_FACTORYPOKEMON_H

#include "Pokemon.h"

class PokemonFactory {
public:
    PokemonFactory();
    virtual ~PokemonFactory();

    Pokemon* createPokemon(PokemonType type);
};


#endif //POKEMONVIDEOGAME_FACTORYPOKEMON_H
