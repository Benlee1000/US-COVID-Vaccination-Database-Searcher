/*
 * Columns: 0 Sate Name
 *          1 Total Doses Delivered
 *          2 Doses Delivered Per 100k
 *          4 Total Doses Administered
 *			5 Doses Administered Per 100k
 *			9 Percent of Pop with at Least One Dose
 */

#include "Database.h"

bool Database::loadData()
{
	// Open existing file
	fin.open("database_files/covid19_vaccinations_in_the_united_states.csv", ios::in);
	
	while (getline(fin, line))
	{
		// Disregard rows that don't contain the usual 50 states
		// rowNum != ( 1 && 2 && 3 && 7 && 9 && 13 && 14 && 17 && 19 && 23 && 32 && 36 && 51 && 53 && 60 && 61)
		if (rowNum != 1 && rowNum != 2 && rowNum != 3 && rowNum != 7 && rowNum != 9 && rowNum != 13 && rowNum != 14 && rowNum != 17 && rowNum != 19 && rowNum != 23 && rowNum != 32 && rowNum != 36 && rowNum != 51 && rowNum != 53 && rowNum != 60 && rowNum != 61)
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

			// Fill in information for each state, use stoi/stof when neccessary (for comparisons later)
			states[stateIndex].setState(row[0]);
			states[stateIndex].setDosesDelivered(stoi(row[1]));
			states[stateIndex].setDosesDeliveredPer100k(stoi(row[2]));
			states[stateIndex].setDosesAdministered(stoi(row[4]));
			states[stateIndex].setDosesAdministeredPer100k(stoi(row[5]));
			states[stateIndex].setPercentOfPopWithAtLeastOneDose(stof(row[9]));
			

			//cout << row[0] << " Total Doses Delivered: " << row[1] << " Doses Delivered Per 100k: " << row[2] << " Total Doses Administed: " << row[4] << " Doses administered per 100k: " << row[5] << " Percent of Pop with at least one dose: " << row[9] << "\n";

			//cout << states[stateIndex].getState() << " Total Doses Delivered: " << states[stateIndex].getDosesDelivered() << " Doses Delivered Per 100k: " << states[stateIndex].getDosesDeliveredPer100k() << " Total Doses Administed: " << states[stateIndex].getDosesAdministered() << " Doses administered per 100k: " << states[stateIndex].getDosesAdministeredPer100k() << " Percent of Pop with at least one dose: " << states[stateIndex].getPercentOfPopWithAtLeastOneDose() << "\n";

			// Increment State Index
			stateIndex++;
		}
		// Increment the row number
		rowNum++;
	}
	fin.close();
	return true;
}

void Database::displayData(int startIndex, int endIndex, Database::displayType whatToDisplay)
{
	// If a state is not found, -1 will be returned by the findState function
	if (startIndex == -1)
	{
		cout << "ERROR, state not found\n";
		return;
	}

	// loop through all states in question, displaying appropriate data
	for (int index = startIndex; index < endIndex; index++)
	{
		switch (whatToDisplay)
		{
			case Database::displayType::allData:
				cout << "|" << states[index].getState() << "|\nTotal Doses Delivered: " << states[index].getDosesDelivered() << "\nDoses Delivered Per 100k: " << states[index].getDosesDeliveredPer100k() << "\nTotal Doses Administed: " << states[index].getDosesAdministered() << "\nDoses administered per 100k: " << states[index].getDosesAdministeredPer100k() << "\nPercent of Population With At Least One Dose: " << states[index].getPercentOfPopWithAtLeastOneDose() << "%\n\n";
				break;
			case Database::displayType::dosesDelivered:
				cout << "|" << states[index].getState() << "| Total Doses Delivered: " << states[index].getDosesDelivered() << "\n";
				break;
			case Database::displayType::dosesDeliveredPer100k:
				cout << "|" << states[index].getState() << "| Doses Delivered Per 100k: " << states[index].getDosesDeliveredPer100k() << "\n";
				break;
			case Database::displayType::dosesAdministered:
				cout << "|" << states[index].getState() << "| Total Doses Administered: " << states[index].getDosesAdministered() << "\n";
				break;
			case Database::displayType::dosesAdministeredPer100k:
				cout << "|" << states[index].getState() << "| Doses Administered Per 100k: " << states[index].getDosesAdministeredPer100k() << "\n";
				break;
			case Database::displayType::percentOfPopWithAtLeastOneDose:
				cout << "|" << states[index].getState() << "| Percent Of Population With At Least One Dose: " << states[index].getPercentOfPopWithAtLeastOneDose() << "%\n";
				break;
			default:
				cout << "ERROR: Incorrect display type\n";
				break;
		}
	}
}

