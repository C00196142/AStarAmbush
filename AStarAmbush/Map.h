#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "TextureLoader.h"


using namespace std;

class Map
{
public:
	Map() { width = 30; height = 30; };
	~Map() {};

	void init(TextureLoader * t, SDL_Renderer * render);
	void Renderer(SDL_Renderer * render);
	void RenderLevel(SDL_Texture * texture, SDL_Renderer * render);
	void Obstacles();

private:
	vector<vector<int>> World;
	int width;
	int height;
	TextureLoader* textureLoader;
	SDL_Rect tilePos;
};

