#pragma once
#include<SFML/Graphics.hpp>

class MouseTile
{
private:

	sf::Texture tileSheet;
	sf::Sprite tile;
	sf::Vector2i m_tileSize;
	sf::Vector2f m_scale;

public:
	MouseTile(const sf::Vector2i& tileSize, const sf::Vector2f& tileScale);
	~MouseTile();

	void Initialize();
	void Load();
	void Update(double& deltaTime, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};

