

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Collision.h"

Player player;

Graphic graphic;
sf::RenderWindow window;
std::vector<Item> itemArray;
PokemonFactory factory;
Pokemon* breloom = factory.createPokemon(PokemonType :: PokemonGrass);
Pokemon* zapdos = factory.createPokemon(PokemonType :: PokemonElectric);
Pokemon* blastoise = factory.createPokemon(PokemonType :: PokemonWater);
Bullet bullet;
std::vector<Bullet> bulletArray;

Bullet effect;
int typeAttack;
int adder1;


Text textDisplay;
vector<Text> textArray;
float a;

Collision collision;

TEST(CollisionTest, CollisionItem){

    graphic.setItem();

    itemArray.push_back(graphic.bicycle);
    player.rect.setPosition(graphic.bicycle.rect.getPosition());

    collision.collisionItem(player, itemArray, graphic);
    ASSERT_EQ("bicycle", itemArray[0].getType());
    ASSERT_EQ(true, player.isBicyclePickUp());

    itemArray.push_back(graphic.medal2);
    player.rect.setPosition(graphic.medal2.rect.getPosition());

    collision.collisionItem(player, itemArray, graphic);
    ASSERT_EQ(1, player.getScore());
    ASSERT_EQ(true, player.pickUp2);
    ASSERT_EQ(true, itemArray[1].isPickedUp());


    itemArray.push_back(graphic.medal6);
    player.rect.setPosition(graphic.medal6.rect.getPosition());

    collision.collisionItem(player, itemArray, graphic);
    ASSERT_EQ(2, player.getScore());
    ASSERT_EQ(true, player.pickUp6);


}

TEST(CollisionTest, CollisionGym){

    std::vector<Item> itemArray1;

    ASSERT_EQ(true, itemArray1.empty());
    player.rect.setPosition(graphic.gym.getPosition());
    player.setDirection(Character::Direction::Up);

    collision.collisionGym(window, player, graphic, itemArray1);
    ASSERT_EQ(true, player.isCollGym());


    itemArray1.push_back(graphic.medal4);
    collision.collisionGym(window, player, graphic, itemArray1);
    ASSERT_EQ(true, player.pass);
    ASSERT_EQ(false, player.moveUp);
}


TEST(CollisionTest, PokemonAttack){

    breloom->direction = 2;
    collision.PokemonAttack(*breloom, bullet, bulletArray, player, adder1, effect);

    ASSERT_EQ(550, effect.rect.getPosition().x);
    ASSERT_EQ(160, effect.rect.getPosition().y);

    ASSERT_EQ(2, bullet.direction);
    ASSERT_EQ(BulletType::BulletGrass, bullet.getType());


    bulletArray.pop_back();
    zapdos->direction = 1;
    collision.PokemonAttack(*zapdos, bullet, bulletArray, player, adder1, effect);

    ASSERT_EQ(50, effect.rect.getPosition().x);
    ASSERT_EQ(160, effect.rect.getPosition().y);

    ASSERT_EQ(1, bullet.direction);
    ASSERT_EQ(BulletType::BulletElectric, bullet.getType());
}

TEST(CollisionTest, BulletCollidesPokemon){

    a = 5.0f;
    typeAttack = 1;
    bulletArray.pop_back();

    FireBullet fireBullet;
    fireBullet.update(typeAttack, adder1);

    fireBullet.rect.setPosition(breloom->rect.getPosition());
    bulletArray.push_back(fireBullet);

    collision.BulletCollidesPokemon(breloom, bulletArray, effect, textDisplay, textArray, a);
    //pokemon d'erba contro bullet di fuoco -> attackDamage + 3
    ASSERT_EQ(13, bulletArray[0].attackDamage);
    ASSERT_EQ(387, breloom->getHp());


    bulletArray.pop_back();
    typeAttack = 2;
    WaterBullet waterBullet;
    waterBullet.update(typeAttack, adder1);

    waterBullet.rect.setPosition(zapdos->rect.getPosition());
    bulletArray.push_back(waterBullet);
    //pokemon elettrico contro bullet d'acqua -> attackDamage - 1
    collision.BulletCollidesPokemon(zapdos, bulletArray, effect, textDisplay, textArray, a);

    ASSERT_EQ(12, bulletArray[0].attackDamage);
    ASSERT_EQ(388, zapdos->getHp());

    bulletArray.pop_back();
    typeAttack = 3;
    ElectricBullet electricBullet;
    electricBullet.update(typeAttack, adder1);

    electricBullet.rect.setPosition(blastoise->rect.getPosition());
    bulletArray.push_back(electricBullet);
    //pokemon d'acqua contro bullet elettrico -> attackDamage + 3
    collision.BulletCollidesPokemon(blastoise, bulletArray, effect, textDisplay, textArray, a);

    ASSERT_EQ(15, bulletArray[0].attackDamage);
    ASSERT_EQ(385, blastoise->getHp());

}

