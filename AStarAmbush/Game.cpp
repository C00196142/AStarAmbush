#include "Game.h"
Game::Game()
{
	gameRunning = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	
	window = SDL_CreateWindow("AStarAmbush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(gameRenderer, SDL_BLENDMODE_BLEND);

	//Game Loop
	gameTime->getInstance();
	lastUpdate = gameTime->running();

	eventListener = new EventListener();
	input = new InputHandler(&m_event, eventListener);

}


Game::~Game() {}

void Game::Run()
{
	while (gameRunning)
	{
		input->InputCheck(gameRunning);
		currentUpdate = gameTime->running();
		if ((currentUpdate - lastUpdate) > GameTick)
		{
			std::cout << "Updating ";
			lastUpdate = currentUpdate;
		}
		Sleep(500);
		std::cout << ".";

		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gameRenderer);

		SDL_RenderPresent(gameRenderer);
	}

}