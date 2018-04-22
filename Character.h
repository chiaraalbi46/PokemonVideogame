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

    bool isMoveRight() const;
    void setMoveRight(bool moveRight);

    bool isMoveDown() const;
    void setMoveDown(bool moveDown);

    bool isMoveLeft() const;
    void setMoveLeft(bool moveLeft);

    bool isMoveUp() const;
    void setMoveUp(bool moveUp);

    float getSpeed() const;
    void setSpeed(float speed);

    Direction getDirection() const;
    void setDirection(Direction direction);

    const std:: string &getName() const;
    void setName(const std:: string &name);

    sf::RectangleShape rect;
    sf::Sprite sprite;

    sf::Text textScore;


protected:
    std::string name;
    float speed = 1;
    bool moveLeft = true;
    bool moveRight = true;
    bool moveUp = true;
    bool moveDown = true;
    Direction direction = Direction::Down;
    int counterWalking = 0;
    int counter = 0;




};


#endif //POKEMONVIDEOGAME_CHARACTER_H
