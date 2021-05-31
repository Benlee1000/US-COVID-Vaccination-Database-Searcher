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
	float m_percentFullyVaccinated;
	int m_JandJDosesAdministered;
	int m_ModernaDosesAdministered;
	int m_PfizerDosesAdministered;

public:
	State();

	// Set functions
	void setState(string state);
	void setDosesDelivered(int dosesDelivered);
	void setDosesDeliveredPer100k(int dosesDeliveredPer100k);
	void setDosesAdministered(int dosesAdministered);
	void setDosesAdministeredPer100k(int dosesAdministeredPer100k);
	void setPercentOfPopWithAtLeastOneDose(float percentOfPopWithAtLeastOneDose);
	void setPercentFullyVaccinated(float percentFullyVaccinated);
	void setJandJDosesAdministered(int JandJDosesAdministered);
	void setModernaDosesAdministered(int ModernaDosesAdministered);
	void setPfizerDosesAdministered(int PfizerDosesAdministered);

	// Get functions
	string getState();
	int getDosesDelivered();
	int getDosesDeliveredPer100k();
	int getDosesAdministered();
	int getDosesAdministeredPer100k();
	float getPercentOfPopWithAtLeastOneDose();
	float getPercentFullyVaccinated();
	int getJandJDosesAdministered();
	int getModernaDosesAdministered();
	int getPfizerDosesAdministered();
};

