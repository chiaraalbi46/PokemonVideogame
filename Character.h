

#ifndef POKEMONVIDEOGAME_CHARACTER_H
#define POKEMONVIDEOGAME_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Character {
public:

    enum class Direction {
        Up, Down, Left, Right
    };

    Character() {}

    virtual ~Character() {}

    virtual void move () = 0;

    Direction getDirection() const;
    void setDirection(Direction direction);

    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf:: Text text;

    int counterWalking = 0;

    bool moveLeft = true;
    bool moveRight = true;
    bool moveUp = true;
    bool moveDown = true;

protected:
    Direction direction = Direction::Down;
    int counterWalking1 = 0;

};



#endif //POKEMONVIDEOGAME_CHARACTER_H
