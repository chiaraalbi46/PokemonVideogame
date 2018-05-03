

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
    if (!textureBicycle.loadFromFile("../Risorse/bicycle.png")) {
        return EXIT_FAILURE;
    }

    //Texture Berry
    if (!textureBerry1.loadFromFile("../Risorse/Baccaliegia.png")) {
        return EXIT_FAILURE;
    }
    if (!textureBerry2.loadFromFile("../Risorse/Baccapesca.png")) {
        return EXIT_FAILURE;
    }

    //Texture Pokeball
    if (!texturePokeball1.loadFromFile("../Risorse/pokeball1.png")) {
        return EXIT_FAILURE;
    }
    if (!texturePokeball2.loadFromFile("../Risorse/pokeball2.png")) {
        return EXIT_FAILURE;
    }

    // load NPC texture
    if (!textureNPC1.loadFromFile("../Risorse/npc1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureNPC2.loadFromFile("../Risorse/npc2.png")) {
        return EXIT_FAILURE;
    }

    //load gym texture
    if (!textureGym.loadFromFile("../Risorse/gym.png")) {
        return EXIT_FAILURE;
    }

}

void Graphic::setFont() {
    font.loadFromFile("../Risorse/pokemonnormal.ttf");
}

void Graphic::setNPC() {
    NPC1.rect.setSize(sf::Vector2f(32, 32));
    NPC1.rect.setPosition(200, 50);
    NPC1.sprite.setTexture(textureNPC1);

    NPC2.rect.setSize(sf::Vector2f(32, 32));
    NPC2.rect.setPosition(450, 70);
    NPC2.sprite.setTexture(textureNPC2);

}

void Graphic:: setItem(){

    bicycle.setType("bicycle");
    bicycle.rect.setSize(sf::Vector2f(32, 32));
    bicycle.rect.setPosition(10, 50);
    bicycle.sprite.setTexture(textureBicycle);

    berry1.setType("cherry berry");
    berry1.rect.setSize(sf::Vector2f(24, 24));
    berry1.rect.setPosition(30, 150);
    berry1.sprite.setTexture(textureBerry1);

    berry2.setType("peach berry");
    berry2.rect.setSize(sf::Vector2f(24, 24));
    berry2.rect.setPosition(150, 50);
    berry2.sprite.setTexture(textureBerry2);

    pokeball1.setType("Megaball");
    pokeball1.rect.setSize(sf::Vector2f(48, 48));
    pokeball1.rect.setPosition(20, 250);
    pokeball1.sprite.setTexture(texturePokeball1);

    pokeball2.setType("Masterball");
    pokeball2.rect.setSize(sf::Vector2f(48, 48));
    pokeball2.rect.setPosition(250, 150);
    pokeball2.sprite.setTexture(texturePokeball2);

    gym.setType("Gym");
    gym.rect.setSize(sf::Vector2f(206, 128));
    gym.sprite.setPosition(370, 0);
    gym.sprite.setTexture(textureGym);
}

void Graphic::setText(Player &player) {

    ostringstream pokeballText;
    pokeballText << "Score:  "<< player.getScore();
    player.text.setString(pokeballText.str());
    player.text.setFont(font);
    player.text.setFillColor(sf:: Color:: Black  );
    player.text.setCharacterSize(30);
    player.text.setPosition(5, 5);

}


int Graphic ::setBattleText(sf::RenderWindow &window, Player &player) {

    if(player.isCollGym()) {
        textBattle.setString("Do you want to fight? \n  YES \n \n  NO  ");
        textBattle.setFont(font);
        textBattle.setFillColor(sf::Color::Black);
        textBattle.setPosition(370, 130);
        textBattle.setCharacterSize(20);
        window.draw(textBattle);
        window.display();
    }

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Mouse::getPosition(window).x > 380 && sf::Mouse::getPosition(window).x < 460 &&
                sf::Mouse::getPosition(window).y > 150 && sf::Mouse::getPosition(window).y < 190 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                player.setEnterGym(true);
                player.setCollGym(false);
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 380 && sf::Mouse::getPosition(window).x < 460 &&
                     sf::Mouse::getPosition(window).y > 210 && sf::Mouse::getPosition(window).y < 260 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                player.setEnterGym(false);
                player.setCollGym(false);

                return 0;
            }
        }
    }
};

int Graphic :: setBackgroundBattle(sf::RenderWindow &window, Player &player) {
    // Load Background
    if (!textureBattle.loadFromFile("../Risorse/backgroundbattle.png")) {
        return EXIT_FAILURE;
    }
    spriteBattle.setTexture(textureBattle);
    spriteBattle.setPosition(0, 0);
}






