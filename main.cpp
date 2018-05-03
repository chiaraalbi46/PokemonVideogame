#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Graphic.h"
#include "TileMap.h"
#include "Collision.h"
#include "Settings.h"



int generateRandom(int max) {
    int randomNum = rand();
    int random = (randomNum % max) + 1;
    return random;
}

int main() {
    enum Gamestate {
        Initialize, Fighting, Playing
    };

    Gamestate gameState = Initialize;

    Graphic graphic;
    Collision collision;
    GraphicPokemon graphicPokemon;
    Settings settings;



    int choosen = 0;  //scelta pokemon iniziale
    int choosen1 = 0;    //scelta pokemon
    int choosen2 = 0;   // seleziona pokemon nemico
    int typeAttack = 0;     //scelta attacco
    int adder1 = 0;    //Sistema posizione attacco

    float a;    // Cambia il turno

    sf::RenderWindow window(sf::VideoMode(900, 507), "Game");
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Clock clock1;

    Player player;
    NPC npc;

    graphic.loadTextures(graphicPokemon);
    graphic.setFont();
    graphicPokemon.loadTexturePokemon(player);

    //Mappa playing
     TileMap map;
    if (!map.load("../Risorse/tileset.png", sf::Vector2u(48, 48), graphic.levelBackground, 29, 16))
        return -1;

    graphic.setBackgroundBattle(window, player);    // Set battaglia

    std::vector<Pokemon *> Array;   // Array pokemon generico
    Array.push_back(graphicPokemon.floatzel);
    Array.push_back(graphicPokemon.infernape);
    Array.push_back(graphicPokemon.luxray);
    Array.push_back(graphicPokemon.breloom);
    Array.push_back(graphicPokemon.rapidash);
    Array.push_back(graphicPokemon.blastoise);
    Array.push_back(graphicPokemon.zapdos);
    Array.push_back(graphicPokemon.bulbasaur);

    graphicPokemon.setCheck(graphicPokemon);

    std::vector<Pokemon *> PokemonArray;      // Array giocatore
    std::vector<Pokemon *> PokemonEnemyArray; // Array nemico
    graphicPokemon.setPokemon();

    if (gameState == Initialize) {
        int i = 0;
        while ( i < 4) {     //Inserisce nell'array pokemon scelti
            settings.choosePokemonBattle(window, choosen, graphicPokemon, player);
            if (choosen == 0 && !player.click0) {
                PokemonArray.push_back(graphicPokemon.floatzel);
                player.click0 = true;
                i++;
            } else if (choosen == 1 && !player.click1) {
                PokemonArray.push_back(graphicPokemon.infernape);
                player.click1 = true;
                i++;
            } else if (choosen == 2 && !player.click2) {
                PokemonArray.push_back(graphicPokemon.luxray);
                player.click2 = true;
                i++;
            } else if (choosen == 3 && !player.click3) {
                PokemonArray.push_back(graphicPokemon.breloom);
                player.click3 = true;
                i++;
            } else if (choosen == 4 && !player.click4) {
                PokemonArray.push_back(graphicPokemon.blastoise);
                player.click4 = true;
                i++;
            }
            else if (choosen == 5 && !player.click5) {
                PokemonArray.push_back(graphicPokemon.rapidash);
                player.click5 = true;
                i++;
            }
            else if (choosen == 6 && !player.click6) {
                PokemonArray.push_back(graphicPokemon.zapdos);
                player.click6 = true;
                i++;
            }
            else if (choosen == 7 && !player.click7) {
                PokemonArray.push_back(graphicPokemon.bulbasaur);
                player.click7 = true;
                i++;
            }
        }

        if(player.click0) {
            graphicPokemon.spriteCheck.setPosition(0, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click1) {
            graphicPokemon.spriteCheck.setPosition(451, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click2) {
            graphicPokemon.spriteCheck.setPosition(451, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click3) {
            graphicPokemon.spriteCheck.setPosition(0, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click4) { //ricomincio da blastoise
            graphicPokemon.spriteCheck.setPosition(226, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click5) {
            graphicPokemon.spriteCheck.setPosition(676, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click6) {
            graphicPokemon.spriteCheck.setPosition(676, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click7) {
            graphicPokemon.spriteCheck.setPosition(226, 255);
            window.draw(graphicPokemon.spriteCheck);
        }

        window.display();

        int counterPok = 0;
        for (auto iter = Array.begin(); iter != Array.end(); iter++) {    //Crea array nemico
            if (Array[counterPok] != PokemonArray[0]) {
                player.enemy0 = true;
            }
            if (Array[counterPok] != PokemonArray[1]) {
                player.enemy1 = true;
            }
            if (Array[counterPok] != PokemonArray[2]) {
                player.enemy2 = true;
            }
            if (Array[counterPok] != PokemonArray[3]) {
                player.enemy3 = true;
            }
            if (player.enemy0 && player.enemy1 && player.enemy2 && player.enemy3) {
                PokemonEnemyArray.push_back(Array[counterPok]);
            }
            player.enemy0 = false;
            player.enemy1 = false;
            player.enemy2 = false;
            player.enemy3 = false;

            counterPok++;
        }

        gameState = Playing;
    }

    //NPC vector array
    std::vector<NPC> NPCArray;
    graphic.setNPC();
    NPCArray.push_back(graphic.NPC1);
    NPCArray.push_back(graphic.NPC2);
    graphic.setItem();

    //Item vector array
    std::vector<Item> ItemArray;
    ItemArray.push_back(graphic.bicycle);
    ItemArray.push_back(graphic.pokeball1);
    ItemArray.push_back(graphic.pokeball2);
    ItemArray.push_back(graphic.berry1);
    ItemArray.push_back(graphic.berry2);

    // Bullet Vector Array
    Bullet bullet;
    std::vector<Bullet> bulletArray;

    Bullet effect;

    //Text
    Text text;
    vector<Text> textArray;
    text.text.setFont(graphic.font);

// FIXME inizio while
    // run the program as long as the window is open
    while (window.isOpen()) {
// check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
                window.close();

            if (!player.isEnemyTurn()) {
                if (player.options) {//Scegliere se attaccare o cambiare pokemon
                    if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 313 &&
                        sf::Mouse::getPosition(window).y > 400 && sf::Mouse::getPosition(window).y < 435 &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        player.setSelect(true);
                        player.options = false;
                    } else if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 313 &&
                               sf::Mouse::getPosition(window).y > 440 && sf::Mouse::getPosition(window).y < 490 &&
                               sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        player.setSelectAttack(true);
                        player.options = false;
                    }
                }
                if (player.isSelectAttack()) {   //scegliere attacco
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                        player.setSelectAttack(false);
                        player.setAttack(true);
                        typeAttack = 1;    // Attacco 1
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                        player.setAttack(true);
                        player.setSelectAttack(false);
                        typeAttack = 2;    // Attacco 2
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                        player.setAttack(true);
                        player.setSelectAttack(false);
                        typeAttack = 3;     // Attacco 3
                    }
                }
            }
        }
        window.clear();

        if (player.isEnterGym()) {
            if (gameState == Playing) {
                gameState = Fighting;
            }
        } else {
            gameState = Playing;
        }

        if (gameState == Fighting) {
            window.clear();
            window.draw(graphic.spriteBattle);    // Disegna palestra sfondo
            window.draw(graphic.attackBackground);
            if (!player.isEnemyTurn()) {
                if (player.options) { //Attacca o Cambia pokemon
                    window.draw(graphic.options);
                }
                if (player.isSelectAttack()) {
                    window.draw(graphic.attack);   //Scegli attacco
                }
            }
        } else if (gameState == Playing) {
            player.playing = true;
            window.draw(map);
        }

        if (gameState == Playing) {
            graphic.setText(player);

            //Load spritePlayer
            if (player.rideBicycle) {
                player.sprite.setTexture(graphic.texturePlayerBike);
            } else {
                player.sprite.setTexture(graphic.texturePlayer);
            }

            //update player
            player.update();
            player.move();

            //collisions NPC
            collision.collisionNPC(player, NPCArray, npc);

            //collisions item
            collision.collisionItem(player, ItemArray);

            //collision gym
            collision.collisionGym(player, graphic);

            //collision gym NPC  ???
            collision.collisionNpcItem(graphic, NPCArray);

            // Draws item
            for (auto iter = ItemArray.begin(); iter != ItemArray.end(); iter++) {
                iter->update();
                window.draw(iter->sprite);
            }

            //Draw NPC
            for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {
                iter->update();
                iter->move();
                window.draw(iter->sprite);
            }

            //delete object
            for (auto iter = ItemArray.begin(); iter != ItemArray.end(); iter++) {
                if (iter->isPickedUp()) {
                    ItemArray.erase(iter);
                    break;
                }
            }

            if(player.textBicycle){
                window.draw(graphic.textBicycle);
            }

            window.draw(graphic.gym.sprite);
            window.draw(player.text);
            window.draw(player.sprite);

            if (player.isCollGym()) {
                graphic.setBattleText(window, player);
            }
            window.display();
        }
// FIXME gamestate = Fighting
        if (gameState == Fighting) {

            bullet.update(typeAttack, adder1);

            if (PokemonEnemyArray[choosen2]->isAlive) {
                graphicPokemon.setPokemonOpponent(window, PokemonEnemyArray, player, choosen2);  //Draw enemy
                player.setEnemy(false);  // direzione != 1
            }
            if (PokemonArray[choosen1]->isAlive && player.isCambio()) {    //Draw pokemon
                if (player.pokemon0) {
                    PokemonArray[0]->update();
                    choosen1 = 0;
                    window.draw(PokemonArray[0]->sprite);
                } else if (player.pokemon1) {
                    PokemonArray[1]->update();
                    choosen1 = 1;
                    window.draw(PokemonArray[1]->sprite);
                } else if (player.pokemon2) {
                    PokemonArray[2]->update();
                    choosen1 = 2;
                    window.draw(PokemonArray[2]->sprite);
                }
                else if (player.pokemon3){
                    PokemonArray[3]->update();
                    choosen1 = 3;
                    window.draw(PokemonArray[3]->sprite);
                }
            }
            graphic.setTextHp(PokemonArray[choosen1]);    // HP pokemon
            window.draw(graphic.hpText);
            graphic.setTextHp(PokemonEnemyArray[choosen2]); // HP pokemon nemico
            window.draw(graphic.hpEnemyText);

            if (player.isFight()) {
                player.fighting = true;
                player.playing = false;
                if (!player.isEnemyTurn()) {    //TURNO GIOCATORE
                    player.textLost2 = false;
                    PokemonArray[choosen1]->updateDirection(player);
                    PokemonArray[choosen1]->update();

                    if (player.isSelect()) {     // Cambio pokemon

                        if(player.textLost1){
                            window.draw(graphic.lostText1);
                        }
                        player.setCambio(true);
                        settings.choosePokemon(window, choosen1, PokemonArray, graphicPokemon, player);
                        PokemonArray[choosen1]->updateDirection(player);
                        PokemonArray[choosen1]->update();
                        if (choosen1 == 0) {
                            window.draw(PokemonArray[0]->sprite);
                        }
                        else if (choosen1 == 1) {
                            window.draw(PokemonArray[1]->sprite);
                        }
                        else if (choosen1 == 2) {
                            window.draw(PokemonArray[2]->sprite);
                        }
                        else if (choosen1 == 3){
                            window.draw(PokemonArray[3]->sprite);
                        }

                        player.setEnemyTurn(true);
                    }

                    if (player.isAttack()) {   //attacco

                        PokemonArray[choosen1]->updateDirection(player);
                        PokemonArray[choosen1]->update();

                        sf::Time elapsed = clock.getElapsedTime();
                        if (elapsed.asSeconds() >= 0.8) {
                            clock.restart();
                            collision.PokemonAttack(*PokemonArray[choosen1], bullet, bulletArray, player, adder1,
                                                    effect);
                        }

                        collision.BulletCollidesPokemon(PokemonEnemyArray[choosen2], bulletArray, effect, text,
                                                        textArray, a);

                        graphic.setTextAttack(PokemonArray[choosen1], bullet); // Scrive l'attacco usato dal pokemon
                        window.draw(graphic.attackText);  // Nome Attacco
                        window.draw(effect.effect1);   // Effetto degli attacchi sul nemico

                        if (a > 3) {  //Turno giocatore finisce
                            player.setAttack(false);
                            player.setEnemyTurn(true);
                            a = 0;
                        }
                    }
                }
                if (player.isEnemyTurn()) { // TURNO NEMICO

                    graphicPokemon.setPokemonOpponent(window, PokemonEnemyArray, player, choosen2);
                    graphic.setTextAttack(PokemonEnemyArray[choosen2], bullet); // Scrive l'attacco usato dal pokemon
                    if(!player.enemyAttack){
                        window.draw(graphic.enemyTurnText);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {  // nemico attacca
                        player.textLost1 = false;
                        player.textLost2 = false;
                        if (!player.enemyAttack){
                            typeAttack = generateRandom(3);
                        }
                        player.enemyAttack = true;
                    }

                    if (player.enemyAttack) {

                        sf::Time elapsed = clock1.getElapsedTime();
                        if (elapsed.asSeconds() >= 0.8) {
                            clock1.restart();
                            collision.PokemonAttack(*PokemonEnemyArray[choosen2], bullet, bulletArray, player, adder1,
                                                    effect);
                        }

                        collision.BulletCollidesPokemon(PokemonArray[choosen1], bulletArray, effect, text, textArray, a);

                        window.draw(effect.effect1); // Effetto degli attacchi sul giocatore
                        window.draw(graphic.attackText);

                        if (a > 3) {   //turno nemico finisce
                            player.enemyAttack = false;
                            player.setEnemyTurn(false);
                            player.options = true;  // Decido se attaccare o cambiare pokemon
                            a = 0;
                        }
                    }
                }

                if (!PokemonArray[choosen1]->isAlive) {  // Appena muore pokemon scelgo quale mettere
                    player.textLost1 = true;
                    player.enemyAttack = false;
                    player.setEnemyTurn(false);
                    player.setCambio(false);
                    player.setSelect(true);
                }

                if (!PokemonEnemyArray[choosen2]->isAlive) {
                    player.setEnemyTurn(true);
                    player.setAttack(false);
                    player.textLost2 = true;
                }

                if(player.textLost2){
                    window.draw(graphic.lostText2);
                }

                //Draw bullet
                for (auto iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
                    iter->update(typeAttack, adder1);
                    window.draw(iter->sprite);

                }

                //Draw text
                for (auto iter = textArray.begin(); iter != textArray.end(); iter++) {
                    iter->update();
                    //cout << "draw bullet" << endl;
                    window.draw(iter->text);
                }

                //Distruzione testo
                for (auto iter = textArray.begin(); iter != textArray.end(); iter++) {
                    if (iter->isDestroyed) {
                        textArray.erase(iter);
                        break;
                    }
                }

                //Distruzione nemico
                int counter1 = 0;
                for (auto iter = PokemonEnemyArray.begin(); iter != PokemonEnemyArray.end(); iter++) {
                    if (!PokemonEnemyArray[counter1]->isAlive) {
                        PokemonEnemyArray.erase(iter);
                        break;
                    }
                    counter1++;
                }

                //Distruzione pokemon
                int counter = 0;
                for (auto iter = PokemonArray.begin(); iter != PokemonArray.end(); iter++) {
                    if (!PokemonArray[counter]->isAlive) {
                        PokemonArray.erase(iter);
                        break;
                    }
                    counter++;
                }

                //Distruzione proiettili
                for (auto iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
                    if (iter->isDestroyed) {
                        bulletArray.erase(iter);
                        break;
                    }
                }
            }

            if (PokemonArray.empty()) {       // Vince il nemico
                player.setFight(false);
                window.draw(graphic.gameOver);
            }
            else if (PokemonEnemyArray.empty()) {  // Vince il giocatore
                player.setFight(false);
                window.draw(graphic.win);
            }
            window.display();
        }
    }
    return 0;
}