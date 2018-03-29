#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void init();

private:
	vector<vector<int>> World;
	int width;
	int height;
};

