

#ifndef POKEMONVIDEOGAME_GRAPHIC_H
#define POKEMONVIDEOGAME_GRAPHIC_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include "NPC.h"
#include "Player.h"
#include "Item.h"
#include "ElectricPokemon.h"
#include "WaterPokemon.h"
#include "FirePokemon.h"
#include "GraphicPokemon.h"
#include <sstream>


class Graphic {
public:
    Graphic() : bicycle("bicycle"), berry1("cherry berry "), berry2("peach berry"),  pokeball1 ("Megaball"), pokeball2 ("Masterball"),
                NPC1(), NPC2(), gym("Gym") {}

    ~Graphic(){}

    int loadTextures(GraphicPokemon &strategy);

    void setText(Player &player);
    void setNPC();
    void setFont();
    void setItem();

    void setTextAttack(Pokemon *pokemon, Bullet &bullet);
    void setTextHp(Pokemon *pokemon);

    int setBattleText(sf::RenderWindow &window, Player &player);
    int setBackgroundBattle(sf::RenderWindow &window, Player &player);

    int setMusicPlayer();
    int setMusicBattle(Player &player);

    //Music&sound
    sf::Music musicplayer;
    sf::Music musicbattle;
    sf::SoundBuffer bufferShot;
    sf::Sound soundShot;

    sf::Texture textureBattle;
    sf::Sprite spriteBattle;

    sf::Texture textureMap1e;
    sf::Sprite map;

    //Textures
    sf::Texture texturePlayer;
    sf::Texture texturePlayerBike;

    sf::Texture textureNPC1;
    sf::Texture textureNPC2;
    sf::Texture textureNPC3;

    sf::Texture textureBicycle;
    sf::Texture textureBerry1;
    sf::Texture textureBerry2;
    sf::Texture texturePokeball1;
    sf::Texture texturePokeball2;

    sf::Texture textureGym;
    sf:: Text textBattle;

    sf:: Text textBicycle;

    sf:: Sprite options;
    sf::Texture optionsTexture;

    sf:: Sprite attack;
    sf::Texture attackTexture;

    sf:: Text lostText1;
    sf:: Text lostText2;
    sf:: Text attackText;
    sf:: Text hpText;
    sf:: Text hpEnemyText;

    sf:: Sprite attackBackground;
    sf::Texture attackBackgroundTexture;

    sf:: Text enemyTurnText;

    sf:: Sprite win;
    sf::Texture textureWin;

    sf:: Sprite gameOver;
    sf::Texture textureGameOver;

    //NPC
    NPC NPC1;
    NPC NPC2;
    NPC NPC3;

    Item bicycle;
    Item berry1;
    Item berry2;
    Item pokeball1;
    Item pokeball2;

    Item gym;

    const int levelBackground[493] =
            {
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  0,  0,  4,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  4,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  1,  0,  0,  0,  0,  0,  4,  4,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  4,  4,  4,  4,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  4,  1,  1,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  4,  4,  4,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,


            };

    //Texture&Front
    sf::Font font;

};

#endif //POKEMONVIDEOGAME_GRAPHIC_H
