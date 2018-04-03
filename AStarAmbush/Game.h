#pragma once

#include "InputManager.h"
#include "GameTime.h"
#include <Windows.h>
#include <iostream>
#include "Map.h"
#include "TextureLoader.h"

const float GameTick = 0.2f;

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* gameRenderer = nullptr;
	bool gameRunning;
	SDL_Event m_event;

	EventListener * eventListener;
	InputHandler * input;
	TextureLoader* texture;
	Map * map;

	float lastUpdate = 0.0f;
	float currentUpdate = 0.0f;
	GameTime* gameTime;

};

