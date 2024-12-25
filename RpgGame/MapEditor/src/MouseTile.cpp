#include "MouseTile.h"

MouseTile::MouseTile()
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{

	tileSheet.loadFromFile("Assets/Maps/full tilemap.png");
	tile.setTexture(tileSheet);
	tile.setTextureRect(sf::IntRect(3 * 16, 1 * 16, 16, 16));
	tile.setScale(sf::Vector2f(5, 5));
}

void MouseTile::Update(double& deltaTime, sf::Vector2f& mousePosition)
{
	tile.setPosition(mousePosition + sf::Vector2f(-40, -40));
}

void MouseTile::Draw(sf::RenderWindow& window)
{

	window.draw(tile);
}
