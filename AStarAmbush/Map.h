#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Map
{
public:
	Map() { width = 30; height = 30; };
	~Map() {};

	void init();
	void Render();

private:
	vector<vector<int>> World;
	int width;
	int height;
};

