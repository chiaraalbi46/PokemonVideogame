

#include "GraphicPokemon.h"



int GraphicPokemon ::loadTexturePokemon(Player &player) {
    //load pokemon texture
    if (!textureInfernape.loadFromFile("../Risorse/infernape.png")) {
        return EXIT_FAILURE;
    }

    if (!textureFloatzel.loadFromFile("../Risorse/floatzel.png")) {
        return EXIT_FAILURE;
    }

    if (!textureLuxray.loadFromFile("../Risorse/luxray.png")) {
        return EXIT_FAILURE;
    }

    if (!textureBreloom.loadFromFile("../Risorse/breloom.png")) {
        return EXIT_FAILURE;
    }

    if (!textureRapidash.loadFromFile("../Risorse/rapidash.png")) {
        return EXIT_FAILURE;
    }

    if (!textureBlastoise.loadFromFile("../Risorse/blastoise.png")) {
        return EXIT_FAILURE;
    }

    if (!textureZapdos.loadFromFile("../Risorse/zapdos.png")) {
        return EXIT_FAILURE;
    }

    if (!textureBulbasaur.loadFromFile("../Risorse/bulbasaur.png")) {
        return EXIT_FAILURE;
    }

}

void GraphicPokemon :: setPokemon(){

    infernape->setName("Infernape");
    infernape->sprite.setTexture(textureInfernape);

    floatzel->setName("Floatzel");
    floatzel->sprite.setTexture(textureFloatzel);

    luxray->setName("Luxray");
    luxray->sprite.setTexture(textureLuxray);

    breloom->setName("Breloom");
    breloom->sprite.setTexture(textureBreloom);

    bulbasaur->setName("Bulbasaur");
    bulbasaur->sprite.setTexture(textureBulbasaur);

    rapidash->setName("Rapidash");
    rapidash->sprite.setTexture(textureRapidash);

    blastoise->setName("Blastoise");
    blastoise->sprite.setTexture(textureBlastoise);

    zapdos->setName("Zapdos");
    zapdos->sprite.setTexture(textureZapdos);

    bulbasaur->setName("Bulbasaur");
    bulbasaur->sprite.setTexture(textureBulbasaur);
}

void GraphicPokemon::setPokemonOpponent(sf::RenderWindow &window, vector <Pokemon*> &PokemonEnemyArray, Player &player,
                                        int &choosen4) {
    player.setEnemy(true);
    PokemonEnemyArray[choosen4]->rect.setPosition(600, 180);
    PokemonEnemyArray[choosen4]->update();
    PokemonEnemyArray[choosen4]->updateDirection(player);
    window.draw(PokemonEnemyArray[choosen4]->sprite);
}

int GraphicPokemon ::setCheck(GraphicPokemon &graphicPokemon) {

    //   sf::Texture pokemonTexture;
    if (!pokemonTexture.loadFromFile("../Risorse/sfondoscelta.png")) {
        return EXIT_FAILURE;
    }
    graphicPokemon.spritePokemon.setTexture(pokemonTexture);

    if (!texturecheck.loadFromFile("../Risorse/check.png")) {
        return EXIT_FAILURE;
    }
    spriteCheck.setTexture(texturecheck);
    sprite.setPosition(70, 180);

}