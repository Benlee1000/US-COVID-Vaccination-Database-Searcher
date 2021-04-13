#include "DatabaseOrganizer.h"

int DatabaseOrganizer::findState(string stateName, Database database) 
{
	for (stateSearchIndex = 0; stateSearchIndex < DATABASE_SIZE; stateSearchIndex++) 
	{
		//states[2].setDosesDelivered(60);
		//cout << "State Answer: "<<states[2].getDosesDelivered();
		if (database.states[stateSearchIndex].getState() == stateName)
		{
			
			return stateSearchIndex;
		}
	}
	return -1;
}
