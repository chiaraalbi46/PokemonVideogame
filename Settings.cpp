#include "Settings.h"

int Settings::choosePokemonBattle(sf::RenderWindow &window, int &choosen, GraphicPokemon &graphicPokemon, Player &player) {
/*
    sf::Text textChoosePokemon;
    textChoosePokemon.setString("Choose 3 Pokemon");
    textChoosePokemon.setFont(graphicPokemon.font);
    textChoosePokemon.setFillColor(sf:: Color:: Black  );
    textChoosePokemon.setCharacterSize(30);
    textChoosePokemon.setPosition(5, 5);
    window.draw(textChoosePokemon);
*/


    sf::Event event;
    while (true) {

        while (window.pollEvent(event)) {

            if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 224 &&
                sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 253 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 0;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 451 && sf::Mouse::getPosition(window).x < 674 &&
                     sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 253 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 1;

                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 224 &&
                     sf::Mouse::getPosition(window).y > 255 && sf::Mouse::getPosition(window).y < 507 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 3;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 451 && sf::Mouse::getPosition(window).x < 674 &&
                     sf::Mouse::getPosition(window).y > 255 && sf::Mouse::getPosition(window).y < 507 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 2;
                return 0;
            }                //Blastoise
            else if (sf::Mouse::getPosition(window).x > 226 && sf::Mouse::getPosition(window).x < 449 &&
                     sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 253 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                choosen = 4;
                return 0;
            }                //Rapidash
            else if (sf::Mouse::getPosition(window).x > 676 && sf::Mouse::getPosition(window).x < 900 &&
                     sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < 253 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                choosen = 5;
                return 0;
            }

                //Zapdos
            else if (sf::Mouse::getPosition(window).x > 676 && sf::Mouse::getPosition(window).x < 900 &&
                     sf::Mouse::getPosition(window).y > 255 && sf::Mouse::getPosition(window).y < 507 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                choosen = 6;
                return 0;
            }

                //Bulbasaur
            else if (sf::Mouse::getPosition(window).x > 226 && sf::Mouse::getPosition(window).x < 449 &&
                     sf::Mouse::getPosition(window).y > 255 && sf::Mouse::getPosition(window).y < 507 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                choosen = 7;
                return 0;
            }



        }
        window.draw(graphicPokemon.spritePokemon);
        if(player.click0) {
            graphicPokemon.spriteCheck.setPosition(0, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click1) {
            graphicPokemon.spriteCheck.setPosition(451, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click2) {
            graphicPokemon.spriteCheck.setPosition(451, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click3) {
            graphicPokemon.spriteCheck.setPosition(0, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click4) {
            graphicPokemon.spriteCheck.setPosition(226, 0); //blastoise
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click5) {
            graphicPokemon.spriteCheck.setPosition(676, 0);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click6) {
            graphicPokemon.spriteCheck.setPosition(676, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        if(player.click7) {
            graphicPokemon.spriteCheck.setPosition(226, 255);
            window.draw(graphicPokemon.spriteCheck);
        }
        window.display();
    }
}

int Settings::choosePokemon(sf::RenderWindow &window, int &choosen2, std::vector<Pokemon*> PokemonArray, GraphicPokemon &graphicPokemon,Player &player) {
    if(player.isSelect()) {
        int counterPok = 0;
        int pos = 0;
        for (auto iter3 = PokemonArray.begin(); iter3 != PokemonArray.end(); iter3++) {
            PokemonArray[counterPok]->updateDirection(player);
            PokemonArray[counterPok]->sprite.setPosition(10, 10 + pos);
            window.draw(PokemonArray[counterPok]->sprite);
            counterPok++;
            pos = pos + 50;
        }
        window.display();
    }

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 163 &&
                sf::Mouse::getPosition(window).y > 20 && sf::Mouse::getPosition(window).y < 60 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen2 = 0;
                player.setSelect(false);
                player.pokemon0 = true;
                player.pokemon1 = false;
                player.pokemon2 = false;
                player.pokemon3 = false;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 163 &&
                     sf::Mouse::getPosition(window).y > 70 && sf::Mouse::getPosition(window).y < 110 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen2 = 1;
                player.setSelect(false);
                player.pokemon0 = false;
                player.pokemon1 = true;
                player.pokemon2 = false;
                player.pokemon3 = false;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 163 &&
                     sf::Mouse::getPosition(window).y > 130 && sf::Mouse::getPosition(window).y < 170 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                player.setSelect(false);
                player.pokemon0 = false;
                player.pokemon1 = false;
                player.pokemon2 = true;
                player.pokemon3 = false;
                choosen2 = 2;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 163 &&
                     sf::Mouse::getPosition(window).y > 140 && sf::Mouse::getPosition(window).y < 180 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen2 = 3;
                player.setSelect(false);

                player.pokemon0 = false;
                player.pokemon1 = false;
                player.pokemon2 = false;
                player.pokemon3 = true;

                return 0;
            }
        }
    }
}

int Settings :: menu(sf::RenderWindow &window, int &press, Player &player) {
    sf:: Texture textureMenu;
    sf:: Sprite spriteMenu;
    if (!textureMenu.loadFromFile("../Risorse/menu.png")) {
        return EXIT_FAILURE;
    }
    spriteMenu.setTexture(textureMenu);
    spriteMenu.setPosition(0, 0);
    sf:: Sprite triangle;
    sf:: Texture textureTriangle;

    if (!textureTriangle.loadFromFile("../Risorse/triangle.png")) {
        return EXIT_FAILURE;
    }
    triangle.setTexture(textureTriangle);
    triangle.setPosition(220, 160);


    sf::Event event;
    while (true) {

        while (window.pollEvent(event)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.one) {
                press = 0;
                return 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.two) {
                press = 1;
                return 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.three) {
                press = 2;
                return 0;
            }
        }
        window.clear();
        window.draw(spriteMenu);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Up)){
            triangle.setPosition(220, 160);
            player.one = true;
            player.two = false;
            player.triangle1 = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Down) &&  (triangle.getPosition().y == 160) && !player.triangle1 ){
            triangle.setPosition(220, 260);
            player.two = true;
            player.one = false;
            player.three = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard:: Down)){
            triangle.setPosition(220, 360);
            player.three = true;
            player.two = false;
        }
        window.draw(triangle);
        // player.triangle1 = true;
        window.display();
    }
}

int Settings::options(sf::RenderWindow &window, Player &player, Graphic &graphic) {
    window.clear();
    window.draw(graphic.controls);
    window.draw(graphic.textControls);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.one = true;
                player.two = false;
                return 0;
            }
        }
    }

}

int Settings::credits(sf::RenderWindow &window, Player &player, Graphic &graphic) {
    window.clear();
    window.draw(graphic.controls);
    window.draw(graphic.textControls);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.one = true;
                player.three = false;
                return 0;
            }
        }
    }
}

int Settings::start1(sf::RenderWindow &window, Player &player, Graphic &graphic) {
    window.clear();
    window.draw(graphic.start1);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.start1) {
                return 0;
            }
        }
        player.start1 = true;
    }
}

int Settings::start2(sf::RenderWindow &window, Player &player, Graphic &graphic) {
    window.clear();
    window.draw(graphic.start2);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.start2) {
                return 0;
            }
        }
        player.start2= true;
    }
}

int Settings::start3(sf::RenderWindow &window, Player &player, Graphic &graphic) {
    window.clear();
    window.draw(graphic.start3);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.start3) {
                return 0;
            }
        }
        player.start3= true;
    }
}