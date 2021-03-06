
#ifndef POKEMONVIDEOGAME_COLLISION_H
#define POKEMONVIDEOGAME_COLLISION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "NPC.h"
#include "Player.h"
#include "Graphic.h"
#include "Item.h"

class Collision {

public:
    void collisionNPC(Player &player, std::vector<NPC> &NPCArray);

    void collisionItem(Player &player, std:: vector<Item> &ItemArray, Graphic &graphic);

    void collisionGym(sf::RenderWindow &window, Player &player, Graphic &graphic, vector<Item> &ItemArray);

    void PokemonAttack(Pokemon &pokemon, Bullet &bullet, vector<Bullet> &bulletArray, Player &player, int &adder1, Bullet &effect);

    void BulletCollidesPokemon( Pokemon *pokemon,std:: vector<Bullet> &bulletArray, Bullet &effect,
                                Text &textDisplay, std :: vector<Text> &textArray, float &a);

    void collisionMap(Player &player, std::vector<sf:: RectangleShape> &mapArray);
};
#endif //POKEMONVIDEOGAME_COLLISION_H
