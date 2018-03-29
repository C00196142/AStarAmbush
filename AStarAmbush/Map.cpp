#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::init()
{
	World.resize(width);
	for (int i = 0; i < width; i++)
	{
		World[i].resize(height);
	}

	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			World[i][j] = 0;
		}
	}
	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			std::cout << World[i][j];
		}
		cout << endl;
	}
}
