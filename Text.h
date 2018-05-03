
#ifndef POKEMONVIDEOGAME_TEXT_H
#define POKEMONVIDEOGAME_TEXT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Text {
public:
    sf::Text text;
    float movementSpeed = 45;
    int counter = 0;
    int lifeTime = 3;
    bool isDestroyed = false;

    Text();
    void update();

};


#endif //POKEMONVIDEOGAME_TEXT_H
