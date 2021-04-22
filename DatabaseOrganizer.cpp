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