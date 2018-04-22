//
//
//

#include <iostream>
#include "Collision.h"

using  namespace std;

void Collision ::collision(sf:: RenderWindow &window, Graphic &graphic, Player &player, std::vector<NPC> &NPCArray, NPC &npc,
                           std:: vector<Item> &ItemArray) {

//Player collides npc
counterNPC = 0;
    for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {

        if (player.rect.getGlobalBounds().intersects(NPCArray[counterNPC].rect.getGlobalBounds())) {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                npc.setSpeak(true);
                window.draw(graphic.text1.sprite);
            }

            if (player.getDirection() == Character::Direction::Up) {

                player.setMoveUp(false);
                player.rect.move(0, 1);
                player.setDirection(Character::Direction::Up);

            }
            else if (player.getDirection() == Character::Direction::Down) {

                player.setMoveDown(false);
                player.rect.move(0, -1);
                player.setDirection(Character::Direction::Down);
            }

            else if (player.getDirection() == Character::Direction::Left) {

                player.setMoveLeft(false);
                player.rect.move(1, 0);
                player.setDirection(Character::Direction::Left);

            }
            else if (player.getDirection() == Character::Direction::Right) {

                player.setMoveRight(false);
                player.rect.move(-1, 0);
                player.setDirection(Character::Direction::Right);

            }

        }
        counterNPC++;
    }

    //player collides item
    counterItem = 0;
    for (auto itr = ItemArray.begin(); itr != ItemArray.end(); itr++) {
        if (player.rect.getGlobalBounds().intersects(ItemArray[counterItem].rect.getGlobalBounds())) {

            if (ItemArray[counterItem].getType() == "bicycle") {
                player.setRideBicycle(true);

            }

            else if (ItemArray[counterItem].getType() == "pokeball"){
                //player.sprite.setTexture(graphic.texturePlayer);
                player.increaseScore(ItemArray[counterItem].pokeballValue);
                cout<<"score: "<<player.getScore()<<endl;
            }


            ItemArray[counterItem].setPickedUp(true);
        }
        counterItem++;
    }

};



