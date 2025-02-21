#include "MouseTile.h"

MouseTile::MouseTile(const sf::Vector2i& tileSize, const sf::Vector2f& tileScale) :
	m_tileSize(tileSize), m_scale(tileScale)
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
	tile.setTextureRect(sf::IntRect(3 * m_tileSize.x, 1 * m_tileSize.x, m_tileSize.x, m_tileSize.y));
	tile.setScale(m_scale);
}

void MouseTile::Update(double& deltaTime, sf::Vector2f& mousePosition)
{
	int x = (mousePosition.x / (m_tileSize.x * tile.getScale().x));
	int xx = x * (m_tileSize.x * tile.getScale().x);

	int y = (mousePosition.y / (m_tileSize.y * tile.getScale().y));
	int yy = y * (m_tileSize.y * tile.getScale().y);

	tile.setPosition(sf::Vector2f(xx, yy));
}

void MouseTile::Draw(sf::RenderWindow& window)
{

	window.draw(tile);
}
