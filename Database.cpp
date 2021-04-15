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

	// Exit function if file is not found
	if (!fin.is_open())
	{
		return false;
	}
	
	while (getline(fin, line))
	{
		//clear previous row
		row.clear();

		// used to break into words
		stringstream s(line);

		// read all columns, store into row vector
		while (getline(s, word, ','))
		{
			// For dealing with any "N/A" cells in the csv file
			if (word == "N/A")
			{
				word = "-1";
			}
			row.push_back(word);
		}

		// Only read rows that contain the usual 50 states
		if (row[0] == "Alabama" || row[0] == "Alaska" || row[0] == "Arizona" || row[0] == "Arkansas" || row[0] == "California" || row[0] == "Colorado" || row[0] == "Connecticut" || row[0] == "Delaware" || row[0] == "Florida" || row[0] == "Georgia" || row[0] == "Hawaii" || row[0] == "Idaho" || row[0] == "Illinois" || row[0] == "Indiana" || row[0] == "Iowa" || row[0] == "Kansas" || row[0] == "Kentucky" || row[0] == "Louisiana" || row[0] == "Maine" || row[0] == "Maryland" || row[0] == "Massachusetts" || row[0] == "Michigan" || row[0] == "Minnesota" || row[0] == "Mississippi" || row[0] == "Missouri" || row[0] == "Montana" || row[0] == "Nebraska" || row[0] == "Nevada" || row[0] == "New Hampshire" || row[0] == "New Jersey" || row[0] == "New Mexico" || row[0] == "New York State" || row[0] == "North Carolina" || row[0] == "North Dakota" || row[0] == "Ohio" || row[0] == "Oklahoma" || row[0] == "Oregon" || row[0] == "Pennsylvania" || row[0] == "Rhode Island" || row[0] == "South Carolina" || row[0] == "South Dakota" || row[0] == "Tennessee" || row[0] == "Texas" || row[0] == "Utah" || row[0] == "Vermont" || row[0] == "Virginia" || row[0] == "Washington" || row[0] == "West Virginia" || row[0] == "Wisconsin" || row[0] == "Wyoming")
		{
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

	// Improves readability
	cout << "\n"; 

	// loop through all states in question, displaying appropriate data
	for (int index = startIndex; index < endIndex; index++)
	{
		switch (whatToDisplay)
		{
			case Database::displayType::allData:
				cout << "|" << states[index].getState() << "|\nTotal Doses Delivered: " << states[index].getDosesDelivered() << "\nDoses Delivered Per 100k: " << states[index].getDosesDeliveredPer100k() << "\nTotal Doses Administed: " << states[index].getDosesAdministered() << "\nDoses Administered Per 100k: " << states[index].getDosesAdministeredPer100k() << "\nPercent of Population With At Least One Dose: " << states[index].getPercentOfPopWithAtLeastOneDose() << "%\n\n";
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

