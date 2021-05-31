/*
 * Columns: 0 Sate Name
 *          1 Total Doses Delivered
 *          2 Doses Delivered Per 100k
 *          4 Total Doses Administered
 *			5 Doses Administered Per 100k
 *			9 Percent of Pop with at Least One Dose
 * 
 *			13 Percent Fully Vaccinated
 *			20 J&J Doses Administered
 *			21 Moderna Doses Administered
 *			22 Pfizer Doses Administered
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
		if (isAState(row[0]))
		{
			// Fill in information for each state, use stoi/stof when neccessary (for comparisons later)
			states[stateIndex].setState(row[0]);
			states[stateIndex].setDosesDelivered(stoi(row[1]));
			states[stateIndex].setDosesDeliveredPer100k(stoi(row[2]));
			states[stateIndex].setDosesAdministered(stoi(row[4]));
			states[stateIndex].setDosesAdministeredPer100k(stoi(row[5]));
			states[stateIndex].setPercentOfPopWithAtLeastOneDose(stof(row[9]));
			states[stateIndex].setPercentFullyVaccinated(stof(row[13]));
			states[stateIndex].setJandJDosesAdministered(stof(row[20]));
			states[stateIndex].setModernaDosesAdministered(stof(row[21]));
			states[stateIndex].setPfizerDosesAdministered(stof(row[22]));

			//cout << row[0] << " Total Doses Delivered: " << row[1] << " Doses Delivered Per 100k: " << row[2] << " Total Doses Administed: " << row[4] << " Doses administered per 100k: " << row[5] << " Percent of Pop with at least one dose: " << row[9] << "\n";
			//cout << states[stateIndex].getState() << " Total Doses Delivered: " << states[stateIndex].getDosesDelivered() << " Doses Delivered Per 100k: " << states[stateIndex].getDosesDeliveredPer100k() << " Total Doses Administed: " << states[stateIndex].getDosesAdministered() << " Doses administered per 100k: " << states[stateIndex].getDosesAdministeredPer100k() << " Percent of Pop with at least one dose: " << states[stateIndex].getPercentOfPopWithAtLeastOneDose() << "\n";

			// Increment State Index
			stateIndex++;
		}
	}
	fin.close();
	return true;
}

bool Database::isAState(string stateName)
{
	// Return true if the name matches a state
	if (stateName == "Alabama" || stateName == "Alaska" || stateName == "Arizona" || stateName == "Arkansas" || stateName == "California" || stateName == "Colorado" || stateName == "Connecticut" || stateName == "Delaware" || stateName == "Florida" || stateName == "Georgia" || stateName == "Hawaii" || stateName == "Idaho" || stateName == "Illinois" || stateName == "Indiana" || stateName == "Iowa" || stateName == "Kansas" || stateName == "Kentucky" || stateName == "Louisiana" || stateName == "Maine" || stateName == "Maryland" || stateName == "Massachusetts" || stateName == "Michigan" || stateName == "Minnesota" || stateName == "Mississippi" || stateName == "Missouri" || stateName == "Montana" || stateName == "Nebraska" || stateName == "Nevada" || stateName == "New Hampshire" || stateName == "New Jersey" || stateName == "New Mexico" || stateName == "New York State" || stateName == "North Carolina" || stateName == "North Dakota" || stateName == "Ohio" || stateName == "Oklahoma" || stateName == "Oregon" || stateName == "Pennsylvania" || stateName == "Rhode Island" || stateName == "South Carolina" || stateName == "South Dakota" || stateName == "Tennessee" || stateName == "Texas" || stateName == "Utah" || stateName == "Vermont" || stateName == "Virginia" || stateName == "Washington" || stateName == "West Virginia" || stateName == "Wisconsin" || stateName == "Wyoming")
	{
		return true;
	}

	return false;
}

string Database::commaSeparate(int numberToSeparate)
{
	stringNumberToSeparate = to_string(numberToSeparate);
	charIndex = stringNumberToSeparate.length() - 3;
	while (charIndex > 0) {
		stringNumberToSeparate.insert(charIndex, ",");
		charIndex -= 3;
	}
	return stringNumberToSeparate;
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
				cout << "|" << states[index].getState() << "|" 
					 << "\nTotal Doses Delivered: " << commaSeparate(states[index].getDosesDelivered()) 
					 << "\nDoses Delivered Per 100k: " << commaSeparate(states[index].getDosesDeliveredPer100k()) 
					 << "\nTotal Doses Administed: " << commaSeparate(states[index].getDosesAdministered()) 
					 << "\nJ&J Doses Administered: " << commaSeparate(states[index].getJandJDosesAdministered())
					 << "\nModerna Doses Administered: " << commaSeparate(states[index].getModernaDosesAdministered())
					 << "\nPfizer Doses Administered: " << commaSeparate(states[index].getPfizerDosesAdministered())
					 << "\nDoses Administered Per 100k: " << commaSeparate(states[index].getDosesAdministeredPer100k()) 
					 << "\nPercent of Population With At Least One Dose: " << states[index].getPercentOfPopWithAtLeastOneDose() << "%"
					 << "\nPercent of Population Fully Vaccinated: " << states[index].getPercentFullyVaccinated() << "%\n\n";
				break;
			case Database::displayType::dosesDelivered:
				cout << "|" << states[index].getState() << "|\nTotal Doses Delivered: " << commaSeparate(states[index].getDosesDelivered()) << "\n\n";
				break;
			case Database::displayType::dosesDeliveredPer100k:
				cout << "|" << states[index].getState() << "|\nDoses Delivered Per 100k: " << commaSeparate(states[index].getDosesDeliveredPer100k()) << "\n\n";
				break;
			case Database::displayType::dosesAdministered:
				cout << "|" << states[index].getState() << "|\nTotal Doses Administered: " << commaSeparate(states[index].getDosesAdministered()) << "\n\n";
				break;
			case Database::displayType::dosesAdministeredPer100k:
				cout << "|" << states[index].getState() << "|\nDoses Administered Per 100k: " << commaSeparate(states[index].getDosesAdministeredPer100k()) << "\n\n";
				break;
			case Database::displayType::percentOfPopWithAtLeastOneDose:
				cout << "|" << states[index].getState() << "|\nPercent Of Population With At Least One Dose: " << states[index].getPercentOfPopWithAtLeastOneDose() << "%\n\n";
				break;
			case Database::displayType::percentFullyVaccinated:
				cout << "|" << states[index].getState() << "|\nPercent Of Population Fully Vaccinated: " << states[index].getPercentFullyVaccinated() << "%\n\n";
				break;
			case Database::displayType::JandJDosesAdministered:
				cout << "|" << states[index].getState() << "|\nJ&J Doses Administered: " << commaSeparate(states[index].getJandJDosesAdministered()) << "\n\n";
				break;
			case Database::displayType::ModernaDosesAdministered:
				cout << "|" << states[index].getState() << "|\nModerna Doses Administered: " << commaSeparate(states[index].getModernaDosesAdministered()) << "\n\n";
				break;
			case Database::displayType::PfizerDosesAdministered:
				cout << "|" << states[index].getState() << "|\nPfizer Doses Administered: " << commaSeparate(states[index].getPfizerDosesAdministered()) << "\n\n";
				break;
			default:
				cout << "ERROR: Incorrect display type\n";
				break;
		}
	}
}

