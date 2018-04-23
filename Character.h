//
//
//

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

    const std:: string &getName() const;
    void setName(const std:: string &name);

    sf::RectangleShape rect;
    sf::Sprite sprite;

    sf::Text text;

    bool moveLeft = true;
    bool moveRight = true;
    bool moveUp = true;
    bool moveDown = true;


protected:
    std::string name;

    Direction direction = Direction::Down;
    int counterWalking = 0;
    int counterWalking1 = 0;
    int counterWalking2 = 0;




};


#endif //POKEMONVIDEOGAME_CHARACTER_H
