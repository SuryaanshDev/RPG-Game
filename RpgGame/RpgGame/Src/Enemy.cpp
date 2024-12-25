#include "Enemy.h"
#include<iostream>

Enemy::Enemy() :
    health(150)
{
}

Enemy::~Enemy()
{
}

void Enemy::setHealth(int hp)
{

    health += hp;
    healthText.setString(std::to_string(health));
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::Initialize()
{

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(32, 32);
}

void Enemy::Load()
{

   

    if (!font.loadFromFile("Assets/Fonts/arial.ttf")) {

        std::cerr << "Error!!! can't load font" << std::endl;
    }

    else {

        std::cout << "Font loaded successfully." << std::endl;
        healthText.setFont(font);
        healthText.setCharacterSize(15);
        healthText.setFillColor(sf::Color::Red);

        healthText.setString(std::to_string(health));
    }

    if (!Texture.loadFromFile("Assets/Enemy/enemy.png")) {
        std::cerr << "Error loading enemy texture" << std::endl;
        return;
    }
    Sprite.setTexture(Texture);

    

    int xIndex = 0;
    int yIndex = 2;

    Sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
    Sprite.setPosition(600, 300);

    Sprite.scale(sf::Vector2f(1.3, 1.3));

    boundingRectangle.setSize(sf::Vector2f(size.x * Sprite.getScale().x, size.y * Sprite.getScale().y));
    boundingRectangle.setPosition(Sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
    if (health > 0) {

        window.draw(Sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}

void Enemy::Update(double deltaTime)
{
    healthText.setPosition(Sprite.getPosition());
}
