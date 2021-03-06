#include "DatabaseOrganizer.h"

int DatabaseOrganizer::findState(const int& startIndex, const int& endIndex, const string& stateGoalName, Database &database) 
{
	// Use a binary search to find the requested state
	middleIndex = (endIndex - startIndex) / 2 + startIndex;

	// If the state name is equal to our goal, we are finished!
	if (database.states[middleIndex].getState() == stateGoalName)
	{
		return middleIndex;
	}

	// When endIndex is greater than or equal to startIndex, the state was not found, so return -1
	if (startIndex < endIndex)
	{
		// Search bottom half if goal < middleIndex
		if (stateGoalName < database.states[middleIndex].getState())
		{
			return findState(startIndex, middleIndex - 1, stateGoalName, database);
		}
		// Otherwise search top half
		else
		{
			return findState(middleIndex + 1, endIndex, stateGoalName, database);
		}
	}
	else
	{
		// Since the state name is verified before searching, this rarely ever happens. Therefore, it is the last thing we check for.
		return -1;
	}

}

void DatabaseOrganizer::sortStates(const int& startIndex, const int& endIndex, Database &database, const DatabaseOrganizer::sortType& whatToSort)
{
	// When endIndex is greater than or equal to startIndex, the sort is finished!
	if (startIndex < endIndex) 
	{
		pivotIndex = startIndex;
		for (currentStateIndex = startIndex + 1; currentStateIndex <= endIndex; currentStateIndex++)
		{
			// Check if greater than pivot depending on what to sort by
			switch (whatToSort)
			{
				case DatabaseOrganizer::sortType::stateName:
					// For alphabetical order, this if statement needs to be reversed
					if (database.states[currentStateIndex].getState() < database.states[pivotIndex].getState())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesDelivered:
					if (database.states[currentStateIndex].getDosesDelivered() > database.states[pivotIndex].getDosesDelivered())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesDeliveredPer100k:
					if (database.states[currentStateIndex].getDosesDeliveredPer100k() > database.states[pivotIndex].getDosesDeliveredPer100k())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesAdministered:
					if (database.states[currentStateIndex].getDosesAdministered() > database.states[pivotIndex].getDosesAdministered())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::dosesAdministeredPer100k:
					if (database.states[currentStateIndex].getDosesAdministeredPer100k() > database.states[pivotIndex].getDosesAdministeredPer100k())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::percentOfPopWithAtLeastOneDose:
					if (database.states[currentStateIndex].getPercentOfPopWithAtLeastOneDose() > database.states[pivotIndex].getPercentOfPopWithAtLeastOneDose())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::percentFullyVaccinated:
					if (database.states[currentStateIndex].getPercentFullyVaccinated() > database.states[pivotIndex].getPercentFullyVaccinated())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::JandJDosesAdministered:
					if (database.states[currentStateIndex].getJandJDosesAdministered() > database.states[pivotIndex].getJandJDosesAdministered())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::ModernaDosesAdministered:
					if (database.states[currentStateIndex].getModernaDosesAdministered() > database.states[pivotIndex].getModernaDosesAdministered())
					{
						greaterThanPivot = true;
					}
					break;
				case DatabaseOrganizer::sortType::PfizerDosesAdministered:
					if (database.states[currentStateIndex].getPfizerDosesAdministered() > database.states[pivotIndex].getPfizerDosesAdministered())
					{
						greaterThanPivot = true;
					}
					break;
				default:
					break;
			}
			if (greaterThanPivot)
			{
				swapState(database.states[pivotIndex + 1], database.states[currentStateIndex]);
				swapState(database.states[pivotIndex], database.states[pivotIndex + 1]);
				pivotIndex++;

				// Reset the pivot boolean
				greaterThanPivot = false;

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

void DatabaseOrganizer::replaceState(State& state1, State& state2) const
{
	state1.setState(state2.getState());
	state1.setDosesDelivered(state2.getDosesDelivered());
	state1.setDosesDeliveredPer100k(state2.getDosesDeliveredPer100k());
	state1.setDosesAdministered(state2.getDosesAdministered());
	state1.setDosesAdministeredPer100k(state2.getDosesAdministeredPer100k());
	state1.setPercentOfPopWithAtLeastOneDose(state2.getPercentOfPopWithAtLeastOneDose());
	state1.setPercentFullyVaccinated(state2.getPercentFullyVaccinated());
	state1.setJandJDosesAdministered(state2.getJandJDosesAdministered());
	state1.setModernaDosesAdministered(state2.getModernaDosesAdministered());
	state1.setPfizerDosesAdministered(state2.getPfizerDosesAdministered());
}

State DatabaseOrganizer::copyState(State& state)
{
	tempCopyState.setState(state.getState());
	tempCopyState.setDosesDelivered(state.getDosesDelivered());
	tempCopyState.setDosesDeliveredPer100k(state.getDosesDeliveredPer100k());
	tempCopyState.setDosesAdministered(state.getDosesAdministered());
	tempCopyState.setDosesAdministeredPer100k(state.getDosesAdministeredPer100k());
	tempCopyState.setPercentOfPopWithAtLeastOneDose(state.getPercentOfPopWithAtLeastOneDose());
	tempCopyState.setPercentFullyVaccinated(state.getPercentFullyVaccinated());
	tempCopyState.setJandJDosesAdministered(state.getJandJDosesAdministered());
	tempCopyState.setModernaDosesAdministered(state.getModernaDosesAdministered());
	tempCopyState.setPfizerDosesAdministered(state.getPfizerDosesAdministered());

	return tempCopyState;
}