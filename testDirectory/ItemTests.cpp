

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Item.h"
#include "../Graphic.h"

TEST(ItemTest, Constructor){

    Item bycicle("bycicle");
    bycicle.rect.setSize(sf::Vector2f(30, 50));

    ASSERT_EQ("bycicle", bycicle.getType());
    ASSERT_EQ(30, bycicle.rect.getSize().x);
    ASSERT_EQ(50, bycicle.rect.getSize().y);

    Item medal6("medal6");
    medal6.rect.setPosition(561, 1318);

    ASSERT_EQ("medal6", medal6.getType());
    ASSERT_EQ(561, medal6.rect.getPosition().x);
    ASSERT_EQ(1318, medal6.rect.getPosition().y);

}

TEST(ItemTest, Update){

    Item medal1("medal1");
    medal1.rect.setPosition(40, 60);
    medal1.update();

    ASSERT_EQ(medal1.rect.getPosition().x, medal1.sprite.getPosition().x);
    ASSERT_EQ(medal1.rect.getPosition().y, medal1.sprite.getPosition().y);
}

