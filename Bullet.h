
#ifndef POKEMONVIDEOGAME_BULLET_H
#define POKEMONVIDEOGAME_BULLET_H

#include <SFML/Graphics.hpp>
using namespace std;

enum class BulletType {BulletWater, BulletFire, BulletElectric, BulletGrass};

class Bullet {
public:
    Bullet(){
        rect.setSize(sf::Vector2f(48, 48));
        rect.setPosition(30, 20);
        rect.setFillColor(sf::Color::Blue);
        loadTexture();
        loadEffectTexture();
        adder = 0;
    }
    const string &getName() const;
    void setName(const string &name);
    void update(int &typeAttack, int& adder1);
    void updateEffects ();

    virtual int loadTexture();
    virtual int loadEffectTexture();

    void setDirection(int direction) {
        Bullet::direction = direction;
    }

    BulletType getType() const;

    //attributi per gli spari
    int counterLifeTime = 0;
    int lifeTime; //"lunghezza" del tratto del proiettile

    int counter = 0;
    int counterAnimation = 0;

    int counterAnimation1 = 0;

    int direction = 0;
    bool isDestroyed = false;
    int attackDamage;

    int adder;

    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Texture attack1Texture;
    sf::Texture attack2Texture;
    sf::Texture attack3Texture;

    sf::Sprite effect1;
    sf::Texture effect1Texture;

protected:
    float movementSpeed = 10;
    string name;
    BulletType type;

};



#endif //POKEMONVIDEOGAME_BULLET_H
