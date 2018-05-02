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

            if (player.getDirection() == Character::Direction::Up) {

                player.moveUp = false;
                player.rect.move(0, 1);
                player.setDirection(Character::Direction::Up);

            }
            else if (player.getDirection() == Character::Direction::Down) {

                player.moveDown = false;
                player.rect.move(0, -1);
                player.setDirection(Character::Direction::Down);
            }

            else if (player.getDirection() == Character::Direction::Left) {

                player.moveLeft = false;
                player.rect.move(1, 0);
                player.setDirection(Character::Direction::Left);

            }
            else if (player.getDirection() == Character::Direction::Right) {

                player.moveRight = false;
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
                player.setBicyclePickUp(true);

            }

            else if (ItemArray[counterItem].getType() == "Megaball" || ItemArray[counterItem].getType() == "Masterball"){
                player.increaseScore(ItemArray[counterItem].pokeballValue);
            }


            ItemArray[counterItem].setPickedUp(true);
        }
        counterItem++;
    }

};

void Collision::collisionGym(Player &player, Graphic &graphic) {
    if (player.rect.getGlobalBounds().intersects(graphic.gym.sprite.getGlobalBounds())) {

        if (player.getDirection() == Character::Direction::Left) {

            player.moveLeft = false;
            player.rect.move(1, 0);
            player.setDirection(Character::Direction::Left);

        } else if (player.getDirection() == Character::Direction::Right) {

            player.moveRight = false;
            player.rect.move(-1, 0);
            player.setDirection(Character::Direction::Right);

        } else if (player.getDirection() == Character::Direction::Up) {
            player.setCollGym(true);
            player.moveUp = false;
            player.rect.move(0, 1);
            player.setDirection(Character::Direction::Up);

        } else if (player.getDirection() == Character::Direction::Down) {

            player.moveDown = false;
            player.rect.move(0, -1);
            player.setDirection(Character::Direction::Down);
        }
    }

}



