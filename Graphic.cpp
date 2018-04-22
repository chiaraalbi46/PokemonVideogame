//
//
//

#include "Graphic.h"


int Graphic::loadTextures() {

   //Texture player
    if (!texturePlayer.loadFromFile("../Risorse/player.png")) {
        return EXIT_FAILURE;
    }
    if (!texturePlayerBike.loadFromFile("../Risorse/playerbicycle.png")) {
        return EXIT_FAILURE;
    }

    //Bike
    if (!textureBicycle.loadFromFile("../Risorse/bicycle3.png")) {
        return EXIT_FAILURE;
    }

    if (!textureBacca.loadFromFile("../Risorse/Baccaliegia.png")) {
        return EXIT_FAILURE;
    }

    if (!texturePokeball.loadFromFile("../Risorse/pokeball.png")) {
        return EXIT_FAILURE;
    }

    // load NPC texture
    if (!textureNPC1.loadFromFile("../Risorse/npc1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureNPC2.loadFromFile("../Risorse/npc2.png")) {
        return EXIT_FAILURE;
    }

    //TextNPC
    if (!texturetext1.loadFromFile("../Risorse/hello.png")) {
        return EXIT_FAILURE;
    }

}

void Graphic::setFont() {
    font.loadFromFile("../Risorse/arial.ttf");
}

void Graphic::setNPC() {
    NPC1.rect.setSize(sf::Vector2f(32, 48));
    NPC1.rect.setPosition(200, 50);
    NPC1.sprite.setTexture(textureNPC1);

    NPC2.rect.setSize(sf::Vector2f(32, 48));
    NPC2.rect.setPosition(450, 70);
    NPC2.sprite.setTexture(textureNPC2);

}

void Graphic:: setItem(){

    bicycle.setType("bicycle");
    bicycle.rect.setSize(sf::Vector2f(32, 32));
    bicycle.rect.setPosition(10, 50);
    bicycle.sprite.setTexture(textureBicycle);

    bacca.setType("stick");
    bacca.rect.setSize(sf::Vector2f(24, 24));
    bacca.rect.setPosition(30, 150);
    bacca.sprite.setTexture(textureBacca);

    pokeball.setType("pokeball");
    pokeball.rect.setSize(sf::Vector2f(25, 25));
    pokeball.rect.setPosition(20, 250);
    pokeball.sprite.setTexture(texturePokeball);


}






