
#include <iostream>
#include "Collision.h"

using  namespace std;

//Player collides npc
void Collision ::collisionNPC(Player &player, std::vector<NPC> &NPCArray, NPC &npc) {

    for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {

        if (player.rect.getGlobalBounds().intersects(iter->rect.getGlobalBounds())) {

            if (player.getDirection() == Character::Direction::Left) {

                player.moveLeft = false;
                player.rect.move(1, 0);
                player.setDirection(Character::Direction::Left);

            }
            else if (player.getDirection() == Character::Direction::Right) {

                player.moveRight = false;
                player.rect.move(-1, 0);
                player.setDirection(Character::Direction::Right);

            }
            else if (player.getDirection() == Character::Direction::Up) {

                player.moveUp = false;
                player.rect.move(0, 1);
                player.setDirection(Character::Direction::Up);

            }
            else if (player.getDirection() == Character::Direction::Down) {

                player.moveDown = false;
                player.rect.move(0, -1);
                player.setDirection(Character::Direction::Down);
            }
            else{}
        }
    }
}

//Player collides objects
void Collision ::collisionItem(Player &player, std :: vector<Item> &ItemArray) {

    for (auto itr = ItemArray.begin(); itr != ItemArray.end(); itr++) {
        if (player.rect.getGlobalBounds().intersects(itr->rect.getGlobalBounds())) {

            if (itr->getType() == "bicycle" ) {
                player.setBicyclePickUp(true);
            }
            else if (itr->getType() == "Megaball" || itr->getType() == "Masterball" ){

                player.increaseScore(itr->pokeballValue);
            }

            itr->setPickedUp(true);
        }

    }
}

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

//NPCGym collision
void Collision ::collisionNpcItem(Graphic &graphic, std:: vector<NPC> NPCArray) {
    for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {
        if (iter->sprite.getGlobalBounds().intersects(graphic.gym.sprite.getGlobalBounds())) {

            if (iter->getDirection() == Character::Direction::Left) {

                iter->moveLeft = false;
                iter->rect.move(1, 0);
                iter->setDirection(Character::Direction::Left);

            } else if (iter->getDirection() == Character::Direction::Right) {

                iter->moveRight = false;
                iter->rect.move(-1, 0);
                iter->setDirection(Character::Direction::Right);

            } else if (iter->getDirection() == Character::Direction::Up) {
                iter->moveUp = false;
                iter->rect.move(0, 1);
                iter->setDirection(Character::Direction::Up);

            } else if (iter->getDirection() == Character::Direction::Down) {

                iter->moveDown = false;
                iter->rect.move(0, -1);
                iter->setDirection(Character::Direction::Down);
            }
        }
    }
}

//Pokemon attacks (shot)
void Collision::PokemonAttack(Pokemon &pokemon, Bullet &bullet, vector<Bullet> &bulletArray, Player &player) { //sistemare con array
    bullet = *pokemon.bulletPtr;

    if ( pokemon.direction == 2){
        bullet.setMovementSpeed(25);
        bullet.rect.setPosition(
                pokemon.rect.getPosition().x + pokemon.rect.getSize().x / 2 - bullet.rect.getSize().x / 2,
                pokemon.rect.getPosition().y + pokemon.rect.getSize().y / 2 - bullet.rect.getSize().y / 2);
        bullet.setDirection(2);
        bulletArray.push_back(bullet);
    }
    /*
            bullet.rect.setPosition(pokemon.rect.getPosition().x + pokemon.rect.getSize().x / 2 - bullet.rect.getSize().x / 2,
                                    pokemon.rect.getPosition().y + pokemon.rect.getSize().y / 2 - bullet.rect.getSize().y / 2);

            bullet.setDirection(3);
            bulletArray.push_back(bullet);
            break;
      */

}

//Collisioni bullet - pokemon avversario
void Collision::BulletCollidesPokemon(vector<Pokemon> &pokemonOpponentArray, vector<Bullet> &bulletArray,
                                      Text &textDisplay, vector<Text> &textArray) {

    counterBullet = 0;
    for (auto iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
        countePokemon = 0;
        for (auto iter1 = pokemonOpponentArray.begin(); iter1 != pokemonOpponentArray.end(); iter1++) {
            if (bulletArray[counterBullet].rect.getGlobalBounds().intersects(
                    pokemonOpponentArray[countePokemon].rect.getGlobalBounds())) {
                bulletArray[counterBullet].isDestroyed = true; //voglio che il proiettile si distrugga dopo il colpo

                //Text Display
                ostringstream attackDamageText;
                attackDamageText << " " << bulletArray[counterBullet].attackDamage;
                textDisplay.text.setString(attackDamageText.str());

                //la scritta va verso l'alto
                textDisplay.text.setPosition(
                        pokemonOpponentArray[countePokemon].rect.getPosition().x + pokemonOpponentArray[countePokemon].rect.getSize().x / 2,
                        pokemonOpponentArray[countePokemon].rect.getPosition().y - pokemonOpponentArray[countePokemon].rect.getSize().y / 2);
                textArray.push_back(textDisplay);

                pokemonOpponentArray[countePokemon].hp -= bulletArray[counterBullet].attackDamage;
                cout << "i punti vita di pokemon opponent sono: " << pokemonOpponentArray[countePokemon].getHp() << endl;

                if (pokemonOpponentArray[countePokemon].hp <= 0) {
                    pokemonOpponentArray[countePokemon].isAlive = false;
                }
            }
            countePokemon++;
        }
        counterBullet++;
    }
}




