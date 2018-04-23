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

        graphic.setText(player);

        //Load spritePlayer
        if(player.rideBicycle) {
            player.sprite.setTexture(graphic.texturePlayerBike);
        }
        else if(!player.rideBicycle)
        {
            player.sprite.setTexture(graphic.texturePlayer);
        }

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
        counterItem = 0;
        for(auto iter2 = ItemArray.begin(); iter2 != ItemArray.end(); iter2++){
            if(ItemArray[counterItem].isPickedUp()){
                ItemArray.erase(iter2);

                break;
            }
            counterItem++;
        }


        window.draw(player.text);
        window.draw(player.sprite);


        window.display();


    }

    return 0;
}