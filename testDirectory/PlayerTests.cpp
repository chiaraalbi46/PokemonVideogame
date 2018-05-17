
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Player.h"

TEST(PlayerTest, Constructor){

    Player Ash;
    Ash.rect.setSize(sf::Vector2f(32, 40));


    ASSERT_EQ(32, Ash.rect.getSize().x);
    ASSERT_EQ(40, Ash.rect.getSize().y);

    //la posizione di default e' (358, 1740)
    ASSERT_EQ(358, Ash.rect.getPosition().x);
    ASSERT_EQ(1740, Ash.rect.getPosition().y);

    ASSERT_EQ(1, Ash.speed);
    ASSERT_EQ(false, Ash.rideBicycle);
}


