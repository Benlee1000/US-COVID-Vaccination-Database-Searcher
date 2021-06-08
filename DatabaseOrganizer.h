#pragma once
#include <iostream>
#include "GlobalConstants.h"
#include "Database.h"

using namespace std;

class DatabaseOrganizer 
{
private:
	// Temporary values for searching for a state
	int middleIndex;

	// Store temporary states, for swapping states
	State tempState;
	State tempCopyState;

	// Temporary values for sorting states
	int pivotIndex;
	int currentStateIndex;
	bool greaterThanPivot = false;

public:
	// Create an enum class to help with organizing data
	enum class sortType { stateName, dosesDelivered, dosesDeliveredPer100k, dosesAdministered, dosesAdministeredPer100k, percentOfPopWithAtLeastOneDose, percentFullyVaccinated, JandJDosesAdministered, ModernaDosesAdministered, PfizerDosesAdministered };

	// Finds and returns the index of the state requested
	int findState(const int& startIndex, const int& endIndex, const string& stateGoalName, Database& database);

	// Quicksort algorithm to sort the states by a certain value
	void sortStates(const int& startIndex, const int& endIndex, Database &database, const sortType& whatToSort);

	// Swap state1 and state2
	void swapState(State &state1, State &state2);

	// Replace the information in state1 with state2
	void replaceState(State &state1, State &state2) const;

	// Return a copy of a state
	State copyState(State& state);
};

