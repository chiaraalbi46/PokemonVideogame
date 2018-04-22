//
//
//

#ifndef POKEMONVIDEOGAME_BULLET_H
#define POKEMONVIDEOGAME_BULLET_H



class Bullet {
    public:
    int getDirection()  {
        return direction;
    }

    void setDirection(int direction) {
        Bullet::direction = direction;
    }

    float getPosX()  {
        return posX;
    }

    void setPosX(float posX) {
        Bullet::posX = posX;
    }

    float getPosY() {
        return posY;
    }

    void setPosY(float posY) {
        Bullet::posY = posY;
    }

private:
    float posX;
    float posY;
    int direction;
};


#endif //POKEMONVIDEOGAME_BULLET_H
