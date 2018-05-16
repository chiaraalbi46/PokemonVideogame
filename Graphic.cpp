
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

    //Texture Pokeball
    if (!texturePokeball1.loadFromFile("../Risorse/pokeball1.png")) {
        return EXIT_FAILURE;
    }
    if (!texturePokeball2.loadFromFile("../Risorse/pokeball2.png")) {
        return EXIT_FAILURE;
    }

    if (!textureMedal1.loadFromFile("../Risorse/medaglia1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal2.loadFromFile("../Risorse/medaglia2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal3.loadFromFile("../Risorse/medaglia3.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal4.loadFromFile("../Risorse/medaglia4.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal5.loadFromFile("../Risorse/medaglia5.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal6.loadFromFile("../Risorse/medaglia6.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal7.loadFromFile("../Risorse/medaglia7.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal8.loadFromFile("../Risorse/medaglia8.png")) {
        return EXIT_FAILURE;
    }

    if (!textureMedalPickUp1.loadFromFile("../Risorse/medalpickup1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp2.loadFromFile("../Risorse/medalpickup2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp3.loadFromFile("../Risorse/medalpickup3.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp4.loadFromFile("../Risorse/medalpickup4.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp5.loadFromFile("../Risorse/medalpickup5.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp6.loadFromFile("../Risorse/medalpickup6.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp7.loadFromFile("../Risorse/medalpickup7.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp8.loadFromFile("../Risorse/medalpickup8.png")) {
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
    if (!textureNPC4.loadFromFile("../Risorse/npc4.png")) {
        return EXIT_FAILURE;
    }

    if (!textureControls.loadFromFile("../Risorse/controls.png")) {
        return EXIT_FAILURE;
    }

    if (!textureStart1.loadFromFile("../Risorse/start1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureStart2.loadFromFile("../Risorse/start2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureStart3.loadFromFile("../Risorse/start3.png")) {
        return EXIT_FAILURE;
    }

    if (!texturePrebattle.loadFromFile("../Risorse/prebattle.png")) {
        return EXIT_FAILURE;
    }
}

void Graphic::setFont() {
    font.loadFromFile("../Risorse/pokemonnormal.ttf");
}

int Graphic::setMusicBattle(Player &player) {

    if (!musicplayer.openFromFile("../Risorse/musicplayer.ogg")) {
        return EXIT_FAILURE;
    }
    musicplayer.setVolume(20);

    if (!musicbattle.openFromFile("../Risorse/soundBattle.ogg")) {
        return EXIT_FAILURE;
    }

    if (!bufferShot.loadFromFile("../Risorse/attacksound.ogg")) {
        return EXIT_FAILURE;
    }
    soundShot.setBuffer(bufferShot);
    soundShot.setVolume(60);

    if (!bufferItem.loadFromFile("../Risorse/itempickup.ogg")) {
        return EXIT_FAILURE;
    }
    soundItem.setBuffer(bufferItem);
    soundItem.setVolume(60);
}

void Graphic::setNPC() {

    NPC1.rect.setSize(sf::Vector2f(20, 20));
    NPC1.rect.setPosition(502, 1275);
    NPC1.sprite.setTexture(textureNPC1);

    NPC2.rect.setSize(sf::Vector2f(20, 20));
    NPC2.rect.setPosition(463, 636);
    NPC2.sprite.setTexture(textureNPC2);

    NPC3.rect.setSize(sf::Vector2f(32, 32));
    NPC3.rect.setPosition(1162, 1689);
    NPC3.sprite.setTexture(textureNPC3);

    NPC4.rect.setSize(sf::Vector2f(32, 32));
    NPC4.rect.setPosition(1127, 956);
    NPC4.sprite.setTexture(textureNPC3);

    //  NPC5.rect.setPosition(1120, 534);

}

void Graphic:: setItem(){

    bicycle.setType("bicycle");
    bicycle.rect.setSize(sf::Vector2f(32, 32));
    bicycle.rect.setPosition(245, 1280);
    bicycle.sprite.setTexture(textureBicycle);

    medal1.setType("medal1");
    medal1.rect.setSize(sf::Vector2f(20, 20));
    medal1.rect.setPosition(779, 1225);
    medal1.sprite.setTexture(textureMedal1);

    medal2.setType("medal2");
    medal2.rect.setSize(sf::Vector2f(20, 20));
    medal2.rect.setPosition(1397, 1700);
    medal2.sprite.setTexture(textureMedal2);

    medal3.setType("medal3");
    medal3.rect.setSize(sf::Vector2f(20, 20));
    medal3.rect.setPosition(993, 705);
    medal3.sprite.setTexture(textureMedal3);

    medal4.setType("medal4");
    medal4.rect.setSize(sf::Vector2f(20, 20));
    medal4.rect.setPosition(1297, 447);
    medal4.sprite.setTexture(textureMedal4);

    medal5.setType("medal5");
    medal5.rect.setSize(sf::Vector2f(20, 20));
    medal5.rect.setPosition(478,261);
    medal5.sprite.setTexture(textureMedal5);

    medal6.setType("medal6");
    medal6.rect.setSize(sf::Vector2f(20, 20));
    medal6.rect.setPosition(561, 1318);
    medal6.sprite.setTexture(textureMedal6);

    medal7.setType("medal7");
    medal7.rect.setSize(sf::Vector2f(20, 20));
    medal7.rect.setPosition(33, 891);
    medal7.sprite.setTexture(textureMedal7);

    medal8.setType("medal8");
    medal8.rect.setSize(sf::Vector2f(20, 20));
    medal8.rect.setPosition(1510, 1312);
    medal8.sprite.setTexture(textureMedal8);

    pokeball1.setType("Megaball");
    pokeball1.rect.setSize(sf::Vector2f(48, 48));
    pokeball1.rect.setPosition(1510, 1312);
    pokeball1.sprite.setTexture(texturePokeball1);

    pokeball2.setType("Masterball");
    pokeball2.rect.setSize(sf::Vector2f(48, 48));
    pokeball2.rect.setPosition(250, 150);
    pokeball2.sprite.setTexture(texturePokeball2);

    gym.setPosition(1050, 75);
    gym.setSize(sf::Vector2f(50,50));
    gym.setFillColor(sf:: Color :: Transparent);
}

void Graphic ::setMenu() {
    controls.setTexture(textureControls);
    controls.setPosition(0, 0);

    textControls.setString("Press A for return to menu");
    textControls.setFont(font);
    textControls.setFillColor(sf:: Color::Black );
    textControls.setCharacterSize(30);
    textControls.setPosition(440, 467);

    start1.setTexture(textureStart1);   //Presentazione gioco
    start1.setPosition(0, 0);

    start2.setTexture(textureStart2);
    start2.setPosition(0, 0);

    start3.setTexture(textureStart3);
    start3.setPosition(0, 0);
}

int Graphic::setText(Player &player, std:: vector<Item> &ItemArray){

    ostringstream pokeballText;
    pokeballText << "Score:  "<< player.getScore();
    player.text.setString(pokeballText.str());
    player.text.setFont(font);
    player.text.setFillColor(sf:: Color::Red);
    player.text.setCharacterSize(30);
    player.text.setPosition(player.rect.getPosition().x -150, player.rect.getPosition().y - 300);

    textBicycle.setString("Press Z to use the bicycle");
    textBicycle.setFont(font);
    textBicycle.setOutlineColor(sf:: Color:: Black);
    textBicycle.setFillColor(sf:: Color:: Red);
    textBicycle.setCharacterSize(30);
    textBicycle.setPosition(245, 1260);

    ostringstream medals;
    medals << "MEDALS: "<< player.getScore() << ". You should pick up: " << ItemArray.size() << " (Press Enter)";
    medalsText.setString(medals.str());
    medalsText.setFont(font);
    medalsText.setFillColor(sf:: Color::Red);
    medalsText.setOutlineColor(sf:: Color:: Black);
    medalsText.setCharacterSize(30);
    medalsText.setPosition(880, 151);

    if (!textureMedal.loadFromFile("../Risorse/medal.png")) {
        return EXIT_FAILURE;
    }
    medal.setTexture(textureMedal);
    medal.setPosition(1026, 198);

    medalPickUp1.setPosition(1042, 223);
    medalPickUp1.setTexture(textureMedalPickUp1);

    medalPickUp2.setPosition(1098, 223);
    medalPickUp2.setTexture(textureMedalPickUp2);

    medalPickUp3.setPosition(1154, 222);
    medalPickUp3.setTexture(textureMedalPickUp3);

    medalPickUp4.setPosition(1210, 221);
    medalPickUp4.setTexture(textureMedalPickUp4);

    medalPickUp5.setPosition(1042, 279);
    medalPickUp5.setTexture(textureMedalPickUp5);

    medalPickUp6.setPosition(1098, 278);
    medalPickUp6.setTexture(textureMedalPickUp6);

    medalPickUp7.setPosition(1154, 278);
    medalPickUp7.setTexture(textureMedalPickUp7);

    medalPickUp8.setPosition(1210, 277);
    medalPickUp8.setTexture(textureMedalPickUp8);
}

int Graphic ::setBattleText(sf::RenderWindow &window, Player &player) {

    if(player.isCollGym()) {
        textBattle.setString("Do you want to fight? \nYES \nNO");
        textBattle.setFont(font);
        textBattle.setFillColor(sf::Color::Red);
        textBattle.setPosition(1000, 100);
        textBattle.setCharacterSize(30);
        window.draw(textBattle);
        window.display();
    }

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Mouse::getPosition(window).x > 336 && sf::Mouse::getPosition(window).x < 430 &&
                sf::Mouse::getPosition(window).y > 140 && sf::Mouse::getPosition(window).y < 170 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                player.setEnterGym(true);
                player.setCollGym(false);
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 336 && sf::Mouse::getPosition(window).x < 430 &&
                     sf::Mouse::getPosition(window).y > 173 && sf::Mouse::getPosition(window).y < 200 &&
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

    if (!attackBackgroundTexture.loadFromFile("../Risorse/sfondoattacco.png")){//sfondo nome attacco
        return EXIT_FAILURE;
    }
    attackBackground.setTexture(attackBackgroundTexture);
    attackBackground.setPosition(0, 390);

    if (!textureWin.loadFromFile("../Risorse/win.png")) {
        return EXIT_FAILURE;
    }
    win.setTexture(textureWin);
    win.setPosition(0, 0);

    if (!textureGameOver.loadFromFile("../Risorse/gameover.png")) {
        return EXIT_FAILURE;
    }
    gameOver.setTexture(textureGameOver);
    gameOver.setPosition(0, 0);

    prebattle.setTexture(texturePrebattle);
    prebattle.setPosition(0, 0);

    restart.setString("-Press Enter for play again" );
    restart.setPosition(70, 420 );
    restart.setFillColor(sf::Color:: Green);
    restart.setCharacterSize(22);
    restart.setFont(font);

    lostText1.setString("-Your pokemon has lost " );
    lostText1.setPosition(70, 420 );
    lostText1.setFillColor(sf::Color::Magenta);
    lostText1.setCharacterSize(22);
    lostText1.setFont(font);

    lostText2.setString("-Enemy pokemon has lost " );
    lostText2.setPosition(460, 420 );
    lostText2.setFillColor(sf::Color::Magenta);
    lostText2.setCharacterSize(22);
    lostText2.setFont(font);

    enemyTurnText.setString("-Press K to proceed" );
    enemyTurnText.setPosition(60, 420 );
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


