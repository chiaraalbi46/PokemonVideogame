
#include "Graphic.h"

using namespace std;

int Graphic::loadTextures(GraphicPokemon &strategy) {

    //Texture player
    if (!texturePlayer.loadFromFile("player.png")) {
        return EXIT_FAILURE;
    }
    if (!texturePlayerBike.loadFromFile("playerbicycle.png")) {
        return EXIT_FAILURE;
    }

    //Texture Bike
    if (!textureBicycle.loadFromFile("bicycle.png")) {
        return EXIT_FAILURE;
    }

    //Texture medal
    if (!textureMedal1.loadFromFile("medaglia1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal2.loadFromFile("medaglia2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal3.loadFromFile("medaglia3.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal4.loadFromFile("medaglia4.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal5.loadFromFile("medaglia5.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal6.loadFromFile("medaglia6.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal7.loadFromFile("medaglia7.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedal8.loadFromFile("medaglia8.png")) {
        return EXIT_FAILURE;
    }

    if (!textureMedalPickUp1.loadFromFile("medalpickup1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp2.loadFromFile("medalpickup2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp3.loadFromFile("medalpickup3.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp4.loadFromFile("medalpickup4.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp5.loadFromFile("medalpickup5.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp6.loadFromFile("medalpickup6.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp7.loadFromFile("medalpickup7.png")) {
        return EXIT_FAILURE;
    }
    if (!textureMedalPickUp8.loadFromFile("medalpickup8.png")) {
        return EXIT_FAILURE;
    }

    //Texture NPC
    if (!textureNPC1.loadFromFile("npc1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureNPC2.loadFromFile("npc2.png")) {
        return EXIT_FAILURE;
    }

    //Texture menu
    if (!textureControls.loadFromFile("controls.png")) {
        return EXIT_FAILURE;
    }

    if (!textureCredits.loadFromFile("credits.jpg")) {
        return EXIT_FAILURE;
    }

    if (!textureStart1.loadFromFile("start1.png")) {
        return EXIT_FAILURE;
    }
    if (!textureStart2.loadFromFile("start2.png")) {
        return EXIT_FAILURE;
    }
    if (!textureStart3.loadFromFile("start3.png")) {
        return EXIT_FAILURE;
    }

    //Texture prebattle
    if (!texturePrebattle.loadFromFile("prebattle.png")) {
        return EXIT_FAILURE;
    }
}

void Graphic::setFont() {
    font.loadFromFile("pokemonnormal.ttf");
}

int Graphic::setMusicBattle(Player &player) {

    if (!musicplayer.openFromFile("musicplayer.ogg")) {
        return EXIT_FAILURE;
    }
    musicplayer.setVolume(20);

    if (!musicbattle.openFromFile("soundBattle.ogg")) {
        return EXIT_FAILURE;
    }

    if (!bufferItem.loadFromFile("itempickup.ogg")) {
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

    gym.setPosition(1050, 75);
    gym.setSize(sf::Vector2f(50,50));
    gym.setFillColor(sf:: Color :: Transparent);
}

void Graphic ::setMenu() {
    controls.setTexture(textureControls);
    controls.setPosition(0, 0);

    credits.setTexture(textureCredits);
    credits.setPosition(0, 0);

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
    
    textBicycle.setString("Press Z to use the bicycle");
    textBicycle.setFont(font);
    textBicycle.setFillColor(sf:: Color:: Red);
    textBicycle.setCharacterSize(30);
    textBicycle.setPosition(245, 1260);

    ostringstream medals;
    medals << "MEDALS: "<< player.getScore() << ". You should pick up: " << ItemArray.size() << " (Press Enter)";
    medalsText.setString(medals.str());
    medalsText.setFont(font);
    medalsText.setFillColor(sf:: Color::Red);
    medalsText.setCharacterSize(30);
    medalsText.setPosition(880, 151);

    if (!textureMedal.loadFromFile("medal.png")) {
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
}

int Graphic :: setBackgroundBattle(sf::RenderWindow &window, Player &player){

    // Load Background
    if (!textureBattle.loadFromFile("backgroundbattle.png")) {
        return EXIT_FAILURE;
    }
    spriteBattle.setTexture(textureBattle);
    spriteBattle.setPosition(0, 0);

    if (!optionsTexture.loadFromFile("options.png")) {// Mostra opzioni scelta
        return EXIT_FAILURE;
    }
    options.setTexture(optionsTexture);
    options.setPosition(100, 400);

    if (!attackTexture.loadFromFile("attacco.png")) {// Mostra opzioni scelta attacchi
        return EXIT_FAILURE;
    }
    attack.setTexture(attackTexture);
    attack.setPosition(50, 400);

    if (!attackBackgroundTexture.loadFromFile("sfondoattacco.png")){//sfondo nome attacco
        return EXIT_FAILURE;
    }
    attackBackground.setTexture(attackBackgroundTexture);
    attackBackground.setPosition(0, 390);

    if (!textureWin.loadFromFile("win.png")) {
        return EXIT_FAILURE;
    }
    win.setTexture(textureWin);
    win.setPosition(0, 0);

    if (!textureGameOver.loadFromFile("gameover.png")) {
        return EXIT_FAILURE;
    }
    gameOver.setTexture(textureGameOver);
    gameOver.setPosition(0, 0);

    prebattle.setTexture(texturePrebattle);
    prebattle.setPosition(0, 0);

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

}

void Graphic ::setTextAttack(Pokemon *pokemon, Bullet &bullet) {

    ostringstream text;
    text << "- " << pokemon->getName() << " use " <<  bullet.getName() ;
    attackText.setString(text.str());
    attackText.setPosition(70, 410 );
    attackText.setFillColor(sf::Color::Yellow);
    attackText.setCharacterSize(30);
    attackText.setFont(font);

}

void Graphic :: setTextHp(Pokemon *pokemon){

    ostringstream hp;
    hp << pokemon->getName() << " HP : " <<  pokemon->getHp() ;
    hpText.setString(hp.str());
    hpText.setPosition(70, 40 );
    hpText.setFillColor(sf::Color::Magenta);
    hpText.setCharacterSize(26);
    hpText.setFont(font);

    ostringstream hp1;
    hp1 << pokemon->getName() << " HP : " <<  pokemon->getHp() ;
    hpEnemyText.setString(hp1.str());
    hpEnemyText.setPosition(550, 40 );
    hpEnemyText.setFillColor(sf::Color::Magenta);
    hpEnemyText.setCharacterSize(30);
    hpEnemyText.setFont(font);


}


