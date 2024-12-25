#include "Map.h"
#include<iostream>

Map::Map() :
	totalTiles(0), tileHeight(16), tileWidth(16), totalTilesX(0), totalTilesY(0),
	mapWidth(10), mapHeight(8), tiles(nullptr)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{

	if (!tileSheetTexture.loadFromFile("Assets/Maps/full tilemap.png")) {

		std::cerr << "Error loading tilesheet." << std::endl;
	}

	else {

		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;

		std::cout << "TileX: " << totalTilesX << std::endl;
		std::cout << "TileY: " << totalTilesY << std::endl;

		std::cout << "Tilesheet loaded successfully.";
		
		totalTiles = totalTilesX * totalTilesY;
		
		tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTilesY; y++) {

			for (int x = 0; x < totalTilesX; x++) {

				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
			}
		}
	}

	for (size_t y = 0; y < mapHeight; y++) {

		for (size_t x = 0; x < mapWidth; x++) {

			int i = x + y * 10;

			int index = mapNumbers[i];

			mapSprites[i].setTexture(tileSheetTexture);
			mapSprites[i].setTextureRect(sf::IntRect(
				tiles[index].position.x,
				tiles[index].position.y,
				tileWidth,
				tileHeight
			));
			mapSprites[i].setScale(sf::Vector2f(5,5));
			mapSprites[i].setPosition(sf::Vector2f(x * tileWidth * mapSprites[i].getScale().x,
				y * tileHeight * mapSprites[i].getScale().y));
		}
	}
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow &window)
{

	for (size_t i = 0; i < mapSize; i++) {
			
		window.draw(mapSprites[i]);
	}
}