

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
    Graphic() : bicycle("bicycle"), medal1("medal1"), medal2("medal2"), medal3("medal3"), medal4("medal4"), medal5("medal5"), medal6("medal6") ,
                medal7("medal7") , medal8("medal8"), NPC1(), NPC2() {}

    ~Graphic(){}

    int loadTextures(GraphicPokemon &strategy);

    int setText(Player &player, std:: vector<Item> &ItemArray);
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

    sf::SoundBuffer bufferItem;
    sf::Sound soundItem;

    //Textures&texts&sprites
    sf::Sprite controls;
    sf:: Texture textureControls;
    sf::Text textControls;

    sf::Sprite credits;
    sf:: Texture textureCredits;

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

    sf::Texture texturePlayer;
    sf::Texture texturePlayerBike;

    sf::Texture textureNPC1;
    sf::Texture textureNPC2;

    sf::Texture textureBicycle;
    sf::Texture textureMedal;
    sf::Texture textureMedal1;
    sf::Texture textureMedal2;
    sf::Texture textureMedal3;
    sf::Texture textureMedal4;
    sf::Texture textureMedal5;
    sf::Texture textureMedal6;
    sf::Texture textureMedal7;
    sf::Texture textureMedal8;

    sf:: Texture textureMedalPickUp1;
    sf:: Texture textureMedalPickUp2;
    sf:: Texture textureMedalPickUp3;
    sf:: Texture textureMedalPickUp4;
    sf:: Texture textureMedalPickUp5;
    sf:: Texture textureMedalPickUp6;
    sf:: Texture textureMedalPickUp7;
    sf:: Texture textureMedalPickUp8;

    sf::Texture texturePrebattle;
    sf:: Sprite prebattle;

    sf::Sprite medal;
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

    sf:: Text medalsText;

    sf::Sprite medalPickUp1;
    sf::Sprite medalPickUp2;
    sf::Sprite medalPickUp3;
    sf::Sprite medalPickUp4;
    sf::Sprite medalPickUp5;
    sf::Sprite medalPickUp6;
    sf::Sprite medalPickUp7;
    sf::Sprite medalPickUp8;

    //NPC
    NPC NPC1;
    NPC NPC2;

    //Item
    Item bicycle;
    Item medal1;
    Item medal2;
    Item medal3;
    Item medal4;
    Item medal5;
    Item medal6;
    Item medal7;
    Item medal8;

    //Front
    sf::Font font;

};
#endif //POKEMONVIDEOGAME_GRAPHIC_H
