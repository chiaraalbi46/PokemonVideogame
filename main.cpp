#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Graphic.h"
#include "TileMap.h"
#include "Collision.h"
#include "GraphicPokemon.h"
#include "Settings.h"
#include <windows.h>

int main() {
    enum Gamestate {
        Initialize, Playing
    };

    Gamestate gameState = Initialize;

    Graphic graphic;
    Collision collision;
    GraphicPokemon graphicPokemon;
    Settings settings;

    int choosen = 0;  //scelta pokemon iniziale

    int counterNPC = 0;
    int counterItem = 0;

    sf::RenderWindow window(sf::VideoMode(800, 500), "Game");

    window.setFramerateLimit(60);

    graphic.loadTextures();
    graphic.setFont();

    Player player;

    NPC npc;

    // Mappa
    TileMap map;
    if (!map.load("../Risorse/tileset.png", sf::Vector2u(32, 32), graphic.levelBackground, 21, 16))
        return -1;

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


    //Enemy vector array
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



    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();


        window.draw(map);

        if (gameState == Playing) {
            graphic.setText(player);

            //Load spritePlayer
            if (player.rideBicycle) {
                player.sprite.setTexture(graphic.texturePlayerBike);
            } else if (!player.rideBicycle) {
                player.sprite.setTexture(graphic.texturePlayer);
            }

            //update player
            player.update();
            player.move();

            // Draws items
            counterItem = 0;
            for (auto iter1 = ItemArray.begin(); iter1 != ItemArray.end(); iter1++) {
                ItemArray[counterItem].update();
                window.draw(ItemArray[counterItem].sprite);
                counterItem++;
            }

            //Draw NPC
            counterNPC = 0;
            for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {
                NPCArray[counterNPC].update();
                NPCArray[counterNPC].move();
                window.draw(NPCArray[counterNPC].sprite);

                counterNPC++;
            }

            //collisions
            collision.collision(window, graphic, player, NPCArray, npc, ItemArray);


            //delete item
            counterItem = 0;
            for (auto iter2 = ItemArray.begin(); iter2 != ItemArray.end(); iter2++) {
                if (ItemArray[counterItem].isPickedUp()) {
                    ItemArray.erase(iter2);

                    break;
                }
                counterItem++;
            }


            window.draw(player.text);
            window.draw(player.sprite);


            window.display();
        }

    }

    return 0;
}