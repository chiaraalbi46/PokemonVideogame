

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
    Graphic() : bicycle("bicycle"), medal1("medal"), medal2("medal"), medal3("medal"), medal4("medal"), medal5("medal"), medal6("medal") ,
                medal7("medal") , medal8("medal") , pokeball1 ("Megaball"), pokeball2 ("Masterball"), NPC1(), NPC2() {}

    ~Graphic(){}

    int loadTextures(GraphicPokemon &strategy);

    void setText(Player &player);
    void setNPC();
    void setFont();
    void setItem();

    void setTextAttack(Pokemon *pokemon, Bullet &bullet);
    void setTextHp(Pokemon *pokemon);
    void setMenu();
    int setBattleText(sf::RenderWindow &window, Player &player);
    int setBackgroundBattle(sf::RenderWindow &window, Player &player);

    int setMusicBattle(Player &player);

    //Music&sound
    sf::Music musicplayer;
    sf::Music musicbattle;

    sf::SoundBuffer bufferShot;
    sf::Sound soundShot;

    sf::SoundBuffer bufferItem;
    sf::Sound soundItem;

    sf::Sprite controls;
    sf:: Texture textureControls;
    sf::Text textControls;

    sf:: Sprite start1;
    sf:: Sprite start2;
    sf:: Sprite start3;

    sf:: Texture textureStart1;
    sf:: Texture textureStart2;
    sf:: Texture textureStart3;

    sf::Texture textureBattle;
    sf::Sprite spriteBattle;

    sf::Texture textureMap1e;
    sf::Sprite map;

    sf:: Text textBicycle;

    //Textures
    sf::Texture texturePlayer;
    sf::Texture texturePlayerBike;

    sf::Texture textureNPC1;
    sf::Texture textureNPC2;
    sf::Texture textureNPC3;

    sf::Texture textureBicycle;
    sf::Texture textureMedal1;
    sf::Texture textureMedal2;
    sf::Texture textureMedal3;
    sf::Texture textureMedal4;
    sf::Texture textureMedal5;
    sf::Texture textureMedal6;
    sf::Texture textureMedal7;
    sf::Texture textureMedal8;
    sf::Texture texturePokeball1;
    sf::Texture texturePokeball2;

    sf::Texture texturePrebattle;
    sf:: Sprite prebattle;

    sf::RectangleShape gym;
    sf:: Text textBattle;

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

    sf:: Text restart;
    //NPC
    NPC NPC1;
    NPC NPC2;
    NPC NPC3;

    Item bicycle;
    Item medal1;
    Item medal2;
    Item medal3;
    Item medal4;
    Item medal5;
    Item medal6;
    Item medal7;
    Item medal8;
    Item pokeball1;
    Item pokeball2;

    //Texture&Front
    sf::Font font;

};
#endif //POKEMONVIDEOGAME_GRAPHIC_H
