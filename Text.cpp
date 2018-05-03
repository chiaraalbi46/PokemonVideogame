

#include "Text.h"

Text::Text() {
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(20);
}

void Text::update() {
    text.move(0, -movementSpeed);
    counter++;
    if(counter >= lifeTime)
        isDestroyed = true;
}