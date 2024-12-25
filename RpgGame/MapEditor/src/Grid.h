#pragma once
#include<SFML/Graphics.hpp>

class Grid
{
private:

	sf::RectangleShape* m_hLine;
	sf::RectangleShape* m_vLine;

	sf::Vector2f m_position;
	sf::Vector2i m_scale;
	sf::Vector2i m_totalCells;
	sf::Vector2i m_cellSize;
	sf::Color m_gridColor;

	sf::Vector2i m_totalLines;

	int m_lineThickness;

public:
		
	Grid(const sf::Vector2f& position,
		const sf::Vector2f& scale,
		const sf::Vector2f& totalCells,
		const sf::Vector2f& cellSize,
		int lineThickness,
		const sf::Color& gridColor);
	~Grid();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow &window);
};

