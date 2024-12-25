#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
private:
	sf::Texture Texture;
	sf::RectangleShape boundingRectangle;

	sf::Text healthText;
	sf::Font font;

	int health;

	sf::Vector2i size;	

public:
	sf::Sprite Sprite;


public:
	Enemy();
	~Enemy();

	void setHealth(int hp);

	int getHealth();

	void Initialize();
	void Load();

	void Draw(sf::RenderWindow& window);
	void Update(double deltaTime);
};

