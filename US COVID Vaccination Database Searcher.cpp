// US COVID Vaccination Database Searcher
#include <iostream>
#include "Database.h"
#include "DatabaseOrganizer.h"
using namespace std;

int main()
{
    Database database; 
    DatabaseOrganizer databaseOrganizer;
    string response, stateResponse, stringContinueRunning;
    int stateSearchIndex;
    bool continueRunning = true;

    database.loadData();

    cout << "Welcome to the COVID-19 Vaccination Database Searcher\n";
    do
    {   
        cout << "What would you like to do? (Enter a number) \n"
             << "1: Display all information for all 50 states \n"
             << "2: Display all information for a specific state \n"
             << "3: Display information for all states in a specific order \n"
             << "4: Learn how to update the database searcher \n";
        getline(cin, response);
        while (response != "1" && response != "2" && response != "3" && response != "4")
        {
            cout << "ERROR: Please enter a number (1-4)\n";
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
                getline(std::cin, stateResponse); // Allows for spaces!
                stateSearchIndex = databaseOrganizer.findState(stateResponse, database);
                database.displayData(stateSearchIndex, stateSearchIndex + 1, Database::displayType::allData);
                break;
            // Display information in order
            case 3:
                break;
            // Display how to update the database searcher
            case 4:
                cout << "1: Navigate to 'https://covid.cdc.gov/covid-data-tracker/#vaccinations'\n";
                cout << "2: Click on 'Data Table for COVID-19 Vaccinations in the United States' near the bottom of the page\n";
                cout << "3: Press 'Download Data', and be sure the file is named 'covid19_vaccinations_in_the_united_states.csv'\n";
                cout << "4: Insert the new downloaded csv file into the 'database_files' folder, replacing the old version\n";
                break;
            default:
                cout << "ERROR: You must enter a number (1-4)\n";
                break;
        }

        // Ask if the user wants to continue using the searcher and check if input is valid
        cout << "Would you like to continue using the database searcher? (Yes/No): ";
        getline(cin, stringContinueRunning);
        while (stringContinueRunning != "Yes" && stringContinueRunning != "yes" && stringContinueRunning != "No" && stringContinueRunning != "no")
        {
            cout << "ERROR: Please enter a valid respone(Yes/No): ";
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

