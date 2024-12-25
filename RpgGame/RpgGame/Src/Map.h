#pragma once
#include<SFML/Graphics.hpp>
#include"Tile.h"


class Map
{
private:

	sf::Sprite sprite;
	sf::Texture tileSheetTexture;

	Tile* tiles = nullptr;

	int tileWidth;
	int tileHeight;

	int totalTilesY;
	int totalTilesX;

	int totalTiles;

	int mapWidth;
	int mapHeight;

	static const int mapSize = 80;

	int mapNumbers[mapSize] = {	12, 12, 12, 12, 12, 12,
							    12, 12, 12, 12, 23, 23,
							    23, 23, 23, 23, 23, 23, 
							    23, 23, 23, 23, 23, 23,
							    23, 23, 23, 23, 23, 23,
							    23, 23, 23, 23, 23, 23,
							    23, 23, 23, 23, 23, 23,
								23, 23, 23, 23, 23, 23,
								23, 23, 23, 23, 23, 23,
								23, 23, 23, 23, 23, 23,
								23, 23, 23, 23, 23, 23,
								23, 23, 23, 23, 12, 12,
								12, 12, 12, 12, 12, 12,
								12, 12
					};

	sf::Sprite mapSprites[mapSize];

public:

	Map();
	~Map();

	void Initialize();
	void Load();

	void Update(double deltaTime);
	void Draw(sf::RenderWindow &window);
};

