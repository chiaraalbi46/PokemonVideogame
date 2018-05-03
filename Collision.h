
#ifndef POKEMONVIDEOGAME_COLLISION_H
#define POKEMONVIDEOGAME_COLLISION_H

#include "NPC.h"
#include "Player.h"
#include "Graphic.h"
#include "Item.h"
#include "Bullet.h"
#include "Pokemon.h"
#include "Text.h"
#include <vector>



class Collision {

public:
    void collisionNPC(Player &player, std::vector<NPC> &NPCArray, NPC &npc);

    void collisionItem(Player &player, std:: vector<Item> &ItemArray);

    void collisionNpcItem(Graphic &graphic, std:: vector<NPC> NPCArray);

    void collisionGym(Player &player, Graphic &graphic);

    void PokemonAttack(Pokemon &pokemon, Bullet &bullet, vector<Bullet> &bulletArray, Player &player);

    void BulletCollidesPokemon(vector<Pokemon> &pokemonOpponentArray, vector<Bullet> &bulletArray,
                               Text &textDisplay, vector<Text> &textArray);

private:
    int counterBullet;
    int countePokemon;


};



#endif //POKEMONVIDEOGAME_COLLISION_H
