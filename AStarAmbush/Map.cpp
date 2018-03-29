#include "Map.h"

void Map::init()
{
	World.resize(width);
	for (int i = 0; i < width; i++)
	{
		World[i].resize(height);
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			World[0][i] = 1;
			World[i][0] = 1;
			World[j][height - 1] = 1;
			World[width - 1][j] = 1;
		}
	}


	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout << World[i][j];
		}
		cout << endl;
	}
}

void Map::Render()
{
	
}