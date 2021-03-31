#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Database
{
private: 
	vector<string> row;
	string line, word, temp;

	// File pointer
	fstream fin;

public:
	bool loadData();
};

