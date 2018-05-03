
#ifndef POKEMONVIDEOGAME_TEXT_H
#define POKEMONVIDEOGAME_TEXT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Text {
public:
    sf::Text text;
    float movementSpeed = 2.0f;
    int counter = 0;
    int lifeTime = 40;
    bool isDestroyed = false;

    Text();
    void update();

};


#endif //POKEMONVIDEOGAME_TEXT_H
