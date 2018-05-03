
#include <iostream>
#include "Collision.h"


void Collision ::collisionNPC(Player &player, std::vector<NPC> &NPCArray, NPC &npc) {

//Player collides npc
    for (auto iter = NPCArray.begin(); iter != NPCArray.end(); iter++) {
        if (player.rect.getGlobalBounds().intersects(iter->rect.getGlobalBounds())) {

            if (player.getDirection() == Character::Direction::Left) {

                player.moveLeft = false;
                player.rect.move(1, 0);
                player.setDirection(Character::Direction::Left);

            } else if (player.getDirection() == Character::Direction::Right) {

                player.moveRight = false;
                player.rect.move(-1, 0);
                player.setDirection(Character::Direction::Right);

            } else if (player.getDirection() == Character::Direction::Up) {

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
}

void Collision ::collisionItem(Player &player, std :: vector<Item> &ItemArray) {
    //player collides object
    for (auto itr = ItemArray.begin(); itr != ItemArray.end(); itr++) {
        if (player.rect.getGlobalBounds().intersects(itr->rect.getGlobalBounds())) {

            if (itr->getType() == "bicycle" ) {
                player.setBicyclePickUp(true);
                player.textBicycle = true;
            }
            else if (itr->getType() == "Megaball" || itr->getType() == "Masterball" ){
                player.increaseScore(itr->pokeballValue);
            }
            itr->setPickedUp(true);
        }
    }

};

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

//Pokemon attacks (shot)
void Collision::PokemonAttack(Pokemon &pokemon, Bullet &bullet, vector<Bullet> &bulletArray, Player &player, int &adder1, Bullet &effect) {
    bullet = *pokemon.bulletPtr;
    effect = *pokemon.bulletPtr;
    if ( pokemon.direction == 2) {
        effect.rect.setPosition(550, 160);
        bullet.rect.setPosition(pokemon.rect.getPosition().x + pokemon.rect.getSize().x/3 + adder1,
                                pokemon.rect.getPosition().y + adder1 );     // adder1 posiziona il bullet in base all'attacco
        bullet.setDirection(2);
        bulletArray.push_back(bullet);
    }
    else {
        effect.rect.setPosition(50, 160);
        bullet.rect.setPosition( pokemon.rect.getPosition().x - pokemon.rect.getSize().x/2 + bullet.rect.getSize().x +adder1,
                                 pokemon.rect.getPosition().y + adder1 );
        bullet.setDirection(1);
        bulletArray.push_back(bullet);
    }
}

//Collisioni bullet - pokemon avversario
void Collision::BulletCollidesPokemon(Pokemon *pokemon, vector<Bullet> &bulletArray, Bullet &effect, Text &textDisplay,
                                      std :: vector<Text> &textArray, float &a) {
    for (auto iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
        if (iter->rect.getGlobalBounds().intersects(pokemon->rect.getGlobalBounds())) {
            effect.updateEffects();    // Effetti
            a = a + 0.1f;

            //Debolezze
            if(pokemon->getType() == PokemonType ::PokemonFire && iter->getType() == BulletType ::BulletWater){
                iter->attackDamage += 3;
            }
            if(pokemon->getType() == PokemonType ::PokemonWater && iter->getType() == BulletType ::BulletElectric){
                iter->attackDamage += 3;
            }
            if(pokemon->getType() == PokemonType ::PokemonElectric && iter->getType() == BulletType ::BulletGrass){
                iter->attackDamage += 3;
            }
            if(pokemon->getType() == PokemonType ::PokemonGrass && iter->getType() == BulletType ::BulletFire){
                iter->attackDamage += 3;
            }

            //Forza
            if(pokemon->getType() == PokemonType ::PokemonFire && iter->getType() == BulletType ::BulletGrass){
                iter->attackDamage -= 1;
            }
            if(pokemon->getType() == PokemonType ::PokemonWater && iter->getType() == BulletType ::BulletFire){
                iter->attackDamage -= 1;
            }
            if(pokemon->getType() == PokemonType ::PokemonElectric && iter->getType() == BulletType ::BulletWater){
                iter->attackDamage -= 1;
            }
            if(pokemon->getType() == PokemonType ::PokemonGrass && iter->getType() == BulletType ::BulletElectric){
                iter->attackDamage -= 1;
            }

            cout << "I punti vita di " << pokemon->getName() << " sono  " << pokemon->getHp() << endl;
            pokemon->hp = pokemon->hp - iter->attackDamage;

            //Text Display
            ostringstream attackDamageText;
            attackDamageText << "-" << iter->attackDamage;
            textDisplay.text.setString(attackDamageText.str());

            //la scritta va verso l'alto
            textDisplay.text.setPosition(pokemon->rect.getPosition().x + pokemon->rect.getSize().x / 2,
                                         pokemon->rect.getPosition().y - 15);
            textArray.push_back(textDisplay);

            pokemon->isAlive = pokemon->hp > 0;
            //   cout <<"a = " << a << endl;

        }
    }
}