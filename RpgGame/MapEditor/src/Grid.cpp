#include "Grid.h"

Grid::Grid(
	const sf::Vector2f& position,
	const sf::Vector2f& scale,
	const sf::Vector2f& totalCells,
	const sf::Vector2f& cellSize,
	int lineThickness,
	const sf::Color& gridColor) :

	m_position(position), m_scale(scale), m_totalCells(totalCells), m_cellSize(cellSize),
	m_lineThickness(lineThickness), m_gridColor(gridColor)
{
	m_totalLines = sf::Vector2i(1 + totalCells.x, 1 + totalCells.y);
	m_hLine = new sf::RectangleShape[m_totalLines.y];
	m_vLine = new sf::RectangleShape[m_totalLines.x];
}

Grid::~Grid()
{

	delete[] m_hLine;
	delete[] m_vLine;
}

void Grid::Initialize()
{
	/*Here extra lineThickness is added in the end of the horizontalLineLength
	to complete the grid*/

	int horizontalLineLength = m_totalCells.x * m_cellSize.x * m_scale.x + m_lineThickness;
	int verticalLineLength = m_totalCells.y * m_cellSize.y * m_scale.y;

	for (size_t i = 0; i < m_totalLines.y; i++)
	{
		m_hLine[i].setSize(sf::Vector2f(horizontalLineLength, m_lineThickness));
		m_hLine[i].setPosition(m_position + sf::Vector2f(0, i * m_cellSize.y * m_scale.y));
		m_hLine[i].setFillColor(m_gridColor);
	}

	for (size_t i = 0; i < m_totalLines.x; i++)
	{
		m_vLine[i].setSize(sf::Vector2f(m_lineThickness, verticalLineLength));
		m_vLine[i].setPosition(m_position + sf::Vector2f(i * m_cellSize.x * m_scale.x, 0));
		m_vLine[i].setFillColor(m_gridColor);
	}

	/*vLine.setSize(sf::Vector2f(lineThickness, verticalLineLength));
	vLine.setPosition(postion);*/	
}

void Grid::Load()
{
}

void Grid::Update(double deltaTime)
{
}


void Grid::Draw(sf::RenderWindow& window)
{

	for (size_t i = 0; i < m_totalLines.y; i++)
	{
		window.draw(m_hLine[i]);
	}

	for (size_t i = 0; i < m_totalLines.x; i++)
	{
		window.draw(m_vLine[i]);
	}
}
