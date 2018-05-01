//
// Created by Niki on 01/05/2018.
//

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