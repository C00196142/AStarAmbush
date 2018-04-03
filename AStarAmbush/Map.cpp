#include "Map.h"

void Map::init(TextureLoader * texture, SDL_Renderer * render)
{
	//Textures

	if (width && height > 200)
	{
		texture->addTexture("wall", "Assets/32/wall32.png", render);
		texture->addTexture("grass", "Assets/32/grass32.png", render);
		tilePos = { 0,0,32,32 };
	}
	else
	{
		texture->addTexture("wall", "Assets/64/wall64.png", render);
		texture->addTexture("grass", "Assets/64/grass64.png", render);
		tilePos = { 0,0,64,64 };
	}

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
			if (World[i][j] != 1)
			{
				World[i][j] = 2;
			}
		}
	}

	//Obsticles
	Obstacles();

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout << World[i][j];
		}
		cout << endl;
	}
	textureLoader = texture;
}

void Map::Renderer(SDL_Renderer * render)
{
	for (int i = 0; i < World.size(); i++)
	{
		for (int j = 0; j < World.at(i).size(); j++)
		{
			if (width && height > 200)
			{
				tilePos = { 32 * i, 32 * j, 32, 32 };
			}
			else
			{
				tilePos = { 64 * i, 64 * j, 64, 64 };

			}
			if (World.at(j).at(i) == 1)
			{
				RenderLevel(textureLoader->getTexture("wall"), render);
			}
			if (World.at(j).at(i) == 2)
			{
				RenderLevel(textureLoader->getTexture("grass"), render);
			}
		}
	}
}

void Map::RenderLevel(SDL_Texture *texture, SDL_Renderer *render)
{
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_ADD);
	SDL_RenderCopy(render, texture, NULL, &tilePos);
}

void Map::Obstacles()
{
	//Obstacles

	// 3 walls with 1 touching the edge
	if (width == 30 && height == 30)
	{
		for (int i = 0; i < World.size() - 3; i++)
		{
			World[i][height / 6] = 1;

			for (int j = 4; j < World.size() - 4; j++)
			{
				World[j - 2][height / 3] = 1;
				World[j][height / 2] = 1;
			}
		}
	}
}