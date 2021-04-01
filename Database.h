#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "State.h"
using namespace std;

class Database
{
private: 
	vector<string> row;
	string line, word;

	// Keep track of current row, state
	int rowNum = 1; 
	int stateIndex = 0;

	// File pointer
	fstream fin;

	// Create an array of states to organize/search later
	State* states = new State[50];

public:
	bool loadData();

	// Deallocate memory when program ends
	~Database();
	
};

