#include "DatabaseOrganizer.h"

int DatabaseOrganizer::findState(string stateName) 
{
	for (stateSearchIndex = 0; stateSearchIndex < DATABASE_SIZE; stateSearchIndex++) 
	{
		if (states[stateSearchIndex].getState() == stateName)
		{
			
			return stateSearchIndex;
		}
	}
	return -1;
}
