
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
            }

                //Rapidash
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

