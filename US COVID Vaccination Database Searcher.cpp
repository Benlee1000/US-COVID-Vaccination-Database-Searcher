// US COVID Vaccination Database Searcher.cpp

#include <iostream>
#include "Database.h"
using namespace std;

int main()
{
    Database database; 
    string respone;
    string stringContinueRunning;
    bool continueRunning = true;

    database.loadData();

    cout << "Welcome to the COVID-19 Vaccination Database Searcher\n";
    do
    {
        
        cout << "What would you like to know? \n";
        cin >> respone;

        // Ask if the user wants to continue using the searcher and check if input is valid
        cout << "Would you like to continue using the database searcher? (Yes/No): ";
        cin >> stringContinueRunning;
        while (stringContinueRunning != "Yes" && stringContinueRunning != "yes" && stringContinueRunning != "No" && stringContinueRunning != "no")
        {
            cout << "ERROR: Please enter a valid respone(Yes/No): ";
            cin >> stringContinueRunning;
        }
        cout << "\n";
        // End the program when the user answers "No" or "no"
        if (stringContinueRunning == "no" || stringContinueRunning == "No")
        {
            continueRunning = false;
        }
    } while (continueRunning);

}

