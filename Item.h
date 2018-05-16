

#ifndef POKEMONVIDEOGAME_ITEM_H
#define POKEMONVIDEOGAME_ITEM_H

#include <SFML/Graphics.hpp>

class Item {

public:

    Item(std:: string type ): type(type) {
        rect.setSize(sf::Vector2f(64, 64));
    }

    ~Item() {}

    void update();

    sf::Sprite sprite;
    sf::RectangleShape rect;

    int medalValue = 1;

    bool isPickedUp() const {
        return pickedUp;
    }

    void setPickedUp(bool pickedUp) {
        Item::pickedUp = pickedUp;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        Item::type = type;
    }

protected:
    std::string type;
    bool pickedUp = false;
};



#endif //POKEMONVIDEOGAME_ITEM_H
