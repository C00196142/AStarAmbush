#pragma once
#include <iostream>
using namespace std;
class GameTime
{
public:
	static GameTime* getInstance();
	float running();
	~GameTime();
protected:
	GameTime();
private:
	static GameTime* instance;
	static float total; 
};

