#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Graphic.h"
#include "TileMap.h"
#include "Collision.h"
#include "Item.h"
#include <windows.h>

int main() {

    Graphic graphic;
    Collision collision;

    int counter = 0;
    int counterNPC = 0;
    int counterItem = 0;

    sf::RenderWindow window(sf::VideoMode(800, 500), "Game");

    window.setFramerateLimit(60);

    graphic.loadTextures();
    graphic.setFont();


    //Load spritePlayer
    Player player;
    player.sprite.setTexture(graphic.texturePlayer);
    player.myTexture = graphic.texturePlayer;

    player.textureExchange = graphic.texturePlayerBike;


    NPC npc;

    // Mappa
    TileMap map;
    if (!map.load("../Risorse/tileset.png", sf::Vector2u(32, 32), graphic.levelBackground, 21, 16))
        return -1;

    //Enemy vector array
    std::vector<NPC> NPCArray;
    graphic.setNPC();
    NPCArray.push_back(graphic.NPC1);
    NPCArray.push_back(graphic.NPC2);

    //Item vector array
    std::vector<Item> ItemArray;
    graphic.setItem();
    ItemArray.push_back(graphic.bicycle);
    ItemArray.push_back(graphic.bacca);
    ItemArray.push_back(graphic.pokeball);



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

        //update player
        player.update();
        player.move();

        // Draws items
        counterItem = 0;
        for (auto iter1 = ItemArray.begin(); iter1 != ItemArray.end(); iter1 ++) {
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
        counter = 0;
        for(auto iter2 = ItemArray.begin(); iter2 != ItemArray.end(); iter2++){
            if(ItemArray[counter].isPickedUp()){
                ItemArray.erase(iter2);

                break;
            }
            counter++;
        }


        window.draw(player.textScore);
        window.draw(player.sprite);


        window.display();


    }

    return 0;
}