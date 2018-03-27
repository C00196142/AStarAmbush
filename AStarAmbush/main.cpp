#include <iostream>
#include <Windows.h>
#include "GameTime.h"

using namespace std;

const float TRIGGER = 0.2f;

int main(void)
{
	float last = 0.0f;
	float current = 0.0f;
	GameTime* gameTime = GameTime::getInstance();

	last = gameTime->running();

	while (true)
	{
		current = gameTime->running();
		if ((current - last) > TRIGGER)
		{
			cout << "Updating";
			last = current;
		}
		Sleep(500);
		cout << ".";
	}
}