

#include "Graphic.h"

using namespace std;

int Graphic::loadTextures(GraphicPokemon &strategy) {

    //Texture player
    if (!texturePlayer.loadFromFile("../Risorse/player.png")) {
        return EXIT_FAILURE;
    }
    if (!texturePlayerBike.loadFromFile("../Risorse/playerbicycle.png")) {
        return EXIT_FAILURE;
    }

    //Texture Bike
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

    if (!textureNPC3.loadFromFile("../Risorse/npc3.png")) {
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
int Graphic::setMusicPlayer() {

    if (!musicplayer.openFromFile("../Risorse/musicplayer.ogg")) {
        return EXIT_FAILURE;
    }

    /*  sound.setBuffer(buffer);
      if (!buffer.loadFromFile("../res/Jump.ogg")) {
          return EXIT_FAILURE;
      }
      sound.setVolume(10);*/
}

int Graphic::setMusicBattle(Player &player) {

    if (!musicplayer.openFromFile("../Risorse/musicplayer.ogg")) {
        return EXIT_FAILURE;
    }


    if (!musicbattle.openFromFile("../Risorse/soundBattle.ogg")) {
        return EXIT_FAILURE;
    }


/*
    if (!bufferShot.loadFromFile("../Risorse/soundattack.ogg")) {
        return EXIT_FAILURE;
    }
    soundShot.setBuffer(bufferShot);
    soundShot.setVolume(10);*/

}

void Graphic::setNPC() {

    NPC1.rect.setSize(sf::Vector2f(32, 32));
    NPC1.rect.setPosition(400, 280);
    NPC1.sprite.setTexture(textureNPC1);

    NPC2.rect.setSize(sf::Vector2f(32, 32));
    NPC2.rect.setPosition(250, 320);
    NPC2.sprite.setTexture(textureNPC2);

    NPC3.rect.setSize(sf::Vector2f(32, 32));
    NPC3.rect.setPosition(150, 100);
    NPC3.sprite.setTexture(textureNPC3);

}

void Graphic:: setItem(){

    bicycle.setType("bicycle");
    bicycle.rect.setSize(sf::Vector2f(32, 32));
    bicycle.rect.setPosition(30, 70);
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
    // pokeball1.sprite.setTextureRect(sf::IntRect( 48 * counter, 0, 48, 48));

    pokeball2.setType("Masterball");
    pokeball2.rect.setSize(sf::Vector2f(48, 48));
    pokeball2.rect.setPosition(250, 150);
    pokeball2.sprite.setTexture(texturePokeball2);
    // pokeball1.sprite.setTextureRect(sf::IntRect( 48 * counter, 0, 48, 48));

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
    player.text.setFillColor(sf:: Color::Cyan  );
    player.text.setCharacterSize(30);
    player.text.setPosition(5, 5);

    textBicycle.setString("Press Z to use the bicycle");
    textBicycle.setFont(font);
    textBicycle.setFillColor(sf:: Color:: Cyan  );
    textBicycle.setCharacterSize(30);
    textBicycle.setPosition(10, 42);
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

int Graphic :: setBackgroundBattle(sf::RenderWindow &window, Player &player){
    // Load Background
    if (!textureBattle.loadFromFile("../Risorse/backgroundbattle.png")) {
        return EXIT_FAILURE;
    }
    spriteBattle.setTexture(textureBattle);
    spriteBattle.setPosition(0, 0);

    if (!optionsTexture.loadFromFile("../Risorse/options.png")) {// Mostra opzioni scelta
        return EXIT_FAILURE;
    }
    options.setTexture(optionsTexture);
    options.setPosition(100, 400);

    if (!attackTexture.loadFromFile("../Risorse/attacco.png")) {// Mostra opzioni scelta attacchi
        return EXIT_FAILURE;
    }
    attack.setTexture(attackTexture);
    attack.setPosition(50, 400);

    if (!attackBackgroundTexture.loadFromFile("../Risorse/sfondoattacco.png")) {  //sfondo nome attacco
        return EXIT_FAILURE;
    }
    attackBackground.setTexture(attackBackgroundTexture);
    attackBackground.setPosition(0, 390);

    if (!textureWin.loadFromFile("../Risorse/win.png")) {// Mostra opzioni scelta attacchi
        return EXIT_FAILURE;
    }
    win.setTexture(textureWin);
    win.setPosition(150, 150);

    if (!textureGameOver.loadFromFile("../Risorse/gameover.png")) {// Mostra opzioni scelta attacchi
        return EXIT_FAILURE;
    }
    gameOver.setTexture(textureGameOver);
    gameOver.setPosition(200, 200);

    lostText1.setString("-Your pokemon has lost " );
    lostText1.setPosition(70, 420 );
    lostText1.setFillColor(sf::Color::Magenta);
    lostText1.setCharacterSize(22);
    lostText1.setFont(font);

    lostText2.setString("-Enemy pokemon has lost " );
    lostText2.setPosition(70, 420 );
    lostText2.setFillColor(sf::Color::Magenta);
    lostText2.setCharacterSize(22);
    lostText2.setFont(font);

    enemyTurnText.setString("-Press K to proceed" );
    enemyTurnText.setPosition(70, 420 );
    enemyTurnText.setFillColor(sf::Color:: Yellow);
    enemyTurnText.setCharacterSize(30);
    enemyTurnText.setFont(font);

};

void Graphic ::setTextAttack(Pokemon *pokemon, Bullet &bullet) {
    //Text Attack
    ostringstream text;
    text << "- " << pokemon->getName() << " use " <<  bullet.getName() ;
    attackText.setString(text.str());
    attackText.setPosition(70, 410 );
    attackText.setFillColor(sf::Color::Yellow);
    attackText.setCharacterSize(30);
    attackText.setFont(font);

}

void Graphic :: setTextHp(Pokemon *pokemon){
    //Text Attack
    ostringstream hp;
    hp << pokemon->getName() << " HP : " <<  pokemon->getHp() ;
    hpText.setString(hp.str());
    hpText.setPosition(70, 40 );
    hpText.setFillColor(sf::Color::Magenta);
    hpText.setCharacterSize(26);
    hpText.setFont(font);

    //Text Attack
    ostringstream hp1;
    hp1 << pokemon->getName() << " HP : " <<  pokemon->getHp() ;
    hpEnemyText.setString(hp1.str());
    hpEnemyText.setPosition(550, 40 );
    hpEnemyText.setFillColor(sf::Color::Magenta);
    hpEnemyText.setCharacterSize(30);
    hpEnemyText.setFont(font);


};



