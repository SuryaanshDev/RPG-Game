#include<SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<math.h>
#include"Player.h"
#include"Enemy.h"
#include"Map.h"
#include"FrameRate.h"
#include "MapLoader.h"

int main() {
    //---------------------------Initialise--------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 640), "RPG Game", sf::Style::Close, settings);

    /*window.setVerticalSyncEnabled(true);*/
    window.setFramerateLimit(60);

    FrameRate frameRate;
    
    Map map;

    frameRate.Initialize();

    MapLoader mapLoader;
    mapLoader.Load("Assets/Maps/Level1.map.txt");
    //---------------------------Initialise--------------------------//

    map.Initialize();

    //----------------------------Enemy Texture-------------------------------//      
    Enemy enemy1;
    enemy1.Initialize();
    //----------------------------Enemy Texture-------------------------------//

    //---------------------------Player Texture-------------------------------//
    Player player1;
    player1.Initialize();
    //----------------------------Player Texture------------------------------//

    //------------------------------Load--------------------------------------//
    map.Load();
    enemy1.Load();
    player1.Load();
    frameRate.Load();      
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

        map.Update(deltaTime);  

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        player1.Update(deltaTime, enemy1, mousePosition);
        enemy1.Update(deltaTime);
        frameRate.Update(deltaTime);
        //-----------------------Update---------------------------//

        //------------------------Draw----------------------------//
        window.clear(sf::Color::Black);

        map.Draw(window);
        player1.Draw(window);
        enemy1.Draw(window);
        frameRate.Draw(window);
        window.display();
        //------------------------Draw----------------------------//
    }

    return 0;
}
