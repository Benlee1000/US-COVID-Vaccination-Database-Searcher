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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
