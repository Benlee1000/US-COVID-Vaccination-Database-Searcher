#pragma once
#include <iostream>
#include "GlobalConstants.h"
#include "Database.h"

using namespace std;

class DatabaseOrganizer 
{
private:
	int stateSearchIndex;

public:
	int findState(string stateName, Database database);
};

