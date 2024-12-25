#include "FrameRate.h"
#include<iostream>
#include<SFML/Graphics.hpp>

FrameRate::FrameRate() :
    timer(0)
{

}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
    
}

void FrameRate::Load()
{
    if (!font.loadFromFile("Assets/Fonts/arial.ttf")) {

        std::cerr << "Error!!! can't load font" << std::endl;
    }

    else {

        std::cout << "Font loaded successfully." << std::endl;
        frameRateText.setFont(font);
        frameRateText.setCharacterSize(20);
        frameRateText.setFillColor(sf::Color::Red);
    }
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}

void FrameRate::Update(float deltaTime)
{

    timer += deltaTime;
    if (timer >= 100.0f) {
     
        float fps = 1000.f / deltaTime;

        std::string frameRateString = "FPS: " + std::to_string(int(fps));

        frameRateText.setString(frameRateString);

        timer = 0;
    }
}
