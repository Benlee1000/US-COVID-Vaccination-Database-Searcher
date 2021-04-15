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
	// Allow DatabaseOrganizer to access array of states
	friend class DatabaseOrganizer;

private: 
	vector<string> row;
	string line, word;
	bool startReading = false;

	// Keep track of current state
	int stateIndex = 0;

	// File pointer
	fstream fin;

	// Create an array of states to organize/search later
	State states[50];

public:

	// Create an enum class to help with displaying data
	enum class displayType {allData, dosesDelivered, dosesDeliveredPer100k, dosesAdministered, dosesAdministeredPer100k, percentOfPopWithAtLeastOneDose};

	bool loadData();
	void displayData(int startIndex, int endIndex, displayType whatToDisplay);
	
};

