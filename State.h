#pragma once
#include <iostream>

using namespace std;
class State
{
private:
	string m_state; 
	int m_dosesDelivered;
	int m_dosesDeliveredPer100k;
	int m_dosesAdministered;
	int m_dosesAdministeredPer100k;
	float m_percentOfPopWithAtLeastOneDose;

public:
	State();

	// Set functions
	void setState(string state);
	void setDosesDelivered(int dosesDelivered);
	void setDosesDeliveredPer100k(int dosesDeliveredPer100k);
	void setDosesAdministered(int dosesAdministered);
	void setDosesAdministeredPer100k(int dosesAdministeredPer100k);
	void setPercentOfPopWithAtLeastOneDose(float percentOfPopWithAtLeastOneDose);

	// Get functions
	string getState();
	int getDosesDelivered();
	int getDosesDeliveredPer100k();
	int getDosesAdministered();
	int getDosesAdministeredPer100k();
	float getPercentOfPopWithAtLeastOneDose();
};

