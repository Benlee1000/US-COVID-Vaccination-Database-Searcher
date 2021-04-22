#pragma once
#include <iostream>
#include "GlobalConstants.h"
#include "Database.h"

using namespace std;

class DatabaseOrganizer 
{
private:
	int stateSearchIndex;

	// Store temporary states, for swapping states
	State tempState;
	State tempCopyState;

public:
	int findState(string stateName, Database &database);

	// Swap state1 and state2
	void swapState(State &state1, State &state2);

	// Replace the information in state1 with state2
	void replaceState(State &state1, State &state2);

	// Return a copy of a state
	State copyState(State& state);
};

