

#ifndef POKEMONVIDEOGAME_PLAYER_H
#define POKEMONVIDEOGAME_PLAYER_H

#include "Character.h"
#include "Item.h"



class Player: public Character {
public:

    Player() : Character() {
        rect.setSize(sf::Vector2f(25, 30));
        rect.setPosition(420, 300);
        rect.setFillColor(sf::Color::Transparent);
        sprite.setTextureRect(sf::IntRect(0, counterWalking1 * 30, 28, 30));
    }

    ~Player() {}

    void update();

    void move() override;

    int getScore() const;
    int increaseScore(int value);

    bool isBicyclePickUp() const;
    void setBicyclePickUp(bool bicyclePickUp);

    bool isCollGym() const;
    void setCollGym(bool collGym);

    bool isEnterGym() const;
    void setEnterGym(bool enterGym);

    bool isSelect() const;
    void setSelect(bool select);

    bool isSelectAttack() const;
    void setSelectAttack(bool selectAttack);

    bool isEnemy() const;
    void setEnemy(bool enemy);

    bool isEnemyTurn() const;
    void setEnemyTurn(bool enemyTurn);

    bool isAttack() const;
    void setAttack(bool attack);

    int vel = 0; // velocità collisione

    bool rideBicycle = false;
    int score = 0;

    bool pokemon0 = true;
    bool pokemon1 = false;
    bool pokemon2 = false;
    bool pokemon3 = false;

    bool enemy0 = false;
    bool enemy1 = false;
    bool enemy2 = false;
    bool enemy3 = false;

    bool click0 = false;
    bool click1 = false;
    bool click2 = false;
    bool click3 = false;
    bool click4 = false;
    bool click5 = false;
    bool click6 = false;
    bool click7 = false;

    bool enemyAttack = false;   // Fa attaccare nemico

    bool options = true;

    bool isCambio() const;
    void setCambio(bool cambio);

    bool isFight() const;
    void setFight(bool fight);

    bool isGameRestart() const;
    void setGameRestart(bool gameRestart);

    bool textBicycle = false;

    bool textLost1 = false;
    bool textLost2 = false;

    bool playing = false;
    bool fighting = false;
protected:
    bool fight = true;
    bool gameRestart = false;
    bool cambio = true;    // cambia pokemon quando muore un altro
    int speed = 1;
    bool bicyclePickUp = false;
    bool collGym = false;
    bool enterGym = false;      // Entra o no in palestra
    bool select = false;        // Seleziona pokemon
    bool selectAttack = false;  // scelgo il mio attacco
    bool attack = false;        // il mio pokemon attacca
    bool enemy = false;         // E' il nemico
    bool enemyTurn = false;

};

#endif //POKEMONVIDEOGAME_PLAYER_H
