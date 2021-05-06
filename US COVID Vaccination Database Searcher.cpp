// US COVID Vaccination Database Searcher
#include <iostream>
#include "Database.h"
#include "DatabaseOrganizer.h"
using namespace std;

int main()
{
    Database database; 
    DatabaseOrganizer databaseOrganizer;
    string response, stateResponse, sortResponse, stringContinueRunning;
    int stateSearchIndex;
    bool continueRunning = true;

    // Load the csv values into databae, return an error if the file couldn't be opened and exit program
    if (!database.loadData())
    {
        cout << "ERROR: 'database_files/covid19_vaccinations_in_the_united_states.csv' was not found\n";
        exit(1);
    }

    // Make sure the states are in alphabetical order, so it can be binary searched
    databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);

    cout << "Welcome to the COVID-19 Vaccination Database Searcher\n";
    do
    {   
        cout << "What would you like to do? (Enter a number)\n"
             << "1: Display all information for all 50 states\n"
             << "2: Display all information for a specific state\n"
             << "3: Display information for all states in a specific order\n" // Display top 5?
             << "4: Learn how to update the database searcher\n";
        getline(cin, response);
        while (response != "1" && response != "2" && response != "3" && response != "4")
        {
            cout << "ERROR, Please enter a number (1-4): ";
            getline(cin, response);
        }

        switch (stoi(response))
        {
            // Display all information 
            case 1:
                database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                break;

            // Display a state's information
            case 2:
                cout << "Which state would you like to display information for? ";
                getline(cin, stateResponse); // Allows for spaces!
                while (!database.isAState(stateResponse))
                {
                    cout << "ERROR, please enter a valid state name (case sensitive): ";
                    getline(cin, stateResponse);
                }
                stateSearchIndex = databaseOrganizer.findState(0, DATABASE_SIZE-1, stateResponse, database);
                database.displayData(stateSearchIndex, stateSearchIndex + 1, Database::displayType::allData);
                break;

            // Display information in a specific order
            case 3:
                cout << "\nHow would you like to sort them? (Enter a number)\n"
                    << "1: By Total Doses Delivered\n"
                    << "2: By Doses Delivered Per 100k\n" 
                    << "3: By Total Doses Administered\n"
                    << "4: By Doses Administered Per 100k\n"
                    << "5: By Percent Of Population With At Least One Dose\n";
                getline(cin, sortResponse);
                while (sortResponse != "1" && sortResponse != "2" && sortResponse != "3" && sortResponse != "4" && sortResponse != "5")
                {
                    cout << "ERROR, Please enter a number (1-5): ";
                    getline(cin, sortResponse);
                }

                switch(stoi(sortResponse))
                {
                    // Organize by Doses Delivered
                    case 1:
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::dosesDelivered);
                        database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                        // Sort back into alphabetical order for the binary search
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);
                        break;
                    
                    // Organize by Doses Delivered Per 100k
                    case 2:
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::dosesDeliveredPer100k);
                        database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);
                        break;

                    // Organize by Doses Administered
                    case 3:
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::dosesAdministered);
                        database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);
                        break;

                    // Organize by Doses Administered Per 100k
                    case 4:
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::dosesAdministeredPer100k);
                        database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);
                        break;

                    // Organize by Percent Of Population With At Least One Dose
                    case 5:
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::percentOfPopWithAtLeastOneDose);
                        database.displayData(0, DATABASE_SIZE, Database::displayType::allData);
                        databaseOrganizer.sortStates(0, DATABASE_SIZE-1, database, DatabaseOrganizer::sortType::stateName);
                        break;

                    default:
                        break;
                }
                break;

            // Display how to update the database searcher
            case 4:
                cout << "\n";
                cout << "1: Navigate to 'https://covid.cdc.gov/covid-data-tracker/#vaccinations'\n";
                cout << "2: Click on 'Data Table for COVID-19 Vaccinations in the United States' near the bottom of the page\n";
                cout << "3: Press 'Download Data', and be sure the file is named 'covid19_vaccinations_in_the_united_states.csv'\n";
                cout << "4: Insert the new downloaded csv file into the 'database_files' folder, replacing the old version\n\n";
                break;

            default:
                break;
        }

        // Ask if the user wants to continue using the searcher and check if input is valid
        cout << "Would you like to continue using the database searcher? (Yes/No): ";
        getline(cin, stringContinueRunning);
        while (stringContinueRunning != "Yes" && stringContinueRunning != "yes" && stringContinueRunning != "No" && stringContinueRunning != "no")
        {
            cout << "ERROR, Please enter a valid respone(Yes/No): ";
            getline(cin, stringContinueRunning);
        }
        cout << "\n";
        // End the program when the user answers "No" or "no"
        if (stringContinueRunning == "no" || stringContinueRunning == "No")
        {
            continueRunning = false;
        }
    } while (continueRunning);

}

