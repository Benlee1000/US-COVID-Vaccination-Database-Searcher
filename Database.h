#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "State.h"
#include "GlobalConstants.h"
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

protected:
	// Create an array of states to organize/search later
	State* states = new State[50];


public:
	// Create an enum class to help with displaying data
	enum class displayType {allData, dosesDelivered, dosesDeliveredPer100k, dosesAdministered, dosesAdministeredPer100k, percentOfPopWithAtLeastOneDose};

	bool loadData();
	void displayData(int startIndex, int endIndex, displayType whatToDisplay);

	// Deallocate memory when program ends
	~Database();
	
};

