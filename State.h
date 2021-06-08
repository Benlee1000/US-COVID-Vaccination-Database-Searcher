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

	// Set functions, arguments passed by parameter reference since they are not modified
	void setState(const string& state);
	void setDosesDelivered(const int& dosesDelivered);
	void setDosesDeliveredPer100k(const int& dosesDeliveredPer100k);
	void setDosesAdministered(const int& dosesAdministered);
	void setDosesAdministeredPer100k(const int& dosesAdministeredPer100k);
	void setPercentOfPopWithAtLeastOneDose(const float& percentOfPopWithAtLeastOneDose);
	void setPercentFullyVaccinated(const float& percentFullyVaccinated);
	void setJandJDosesAdministered(const int& JandJDosesAdministered);
	void setModernaDosesAdministered(const int& ModernaDosesAdministered);
	void setPfizerDosesAdministered(const int& PfizerDosesAdministered);

	// Get functions, constant functions because they change no values
	string getState();
	int getDosesDelivered() const;
	int getDosesDeliveredPer100k() const;
	int getDosesAdministered() const;
	int getDosesAdministeredPer100k() const;
	float getPercentOfPopWithAtLeastOneDose() const;
	float getPercentFullyVaccinated() const;
	int getJandJDosesAdministered() const;
	int getModernaDosesAdministered() const;
	int getPfizerDosesAdministered() const;
};

