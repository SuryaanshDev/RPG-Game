#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Bullet.h"
#include"Enemy.h"

class Player
{
private:

	sf::Texture Texture;
	std::vector<Bullet> bullets;
	
	float maxFireRate;
	float fireRateTimer;

	sf::Vector2f bulletDirection;

	float playerSpeed = 0.09f;

	sf::RectangleShape boundingRectangle;

	float width = 32;
	float height = 32;

	sf::Vector2i size;

public:
	sf::Sprite Sprite;

public:

	Player();
	~Player();
	void Initialize();
	void Load();

	void Update(double deltaTime, Enemy& enemy1, sf::Vector2f &mousePosition);
	void Draw(sf::RenderWindow& window);
};

