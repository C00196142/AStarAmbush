#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "EventListener.h"

using namespace std;

class InputHandler
{
public:
	InputHandler() {};
	InputHandler(SDL_Event * e, EventListener * ep)
	{
		m_e = e; m_eventlisten = ep;
		m_Rightdirection.x = 0;
		m_Rightdirection.y = 0;

		m_Leftdirection.x = 0;
		m_Leftdirection.y = 0;


	};
	~InputHandler();

	void InputCheck(bool & gameRunning);
	SDL_Point GetRightAnaloguerotation();
	SDL_Point GetLeftAnalogue();

private:
	SDL_Event * m_e;
	EventListener * m_eventlisten;
	const int DEADZONE = 5000;
	SDL_Joystick *controller = nullptr;
	SDL_Haptic *gControllerHaptic = nullptr;
	SDL_Point m_Rightdirection;
	SDL_Point m_Leftdirection;

};
#endif
