#include "DatabaseOrganizer.h"

int DatabaseOrganizer::findState(string stateName, Database &database) 
{
	for (stateSearchIndex = 0; stateSearchIndex < DATABASE_SIZE; stateSearchIndex++) 
	{
		if (database.states[stateSearchIndex].getState() == stateName)
		{
			return stateSearchIndex;
		}
	}
	return -1;
}

void DatabaseOrganizer::sortStates(int startIndex, int endIndex, Database &database, DatabaseOrganizer::sortType whatToSort)
{
	// When startIndex is less than endIndex, the sort is finished!
	if (startIndex < endIndex) 
	{
		pivotIndex = startIndex;
		for (currentStateIndex = startIndex + 1; currentStateIndex <= endIndex; currentStateIndex++)
		{
			// Check if less than pivot depending on what to sort by
			switch (whatToSort)
			{
				case DatabaseOrganizer::sortType::stateName:
					if (database.states[currentStateIndex].getState() < database.states[pivotIndex].getState())
					{
						lessThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesDelivered:
					if (database.states[currentStateIndex].getDosesDelivered() < database.states[pivotIndex].getDosesDelivered())
					{
						lessThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesDeliveredPer100k:
					if (database.states[currentStateIndex].getDosesDeliveredPer100k() < database.states[pivotIndex].getDosesDeliveredPer100k())
					{
						lessThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesAdministered:
					if (database.states[currentStateIndex].getDosesAdministered() < database.states[pivotIndex].getDosesAdministered())
					{
						lessThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesAdministeredPer100k:
					if (database.states[currentStateIndex].getDosesAdministeredPer100k() < database.states[pivotIndex].getDosesAdministeredPer100k())
					{
						lessThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::percentOfPopWithAtLeastOneDose:
					if (database.states[currentStateIndex].getPercentOfPopWithAtLeastOneDose() < database.states[pivotIndex].getPercentOfPopWithAtLeastOneDose())
					{
						lessThanPivot = true;
					}
					break;
				default:
					break;
			}
			if (lessThanPivot)
			{
				swapState(database.states[pivotIndex + 1], database.states[currentStateIndex]);
				swapState(database.states[pivotIndex], database.states[pivotIndex + 1]);
				pivotIndex++;

				// Simailar to:
				// swap(anArray[pivotIndex + 1], anArray[i]);
				// swap(anArray[pivotIndex], anArray[pivotIndex + 1]);
				
			}
		}
		sortStates(startIndex, pivotIndex - 1, database, whatToSort);
		sortStates(pivotIndex + 1, endIndex, database, whatToSort);

		// Similar to:
		// quickSort(theArray, first, pivotIndex - 1) 
		// quickSort(theArray, pivotIndex + 1, last)
	}



}

void DatabaseOrganizer::swapState(State& state1, State& state2)
{
	tempState = copyState(state1);
	replaceState(state1, state2);
	replaceState(state2, tempState);
}

void DatabaseOrganizer::replaceState(State& state1, State& state2)
{
	state1.setState(state2.getState());
	state1.setDosesDelivered(state2.getDosesDelivered());
	state1.setDosesDeliveredPer100k(state2.getDosesDeliveredPer100k());
	state1.setDosesAdministered(state2.getDosesAdministered());
	state1.setDosesAdministeredPer100k(state2.getDosesAdministeredPer100k());
	state1.setPercentOfPopWithAtLeastOneDose(state2.getPercentOfPopWithAtLeastOneDose());
}

State DatabaseOrganizer::copyState(State& state)
{
	tempCopyState.setState(state.getState());
	tempCopyState.setDosesDelivered(state.getDosesDelivered());
	tempCopyState.setDosesDeliveredPer100k(state.getDosesDeliveredPer100k());
	tempCopyState.setDosesAdministered(state.getDosesAdministered());
	tempCopyState.setDosesAdministeredPer100k(state.getDosesAdministeredPer100k());
	tempCopyState.setPercentOfPopWithAtLeastOneDose(state.getPercentOfPopWithAtLeastOneDose());

	return tempCopyState;
}