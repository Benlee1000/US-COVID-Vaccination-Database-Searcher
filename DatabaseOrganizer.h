#pragma once
#include <iostream>
#include "GlobalConstants.h"
#include "Database.h"

using namespace std;

class DatabaseOrganizer : public Database
{
private:
	int stateSearchIndex;

public:
	int findState(string stateName);
};

