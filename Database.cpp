#include "Database.h"

bool Database::loadData()
{
	// Open existing file
	fin.open("database_files/covid19_vaccinations_in_the_united_states.csv", ios::in);
	
	while (getline(fin, line))
	{
		//clear previous row
		row.clear();

		// used to break into words
		stringstream s(line);

		// read all columns, store into row vector
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}

		if (row.size() > 0) cout << row[0] << "\n";


	}
	return true;
}