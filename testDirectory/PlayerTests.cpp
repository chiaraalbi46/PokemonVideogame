
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Player.h"

TEST(PlayerTest, Constructor){

    Player Ash;
    Ash.rect.setSize(sf::Vector2f(32, 40));


    ASSERT_EQ(32, Ash.rect.getSize().x);
    ASSERT_EQ(40, Ash.rect.getSize().y);

    //la posizione di default e' (450, 1605)
    ASSERT_EQ(450, Ash.rect.getPosition().x);
    ASSERT_EQ(1605, Ash.rect.getPosition().y);

    ASSERT_EQ(1, Ash.speed);
    ASSERT_EQ(false, Ash.rideBicycle);
}


