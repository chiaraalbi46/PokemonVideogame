

#include "PokemonFactory.h"
#include "WaterPokemon.h"
#include "FirePokemon.h"
#include "ElectricPokemon.h"


PokemonFactory:: ~PokemonFactory(){}

PokemonFactory:: PokemonFactory(){}

Pokemon *PokemonFactory::createPokemon(PokemonType type) {
    if (type == PokemonType ::PokemonWater) {
        return new WaterPokemon();
    }
    else if (type == PokemonType ::PokemonFire) {
        return new FirePokemon ();
    }
    else if(type == PokemonType :: PokemonElectric){
        return new ElectricPokemon();
    }

}