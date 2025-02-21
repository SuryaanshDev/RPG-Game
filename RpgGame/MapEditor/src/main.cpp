#include<SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<math.h>
#include"Grid.h"
#include"MouseTile.h"

int main() {
    //---------------------------Initialise--------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(802, 642), "Map Editor", sf::Style::Close, settings);

    /*window.setVerticalSyncEnabled(true);*/
    window.setFramerateLimit(60);

    Grid grid(
        sf::Vector2f(0, 0),
        sf::Vector2f(5, 5),
        sf::Vector2f(10, 8),
        sf::Vector2f(16, 16),
        2,
        sf::Color(255, 255, 255, 128));

    MouseTile mouseTile(sf::Vector2i(16,16), sf::Vector2f(5, 5));
    //---------------------------Initialise--------------------------//

    grid.Initialize();
    mouseTile.Initialize();
    //---------------------------Initialise--------------------------//

    //------------------------------Load--------------------------------------//
        
    grid.Load();
    mouseTile.Load();
    //------------------------------Load--------------------------------------//

    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMilliseconds();

        //-----------------------Update----------------------------//
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        grid.Update(deltaTime);
        mouseTile.Update(deltaTime, mousePosition);
        //-----------------------Update---------------------------//

        //------------------------Draw----------------------------//
        window.clear(sf::Color::Black);
        mouseTile.Draw(window);
        grid.Draw(window);
        window.display();
        //------------------------Draw----------------------------//
    }

    return 0;
}
