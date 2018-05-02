//
//
//

#ifndef POKEMONVIDEOGAME_COLLISION_H
#define POKEMONVIDEOGAME_COLLISION_H

#include "NPC.h"
#include "Player.h"
#include "Graphic.h"
#include "Item.h"
#include <vector>



class Collision {

public:
    void collision(sf:: RenderWindow &window, Graphic &graphic, Player &player, std::vector<NPC> &NPCArray,
                   NPC &npc, std:: vector<Item> &ItemArray);

    void collisionGym(Player &player, Graphic &graphic);

protected:
    int counterItem;
    int counterNPC;

};



#endif //POKEMONVIDEOGAME_COLLISION_H
