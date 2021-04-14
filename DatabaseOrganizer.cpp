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
