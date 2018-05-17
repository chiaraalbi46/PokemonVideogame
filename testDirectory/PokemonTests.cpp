

#include <gtest/gtest.h>
#include "../Pokemon.h"
#include "../PokemonFactory.h"


TEST(PokemonTest, Constructor){

    PokemonFactory factory;
    Pokemon* luxray = factory.createPokemon(PokemonType :: PokemonElectric);
    luxray->setName("luxray");

    ASSERT_EQ(PokemonType::PokemonElectric, luxray->getType());
    ASSERT_EQ("luxray", luxray->getName());

}